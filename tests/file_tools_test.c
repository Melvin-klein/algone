#include "stdio.h"
#include "check.h"

#include "file_tools_test.h"
#include "../src/algone.h"
#include "../src/error/error.h"

START_TEST (test_read_metadata)
{
    FILE *file = fopen("tests/factory/basic_network.alg", "r");

    if (file != NULL) {
        ALG_FileMetadata *meta = ALG_ReadMetadataFromFile(file);
        ck_assert_int_eq(meta->inputSize, 2);
        ck_assert_int_eq(meta->nbLayers, 2);
        ALG_DestroyFileMetadata(meta);
        fclose(file);
    } else {
        ALG_SetError(ALG_FILE_ERROR, "Can't open file : tests/factory/basic_network.alg", __FILE__, __LINE__);

        ALG_PrintError();
    }
}
END_TEST

Suite *file_tools_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("File tools");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_read_metadata);
    suite_add_tcase(s, tc_core);

    return s;
}
