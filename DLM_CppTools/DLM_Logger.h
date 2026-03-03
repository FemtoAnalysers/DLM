#ifndef DLM_LoggerH
#define DLM_LoggerH

#define LOG_LEVEL_FATAL 0
#define LOG_LEVEL_ERROR 10
#define LOG_LEVEL_WARN  20
#define LOG_LEVEL_INFO  30
#define LOG_LEVEL_DEBUG 40

// LOG_LEVEL can be specified at compile-time with cmake. For this you have to compile manually (not with quick_install)
// cd install/CMake
// cmake -DLOG_LEVEL=40 . && make -j16 && make install
#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_ERROR // By default, only show problems
#endif

#include <iostream>

#define LOG_LEVEL_STRING(level) \
    ((level) == LOG_LEVEL_ERROR ? "ERROR" : \
    (level) == LOG_LEVEL_FATAL  ? "FATAL" : \
    (level) == LOG_LEVEL_WARN  ? "WARNING" : \
    (level) == LOG_LEVEL_INFO  ? "INFO" : \
    (level) == LOG_LEVEL_DEBUG ? "DEBUG" : "UNKNOWN")

#define LOG(level, msg)                                              \
    do {                                                             \
        if (level <= LOG_LEVEL) {                                    \
            std::cerr << "[" << LOG_LEVEL_STRING(level) << "]"       \
                      << "[" << __func__ << ":" << __LINE__ << "] "  \
                      << msg << std::endl;                           \
            if (level == LOG_LEVEL_FATAL) {                       \
                throw std::runtime_error(msg);                   \
            }  \
        }                                                            \
    } while (0)

#endif
