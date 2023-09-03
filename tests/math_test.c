#include "check.h"

#include "math_test.h"
#include "../src/algone.h"

START_TEST (test_create_matrix)
{
    ALG_Matrix* m = ALG_MatrixCreate(4, 4, 8);
    ck_assert_ptr_nonnull(m);

    for (int i = 0; i < m->_size[0]; i++) {
        for (int j = 0; j < m->_size[1]; j++) {
            ck_assert_double_eq(m->values[i][j], 8);
        }
    }

    ALG_MatrixDestroy(m);
}
END_TEST

START_TEST (test_sigmoid)
{
    double x[] = { -10, -1.5, 0 , 1.5, 10};
    double y[] = { 0.000045, 0.182426, 0.500000, 0.817574, 0.999955};

    for (int i = 0; i < 5; i++) {
        ck_assert_double_eq_tol(ALG_Sigmoid(x[i], 1), y[i], 0.000001);
    }
}
END_TEST

START_TEST (test_MSE)
{
    double yTrue[5] = {3.43, 2.67, 0.47, -1.34, -0.21};
    double yPred[5] = {2, 5, -2, 3, 0};

    ck_assert_double_eq_tol(ALG_MeanSquaredError(yPred, yTrue, 5), 6.490880, 0.000001);
}
END_TEST

Suite *math_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Math");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_create_matrix);
    tcase_add_test(tc_core, test_sigmoid);
    tcase_add_test(tc_core, test_MSE);
    suite_add_tcase(s, tc_core);

    return s;
}