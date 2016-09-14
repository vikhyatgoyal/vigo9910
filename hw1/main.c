#include <stdio.h>
#include <stdint.h>
#include "hw1.h"
#define MAX_LEN (100)
<<<<<<< 170eb6eab53a327329d2a972cdafb957ca2705c3

=======
>>>>>>> Added cross compiler support .

typedef long unsigned int ul;

int main()
{

<<<<<<< 170eb6eab53a327329d2a972cdafb957ca2705c3
char *ptrchar;
int *ptrint;
float *ptrfloat;
int8_t *ptr8si;
int16_t *ptr16si;
int32_t *ptr32si;
char arr[MAX_LEN];
=======
 char arr[MAX_LEN];
>>>>>>> Added cross compiler support .
 int arrlen,i=0,j=0;
 char finalreslt;



<<<<<<< 170eb6eab53a327329d2a972cdafb957ca2705c3
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
printf("size of char*    - %lu \n",sizeof(ptrchar));
printf("size of int*     - %lu \n",sizeof(ptrint));
printf("size of float*   - %lu \n",sizeof(ptrfloat));
printf("size of void*    - %lu \n",sizeof(void*));
printf("size of int8_t*  - %lu \n",sizeof(ptr8si));
printf("size of int16_t* - %lu \n",sizeof(ptr16si));
printf("size of int32_t* - %lu \n",sizeof(ptr32si));
printf("size of char*    - %lu \n",sizeof(char *));
printf("size of int*     - %lu \n",sizeof(int *));
printf("size of float*   - %lu \n",sizeof(float *));
printf("size of void*    - %lu \n",sizeof(void*));
printf("size of int8_t*  - %lu \n",sizeof(int8_t *));
printf("size of int16_t* - %lu \n",sizeof(int16_t *));
printf("size of int32_t* - %lu \n",sizeof(int32_t *));
=======
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
>>>>>>> Added cross compiler support .

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

