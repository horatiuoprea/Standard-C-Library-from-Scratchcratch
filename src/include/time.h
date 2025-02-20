#ifndef	__STRING_H__
#define	__STRING_H__	1

#ifdef __cplusplus
extern "C" {
#endif

struct timespec
{
    /* data */
    long rqtp, rmtp;
};

int nanosleep(const struct timespec *t1, struct timespec *t2);

#ifdef __cplusplus
}
#endif

#endif
