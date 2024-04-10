/*****************************************************************************
* University of Macau
* SoftMatter Engineering Lab
*
* MODULENAME.: Zmotion_MC.h
*
* PROJECT....: Development of a customizable soft material printer 
*              for advanced functional material fabrication
*
* DESCRIPTION: Functions created for basic motion control of HPGS
*              
*
* Change Log:
******************************************************************************
* Date    NAME    Change
* YYMMDD
* --------------------
* 240114  DechaoJiang    Module created
*
*****************************************************************************/

#pragma once
/***************************** Include files *******************************/
#include <iostream>
#include <windows.h>
#include "G_CODE_MOD.h"                        
#include "zauxdll2.h"
#include "zmotion.h"
#include "Zmotion_connect.h"

/*****************************   Variables   *******************************/


/*****************************   FUNCTION    *******************************/

void HPGS_inject_motion_param(int axis, float speed, float acceleration, float deceleration, ZMC_HANDLE &handle); 
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Set parameters for motion process
******************************************************************************/

void HPGS_home_set(int &ret, int axis, ZMC_HANDLE &handle);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Reset DPOS and MPOS to 0
******************************************************************************/

void HPGS_single_axis_motion(int &ret, int axis, float speed, float dist, float acceleration, ZMC_HANDLE &handle);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Combined function of param seting and motion execution
******************************************************************************/

void HPGS_coord_motion(int &ret, float speed, float poslist[3], float acceleration, ZMC_HANDLE &handle);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Move to a given coordinate
******************************************************************************/

int HPGS_GCODE(int &ret, PrintComm executable[], ZMC_HANDLE &handle);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Read G-Code
******************************************************************************/



/****************************** End Of Module *******************************/

