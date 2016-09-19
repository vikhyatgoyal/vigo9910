#include <stdio.h>
#include <stdint.h>
#include "memory.h"
#include "data.h"
#include "Project_1.h"
#include "Project_1 _settings.h"

int main()
{
 #if(TEST_DATA == TEST_DATA_ON)
 #ifdef TEST
  uint32_t DATAFunction2Test_u8; 
  uint32_t MEMFunction2Test_u8;
 #endif
 #endif

 #if(PROJECT_1_COMPILE == PROJECT_1_COMPILE_ON)
   #ifdef PROJECT_1
     project_1_report();
   #endif
 #endif

 #if(TEST_DATA == TEST_DATA_ON)
 #ifdef TEST
  printf("\nStarting check for data file \n");
  printf("Use below table to chose the function to be tested: \n");
  printf("| 0 = my_itoa        | \n");
  printf("| 1 = my_atoi        | \n");
  printf("| 2 = dump_memory    | \n");
  printf("| 3 = big_to_little  | \n");
  printf("| 4 = little_to_big  | \n");
  printf("Enter your choice \n");
  scanf("%d",&DATAFunction2Test_u8);
  Project_1_DataCheck(DATAFunction2Test_u8);

  printf("\nStarting check for memory file \n");
  printf("Use below table to chose the function to be tested: \n");
  printf("| 0 = my_memmove        | \n");
  printf("| 1 = my_memzero        | \n");
  printf("| 2 = my_reverse        | \n");
  printf("Enter your choice \n");
  scanf("%d",&MEMFunction2Test_u8);
  Project_1_MemoryCheck(MEMFunction2Test_u8);

 #endif
 #endif

 return (0);
}

