#include "check.h"

#include "network_test.h"
#include "../src/algone.h"

START_TEST (test_create_network)
{
    ALG_Network* n = ALG_NetworkCreate(10);
    ck_assert_int_eq(n->_size, 1);
    ck_assert_ptr_nonnull(n->_layers);
    ck_assert_int_eq(n->_layers[0]->_size, 10);
    ALG_NetworkDestroy(n);
    ck_assert_int_eq(2, 2);
}
END_TEST

START_TEST (test_add_layer)
{
    ALG_Network* n = ALG_NetworkCreate(10);
    ck_assert_int_eq(n->_size, 1);
    ALG_NetworkAddLayer(n, 20);
    ck_assert_int_eq(n->_size, 2);
    ck_assert_ptr_nonnull(n->_layers);
    ck_assert_int_eq(n->_layers[0]->_size, 10);
    ck_assert_int_eq(n->_layers[1]->_size, 20);
    ALG_NetworkDestroy(n);
}
END_TEST

Suite *network_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Network");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_create_network);
    tcase_add_test(tc_core, test_add_layer);
    suite_add_tcase(s, tc_core);

    return s;
}
