#ifndef _PROJECT_1_SETTINGS_H
#define _PROJECT_1_SETTINGS_H
/****************************************************/
/*Module name: memory.h				    */
/*Author name : Vikhyat Goyal			    */
/* Date : 09/15/16				    */
/****************************************************/


#define PROJECT_1_COMPILE_OFF  0 
/* PROJECT_1_COMPILE_OFF - compilation of project 1 is swicthed OFF */
#define PROJECT_1_COMPILE_ON   1
/* PROJECT_1_COMPILE_ON - compilation of project 1 is swicthed ON */

#define PROJECT_1_COMPILE PROJECT_1_COMPILE_ON
/* PROJECT_1_COMPILE set to PROJECT_1_COMPILE_ON to compile Project_1*/
/* PROJECT_1_COMPILE set to PROJECT_1_COMPILE_OFF to not compile Project_1*/

#define TEST_DATA_OFF  0 
/* TEST_DATA_OFF - testing for data file is swicthed ON */
#define TEST_DATA_ON   1
/* TEST_DATA_ON - testing for data file is swicthed OFF */

#define TEST_DATA TEST_DATA_ON
/* TEST_DATA to TEST_DATA_ON to enable data file testing. */
/* TEST_DATA set to TEST_DATA_OFF to disable data file testing */

/* FRDM KL25z compilation should not compile a code with printf or scanf statements*/

#ifdef POISON
 #pragma GCC poison printf sprint fprint
#endif


#endif
