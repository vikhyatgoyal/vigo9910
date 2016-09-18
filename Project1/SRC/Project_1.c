/****************************************************/
/*Module name: memory.c			    */
/*Author name : Vikhyat Goyal			    */
/* Date : 09/15/16				    */
/****************************************************/
#include <stdio.h>
#include <stdint.h>
#include "Project_1.h"
#include "memory.h"
#include "data.h"
#include "Project_1 _settings.h"

#define MAX_DATA_ARRAY (32)
#define FIRST_POINTER_ELEMENT (0)
#define SECOND_POINTER_ELEMENT (8)
#define THIRD_POINTER_ELEMENT (16)
#define MY_DATA_BASE (31)

#define MAX_LEN (100)

#define FALSE 0
#define TRUE !(FALSE)

#if(TEST_DATA == TEST_DATA_ON)
#endif

static uint8_t FAULT_SET = FALSE;

/*******************************************************************/
/*descrition:Funtion is used to throw approprite error message     */
/*parameter: error code mapped to the situation		           */
/*return:    0 : always					           */
/*******************************************************************/
uint8_t my_faulthandleing(uint8_t errorcode) {
 if(!FAULT_SET)
  {
   printf("The program ended with an error. \n");
   printf("The step %d has failed.", errorcode);
   FAULT_SET = TRUE;
  }
return(0);
}


/*******************************************************************/
/*descrition: function used to copy data from one memory           */
/*            to other.					           */
/*parameter: a pointer to source, a pointer to destination         */
/*	     and length of data to be moved      	           */
/*return:    0 : if the memory address specified are NULL          */
/*  		 if there is an overlap between the memory blocks. */
/*	     1 : otherwise					   */
/*******************************************************************/
void project_1_report(void){
uint8_t arr[MAX_DATA_ARRAY];
uint8_t *aptr_1 , *aptr_2, *aptr_3;
uint8_t i = 0, j = 0,result = 0;

aptr_1 = &arr[FIRST_POINTER_ELEMENT];
aptr_2 = &arr[SECOND_POINTER_ELEMENT];
aptr_3 = &arr[THIRD_POINTER_ELEMENT];

  for(i = 0 ; i<16 ; i++)
  {
   *(aptr_1 +i) = MY_DATA_BASE + i ;
  }
 
/*step 1*/
 result = my_memzero(aptr_3, MAX_DATA_ARRAY - THIRD_POINTER_ELEMENT );
 
/*step 2*/
 (result) ? (result = my_memmove(aptr_1,aptr_3,8)) : (result = my_faulthandleing(1)); 

/*step 3*/ 
 
 (result) ? (result = my_memmove(aptr_2,aptr_1,16)) : (result = my_faulthandleing(2)) ;

/*step 4*/
 (result) ? (result = my_reverse(aptr_1,MAX_DATA_ARRAY)) : (result = my_faulthandleing(3)) ;

 printf("|");
 for(j = 0; j < MAX_DATA_ARRAY ; j++)
  {
   printf(" %d |",arr[j]);
  }
 printf("\n");
}

#if(TEST_DATA == TEST_DATA_ON)

void Project_1_DataCheck(void){
  int8_t arr[MAX_LEN];
  int32_t data,base;
  int8_t brr[MAX_LEN];
  uint8_t crr[MAX_LEN];
  int32_t bigData,endResult,len;
  int32_t littleData;

 /*****Test for itoa***************************************************/
 printf("Testing my_itoa function \n");
 printf("please enter the integer to be converted to string \n");
 scanf("%d",&data);
 printf("please enter the base used \n");
 scanf("%d",&base);

 my_itoa(arr,data,base);

 printf("the string equivalent is: \n");
 printf("%s \n",arr);

 /*****Test for my_atoi function ******************/
 printf("Testing my_atoi function \n");
 printf("Please enter the string \n");
 scanf("%s",brr);
 data = my_atoi(brr);
 printf("the integer equivalent is: \n");
 printf("%d \n",data);

 /*****Test for dump_memory function ******************/
 printf("Testing dump_memory function \n");
 printf("Please enter the string \n");
 scanf("%s",crr);
 printf("Please enter the length \n");
 scanf("%d",&len);
 dump_memory(crr,len);

 /*****Test for big_to_little function ******************/
 printf("Testing big_to_little function \n");
 printf("Please enter the big endian data \n");
 scanf("%d",&bigData);
 endResult = big_to_little(bigData);
 printf("The data in little endian is %d \n",endResult);

 /*****Test for little_to_big function ******************/
 printf("Testing little_to_big function \n");
 printf("Please enter the little endian data \n");
 scanf("%d",&littleData);
 endResult = little_to_big(littleData);
 printf("The data in big endian is %d \n",endResult);
}
#endif
