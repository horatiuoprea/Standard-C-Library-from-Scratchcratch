// SPDX-License-Identifier: BSD-3-Clause

#include <stddef.h>
#include <time.h>

// extern int nanosleep();

int main(void) {
    struct timespec wait = {10, 0};

    nanosleep(&wait, NULL);

    return 0;
}
