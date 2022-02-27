#include "..\..\userInput.h"
#include "..\..\dialogue.h"
#include "..\..\coloredText.h"
#include "..\..\init.h"

void intro()
{
    currentScene = 1;


    output("You are opening your eyes. You hear, nor see anything. You slowly get out of bed and start rubbing your eyes. \nAcross the room you see your old "); color("TV", "yellow"); output(".");
    newLine();
    output("You should try "); color("turning ", "cyan"); output("it "); color("on", "cyan"); newLine(0);

    while (tv.getInteracted() == false)
    {
        userComandInterface();
    }
    output("You hear a female voice out of the telly");
}