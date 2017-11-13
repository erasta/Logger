/*
 * Logger.h
 *
 *  Created on: Nov 9, 2017
 *      Author: eran
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include "print.h"
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */

class Logger {
public:
	Logger() {
		startLog = clock();
	}
	virtual ~Logger() {
		// TODO Auto-generated destructor stub
	}

	static Logger & the() {
		static Logger me;
		return me;
	}

	enum Severity {
		debugging, logging, warning, erroring, criticaling
	};

	template<typename ...Ts>
	void prn(Severity logSeverity, Ts ... args) const {
		if (logSeverity < severity)
			return;
		auto c = ((double)clock() - startLog) / CLOCKS_PER_SEC;
		print(c, args...);
	}

	template<typename ...Ts>
	static void debug(Ts ... args) {
		Logger::the().prn(Logger::debugging, "Debug", args...);
	}

	template<typename ...Ts>
	static void log(Ts ... args) {
		Logger::the().prn(Logger::logging, "Log", args...);
	}

	template<typename ...Ts>
	static void warn(Ts ... args) {
		Logger::the().prn(Logger::warning, "Warning", args...);
	}

	template<typename ...Ts>
	static void error(Ts ... args) {
		Logger::the().prn(Logger::erroring, "ERROR", args...);
	}

	template<typename ...Ts>
	static void critical(Ts ... args) {
		Logger::the().prn(Logger::criticaling, "CRITICAL", args...);
	}

	template<typename T>
	struct Scope {
		Scope(T _arg) : arg(_arg){
			Logger::log("Starting", arg);
			startScope = clock();
		}
		~Scope() {
			auto duration = ((double)clock() - startScope) / CLOCKS_PER_SEC;
			Logger::log("Exiting", arg, "took", duration, "seconds");
		}
		T arg;
		clock_t startScope;
	};

	template<typename T>
	static Scope<T> scope(T arg) {
		return Scope<T>(arg);
	}

	Severity severity = logging;
	clock_t startLog;
};

#define LOGPOS {Logger::the().prn(Logger::logging, "POS", __FILE__, __LINE__, __FUNCTION__);}


#endif /* LOGGER_H_ */
