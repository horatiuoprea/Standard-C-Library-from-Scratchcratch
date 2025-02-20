// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <unistd.h>

int truncate(const char *path, off_t length) {
    /* TODO: Implement truncate(). */
    int rez;
    rez = syscall(76, path, length);
    if (rez >= 0) return rez;
    errno = -rez;
    return -1;
}
