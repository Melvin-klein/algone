#include "check.h"
#include "vector_test.h"
#include "../src/algone.h"
#include "../src/error/error.h"

START_TEST (test_create_vector)
{
    ALG_Vector *v = ALG_CreateVector(4);
    ck_assert_ptr_nonnull(v);
    ck_assert_int_eq(v->size, 4);
    ck_assert_ptr_nonnull(v->values);
    ALG_DestroyVector(v);
}
END_TEST

START_TEST (test_create_vector_from_string)
{
    ALG_Vector *v = ALG_CreateVectorFromString("12 13.23 3. 72.1");
    ck_assert_int_eq(v->size, 4);
    ck_assert_double_eq(ALG_GetVectorValueAt(v, 0), 12.);
    ck_assert_double_eq(ALG_GetVectorValueAt(v, 1), 13.23);
    ck_assert_double_eq(ALG_GetVectorValueAt(v, 2), 3.);
    ck_assert_double_eq(ALG_GetVectorValueAt(v, 3), 72.1);
    ALG_DestroyVector(v);
}
END_TEST

START_TEST (test_create_vector_from_file)
{
    FILE *file = fopen("tests/factory/basic_network.alg", "r");

    if (file != NULL) {
        ALG_ReadMetadataFromFile(file);
        ALG_Vector *v = ALG_CreateVectorFromFile(file);
        ck_assert_int_eq(v->size, 4);
        ck_assert_double_eq(ALG_GetVectorValueAt(v, 0), 1.);
        ck_assert_double_eq(ALG_GetVectorValueAt(v, 1), 2.);
        ck_assert_double_eq(ALG_GetVectorValueAt(v, 2), 1.);
        ck_assert_double_eq(ALG_GetVectorValueAt(v, 3), 2.);
        ALG_DestroyVector(v);
        fclose(file);
    } else {
        ALG_SetError(ALG_FILE_ERROR, "Can't open file : tests/factory/basic_network.alg", __FILE__, __LINE__);

        ALG_PrintError();
    }
}
END_TEST

START_TEST (test_fill_vector)
{
    ALG_Vector *v = ALG_CreateVector(4);
    ALG_FillVector(v, 3);
    for (int i = 0; i < 4; i++) {
        ck_assert_double_eq(ALG_GetVectorValueAt(v, i), 3.);
    }
    ALG_DestroyVector(v);
}
END_TEST

START_TEST (test_get_value_at)
{
    ALG_Vector *v = ALG_CreateVectorFromString("12 13.23 3. 72.1");
    ck_assert_double_eq(ALG_GetVectorValueAt(v, 3), 72.1);
    ALG_DestroyVector(v);
}
END_TEST

START_TEST (test_set_value_at)
{
    ALG_Vector *v = ALG_CreateVectorFromString("12 13.23 3. 72.1");
    ALG_SetVectorValueAt(v, 0, 1);
    ALG_SetVectorValueAt(v, 1, 2);
    ALG_SetVectorValueAt(v, 2, 3);
    ALG_SetVectorValueAt(v, 3, 4);
    ck_assert_double_eq(ALG_GetVectorValueAt(v, 0), 1.);
    ck_assert_double_eq(ALG_GetVectorValueAt(v, 1), 2.);
    ck_assert_double_eq(ALG_GetVectorValueAt(v, 2), 3.);
    ck_assert_double_eq(ALG_GetVectorValueAt(v, 3), 4.);
    ALG_DestroyVector(v);
}
END_TEST

Suite *vector_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Vector");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_create_vector_from_string);
    tcase_add_test(tc_core, test_create_vector_from_file);
    tcase_add_test(tc_core, test_create_vector);
    tcase_add_test(tc_core, test_fill_vector);
    tcase_add_test(tc_core, test_get_value_at);
    tcase_add_test(tc_core, test_set_value_at);
    suite_add_tcase(s, tc_core);

    return s;
}
