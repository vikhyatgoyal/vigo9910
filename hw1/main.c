#include <stdio.h>
#include <stdint.h>
<<<<<<< 4b217490ca2e4abc07ba7e9fd6ef4300402eb486
=======
#include "hw1.h"
#define MAX_LEN (100)
>>>>>>> Reverse string finction added to teh main .c file



int main()
{
<<<<<<< 4b217490ca2e4abc07ba7e9fd6ef4300402eb486
char *ptrchar;
int *ptrint;
float *ptrfloat;
int8_t *ptr8si;
int16_t *ptr16si;
int32_t *ptr32si;
=======
 char arr[MAX_LEN];
 int arrlen,i=0,j=0;
 char finalreslt;


>>>>>>> Reverse string finction added to teh main .c file
printf("size of char  - %lu \n",sizeof(char));
printf("size of int   - %lu \n",sizeof(int));
printf("size of float - %lu \n",sizeof(float));
printf("size of double- %lu \n",sizeof(double));
printf("size of short - %lu \n",sizeof(short));
printf("size of long  - %lu \n",sizeof(long));
printf("size of long int - %lu \n",sizeof(long int));
printf("size of long long- %lu \n",sizeof(long long));
printf("size of int8_t   - %lu \n",sizeof(int8_t));
printf("size of uint8_t  - %lu \n",sizeof(uint8_t));
printf("size of uint16_t - %lu \n",sizeof(uint16_t));
printf("size of uint32_t - %lu \n",sizeof(uint32_t));
<<<<<<< 4b217490ca2e4abc07ba7e9fd6ef4300402eb486
printf("size of char*    - %lu \n",sizeof(ptrchar));
printf("size of int*     - %lu \n",sizeof(ptrint));
printf("size of float*   - %lu \n",sizeof(ptrfloat));
printf("size of void*    - %lu \n",sizeof(void*));
printf("size of int8_t*  - %lu \n",sizeof(ptr8si));
printf("size of int16_t* - %lu \n",sizeof(ptr16si));
printf("size of int32_t* - %lu \n",sizeof(ptr32si));
=======
printf("size of char*    - %lu \n",sizeof(char *));
printf("size of int*     - %lu \n",sizeof(int *));
printf("size of float*   - %lu \n",sizeof(float *));
printf("size of void*    - %lu \n",sizeof(void*));
printf("size of int8_t*  - %lu \n",sizeof(int8_t *));
printf("size of int16_t* - %lu \n",sizeof(int16_t *));
printf("size of int32_t* - %lu \n",sizeof(int32_t *));

 printf("Please enter the array \n");
 scanf("%99[^\n]s",arr);

 arrlen = stringlen(arr);

 finalreslt = reverse(arr,arrlen);

 if(!finalreslt)
   {
    printf("the string in reverse is: \n");
    printf("%s \n",arr);
   }
 else
   {
   printf("invalid string");
   }

>>>>>>> Reverse string finction added to teh main .c file
return 0;
}

