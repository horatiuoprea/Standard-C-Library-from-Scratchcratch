#include <errno.h>
#include <internal/syscall.h>
#include <string.h>
#include <unistd.h>

int puts(const char* str) {
    ssize_t rez;
    rez = syscall(1, 1, str, strlen(str));
    rez = syscall(1, 1, "\n", 2);
    if (rez >= 0) return rez;
    errno = -rez;
    return -1;
}
