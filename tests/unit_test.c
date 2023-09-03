#include "check.h"

#include "unit_test.h"
#include "../src/algone.h"

START_TEST (test_create_unit)
{
    ALG_Unit* u = ALG_CreateUnit(10);
    ck_assert_int_eq(u->_nbWeights, 10);
    ck_assert_ptr_nonnull(u->_weights);
    ALG_DestroyUnit(u);
}
END_TEST

Suite *unit_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Unit");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_create_unit);
    suite_add_tcase(s, tc_core);

    return s;
}
