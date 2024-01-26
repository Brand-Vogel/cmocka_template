#include "coin.h"
#include "myrandom.h"

enum TOSS_RESULTS coin_toss()
{
    if(myrandom_generate() % 100 < 50)
    {
        return COIN_TOSSRESULTS_HEADS;
    }
    else
    {
        return COIN_TOSSRESULTS_TAILS;
    }
}