#pragma once

#include <string>

namespace Constants {
    // User-related constants
    constexpr size_t MAX_NAME_LENGTH = 50;
    constexpr size_t MAX_PHONE_LENGTH = 15;
    
    // Split-related constants
    constexpr double EPSILON = 0.0001;  // For floating-point comparisons
    constexpr double PERCENTAGE_TOTAL = 100.0;
    
    // Error messages (minimal for validation)
    const std::string ERR_INVALID_EMAIL = "Invalid email format";
    const std::string ERR_DUPLICATE_USER = "User already exists";
    const std::string ERR_INVALID_SPLIT = "Invalid split configuration";
}
