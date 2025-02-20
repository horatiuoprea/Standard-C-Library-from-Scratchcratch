#include <errno.h>
#include <internal/syscall.h>
#include <time.h>
#include <unistd.h>

extern int nanosleep();

unsigned int sleep(unsigned int seconds) {
    int rez;
    const struct timespec t1 = {seconds, 0};
    rez = nanosleep(&t1, NULL);
    if (rez >= 0) return rez;
    errno = -rez;
    return -1;
}
