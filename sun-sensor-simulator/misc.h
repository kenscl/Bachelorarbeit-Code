#include <cstdint>
#include <sys/time.h>
#ifndef __MISC
#define __MSIC
constexpr int64_t NANOSECONDS  = 1LL;
constexpr int64_t MICROSECONDS = (1000LL * NANOSECONDS);
constexpr int64_t MILLISECONDS = (1000LL * MICROSECONDS);
constexpr int64_t SECONDS      = (1000LL * MILLISECONDS);

inline int64_t NOW() {
    struct timeval t;
    gettimeofday(&t, 0);
    return (t.tv_sec * 1000000LL + t.tv_usec) * 1000;
}

#endif
