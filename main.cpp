#include "ThreadManager.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <optional>

using namespace std;

optional<int> get_even_number(int num) {
    if (num % 2 == 0) {
        return num;
    } else {
        return {};
    }
}

int main() {

    ThreadManager ThreadManager;
    ThreadManager.startThreads();
    ThreadManager.joinThreads();
    ThreadManager.getThreadsNumber();

    auto opt = get_even_number(3);

    if (opt.has_value()) {
        cout << "Even number: " << opt.value() << "\n";
    } else {
        cout << "Not an even number.\n";
    }

    // OpenCV: Create and show a simple image
    cv::Mat img = cv::Mat::ones(256, 256, CV_8UC3) * 255; // White image
    cv::putText(img, "OpenCV OK", cv::Point(30, 130), cv::FONT_HERSHEY_SIMPLEX,
                1, cv::Scalar(0, 0, 0), 2);
    cv::imshow("Test Image", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
