/*****************************************************************************
* University of Macau
* SoftMatter Engineering Lab
*
* MODULENAME.: Zmotion_connect.h
*
* PROJECT....: Development of a customizable soft material printer 
*              for advanced functional material fabrication
*
* DESCRIPTION: Functions for initialize and end the connection. 
*              And a universal function for checking error.
*
* Change Log:
******************************************************************************
* Date    NAME    Change
* YYMMDD
* --------------------
* 240114  DechaoJiang    Module created
*
*****************************************************************************/

/***************************** Include files *******************************/
#pragma once
#include <iostream>
#include <windows.h>                        
#include "zauxdll2.h"
#include "zmotion.h"
#include "Zmotion_HOME.h"

/*****************************    Defines    *******************************/
#define Z_AXIS 2 // You are not advised to change this
#define X_AXIS 1 // You are not advised to change this
#define Y_AXIS 0 // You are not advised to change this

/*****************************   Variables   *******************************/
 // You are not advised to change this

/*************************   STATE DEFINITION    ***************************/

/*****************************   FUNCTION    *******************************/

void commandCheckHandler(const char* command, int ret);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Check if execution return error
******************************************************************************/

void HPGS_init(int &ret, ZMC_HANDLE &handle);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Make connection via ethernet (default IP: 192.168.0.11)
******************************************************************************/

void HPGS_close(int &ret, ZMC_HANDLE &handle);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Disconnect
******************************************************************************/

/****************************** End Of Module *******************************/