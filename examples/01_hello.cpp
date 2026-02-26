#include <iostream>
#include <logxxi/logger.hpp>

int main() {
    // Setting the logging level to DEBUG
    logxxi::Logger::getInstance().setLevel(logxxi::LogLevel::DEBUG);

    // Demonstrating all logging levels
    LOG_DEBUG("This is a DEBUG level message\n");
    LOG_INFO("This is a INFO level message\n");
    LOG_WARNING("This is a WARNING level message\n");
    LOG_ERROR("This is a ERROR level message\n");

    // Example of logging in a loop
    for(int i = 0; i < 3; ++i) {
        LOG_INFO("Loop iteration: " + std::to_string(i) + "\n");
    }

    return 0;
}