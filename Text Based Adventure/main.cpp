#include <iostream>
#include <windows.h>
#include "dialogue.h"
#include "endingPoints.h"
#include "save.h"
#include "inventory.h"
#include "userInput.h"
#include "objects.h"
#include "init.h"
#include "coloredText.h"

short int currentScene = 0;

int main()
{
    /*
    *     currentScene = 1;
    std::cout << "Let's look around and see if I can find something!" << std::endl;
    while (true)
    {
        userComandInterface();
    }

    */
    output("I have a "); color("TV", "yellow"); output("!");
    narration("I am the narrator!");
    dialogue("gamer", "You are cringe", "red");
    output("Which path do you want to take? Straight[1], Left[2], Up[3]");
    newLine();

    int choice1 = userChoiceNumbered(3);
    int goNext = 0;

    while (goNext == 0)
    {
        userComandInterface();

    }

    return 0;
}
