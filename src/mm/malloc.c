// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/essentials.h>
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

void *malloc(size_t size) {
    /* TODO: Implement malloc(). */
    void *rez;
    rez = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE,
               -1, 0);
    int *int_rez;
    int_rez = (int *)rez;
    if (*int_rez >= 0) return rez;
    errno = -(*int_rez);
    return NULL;
}

void *calloc(size_t nmemb, size_t size) {
    /* TODO: Implement calloc(). */
    void *rez;
    rez = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE,
               MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    rez = memset(rez, 0, nmemb * size);
    int *int_rez;
    int_rez = (int *)rez;
    if (*int_rez >= 0) return rez;
    errno = -(*int_rez);
    return NULL;
}

void free(void *ptr) {
    /* TODO: Implement free(). */
    struct mem_list *iter;
    iter = mem_list_find(ptr);
    munmap(ptr, iter->len);
}

void *realloc(void *ptr, size_t size) {
    /* TODO: Implement realloc(). */
    void *rez;
    rez = mmap(ptr, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE,
               -1, 0);
    int *int_rez;
    int_rez = (int *)rez;
    if (*int_rez >= 0) return rez;
    errno = -(*int_rez);
    return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
    /* TODO: Implement reallocarray(). */
    void *rez;
    rez = mmap(ptr, nmemb * size, PROT_READ | PROT_WRITE,
               MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    int *int_rez;
    int_rez = (int *)rez;
    if (*int_rez >= 0) return rez;
    errno = -(*int_rez);
    return NULL;
}
