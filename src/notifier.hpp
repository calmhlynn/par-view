#pragma once
#include "config.hpp"
#include <string>

class Notifier {
  public:
    Notifier(const Config &cfg);
    void send(const string &message);

  private:
    Config cfg_;
};
