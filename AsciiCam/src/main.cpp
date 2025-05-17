#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>
#include <sys/stat.h>
#include <limits.h>
#include <stdlib.h>


bool fileExists(const std::string& path) {
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0);
}


std::string getAbsolutePath(const std::string& path) {
    char* absPath = realpath(path.c_str(), nullptr);
    if (!absPath) return path;
    std::string result(absPath);
    free(absPath);
    return result;
}

int main() {
    const std::string configPath = "models/deploy.prototxt";
    const std::string modelPath = "models/res10_300x300_ssd_iter_140000.caffemodel";

    
    if (!fileExists(configPath) || !fileExists(modelPath)) {
        std::cerr << "Error: Model files not found!\n"
                  << "1. " << getAbsolutePath(configPath) << "\n"
                  << "2. " << getAbsolutePath(modelPath) << "\n";
        return -1;
    }

    
    cv::dnn::Net net = cv::dnn::readNetFromCaffe(configPath, modelPath);
    if (net.empty()) {
        std::cerr << "Failed to load DNN model!\n";
        return -1;
    }

    // Инициализация камеры
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: cannot open camera\n";
        return -1;
    }

    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        
        cv::Mat blob = cv::dnn::blobFromImage(frame, 1.0, cv::Size(300, 300), 
                                            cv::Scalar(104.0, 177.0, 123.0), false, false);
        net.setInput(blob);
        cv::Mat detections = net.forward();

        
        cv::Mat detectionMat(detections.size[2], detections.size[3], CV_32F, detections.ptr<float>());
        
        for (int i = 0; i < detectionMat.rows; ++i) {
            float confidence = detectionMat.at<float>(i, 2);
            
            if (confidence > 0.6) {
                int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * frame.cols);
                int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * frame.rows);
                int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * frame.cols);
                int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * frame.rows);

                
                int padding = 30;
                x1 = std::max(0, x1 - padding);
                y1 = std::max(0, y1 - padding);
                x2 = std::min(frame.cols - 1, x2 + padding);
                y2 = std::min(frame.rows - 1, y2 + padding);

                
                cv::Rect faceROI(x1, y1, x2 - x1, y2 - y1);
                cv::Mat face = frame(faceROI);
                cv::Mat smallFace, pixelatedFace;
                cv::resize(face, smallFace, cv::Size(10, 10), 0, 0, cv::INTER_LINEAR);
                cv::resize(smallFace, pixelatedFace, face.size(), 0, 0, cv::INTER_NEAREST);
                pixelatedFace.copyTo(frame(faceROI));

                cv::rectangle(frame, faceROI, cv::Scalar(0, 255, 0), 2);
            }
        }

        cv::imshow("Face Pixelator", frame);
        if (cv::waitKey(10) == 27) break;
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}