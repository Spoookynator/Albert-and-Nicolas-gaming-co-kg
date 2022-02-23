#include <map>
#include "init.h"
#include "objects.h"

short int Scene = 0;

// scene 1
Object tree("tree", "A normal looking tree.", false, 1, "You touch the tree's trunk. It feels nice.");
Object rock("rock", "Looks very spiky!", true, 1, "You touch the rock. You can feel its rough surface.");
Object stick("stick", "Yea, it's a stick made out of wood. It probably came from a tree.", false, 1, "You feel the stick's surface and rub your fingers all around it. You notice a small bump", "bump", "After further inspection you came to the conclusion that it was, in fact, just a normal bump");
Object leaf("leaf", "It's still green, it probably fell from the tree recently.", true, 1, "It has a weird, hary surface.");


//scene 2