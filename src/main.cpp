#include "config.hpp"
#include "motion_detector.hpp"
#include "notifier.hpp"
#include <opencv2/opencv.hpp>

int main() {
    auto cfg = loadConfig();
    cv::VideoCapture cap(cfg.cameraUrl);
    if (!cap.isOpened())
        return -1;

    cv::Mat prev;
    cap.read(prev);
    cv::cvtColor(prev, prev, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(prev, prev, cv::Size(21, 21), 0);

    MotionDetector detector(cfg.motionThreshold);
    Notifier notifier(cfg);

    cv::Mat frame, gray;
    while (cap.read(frame)) {
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
        cv::GaussianBlur(gray, gray, cv::Size(21, 21), 0);

        if (detector.detect(prev, gray)) {
            notifier.send("{ \"event\": \"motion\" }");
        }
        prev = gray.clone();
        if (cv::waitKey(30) == 'q')
            break;
    }
    return 0;
}
