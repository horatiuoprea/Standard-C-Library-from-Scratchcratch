// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source) {
    /* TODO: Implement strcpy(). */
    char *q = destination;
    const char *p = source;
    while (*p != '\0') {
        *q = *p;
        q++;
        p++;
    }
    *q = *p;
    return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
    /* TODO: Implement strncpy(). */
    unsigned long i;
    for (i = 0; i < len; i++) {
        if (source[i] != '\0') {
            destination[i] = source[i];
        } else {
            destination[i] = '\0';
        }
    }
    return destination;
}

char *strcat(char *destination, const char *source) {
    /* TODO: Implement strcat(). */
    char *p = destination;
    const char *q = source;
    while (*p != '\0') p++;
    while (*q != '\0') {
        *p = *q;
        p++;
        q++;
    }
    *p = *q;
    return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
    /* TODO: Implement strncat(). */
    unsigned long i, nr = 0;
    char *p = destination;
    const char *q = source;
    while (*q != '\0') {
        nr++;
        q++;
    }
    q = source;
    if (nr <= len) {
        destination = strcat(destination, source);
    } else {
        while (*p != '\0') p++;
        for (i = 0; i < len; i++) {
            *p = *q;
            p++;
            q++;
        }
        *p = '\0';
    }
    return destination;
}

int strcmp(const char *str1, const char *str2) {
    /* TODO: Implement strcmp(). */
    const char *p = str1, *q = str2;
    while (*p != '\0' && *q != '\0') {
        if (*p > *q) return 1;
        if (*p < *q) return -1;
        p++;
        q++;
    }
    if (*p == '\0' && *q != '\0') return -1;
    if (*p != '\0' && *q == '\0') return 1;
    return 0;
}

int strncmp(const char *str1, const char *str2, size_t len) {
    /* TODO: Implement strncmp(). */
    const char *p = str1, *q = str2;
    unsigned long i = 0;
    while (*p != '\0' && *q != '\0' && i < len) {
        if (*p > *q) return 1;
        if (*p < *q) return -1;
        p++;
        q++;
        i++;
    }
    if (i == len) return 0;
    if (*p == '\0' && *q != '\0') return -1;
    if (*p != '\0' && *q == '\0') return 1;
    return 0;
}

size_t strlen(const char *str) {
    size_t i = 0;

    for (; *str != '\0'; str++, i++) {}

    return i;
}

char *strchr(const char *str, int c) {
    /* TODO: Implement strchr(). */
    const char *p = str;
    while (*p != '\0') {
        if (*p == c) return (char *)p;
        p++;
    }
    return NULL;
}

char *strrchr(const char *str, int c) {
    /* TODO: Implement strrchr(). */
    unsigned long i;
    const char *p = str;
    p = p + strlen(str) - 1;
    for (i = 0; i < strlen(str); i++) {
        if (*p == c) return (char *)p;
        p--;
    }
    return NULL;
}

char *strstr(const char *haystack, const char *needle) {
    /* TODO: Implement strstr(). */
    if (needle == NULL) return (char *)haystack;
    const char *p = haystack, *q = needle;
    while (*(p + strlen(q) - 1) != '\0') {
        if (strncmp(p, q, strlen(q)) == 0) return (char *)p;
        p++;
    }
    return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
    /* TODO: Implement strrstr(). */
    const char *p = haystack, *q = needle, *last = NULL;
    while (1) {
        p = strstr(p, q);
        if (p)
            last = p;
        else
            return (char *)last;
        p++;
    }
}

void *memcpy(void *destination, const void *source, size_t num) {
    /* TODO: Implement memcpy(). */
    strncpy(destination, source, num);
    return destination;
}

void *memmove(void *destination, const void *source, size_t num) {
    /* TODO: Implement memmove(). */
    strncpy(destination, source, num);
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
    /* TODO: Implement memcmp(). */
    return strncmp(ptr1, ptr2, num);
}

void *memset(void *source, int value, size_t num) {
    /* TODO: Implement memset(). */
    unsigned long i;
    char *p = source;
    for (i = 0; i < num; i++) {
        *p = value;
        p++;
    }
    return source;
}
