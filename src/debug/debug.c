#include "stdio.h"

#include "debug.h"

void ALG_DebugHeader(char title[])
{
    printf("========== DEBUG : %s ==========\n\n", title);
}

void ALG_DebugFooter()
{
    printf("\n========== END DEBUG =========\n");
}
