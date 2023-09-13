#include "check.h"

#include "layer_test.h"
#include "../src/algone.h"

START_TEST (test_create_layer_in_network)
{
    // TODO: implement
}
END_TEST

START_TEST (test_create_layer_from_vector)
{
    ALG_Vector *v = ALG_CreateVectorFromString("1 2 3 4 5 6");
    ALG_Layer *l = ALG_CreateLayerFromVector(v, 3);
    ck_assert_int_eq(l->_nbUnits, 3);
    ck_assert_double_eq(l->_units[0]->_weights[0], 1.);
    ck_assert_double_eq(l->_units[0]->_weights[1], 2.);
    ck_assert_double_eq(l->_units[1]->_weights[0], 3.);
    ck_assert_double_eq(l->_units[1]->_weights[1], 4.);
    ck_assert_double_eq(l->_units[2]->_weights[0], 5.);
    ck_assert_double_eq(l->_units[2]->_weights[1], 6.);
    ALG_DestroyLayer(l);
    ALG_DestroyVector(v);
}
END_TEST

START_TEST (test_append_layer_to_network)
{
    ALG_Vector *v = ALG_CreateVectorFromString("1 2 3 4 5 6");
    ALG_Layer *l = ALG_CreateLayerFromVector(v, 3);
    ALG_Network *n = ALG_CreateBareNetwork(2);
    ALG_AppendLayerToNetwork(l, n);
    ck_assert_int_eq(n->_nbLayers, 2);
    ck_assert_int_eq(n->_nbMaxLayer, 2);
    ck_assert_int_eq(n->_nbLayers, 2);

    ck_assert_int_eq(l->_nbUnits, 3);
    ck_assert_double_eq(l->_units[0]->_weights[0], 1.);
    ck_assert_double_eq(l->_units[0]->_weights[1], 2.);
    ck_assert_double_eq(l->_units[1]->_weights[0], 3.);
    ck_assert_double_eq(l->_units[1]->_weights[1], 4.);
    ck_assert_double_eq(l->_units[2]->_weights[0], 5.);
    ck_assert_double_eq(l->_units[2]->_weights[1], 6.);
    ALG_DestroyLayer(l);
    ALG_DestroyVector(v);
}
END_TEST

START_TEST (test_append_layer_to_network_fail_network_and_layer_not_compatible)
{
    ALG_Vector *v = ALG_CreateVectorFromString("1 2 3 4 5 6");
    ALG_Layer *l = ALG_CreateLayerFromVector(v, 2);
    ALG_Network *n = ALG_CreateBareNetwork(2);
    ALG_AppendLayerToNetwork(l, n);
    ALG_Error *error = ALG_GetError();
    ck_assert_int_eq(error->code, ALG_INCOMPATIBLE_ERROR);
    ALG_DestroyLayer(l);
    ALG_DestroyVector(v);
}
END_TEST

START_TEST (test_create_layer_from_vector_in_network)
{
    ALG_Vector *v = ALG_CreateVectorFromString("1 2 3 4 5 6");
    ALG_Network *n = ALG_CreateBareNetwork(2);
    ALG_CreateLayerFromVectorInNetwork(n, v);
    ck_assert_int_eq(n->_nbLayers, 2);

    ck_assert_int_eq(n->_layers[n->_nbLayers - 1]->_nbUnits, 3);
    ck_assert_double_eq(n->_layers[n->_nbLayers - 1]->_units[0]->_weights[0], 1.);
    ck_assert_double_eq(n->_layers[n->_nbLayers - 1]->_units[0]->_weights[1], 2.);
    ck_assert_double_eq(n->_layers[n->_nbLayers - 1]->_units[1]->_weights[0], 3.);
    ck_assert_double_eq(n->_layers[n->_nbLayers - 1]->_units[1]->_weights[1], 4.);
    ck_assert_double_eq(n->_layers[n->_nbLayers - 1]->_units[2]->_weights[0], 5.);
    ck_assert_double_eq(n->_layers[n->_nbLayers - 1]->_units[2]->_weights[1], 6.);
    ALG_DestroyNetwork(n);
    ALG_DestroyVector(v);
}
END_TEST

Suite *layer_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Layer");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_create_layer_in_network);
    tcase_add_test(tc_core, test_create_layer_from_vector);
    tcase_add_test(tc_core, test_append_layer_to_network);
    tcase_add_test(tc_core, test_append_layer_to_network_fail_network_and_layer_not_compatible);
    tcase_add_test(tc_core, test_create_layer_from_vector_in_network);
    suite_add_tcase(s, tc_core);

    return s;
}
