//
// Created by Home on 6/18/2023.
//
#include <stdexcept>
#include "Exceptii.h"

noteams_error :: noteams_error(std::string s): app_error(s) {};
wrongteam_error :: wrongteam_error(int lenght): app_error("Lungimea sirului trebuie sa fie mai mica sau egala cu " + std::to_string(lenght)) {};