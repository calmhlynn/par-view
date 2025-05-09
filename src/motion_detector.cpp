#include "motion_detector.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

MotionDetector::MotionDetector(double threshold) : threshold_(threshold) {}

bool MotionDetector::detect(const Mat &prev, const Mat &curr) {
    Mat delta, thresh;
    absdiff(prev, curr, delta);
    threshold(delta, thresh, 25, 255, THRESH_BINARY);
    dilate(thresh, thresh, Mat(), Point(-1, 1));
    double area = sum(thresh)[0] / 255.0;
    return area > this->threshold_;
}
