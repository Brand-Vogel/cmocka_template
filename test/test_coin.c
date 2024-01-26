#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "myrandom.h"
#include "coin.h"

int __wrap_myrandom_generate()
{
    return mock_type(int);
}
 
static void test_coin_toss_returns_heads(void **state) 
{
    (void) state; /* unused */
    will_return(__wrap_myrandom_generate, 1);
    assert_int_equal(coin_toss(), COIN_TOSSRESULTS_HEADS);
}
static void test_coin_toss_returns_tails(void **state) 
{
    (void) state; /* unused */
    will_return(__wrap_myrandom_generate, 51);
    
    assert_int_equal(coin_toss(), COIN_TOSSRESULTS_TAILS);
}
 
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_coin_toss_returns_heads),
        cmocka_unit_test(test_coin_toss_returns_tails),
    };
 
    return cmocka_run_group_tests(tests, NULL, NULL);
}