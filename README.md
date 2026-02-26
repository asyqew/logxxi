# Logxxi

**Logxxi** is a lightweight, header-only C++ logging library with a simple API and stream-style logging support.
It provides multiple log levels, timestamped output, and optional ANSI-colored level tags.

* Header-only
* C++17 compatible
* Stream-style and macro-based logging
* Minimal dependencies (standard library only)

## Features

* Log levels: `DEBUG`, `INFO`, `WARNING`, `ERROR`
* ISO-like timestamp format: `YYYY-MM-DDTHH:MM:SS`
* ANSI color support for selected levels (terminal-dependent)
* Singleton-based logger
* Stream-style API (`log.info << ...`)
* Macro-based API (`LOG_INFO(...)`)
* CMake integration via `INTERFACE` target

## Requirements

* C++17 or newer
* CMake 3.14+ (for building examples or installing)

## Installation

### Option 1 — As a Subdirectory (Recommended)

```cmake
add_subdirectory(logxxi)
target_link_libraries(your_target PRIVATE logxxi)
```

### Option 2 — Install and Use via CMake

```bash
cmake -S . -B build
cmake --build build
cmake --install build
```

Then in your project:

```cmake
find_package(logxxi REQUIRED)
target_link_libraries(your_target PRIVATE logxxi::logxxi)
```

## Basic Usage

Include the header:

```cpp
#include <logxxi/logger.hpp>
```

### Macro-based Logging

```cpp
logxxi::Logger::getInstance().setLevel(logxxi::LogLevel::DEBUG);

LOG_DEBUG("Debug message\n");
LOG_INFO("Info message\n");
LOG_WARNING("Warning message\n");
LOG_ERROR("Error message\n");
```

### Stream-style Logging

```cpp
using namespace logxxi;

Logger::getInstance().setLevel(LogLevel::INFO);

log.info << "Application started" << std::endl;
log.error << "Something went wrong" << std::endl;
```

## Log Levels

| Level   | Description                     |
| ------- | ------------------------------- |
| DEBUG   | Detailed diagnostic information |
| INFO    | General runtime information     |
| WARNING | Non-critical issues             |
| ERROR   | Serious errors                  |

Messages below the currently set level are ignored.

## Example Output

```
[2026-02-25T18:42:31] [INF] Application started
[2026-02-25T18:42:31] [ERR] Something went wrong
```

(Some levels may include ANSI color codes in supported terminals.)

## Project Structure

```
include/
  loggerxxi/
    logger.hpp

examples/
  01_hello.cpp
  02_advanced.cpp

CMakeLists.txt
```

## Design Notes

* Implemented as a singleton (`Logger::getInstance()`).
* `LogStream` buffers output and flushes on destruction (RAII-based).
* Macros perform level checks before invoking logging logic.
* Thread safety is not guaranteed.
