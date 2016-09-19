/****************************************************/
/*Module name: memory.c			    */
/*Author name : Vikhyat Goyal			    */
/* Date : 09/15/16				    */
/****************************************************/
#include <stdio.h>
#include <stdint.h>
#include "data.h"
#include "memory.h"


#define FOB_MASK_U32 (uint32_t)(0xFF000000)
#define TB_MASK_U32  (uint32_t)(0x00FF0000)
#define SB_MASK_U32  (uint32_t)(0x0000FF00)
#define FB_MASK_U32  (uint32_t)(0x000000FF)

#define SWAP_FIRST_FORTH (uint32_t)(24)
#define SWAP_SECOND_THIRD (uint32_t)(8)

typedef long unsigned int ul;

int Calculatestringlen(char *str)
{
  int i=0;
  while(*(str + (sizeof(char))*i) != '\0')
       {
	i++;
       }
  return i;
}

int8_t Reverse_string(int8_t *src, uint32_t length)
{
int8_t result = 1;
int8_t temp;
int templen;

 templen=length;

/*check if the any of the pointer is a NULL pointer.*/
 if((src == NULL)||(length == 0)) {
    result = 0;
   }
/*check if there is enough space in memory for the reverse*/
 /*if(src + length*(sizeof(uint8_t)) > MAX_MEMORY_ADDRESS) {
    length = MAX_MEMORY_ADDRESS;
    }*/
 while((templen/2)||(templen ==2))
         {
          temp = *src;
          *src = *(src +(sizeof(uint8_t))*(templen-1));
          *(src + (sizeof(uint8_t))*(templen -1)) = temp;
          src++;
          templen =templen-2;
         } 
return(result);
}


/*******************************************************************/
/*descrition: function used to convert integer data into ASCII     */
/*            string.					           */
/*parameter: a pointer to string, data to be converted             */
/*	     and base format used		      	           */
/*return:    a pointer to the converted string		           */
/*******************************************************************/

int8_t* my_itoa(int8_t *str, int32_t data, int32_t base)
{
 int8_t *ptr = NULL;
 uint8_t rem = 0, Nflag = 0;
 ptr = str;
 *str++ = '\0';

/* If negative number*/
if(data < 0) {
data = -data;
Nflag = 1;
}

/*If number is zero*/
 if( data == 0) {
  *str++ = '0';
 }
 else {
   do {
        rem = data%base;
	(rem < 9) ? (*str++ = rem + '0') : (*str++ = ((rem - 9) + 'A')) ;
       data = data/base;
      }
   while(data > 0);
   if(Nflag)
     {
     *str++ = '-';
     }
 }
/*reverse the string*/	
Reverse_string(ptr,(str - ptr));
return (str);
}

/*******************************************************************/
/*descrition: function used to convert an ASCII string to          */
/*            decimal.					           */
/*parameter: a pointer to string				   */
/*return:    the converted value		                   */
/*******************************************************************/

int32_t my_atoi(int8_t *str)
{
 int32_t result = 0;
 int8_t negative = 1;

 /* if the string is not a null string*/
 if(!((*str == '0')&&(*(str + 1) == '\0'))) {
  if(*str == '-') {
    negative = -1;
    str++;
   }
  while(*str != '\0') { 
    result = result*10 + (*str++ -'0'); /* assuming base 10 always*/
   }
  }
  else
  {
   result =0;
  }
 return (negative*result); 
}



/*******************************************************************/
/*descrition: function used to dump data from memory on screen     */
/*parameter: a pointer to memory start adddress, length to be      */
/*           processed.					           */
/*return:    void				                   */
/*******************************************************************/
void dump_memory(uint8_t *start, uint32_t length)
{
 while(length--) {
  printf("value at | %x | \n", *start++);
 }
}


/*******************************************************************/
/*descrition: function used to convert big endian data to little.  */
/*parameter: The data to be converted.			           */
/*return:    converted data in little endian format                */
/*******************************************************************/
uint32_t big_to_little(uint32_t data)
{
uint32_t result = 0;
result = (uint32_t)(((data & FB_MASK_U32) << (SWAP_FIRST_FORTH))
	            |((data & SB_MASK_U32) <<(SWAP_SECOND_THIRD))
	    	    |((data & TB_MASK_U32) >>(SWAP_SECOND_THIRD))
            	    |((data & FOB_MASK_U32) >>(SWAP_FIRST_FORTH)));
 return(result);
}



/*******************************************************************/
/*descrition:function used to convert little endian data to big.   */
/*parameter: The data to be converted.			           */
/*return:    converted data in big endian format                   */
/*******************************************************************/
uint32_t little_to_big(uint32_t data)
{
/* The algorithum should remain same for both the conversion. (check)*/
return(big_to_little(data));
}
 
