#include <stdlib.h>
#include <time.h>

#include "coin_di.h"
#include "myrandom.h"

void coin_di_init(struct coin_descriptor *obj)
{
    obj->rand_func_ptr = myrandom_generate;
}
enum toss_results_t coin_di_toss(struct coin_descriptor *obj)
{
    if(obj->rand_func_ptr() % 100 < 50)
    {
        return COINDI_TOSSRESULTS_HEADS;
    }
    else
    {
        return COINDI_TOSSRESULTS_TAILS;
    }
}