#include "stdlib.h"

#include "check.h"

#include "unit_test.h"

int main(void)
{
    int num_failed;
    Suite *s;
    SRunner *sr;

    s = unit_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return num_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
