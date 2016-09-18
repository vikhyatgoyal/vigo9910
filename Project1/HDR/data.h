#ifndef _DATA_H
#define _DATA_H
/****************************************************/
/*Module name: memory.h				    */
/*Author name : Vikhyat Goyal			    */
/* Date : 09/15/16				    */
/****************************************************/




/*******************************************************************/
/*descrition: function used to convert integer data into ASCII     */
/*            string.					           */
/*parameter: a pointer to string, data to be converted             */
/*	     and base format used		      	           */
/*return:    a pointer to the converted string		           */
/*******************************************************************/

int8_t* my_itoa(int8_t *str, int32_t data, int32_t base);

/*******************************************************************/
/*descrition: function used to convert an ASCII string to          */
/*            decimal.					           */
/*parameter: a pointer to string				   */
/*return:    the converted value		                   */
/*******************************************************************/

int32_t my_atoi(int8_t *str);

/*******************************************************************/
/*descrition: function used to dump data from memory on screen     */
/*parameter: a pointer to memory start adddress, length to be      */
/*           processed.					           */
/*return:    void				                   */
/*******************************************************************/
void dump_memory(uint8_t *start, uint32_t length);

/*******************************************************************/
/*descrition: function used to convert big endian data to little.  */
/*parameter: The data to be converted.			           */
/*return:    converted data in little endian format                */
/*******************************************************************/
uint32_t big_to_little(uint32_t data);


/*******************************************************************/
/*descrition:function used to convert little endian data to big.   */
/*parameter: The data to be converted.			           */
/*return:    converted data in big endian format                   */
/*******************************************************************/
uint32_t little_to_big(uint32_t data);

int Calculatestringlen(char *str);

#endif
