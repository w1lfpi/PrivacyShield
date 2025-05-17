# English
# PrivacyShield
## Created by [w1lfpi](https://github.com/w1lfpi)
> **Note:** This guide is intended for **macOS and Linux** users.  
> Windows users will need to adapt the steps accordingly, for example, using Visual Studio and pre-built OpenCV binaries.


## 📖 About the Project

**PrivacyShield** is a C++ application using **OpenCV** for real-time face detection and pixelation from a live camera feed.

## Demo
![Demo](assets/demo.gif)

## 📦 Clone the Repository

Start by cloning this repository:

```
git clone https://github.com/w1lfpi/PrivacyShield.git
cd PrivacyShield
```

## ⚙️ Installing OpenCV

If you don't have OpenCV installed, you can clone and build it manually:

```
git clone https://github.com/opencv/opencv.git
```

```
cd opencv
```

```
mkdir build && cd build
```

```
cmake ..
```

```
make -j$(nproc)
```

```
sudo make install
```

## 🛠️ Building AsciiCam

After installing OpenCV, go back to the `PrivacyShield` directory and:

```
cd AsciiCam
```

```
mkdir build
```

```
cd build
```

```
cmake ..
```

```
make
```

## ▶️ Running the Application

After a successful build, you can run the app from the `AsciiCam/build` directory:

```
./AsciiCam
```

If you encounter a runtime error related to missing libraries (especially on macOS), run the following command to add the necessary runtime path:

```
install_name_tool -add_rpath /usr/local/lib ./AsciiCam
```

This fixes issues where the OpenCV dynamic libraries cannot be found at runtime.

## ⚠️ Important Notes

- Make sure you have the following files in the `AsciiCam/models/` directory:
  - `deploy.prototxt`
  - `res10_300x300_ssd_iter_140000.caffemodel`

  If these files are missing, download them from:

  - [deploy.prototxt](https://github.com/opencv/opencv/blob/master/samples/dnn/face_detector/deploy.prototxt)
  - [res10_300x300_ssd_iter_140000.caffemodel](https://github.com/opencv/opencv/blob/master/samples/dnn/face_detector/res10_300x300_ssd_iter_140000.caffemodel)

- If OpenCV is installed in a non-standard location, you may need to specify the path manually when running `cmake`:

```
cmake -DOpenCV_DIR=/path/to/opencv ..
```

- A working webcam is required for proper functionality.

## 📂 Project Structure

```
PrivacyShield/
├── AsciiCam/
│   ├── include/
│   ├── models/        # ← place .prototxt and .caffemodel files here
│   ├── src/
│   ├── CMakeLists.txt
│   └── build/
├── opencv/
└── README.md
```



# Russian

# PrivacyShield 
## Created by [w1lfpi](https://github.com/w1lfpi)

> **Важно:** Эта инструкция предназначена для пользователей **macOS и Linux**.  
> Пользователям Windows потребуется использовать Visual Studio и установить OpenCV другим способом.

## Демо
![Demo](assets/demo.gif)

## 📖 О проекте

**PrivacyShield** — это C++-приложение с использованием **OpenCV** для распознавания и пикселизации лиц в реальном времени прямо с камеры.

## 📦 Клонирование репозитория

Склонируйте основной репозиторий:

```
git clone https://github.com/w1lfpi/PrivacyShield.git
cd PrivacyShield
```

## ⚙️ Установка OpenCV

Если у вас не установлен OpenCV, склонируйте и соберите его:

```
git clone https://github.com/opencv/opencv.git
```

```
cd opencv
```

```
mkdir build && cd build
```

```
cmake ..
```

```
make -j$(nproc)
```

```
sudo make install
```

## 🛠️ Сборка AsciiCam

Вернитесь в корень `PrivacyShield`, затем:

```
cd AsciiCam
```

```
mkdir build
```

```
cd build
```

```
cmake ..
```

```
make
```

## ▶️ Запуск

После успешной сборки запустите программу:

```
./AsciiCam
```

Если при запуске возникла ошибка, связанная с отсутствием библиотек (особенно на macOS), выполните:

```
install_name_tool -add_rpath /usr/local/lib ./AsciiCam
```

Эта команда добавит путь к установленным библиотекам OpenCV, если они не находятся в стандартных директориях загрузчика.

## ⚠️ Важные замечания

- Убедитесь, что в папке `AsciiCam/models/` находятся следующие файлы:
  - `deploy.prototxt`
  - `res10_300x300_ssd_iter_140000.caffemodel`

  Если этих файлов нет, скачайте их по официальным ссылкам:

  - [deploy.prototxt](https://github.com/opencv/opencv/blob/master/samples/dnn/face_detector/deploy.prototxt)
  - [res10_300x300_ssd_iter_140000.caffemodel](https://github.com/opencv/opencv/blob/master/samples/dnn/face_detector/res10_300x300_ssd_iter_140000.caffemodel)

- Если OpenCV установлен в нестандартный путь, при сборке может понадобиться указать его явно:

```
cmake -DOpenCV_DIR=/path/to/opencv ..
```

- Для корректной работы требуется веб-камера.

## 📂 Структура проекта

```
PrivacyShield/
├── AsciiCam/
│   ├── include/
│   ├── models/        # ← сюда положить .prototxt и .caffemodel
│   ├── src/
│   ├── CMakeLists.txt
│   └── build/
├── opencv/
└── README.md
```