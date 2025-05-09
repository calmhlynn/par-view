#pragma once
#include <string>

using namespace std;

struct Config {
    string cameraUrl;
    double motionThreshold;
    string notifyHost;
    string notifyPath;
    unsigned short notifyPort;
};

Config loadConfig();
