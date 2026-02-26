#include <iostream>
#include <stdexcept>
#include <logxxi/logger.hpp>

using namespace logxxi;

void divide(int a, int b) {
    try {
        if (b == 0) {
            throw std::runtime_error("Division by zero!");
        }
        int result = a / b;
        log.info << "Division result: " << std::to_string(result) << std::endl;
    } catch (const std::exception& e) {
        log.error << "Error during division: " << std::string(e.what()) << std::endl;
    }
}

int main() {
    // Setting the logging level to WARNING
    Logger::getInstance().setLevel(LogLevel::INFO);

    log.info << "Start" << std::endl;

    // Demonstration of error handling
    divide(10, 2);  // Successful
    divide(10, 0);  // Error

    log.info << "End" << std::endl;

    return 0;
}
