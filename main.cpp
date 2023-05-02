#include <opencv2/opencv.hpp>

#include <chrono>
#include <iostream>
#include <thread>
using namespace std;
using namespace cv;

string pixelToASCII(int pixel_intensity) {
  // const string ASCII_CHARS = "@$%#&!*+=-_.                ";
  //    const string ASCII_CHARS = "@#&!*+=-_.     ";
  const string ASCII_CHARS = "   ._-=+*!&#%$@";
  string s =
      string(1, ASCII_CHARS[pixel_intensity * ASCII_CHARS.length() / 256]);
  return s;
}

int main() {
  string video_path = "/Users/servetg/Projects/yt/video-to-ascii-cpp/vid1.mp4";
  VideoCapture cap(video_path);

  double fps = cap.get(CAP_PROP_FPS);

  cout << fps << endl;

  int frame_duration_ms = 1000 / fps;

  int width = 250;
  int height = 50;

  int frame_width = cap.get(CAP_PROP_FRAME_WIDTH);
  int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT);
  cout << frame_width << " " << frame_height << endl;
  // 4096 2160
  // 751 × 944

  height = (width * frame_height / frame_width) * 0.4194;

  Mat frame, gray_frame, resized_frame;

  while (true) {
    cap >> frame;
    if (frame.empty())
      break;

    cv::cvtColor(frame, gray_frame, cv::COLOR_BGR2GRAY);

    resize(gray_frame, resized_frame, Size(width, height), 0, 0, INTER_LINEAR);

    string ascii_frame;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        ascii_frame += pixelToASCII(resized_frame.at<uchar>(i, j));
      }
      ascii_frame += "\n";
    }

    system("clear"); // to clear the console
    cout << ascii_frame;
    std::this_thread::sleep_for(std::chrono::milliseconds(frame_duration_ms));
  }

  return 0;
}
