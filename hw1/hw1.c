/****************************************************/
/*Module name: Arrayreverse.c			    */
/*Author name : Vikhyat Goyal			    */
/* Date : 09/03/16				    */
/****************************************************/
#include <stdio.h>
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

int main()
{
char arr[MAX_LEN];
int arrlen,i=0,j=0;
char finalreslt;
printf("Please enter the length of the array to be reversed: \n");
scanf("%d",&arrlen);
printf("Please enter the array \n");
scanf("%s",arr);


finalreslt = reverse(arr,arrlen);

if(!finalreslt)
{
printf("the array in reverse is: \n");
for(j =0; j < arrlen ; j++)
{
printf("%d %c \n",j,arr[j]);
}
}
else
{
printf("wrong array or invalid length");
}
return 0;
}

