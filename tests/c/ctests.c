#include "CuTest.h"
#include <stdio.h>

CuSuite* get_default_suite();
CuSuite* get_free_suite();

int main()
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();
    
    CuSuiteAddSuite(suite, get_default_suite());
    CuSuiteAddSuite(suite, get_free_suite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);

    CuStringDelete(output);
    CuSuiteDelete(suite);
    
    return 0;
}
