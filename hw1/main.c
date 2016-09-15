#include <stdio.h>
#include <stdint.h>
#include "hw1.h"
#define MAX_LEN (100)


typedef long unsigned int ul;


int main()
{
char arr[MAX_LEN];
int arrlen,i=0,j=0;
char finalreslt;

printf("size of char  - %lu \n",(ul)sizeof(char));
printf("size of int   - %lu \n",(ul)sizeof(int));
printf("size of float - %lu \n",(ul)sizeof(float));
printf("size of double- %lu \n",(ul)sizeof(double));
printf("size of short - %lu \n",(ul)sizeof(short));
printf("size of long  - %lu \n",(ul)sizeof(long));
printf("size of long int - %lu \n",(ul)sizeof(long int));
printf("size of long long- %lu \n",(ul)sizeof(long long));
printf("size of int8_t   - %lu \n",(ul)sizeof(int8_t));
printf("size of uint8_t  - %lu \n",(ul)sizeof(uint8_t));
printf("size of uint16_t - %lu \n",(ul)sizeof(uint16_t));
printf("size of uint32_t - %lu \n",(ul)sizeof(uint32_t));
printf("size of char*    - %lu \n",(ul)sizeof(char *));
printf("size of int*     - %lu \n",(ul)sizeof(int*));
printf("size of float*   - %lu \n",(ul)sizeof(float *));
printf("size of void*    - %lu \n",(ul)sizeof(void*));
printf("size of int8_t*  - %lu \n",(ul)sizeof(int8_t *));
printf("size of int16_t* - %lu \n",(ul)sizeof(int16_t *));
printf("size of int32_t* - %lu \n",(ul)sizeof(int32_t *));
printf("size of char*    - %lu \n",(ul)sizeof(char *));
printf("size of int*     - %lu \n",(ul)sizeof(int *));
printf("size of float*   - %lu \n",(ul)sizeof(float *));
printf("size of void*    - %lu \n",(ul)sizeof(void*));
printf("size of int8_t*  - %lu \n",(ul)sizeof(int8_t *));
printf("size of int16_t* - %lu \n",(ul)sizeof(int16_t *));
printf("size of int32_t* - %lu \n",(ul)sizeof(int32_t *));
printf("size of char  - %lu \n",(ul)(sizeof(char)));
printf("size of int   - %lu \n",(ul)(sizeof(int)));
printf("size of float - %lu \n",(ul)(sizeof(float)));
printf("size of double- %lu \n",(ul)(sizeof(double)));
printf("size of short - %lu \n",(ul)(sizeof(short)));
printf("size of long  - %lu \n",(ul)(sizeof(long)));
printf("size of long int - %lu \n",(ul)(sizeof(long int)));
printf("size of long long- %lu \n",(ul)(sizeof(long long)));
printf("size of int8_t   - %lu \n",(ul)(sizeof(int8_t)));
printf("size of uint8_t  - %lu \n",(ul)(sizeof(uint8_t)));
printf("size of uint16_t - %lu \n",(ul)(sizeof(uint16_t)));
printf("size of uint32_t - %lu \n",(ul)(sizeof(uint32_t)));
printf("size of char*    - %lu \n",(ul)(sizeof(char *)));
printf("size of int*     - %lu \n",(ul)(sizeof(int *)));
printf("size of float*   - %lu \n",(ul)(sizeof(float *)));
printf("size of void*    - %lu \n",(ul)(sizeof(void*)));
printf("size of int8_t*  - %lu \n",(ul)(sizeof(int8_t *)));
printf("size of int16_t* - %lu \n",(ul)(sizeof(int16_t *)));
printf("size of int32_t* - %lu \n",(ul)(sizeof(int32_t *)));
printf("size of char*    - %lu \n",(ul)(sizeof(char *)));
printf("size of int*     - %lu \n",(ul)(sizeof(int *)));
printf("size of float*   - %lu \n",(ul)(sizeof(float *)));
printf("size of void*    - %lu \n",(ul)(sizeof(void*)));
printf("size of int8_t*  - %lu \n",(ul)(sizeof(int8_t *)));
printf("size of int16_t* - %lu \n",(ul)(sizeof(int16_t *)));
printf("size of int32_t* - %lu \n",(ul)(sizeof(int32_t *)));

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

return 0;
}

