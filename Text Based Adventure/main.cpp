#include <iostream>
#include "dialogue.h"
#include "endingPoints.h"
#include "save.h"
#include "inventory.h"

int main()
{
    addToInventory("Apple");
    addToInventory("Cookie");
    addToInventory("Fish");
    removeFromInventory("Fish");
    savedUserChoicesNumbered = { 1, 1, 2, 2, 1, 3, 4}; 
    SAVE();
    removeFromInventory("Cookie");
    LOAD();

    return 0;
}
