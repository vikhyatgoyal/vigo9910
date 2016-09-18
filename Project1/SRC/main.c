#include <stdio.h>
#include <stdint.h>
#include "memory.h"
#include "data.h"
#include "Project_1.h"
#include "Project_1 _settings.h"

int main()
{
#if(TEST_DATA == TEST_DATA_ON)

#endif

#if(PROJECT_1 == PROJECT_1_COMPILE_ON)
project_1_report();
#endif

#if(TEST_DATA == TEST_DATA_ON)
Project_1_DataCheck();
#endif

return 0;
}

