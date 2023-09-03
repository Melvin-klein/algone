#include "check.h"

#include "layer_test.h"
#include "../src/algone.h"

START_TEST (test_create_layer)
{
    ALG_Layer* l = ALG_CreateLayer(10, NULL);
    ck_assert_int_eq(l->_nbUnits, 10);
    ck_assert_ptr_nonnull(l->_units);
    ALG_DestroyLayer(l);
}
END_TEST

Suite *layer_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Layer");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_create_layer);
    suite_add_tcase(s, tc_core);

    return s;
}
