/*****************************************************************************
* University of Macau
* SoftMatter Engineering Lab
*
* MODULENAME.: OB1_Task.h
*
* PROJECT....: Development of a customizable soft material printer 
*              for advanced functional material fabrication
*
* DESCRIPTION: Functions created for control of OB1 Pneumatic controller
*              
*
* Change Log:
******************************************************************************
* Date    NAME    Change
* YYMMDD
* --------------------
* 230625  DechaoJiang    Module created
*
*****************************************************************************/

#pragma once
/***************************** Include files *******************************/
#include "Elveflow64.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <tchar.h>

/*****************************   Variables   *******************************/



/*************************   STATE DEFINITION    ***************************/





/*****************************   FUNCTION    *******************************/
void Check_Error(int ElveflowError);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Check and output error of OB1
******************************************************************************/

void myOB1_initialization();
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Connect to and initialize OB1
******************************************************************************/

void myOB1_SETPRES();
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Set pressure
******************************************************************************/

void myOB1_GETPRES();
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Read pressure
******************************************************************************/

void OB1_pressurize(double pressure, int channel);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Set pressure of a channel
******************************************************************************/

void OB1_depressurize(int channel);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Read pressure of a channel
******************************************************************************/

void OB1_close();
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Close the connection
******************************************************************************/

/****************************** End Of Module *******************************/