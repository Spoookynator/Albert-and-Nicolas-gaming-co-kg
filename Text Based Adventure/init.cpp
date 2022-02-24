#include <map>
#include "init.h"
#include "objects.h"


short int Scene = 0;

// Objects in scene 1
Object tree(1, "tree", "A normal looking tree.", false, "You touch the tree's trunk. It feels nice.");
Object rock(2, "rock", "Looks very spiky!", true,  "You touch the rock. You can feel its rough surface.");
Object stick(1, "stick", "Yea, it's a stick made out of wood. It probably came from a tree.", false, "You feel the stick's surface and rub your fingers all around it. You notice a small bump", "bump", "After further inspection you came to the conclusion that it was, in fact, just a normal bump");
Object leaf(1, "leaf", "It's still green, it probably fell from the tree recently.", true, "It has a weird, hary surface.");
Object TV(1, "TV", "It's an old TV. Looks like can it can be turned on", false, "You turn on the TV, it's flickering and producing nothing but whitenoise. Suddenly, the news channel turn on.");

// specific words or objects
Keyword k_tree(false, { "tree", "tree,", "tree.", "tree!", "tree?" });
Keyword k_rock(false, { "rock", "rock,", "rock.", "rock!", "rock?" });
Keyword k_stick(false, { "stick", "stick,", "stick.", "stick!", "stick?" });
Keyword k_leaf(false, { "leaf", "leaf,", "leaf.", "leaf!", "leaf?" });
Keyword k_TV(false, { "Television", "TV", "TV!", "Television!", "TV?", "Television!" });
//scene 2