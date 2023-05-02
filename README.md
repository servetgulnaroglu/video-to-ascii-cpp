# Video to ASCII Converter (C++)

This repository contains a C++ implementation of a real-time video-to-ASCII converter. It takes input from a webcam or video file and generates an ASCII art representation of the video content. The project uses OpenCV library to handle video input and processing.

## Table of Contents

1. [Features](#features)
2. [Dependencies](#dependencies)
3. [Building and Running](#building-and-running)
4. [Usage](#usage)
5. [Example](#example)
6. [Contributing](#contributing)
7. [License](#license)

## Features

- Real-time video-to-ASCII conversion
- Supports input from webcam or video files
- Adjustable ASCII character set and resolution
- Easily customizable to suit your needs
- Cross-platform support (tested on Windows and Linux)

## Dependencies

This project depends on the following libraries:

- [OpenCV](https://opencv.org/) (>= 4.0)

## Building and Running

### MacOS

1. Install OpenCV and set up the environment.
2. If you are using vim edit the compile_commands.json. Find the path of opencv and change with the path in compile_commands.json 
3. Modify the opencv path in build.sh
4. Give permission to build.sh by:
      $ chmod +x build.sh
5. Run in terminal:
      $ ./build.sh

## Usage

Usage: 

1. Edit the path of video in main.cpp
2. Run in terminal:
      $ ./build.sh

## Contributing

Contributions are welcome! Please feel free to open an issue or submit a pull request if you find a bug, have a feature request, or would like to improve the project in any way.

## License

This project is licensed under the MIT License.
