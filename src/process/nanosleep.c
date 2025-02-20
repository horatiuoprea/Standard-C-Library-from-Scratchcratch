#include <errno.h>
#include <internal/syscall.h>
#include <time.h>
#include <unistd.h>

int nanosleep(const struct timespec *t1, struct timespec *t2) {
    int rez;
    rez = syscall(35, t1, t2);
    if (rez >= 0) return rez;
    errno = -rez;
    return -1;
}
