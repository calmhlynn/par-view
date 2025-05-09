#include "config.hpp"
#include <cstdlib>
#include <stdexcept>

static string getEnv(const char *key) {
    const char *val = getenv(key);

    if (!val) {
        throw runtime_error(string("Missing env var: ") + key);
    }

    return string(val);
}

Config loadConfig() {
    Config cfg;

    cfg.cameraUrl = getEnv("CAMERA_URL");
    cfg.motionThreshold = std::stod(getEnv("MOTION_THRESHOLD"));
    cfg.notifyHost = getEnv("NOTIFY_HOST");
    cfg.notifyPath = getEnv("NOTIFY_PATH");
    cfg.notifyPort =
        static_cast<unsigned short>(std::stoi(getEnv("NOTIFY_PORT")));

    return cfg;
}
