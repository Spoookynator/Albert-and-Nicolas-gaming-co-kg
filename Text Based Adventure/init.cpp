#include <map>
#include "init.h"
#include "coloredText.h"

int currentScene = 0;
// Objects in scene 1
Object tv(1, "TV", "It's your old TV. Looks like can it can be turned on", false, "You turn on the TV, it's flickering and producing nothing but whitenoise. Suddenly, the news channel turns on.");
	
// specific words or objects
Keyword k_tv(false, { "television", "tv", "tv!", "television!", "tv?", "television!" });
//scene 2