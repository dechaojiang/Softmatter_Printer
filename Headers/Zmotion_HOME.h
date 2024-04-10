/*****************************************************************************
* University of Macau
* SoftMatter Engineering Lab
*
* MODULENAME.: Zmotion_HOME.h
*
* PROJECT....: Development of a customizable soft material printer 
*              for advanced functional material fabrication
*
* DESCRIPTION: Functions for HOME process
*              
*
* Change Log:
******************************************************************************
* Date    NAME    Change
* YYMMDD
* --------------------
* 240116  DechaoJiang    Module created
*
*****************************************************************************/

/***************************** Include files *******************************/

#pragma once
#include <chrono>
#include "Zmotion_MC.h"

/*****************************    Defines    *******************************/

#define XHOME_IO 4 // X-axis home I/O is IN4
#define YHOME_IO 1 // Y-axis home I/O is IN1
#define ZHOME_IO 7 // Z-axis home I/O is IN7
#define HOME_SPEED 10.5
#define HOME_ACCEL 300.5
#define HOME_DECEL 6
#define HOME_CREEP 2.5
/*****************************   Functions   *******************************/

void HPGS_home_param(int &ret, int axis, ZMC_HANDLE &handle);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Set parameters for single axis HOME process
******************************************************************************/

void HPGS_home_motion(int &ret, int axis, ZMC_HANDLE &handle);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Param set & Execution of HOME process
******************************************************************************/

void HPGS_HOME(int &ret, ZMC_HANDLE &handle);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : An ultimate function cover all HOME process for all axis
******************************************************************************/


/****************************** End Of Module *******************************/