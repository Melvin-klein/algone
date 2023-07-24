#include "check.h"

#include "unit_test.h"

START_TEST (test_unit)
{
    ck_assert_int_eq(2, 2);
}
END_TEST

Suite *unit_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Unit");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_unit);
    suite_add_tcase(s, tc_core);

    return s;
}
