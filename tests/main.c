#include "stdlib.h"

#include "check.h"

#include "unit_test.h"
#include "network_test.h"
#include "layer_test.h"
#include "math_test.h"
#include "vector_test.h"
#include "file_tools_test.h"

int main(void)
{
    int num_failed;
    Suite *s_unit, *s_network, *s_layer, *s_math, *s_vec, *s_file_tools;
    SRunner *sr;

    s_unit = unit_suite();
    s_network = network_suite();
    s_layer = layer_suite();
    s_math = math_suite();
    s_vec = vector_suite();
    s_file_tools = file_tools_suite();
    sr = srunner_create(s_network);

    srunner_add_suite(sr, s_unit);
    srunner_add_suite(sr, s_layer);
    srunner_add_suite(sr, s_math);
    srunner_add_suite(sr, s_vec);
    srunner_add_suite(sr, s_file_tools);

    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return num_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
