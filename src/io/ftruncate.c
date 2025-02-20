// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <unistd.h>

int ftruncate(int fd, off_t length) {
    /* TODO: Implement ftruncate(). */
    int rez;
    rez = syscall(77, fd, length);
    if (rez >= 0) return rez;
    errno = -rez;
    return -1;
}
