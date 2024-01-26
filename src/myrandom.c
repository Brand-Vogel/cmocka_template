#include <stdlib.h>
#include "myrandom.h"
#include "time.h"

int myrandom_generate()
{
    time_t t;
    srand(time(&t));
    return rand();
}