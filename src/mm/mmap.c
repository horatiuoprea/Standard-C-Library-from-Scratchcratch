// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <sys/mman.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd,
           off_t offset) {
    /* TODO: Implement mmap(). */
    void *rez;
    rez = (void *)syscall(9, addr, length, prot, flags, fd, offset);
    int long long int_rez;
    int_rez = (long long int)rez;
    if (int_rez >= 0) return rez;
    errno = -(int_rez);
    return MAP_FAILED;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags) {
    /* TODO: Implement mremap(). */
    void *rez;
    rez = (void *)syscall(25, old_address, old_size, new_size, flags);
    int long long int_rez;
    int_rez = (long long int)rez;
    if (int_rez >= 0) return rez;
    errno = -(int_rez);
    return MAP_FAILED;
}

int munmap(void *addr, size_t length) {
    /* TODO: Implement munmap(). */
    int rez;
    rez = syscall(11, addr, length);
    if (rez >= 0) return 0;
    errno = -rez;
    return -1;
}
