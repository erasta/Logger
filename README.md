# Logger
Simple logger with severity filter and template variadic printing

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)

Example:
```cpp
#include "Logger.h"
void func() {
    auto scope = Logger::scope("func");
}
void main() {
    Logger::log("hello", "world", 1234);
    func();
    LOGPOS;
}
```
Output for example:
```
1e-06 Log hello world 1234
4.3e-05 Log Starting func
4.9e-05 Log Exiting func took 0 seconds
5.4e-05 POS ../src/example.cpp 18 main
```
