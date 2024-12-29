/****** Required by Picolibc ********/

#include <stdio.h>
#include <errno.h>

_Noreturn void _exit (int status)
{
    (void)status;

    while(1);
}

static int _putc(char c, FILE *file)
{
    int status = 1;

    (void)file;
    (void)c;

    if (!status)
    {
        errno = EIO;
        status = -1;
    }

    return status;
}

static int _getc(FILE *file)
{
    int c = 0;

    (void)file;

    return c;
}

static int _flush(FILE *file)
{
    (void)file;
    
    return 0;
}

static FILE __stdio = {
    .flags = __SRD | __SWR,
    .flush = _flush,
    .get = _getc,
    .put = _putc
};

FILE * const __attribute__((used)) stdin  = &__stdio;
FILE * const __attribute__((used)) stdout = &__stdio;
FILE * const __attribute__((used)) stderr = &__stdio;
