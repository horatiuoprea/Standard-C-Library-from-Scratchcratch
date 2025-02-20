// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <sys/stat.h>

int fstat(int fd, struct stat *st) {
    /* TODO: Implement fstat(). */
    int rez;
    rez = syscall(5, fd, st);
    if (rez >= 0) return rez;
    errno = -rez;
    return -1;
}
