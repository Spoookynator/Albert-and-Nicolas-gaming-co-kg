#include <iostream>
#include "dialogue.h"
#include "endingPoints.h"
#include "save.h"
#include "inventory.h"
#include "userInput.h"
#include "objects.h"
#include "init.h"

short int currentScene = 0;

int main()
{
    currentScene = 1;
    std::cout << "Let's look around and see if I can find something!" << std::endl;
    userComandInterface();
    return 0;
}
