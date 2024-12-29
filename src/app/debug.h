#pragma once

#include <stdio.h>

static inline void debug_print(const char * sFormat, ...)
{
#if DEBUG
    va_list ParamList;

    va_start(ParamList, sFormat);

    (void)printf("%s:%d:%s(): ", __FILE__, __LINE__, __func__);
    (void)vprintf(sFormat, ParamList);

    va_end(ParamList);
#else
    (void)sFormat;
#endif
    return;
}
