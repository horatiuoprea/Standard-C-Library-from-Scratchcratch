// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <unistd.h>

int close(int fd) {
    /* TODO: Implement close(). */
    int rez = syscall(3, fd);
    if (rez != -1) return 0;
    return -1;
}
