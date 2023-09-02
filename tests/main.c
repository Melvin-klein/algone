#include "stdlib.h"

#include "check.h"

#include "unit_test.h"
#include "network_test.h"
#include "layer_test.h"

int main(void)
{
    int num_failed;
    Suite *s_unit, *s_network, *s_layer;
    SRunner *sr;

    s_unit = unit_suite();
    s_network = network_suite();
    s_layer = layer_suite();
    sr = srunner_create(s_network);

    //srunner_add_suite(sr, s_unit);
    //srunner_add_suite(sr, s_layer);

    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return num_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
