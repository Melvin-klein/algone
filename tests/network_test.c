#include "check.h"

#include "network_test.h"
#include "../src/algone.h"

START_TEST (test_create_network)
{
    ALG_Network* n = ALG_CreateNetwork(10, 2);
    ck_assert_int_eq(n->_nbLayers, 1);
    ck_assert_ptr_nonnull(n->_layers);
    ck_assert_ptr_nonnull(n->_lastLayer);
    ck_assert_ptr_eq(n->_lastLayer, n->_layers[n->_nbLayers - 1]);
    ck_assert_int_eq(n->_layers[0]->_nbUnits, 10);
    ALG_DestroyNetwork(n);
    ck_assert_int_eq(2, 2);
}
END_TEST

START_TEST (test_create_bare_network)
{
    ALG_Network* n = ALG_CreateBareNetwork(10);
    ck_assert_int_eq(n->_nbLayers, 1);
    ck_assert_ptr_nonnull(n->_layers);
    ck_assert_ptr_nonnull(n->_lastLayer);
    ck_assert_int_eq(n->_layers[0]->_nbUnits, 10);
    ALG_DestroyNetwork(n);
    ck_assert_int_eq(2, 2);
}
END_TEST

START_TEST (test_create_network_from_file)
{
    FILE *file = fopen("tests/factory/basic_network.alg", "r");
    ALG_Network* n = ALG_CreateNetworkFromFile(file);

    ck_assert_int_eq(n->_nbLayers, 3);
    ck_assert_int_eq(n->_nbMaxLayer, 3);
    ck_assert_ptr_nonnull(n->_layers);
    ck_assert_ptr_eq(n->_lastLayer, n->_layers[n->_nbLayers - 1]);

    ck_assert_double_eq(n->_layers[1]->_units[0]->_weights[0], 1.);
    ck_assert_double_eq(n->_layers[1]->_units[0]->_weights[1], 2.);
    ck_assert_double_eq(n->_layers[1]->_units[1]->_weights[0], 1.);
    ck_assert_double_eq(n->_layers[1]->_units[1]->_weights[1], 2.);

    ck_assert_double_eq(n->_layers[2]->_units[0]->_weights[0], 2.);
    ck_assert_double_eq(n->_layers[2]->_units[0]->_weights[1], 1.);
    ck_assert_double_eq(n->_layers[2]->_units[1]->_weights[0], 2.);
    ck_assert_double_eq(n->_layers[2]->_units[1]->_weights[1], 1.);

    ck_assert_int_eq(2, 2);

    ALG_DestroyNetwork(n);
    fclose(file);
}
END_TEST

START_TEST (test_fill_network_input)
{
    ALG_Vector *inputs = ALG_CreateVectorFromString("1 2 3");
    ALG_Network *n = ALG_CreateBareNetwork(3);

    ALG_FillNetworkInputs(n, inputs);

    ck_assert_double_eq(n->_layers[0]->_units[0]->output, 1.);
    ck_assert_double_eq(n->_layers[0]->_units[1]->output, 2.);
    ck_assert_double_eq(n->_layers[0]->_units[2]->output, 3.);

    ALG_DestroyVector(inputs);
}
END_TEST

START_TEST (test_forward)
{
    FILE *file = fopen("tests/factory/basic_network.alg", "r");
    ALG_Network* n = ALG_CreateNetworkFromFile(file);
    ALG_Vector *inputs = ALG_CreateVectorFromString("1 1");

    ALG_Forward(n, inputs);

    ck_assert_double_eq_tol(n->_lastLayer->_units[0]->output, 0.9457165, 0.0000001);
    ck_assert_double_eq_tol(n->_lastLayer->_units[1]->output, 0.9457165, 0.0000001);

    ALG_DestroyVector(inputs);
    ALG_DestroyNetwork(n);
    fclose(file);
}
END_TEST

START_TEST (test_forward_fail_inputs_not_compatible)
{
    FILE *file = fopen("tests/factory/basic_network.alg", "r");
    ALG_Network* n = ALG_CreateNetworkFromFile(file);
    ALG_Vector *inputs = ALG_CreateVectorFromString("1 1 1 1");

    ALG_Forward(n, inputs);

    ALG_Error *error = ALG_GetError();
    ck_assert_int_eq(error->code, ALG_INCOMPATIBLE_ERROR);

    ALG_DestroyNetwork(n);
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
    tcase_add_test(tc_core, test_create_bare_network);
    tcase_add_test(tc_core, test_create_network_from_file);
    tcase_add_test(tc_core, test_fill_network_input);
    tcase_add_test(tc_core, test_forward);
    tcase_add_test(tc_core, test_forward_fail_inputs_not_compatible);
    suite_add_tcase(s, tc_core);

    return s;
}
