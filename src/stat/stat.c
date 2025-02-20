// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <fcntl.h>
#include <internal/syscall.h>
#include <sys/stat.h>

int stat(const char *restrict path, struct stat *restrict buf) {
    /* TODO: Implement stat(). */
    int rez;
    rez = syscall(4, path, buf);
    if (rez >= 0) return rez;
    errno = -rez;
    return -1;
}
