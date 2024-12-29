#include <stdlib.h>
#include "init.h"
#include "debug.h"

int main(void)
{
    init_device();

    debug_print("Hello, World!\n");

    while(1);

    return 0;
}
