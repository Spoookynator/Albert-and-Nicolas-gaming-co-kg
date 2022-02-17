#include <iostream>
#include "coloredText.h"
#include "dialogue.h"
#include "endingPoints.h"
#include "userInput.h"
#include "save.h"
#include "objects.h"

int main()
{
    output("There is a "); color("fire", "red"); output(" burning in the forest!\n");

    narration("The fire slowly starts consuming the forest, you should make haste and do something about it");

    dialogue("Gamer", "You are an idiot!", "purple", "red");
    newLine();
    pointsAdd(10);
    pointsRemove(3);

    std::cout << userChoiceNumbered(2);
    newLine();

    output("Points: "); color(pointsReturn(), "red"); newLine();

    Object tree("schmamer", "schmamer", "schmamer", "schmamer", "schmamer");

    return 0;
}
