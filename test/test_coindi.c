#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "myrandom.h"
#include "coin_di.h"

int random_mock()
{
    return mock_type(int);
}

int random_stub()
{
    return 4;
}
 

static void test_coin_toss_with_DI_returns_heads(void **state) 
{
    (void) state; /* unused */
    struct coin_descriptor cd;
    cd.rand_func_ptr=random_mock;

    will_return(random_mock, 1);
    assert_int_equal(coin_di_toss(&cd), COINDI_TOSSRESULTS_HEADS);
}

static void test_coin_toss_with_DI_returns_tails(void **state) 
{
    (void) state; /* unused */
    struct coin_descriptor cd;
    cd.rand_func_ptr=random_mock;
    
    will_return(random_mock, 51);
    assert_int_equal(coin_di_toss(&cd), COINDI_TOSSRESULTS_TAILS);
}

static void test_coin_toss_with_DI_and_stub_returns_heads(void **state) 
{
    (void) state; /* unused */
    struct coin_descriptor cd;
    cd.rand_func_ptr=random_stub;

    assert_int_equal(coin_di_toss(&cd), COINDI_TOSSRESULTS_HEADS);
}
 
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_coin_toss_with_DI_returns_heads),
        cmocka_unit_test(test_coin_toss_with_DI_returns_tails),
        cmocka_unit_test(test_coin_toss_with_DI_and_stub_returns_heads),
    };
 
    return cmocka_run_group_tests(tests, NULL, NULL);
}