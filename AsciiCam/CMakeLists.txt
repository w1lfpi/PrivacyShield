
cmake_minimum_required(VERSION 3.15)
project(AsciiCam)

# Настройки компилятора
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Release)

# Поиск OpenCV
find_package(OpenCV REQUIRED 
    COMPONENTS 
        core 
        imgproc 
        highgui 
        videoio 
        dnn
)

# Настройки для macOS
if (APPLE)
    set(CMAKE_MACOSX_RPATH TRUE)
    set(OPENCV_LIB_DIR "/usr/local/opt/opencv/lib")
endif()

# Создание исполняемого файла
add_executable(AsciiCam src/main.cpp)

# Настройки линковки
target_include_directories(AsciiCam PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(AsciiCam PRIVATE ${OpenCV_LIBS})

# Настройки RPATH
set_target_properties(AsciiCam PROPERTIES
    INSTALL_RPATH "${OPENCV_LIB_DIR}"
    BUILD_WITH_INSTALL_RPATH TRUE
)

# Копирование моделей
file(COPY ${CMAKE_SOURCE_DIR}/models DESTINATION ${CMAKE_BINARY_DIR})