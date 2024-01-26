#include <stdio.h>
#include "myrandom.h"
#include "coin.h"

int main()
{
    if(coin_toss() == COIN_TOSSRESULTS_HEADS)
    {
        printf("heads\n");
    }
    else
    {
        printf("tails\n");
    }
    return 0;
}