#pragma once
#include <stdio.h>
#define _ASSERT_(cond)                                \
    if (!(cond))                                      \
    {                                                 \
        printf("assertion error line %d, file(%s)\n", \
               __LINE__, __FILE__);                   \
        exit(EXIT_FAILURE);                           \
    }
