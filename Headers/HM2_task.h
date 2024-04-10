/*****************************************************************************
* University of Macau
* SoftMatter Engineering Lab
*
* MODULENAME.: HM2_task.h
*
* PROJECT....: Development of a customizable soft material printer 
*              for advanced functional material fabrication
*
* DESCRIPTION: Task Function of Printer HM2
*              
*
* Change Log:
******************************************************************************
* Date    NAME    Change
* YYMMDD
* --------------------
* 240311  DechaoJiang    Module created
* 240330  Dechaojiang    Add Z-axis calibration task
*
*****************************************************************************/
/***************************** Include files *******************************/
#pragma once
#include <iostream>
#include "StateDefinition.h"
#include "G_CODE_MOD.h"
#include "Zmotion_MC.h"
#include "Zmotion_HOME.h"
#include "OB1_Task.h"

/*****************************   FUNCTION    *******************************/

void Task_home_menu(int &state_global, bool &loop);
/*****************************************************************************
*   Entry    : state_global == HOME_MENU
*   Output   : -
*   Function : Give state_global value to jump to other task function or quit
******************************************************************************/

class PARAM
{
public:
	// Param for all motion
	float speed;
	float acceleration;
	// Param for Single-Axis Motion
	int axis;
	float dist;
	float poslist[3];
	// Param for 3D Printing
	float non_print_speed;
	double pressure;

	void Task_param_set(ZMC_HANDLE &handle, int &state_param, int state_global);

private:
	char axis_chr;
};
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Description : An object storing printer parameters
******************************************************************************/

void Task_signle_axis_motion(int &ret, ZMC_HANDLE &handle, int &state_global);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Task of signle axis motion
******************************************************************************/

void Task_coordinate_motion(int &ret, ZMC_HANDLE &handle, int &state_global);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Task of coordinate motion
******************************************************************************/

void Task_gocde_print(int &ret, ZMC_HANDLE &handle, int &state_global, PrintComm executable[]);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Task of 3D printing using G-Code
******************************************************************************/

void Task_pneumatic_test(int& state_global);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Test task of pnuematic controller
******************************************************************************/

float Task_zaxis_calibration(int &ret, ZMC_HANDLE &handle);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Task of Z-axis calibration task
******************************************************************************/