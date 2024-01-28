#include <stdio.h>
#include "myrandom.h"
#include "coin.h"
#include "coin_di.h"

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

    struct coin_descriptor cd;
    
    //same example with dependency injection
    coin_di_init(&cd);

    if(coin_toss() == COINDI_TOSSRESULTS_HEADS)
    {
        printf("heads\n");
    }
    else
    {
        printf("tails\n");
    }
    return 0;
}