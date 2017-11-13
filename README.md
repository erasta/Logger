# Logger
Simple logger with severity filter and template variadic printing

Example:
```cpp
#include "Logger.h"

void func() {
	auto scope = Logger::scope("func");
}

int main() {
	Logger::log("hello", "world", 1234);
	func();
	LOGPOS;
	return 0;
}
```

Output for example.cpp:
```
1e-06 Log hello world 1234
4.3e-05 Log Starting func
4.9e-05 Log Exiting func took 0 seconds
5.4e-05 POS ../src/example.cpp 18 main
```
