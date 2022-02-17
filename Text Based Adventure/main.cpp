#include <iostream>
#include "coloredText.h"
#include "dialogue.h"
#include "endingPoints.h"
#include "userInput.h"
#include "save.h"
#include "objects.h"
#include "inventory.h"

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

    editInventory(inventory, "gamer", "add");

    inventoryCheckFor(inventory, "gamer");
    inventoryCheckFor(inventory, "apple");

    output("Points: "); color(pointsReturn(), "red"); newLine();

    Object tree("tree", "Just a normal tree", "cant do anything");
    return 0;
}
