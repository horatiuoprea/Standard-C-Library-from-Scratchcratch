// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>

int open(const char *filename, int flags, ...) {
    /* TODO: Implement open system call. */
    int rez;
    rez = syscall(2, filename, flags);
    if (rez >= 0) return rez;
    errno = -rez;
    return -1;
}
