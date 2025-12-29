#ifndef MEOW_DBG_H
#define MEOW_DBG_H

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
#define DEBUG(M, ...)
#else
#define DEBUG(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", \
        __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define CLEAN_ERRNO() (errno == 0 ? "None" : strerror(errno))

#define LOG_ERR(M, ...) fprintf(stderr, \
        "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, \
        CLEAN_ERRNO(), ##__VA_ARGS__)

#define LOG_WARN(M, ...) fprintf(stderr, \
        "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, \
        CLEAN_ERRNO(), ##__VA_ARGS__)

#define LOG_INFO(M, ...) fprintf(stderr, \
        "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define CHECK(A, M, R,...) if (!(A))\
{\
    LOG_ERR(M, ##__VA_ARGS__);\
    errno = 0;\
    return R;\
}

#define SENTINEL(M, R, ...)\
{\
    LOG_ERR(M, ##__VA_ARGS__);\
    errno = 0;\
    return R;\
}

#define CHECK_MEM(A, R) CHECK((A), "Out of memory.", R)

#define CHECK_DEBUG(A, M, R,...) if(!(A))\
{\
    DEBUG(M, ##__VA_ARGS__);\
    errno = 0;\
    return R;\
}

/* ifndef MEOW_DBG_H */
#endif
