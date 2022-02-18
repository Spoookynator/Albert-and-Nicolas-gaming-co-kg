#include <iostream>
#include "dialogue.h"
#include "endingPoints.h"
#include "save.h"
#include "inventory.h"

int main()
{
    editInventory("gamer", "add");
    savedUserChoicesNumbered = { 1, 1, 2, 2, 1, 3, 4}; 
    SAVE();
    LOAD();
    return 0;
}
