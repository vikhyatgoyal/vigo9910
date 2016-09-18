#ifndef _PROJECT_1_H
#define _PROJECT_1_H
/****************************************************/
/*Module name: memory.h				    */
/*Author name : Vikhyat Goyal			    */
/* Date : 09/15/16				    */
/****************************************************/

/*******************************************************************/
/*descrition:Funtion is used to throw approprite error message     */
/*parameter: error code mapped to the situation		           */
/*return:    0 : always					           */
/*******************************************************************/
uint8_t my_faulthandleing(uint8_t errorcode);

/*******************************************************************/
/*descrition: function used to copy data from one memory           */
/*            to other.					           */
/*parameter: a pointer to source, a pointer to destination         */
/*	     and length of data to be moved      	           */
/*return:    0 : if the memory address specified are NULL          */
/*  		 if there is an overlap between the memory blocks. */
/*	     1 : otherwise					   */
/*******************************************************************/
void project_1_report(void);

#endif
