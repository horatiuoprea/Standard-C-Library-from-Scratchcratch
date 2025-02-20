// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/essentials.h>
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#define ALLOC_SIZE (4 * 1024 * 1024)
#define INFINITE 1000000

extern int sleep();

int main(void) {
    void *p;

    sleep(2);

    p = mmap(NULL, ALLOC_SIZE, PROT_READ | PROT_WRITE,
             MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (p == MAP_FAILED) exit(EXIT_FAILURE);

    munmap(p, ALLOC_SIZE);

    sleep(INFINITE);

    return 0;
}
