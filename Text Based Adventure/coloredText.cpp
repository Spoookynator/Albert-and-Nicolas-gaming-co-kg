#include <windows.h> 
#include "coloredText.h"
#include "debugLog.h"


void color(std::string input, std::string color)
{
    // get the current console handle (idk what it does)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // create new variable to get the default text color
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

    // variable to save the default text color in
    WORD saved_attributes;

    // get default text color
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

    // save default text color
    saved_attributes = consoleInfo.wAttributes;

    // values go up to 255, but there are not 255 different colors, its colors + background colors

    int textColor = -101;

    // dark colors
#pragma region dark_colors
    if (color == "darkblue" || color == "dblue")
    {
    
        textColor = 1;
    }
    if (color == "darkgreen" || color == "dgreen")
    {
        textColor = 2;
    }
    if (color == "darkcyan" || color == "dcyan")
    {
        textColor = 3;
    }
    if (color == "darkred" || color == "dred") 
    {
        textColor = 4;
    }
    if (color == "darkmagenta" || color == "dmagenta" || color == "purple")
    {
        textColor = 5;
    }
    if (color == "darkyellow" || color == "dyellow")
    {
        textColor = 6;
    }
    if (color == "darkwhite" || color == "dwhite")
    {
        textColor = 7;
    }
    if (color == "grey")
    {
        textColor = 8;
    }
#pragma endregion 
   

    // light colors
#pragma region light_colors
    if (color == "blue")
    {
        textColor = 9;
    }
    if (color == "green")
    {
        textColor = 10;
    }
    if (color == "cyan")
    {
        textColor = 11;
    }
    if (color == "red")
    {
        textColor = 12;
    }
    if (color == "magenta")
    {
        textColor = 13;
    }
    if (color == "yellow")
    {
        textColor = 14;
    }
    if (color == "white")
    {
        textColor = 15;
    }
#pragma endregion
 
    //default text color
    if (color == "default")
    {
        textColor = saved_attributes;
    }

    // if color is set
    if (textColor != -101)
    {
        SetConsoleTextAttribute(hConsole, textColor);
        std::cout << input;
        SetConsoleTextAttribute(hConsole, saved_attributes);
    }
    else
    {
        LOG("\nError: Invalid color \"" + color + "\"");
    }

}
