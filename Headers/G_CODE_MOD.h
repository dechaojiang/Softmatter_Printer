/*****************************************************************************
* University of Macau
* SoftMatter Engineering Lab
*
* MODULENAME.: G_CODE_MOD.h
*
* PROJECT....: Development of a customizable soft material printer
*              for advanced functional material fabrication
*
* DESCRIPTION: Functions created for read G-Code in to an command array
*
*
* Change Log:
******************************************************************************
* Date    NAME    Change
* YYMMDD
* --------------------
* 240302  DechaoJiang    Module created
*
*****************************************************************************/

#ifndef GCODE_READ_G_CODE_MOD_H
#define GCODE_READ_G_CODE_MOD_H

/*****************************    Defines    *******************************/
#define MAX_LINES 100000 // Defines the maximum number of lines that can 
                         // be read from the file and stored into the array.

/***************************** Include files *******************************/
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <queue>
using namespace std;


/*****************************   Structures   *******************************/
struct PrintLine
{
    float g;
    float x;
    float y;
    float z;
    float e;
};

struct PrintComm
{
    float x;
    float y;
    float z;
    bool OB1; // Fire up pressure when be TRUE
};


/*************************    Class & Functions   ***************************/
class G_CODE
{
public:
    PrintLine *MOD;
    string *Original_text;
    int lines;
    bool fileopen;

    G_CODE() 
    {
        MOD = new PrintLine[MAX_LINES];
        Original_text = new string[MAX_LINES];
    }

    ~G_CODE() 
    {
        delete[] MOD;
        delete[] Original_text;
    }

    void read(string filename);
    /*****************************************************************************
    *   Input    : 1. A FILE PATH store in a string
    *              2. Lines of G-Code store in an array of strings
    *   Output   : -
    *   Function : Transfer data in G-Code file into a C++ string array
    ******************************************************************************/

    float extract_value(char Chr, string Line);
    /*****************************************************************************
    *   Input    : 1. Target parameter in Char ('G' 'X' etc.)
    *              2. One string line from G-Code data array (Original_text[num])
    *   Output   : The value of target parameter
    *   Function : -
    ******************************************************************************/

    PrintLine filter(string Original_text_line);
    /*****************************************************************************
    *   Input    : One string line from G-Code data array (Original_text[num])
    *   Output   : One PrintLine structure storing value
    *   Function : Extract value and filtering out useless lines
    ******************************************************************************/

    int set_MOD(int lines);
    /*****************************************************************************
    *   Input    : -
    *   Output   : -
    *   Function : Filtering out useless lines
    ******************************************************************************/

    void set_PrintComm(int n_of_lines_MOD, PrintComm executable[]);
    /*****************************************************************************
    *   Input    : -
    *   Output   : -
    *   Function : Write filted date into PrintComm struture
    ******************************************************************************/

};

#endif //GCODE_READ_G_CODE_MOD_H
