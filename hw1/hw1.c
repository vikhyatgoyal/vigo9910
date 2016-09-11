/****************************************************/
/*Module name: Arrayreverse.c			    */
/*Author name : Vikhyat Goyal			    */
/* Date : 09/03/16				    */
/****************************************************/
#include <stdio.h>
#include "hw1.h"
#define MAX_LEN (100)

char reverse(char *str,int length)
{
 char result =0;
 char temp;

 int templen;

 templen=length;
 if((length ==0)||(length >MAX_LEN))
   {
    result = 1;
   }
 else
   {
    while((templen/2)||(templen ==2))
         {
          temp = *str;
          *str = *(str +(sizeof(char))*(templen-1));
          *(str + (sizeof(char))*(templen -1)) = temp;
          str++;
          templen =templen-2;
         }  
   }
 return(result);
}

int stringlen(char *str)
{
  int i=0;
  while(*(str + (sizeof(char))*i) != '\0')
       {
	i++;
       }
  return i;
}

int main()
{
 char arr[MAX_LEN];
 int arrlen,i=0,j=0;
 char finalreslt;
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

