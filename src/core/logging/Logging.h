//
// Created by deril on 9/9/24.
//

#ifndef LOGGING_H
#define LOGGING_H
#include <cstdio>
#define LOGGING_ENABLED

#ifdef LOGGING_ENABLED
#define LOG_ERROR(...) printf(__VA_ARGS__);
#define LOG_INFO(...) printf(__VA_ARGS__);
#else

#endif

#endif //LOGGING_H
