#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

class MotionDetector {
  public:
    MotionDetector(double threshold);
    bool detect(const Mat &prev, const Mat &curr);

  private:
    double threshold_;
};
