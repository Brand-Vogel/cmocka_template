enum toss_results_t {COINDI_TOSSRESULTS_HEADS, COINDI_TOSSRESULTS_TAILS};

struct coin_descriptor
{
    //pointer to the function that will generate the random number
    //we intend to use int myrandom_generate();
    int (*rand_func_ptr)(void);
};

void coin_di_init(struct coin_descriptor *obj);
enum toss_results_t coin_di_toss(struct coin_descriptor *obj);
