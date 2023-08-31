#include "check.h"

#include "network_test.h"

START_TEST (test_network)
{
    ck_assert_int_eq(2, 2);
}
END_TEST

Suite *network_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Network");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_network);
    suite_add_tcase(s, tc_core);

    return s;
}
