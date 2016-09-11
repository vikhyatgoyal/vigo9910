#include <stdio.h>
#include <stdint.h>



int main()
{
char *ptrchar;
int *ptrint;
float *ptrfloat;
int8_t *ptr8si;
int16_t *ptr16si;
int32_t *ptr32si;
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
return 0;
}

