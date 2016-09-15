/**************************************************/
/*module name : Sizeof.c			  */
/*Author name : vikhyat goyal			  */
/*Date	      : 09/03/16			  */
/**************************************************/
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
printf("size of char in host is %lu \n",sizeof(char));
printf("size of int in host is %lu \n",sizeof(int));
printf("size of float in host is %lu \n",sizeof(float));
printf("size of double in host is %lu \n",sizeof(double));
printf("size of short in host is %lu \n",sizeof(short));
printf("size of long int host is %lu \n",sizeof(long));
printf("size of long int in host is %lu \n",sizeof(long int));
printf("size of long long in host is %lu \n",sizeof(long long));
printf("size of int8_t in host is %lu \n",sizeof(int8_t));
printf("size of uint8_t in host is %lu \n",sizeof(uint8_t));
printf("size of uint16_t in host is %lu \n",sizeof(uint16_t));
printf("size of uint32_t in host is %lu \n",sizeof(uint32_t));
printf("size of char* in host is %lu \n",sizeof(ptrchar));
printf("size of int* in host is %lu \n",sizeof(ptrint));
printf("size of float* in host is %lu \n",sizeof(ptrfloat));
printf("size of void* in host is %lu \n",sizeof(void*));
printf("size of int8_t* in host is %lu \n",sizeof(ptr8si));
printf("size of int16_t* in host is %lu \n",sizeof(ptr16si));
printf("size of int32_t* in host is %lu \n",sizeof(ptr32si));
return 0;
}
















