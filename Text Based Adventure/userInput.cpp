#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "userInput.h"
#include "coloredText.h"
#include "save.h"
#include "init.h"
#include "objects.h"
#include "inventory.h"
#include "debugLog.h"


std::vector<std::string> splitInput;

// use for story progression choices

int userChoiceNumbered(int options)
{
	// sets text color to grey
	color("nothing", "hgrey");
	
	int input;

	std::cin >> input;

	while (std::cin.fail() || input <= 0 || input > options)
	{
		color("You should choose a number between 1 and " + std::to_string(options) + "\n", "dred");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> input;
	}

	savedUserChoicesNumbered.push_back(input);

	// changes the text color back to white
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	color("nothing", "hwhite");
	return input;
}

// conditionals for word finding in input
// also find synonmys for words = more input variation
// universal words
Keyword save(false, { "save", "save,", "save.", "save!", "save?" });
Keyword load(false, { "load", "load,", "load.", "load!", "load?" });
Keyword textspeed(false, { "textspeed", "textspeed,", "textspeed.", "textspeed!"});
Keyword look(false, { "look", "look,", "look.", "look!", "look?", "inspect", "inspect,", "inspect.", "inspect!", "inspect?", "examine", "examine,", "examine.", "examine!", "examine?" });
Keyword interact(false, { "interact", "interact,","interact.", "interact!", "interact?", "touch", "touch,","touch.", "touch!", "touch?", "interact", "interact,","interact.", "interact!", "interact?" });
Keyword pickUp(false, { "take", "take,", "take.", "take!", "take?", "pick", "pick,", "pick.", "pick!", "pick?" });
Keyword playerInventory(false, { "inventory", "inventory,", "inventory.", "inventory!", "inventory?",  "backpack", "backpack,", "backpack.", "backpack!", "backpack?", "bag", "bag,", "bag.", "bag!", "bag?" });
Keyword turnOn(false, { "turn", "turn,", "turn.", "turn!", "turn?" });
Keyword drink(false, { "drink", "drink,", "drink.", "drink!", "drink?" });



void userComandInterface()
{
	// sets text color to grey
	color("nothing", "hgrey");
	std::string input;
	splitInput.clear();
	getline(std::cin, input);
	
	std::cin.clear();

	// input validation
	while (std::cin.fail())
	{
		color("You can't do that", "dread");
		std::cin.clear();
		std::cin.ignore(256, '\n');
		getline(std::cin, input);

	}

	size_t pos = 0;
	std::string space = " ";
	input += space;

	// makes the whole input lower case for easier comparison
	std::for_each(input.begin(), input.end(), [](char& c) {
		c = ::tolower(c);
		});

	// seperates words by space
	if ((pos = input.find(space)) == std::string::npos)
	{
		splitInput.push_back(input);
	}
	else
	{
		pos = 0;
		while ((pos = input.find(space)) != std::string::npos) {
			// saves the item to the split string
			splitInput.push_back(input.substr(0, pos));
			input.erase(0, pos + INVENTORY.length());
		}
	}


	// defaults variables
	clear();

	// checks input for keywords
	lookFor();

	// CHANGE FOR NEW KEYWORD
	// uses keywords from before
	if (save.foundWords() == true)
	{
		SAVE();
	}
	else if (load.foundWords() == true)
	{
		LOAD();
	}
	else if (textspeed.foundWords() == true)
	{
		setTextspeed();
		std::cin.clear();
	}
	else if (look.foundWords() == true)
	{
		lookOptions(true);
	}
	else if (interact.foundWords() == true)
	{
		lookOptions(false);

	}
	else if (drink.foundWords() == true)
	{
		lookOptions(false);

	}
	else if (turnOn.foundWords() == true)
	{
		lookOptions(false);
	}
	else if (pickUp.foundWords() == true)
	{
		pickUpItem();

	}
	else if (playerInventory.foundWords() == true)
	{
		outputInventory();
		std::cin.clear();
	}
	else {
		color("You can't do that!\n", "dred");
		userComandInterface();
	}


	// changes the text color back to white
	color("nothing", "hwhite");
} 

void lookFor()
{
	// looks if keywords are in the WHOLE string (look, save, load)
	for (std::string words : splitInput)
	{ 
		// universal words
#pragma region universalWords
		for (std::string instance : save.getKeywords())
		{
			if (instance == words) save.foundWords(true);
		}
		for (std::string instance : load.getKeywords())
		{
			if (instance == words) load.foundWords(true);
		}
		for (std::string instance : look.getKeywords())
		{
			if (instance == words) look.foundWords(true);
		}
		for (std::string instance : interact.getKeywords())
		{
			if (instance == words) interact.foundWords(true);
		}
		for (std::string instance : textspeed.getKeywords())
		{
			if (instance == words) textspeed.foundWords(true);
		}
		for (std::string instance : pickUp.getKeywords())
		{
			if (instance == words) pickUp.foundWords(true);
		}
		for (std::string instance : playerInventory.getKeywords())
		{
			if (instance == words) playerInventory.foundWords(true);
		}
		for (std::string instance : turnOn.getKeywords())
		{
			if (instance == words) turnOn.foundWords(true);
		}
		for (std::string instance : drink.getKeywords())
		{
			if (instance == words) drink.foundWords(true);
		}
#pragma endregion
		// specific words
		for (std::string instance : k_tv.getKeywords())
		{
			if (instance == words) k_tv.foundWords(true);
		}
		for (std::string instance : k_waterbottle.getKeywords())
		{
			if (instance == words) k_waterbottle.foundWords(true);
		}
		for (std::string instance : k_gascanister.getKeywords())
		{
			if (instance == words) k_gascanister.foundWords(true);
		}
		for (std::string instance : k_radio.getKeywords())
		{
			if (instance == words) k_radio.foundWords(true);
		}
		for (std::string instance : k_key.getKeywords())
		{
			if (instance == words) k_key.foundWords(true);
		}
		for (std::string instance : k_door.getKeywords())
		{
			if (instance == words) k_door.foundWords(true);
		}

	}
}

void setTextspeed()
{
	int textspeed = 0;
	for (std::string words : splitInput)
	{
		if (words == "slow" || words == "easy" || words == "relaxed")
		{
			textspeed = 0;
		}
		else if (words == "default" || words == "normal" || words == "standart" || words == "ordinary" || words == "regualar")
		{
			textspeed = 1;
		}
		else if (words == "fast" || words == "quick" || words == "swift")
		{
			textspeed = 2;
		}

	}

	switch (textspeed)
	{
	case 0:
		textspeed = 80;
		color("You are now using the slow text speed.\n", "grey");
		break;
	case 1:
		textspeed = 50;
		color("You are now using the default text speed.\n", "grey");
		break;
	case 2:
		textspeed = 30;
		color("ZOOOOOOOM.\n", "yellow");
		break;
	default:
		color("Wrong input!\n", "dred");
		break;
	}

}
void lookOptions(bool look)
{
	// limits objects to specific scenes (so they cant be accessed before or after)
	
	if (look == true)
	{
		// description
		if (currentScene == tv.getScene() && k_tv.foundWords() == true)
		{
			color(tv.getDescription(), "white");
		}	
		else if (currentScene == waterbottle.getScene() && k_waterbottle.foundWords() == true)
		{
			color(waterbottle.getDescription(), "white");
		}
		else if (currentScene == gascanister.getScene() && k_gascanister.foundWords() == true)
		{
			color(gascanister.getDescription(), "white");
		}
		else if (currentScene == radio.getScene() && k_radio.foundWords() == true)
		{
			color(radio.getDescription(), "white");
		}
		else if (currentScene == key.getScene() && k_key.foundWords() == true)
		{
			color(key.getDescription(), "white");
		}
		else if (currentScene == door.getScene() && k_door.foundWords() == true)
		{
			color(door.getDescription(), "white");
		}
		// default message when object not found
		else {
			color("You don't see that!", "dred");
			std::cout << std::endl;
			userComandInterface();
		}
	}
	else
	{
		// interaction
		if (currentScene == tv.getScene() && k_tv.foundWords() == true)
		{
			color(tv.getInteraction(), "white");
			tv.setInteracted(true);
		}
		else if (currentScene == waterbottle.getScene() && k_waterbottle.foundWords() == true)
		{
			color(waterbottle.getInteraction(), "white");
			waterbottle.setInteracted(true);
		}
		else if (currentScene == gascanister.getScene() && k_gascanister.foundWords() == true)
		{
			color(gascanister.getInteraction(), "white");
			gascanister.setInteracted(true);
		}
		else if (currentScene == radio.getScene() && k_radio.foundWords() == true)
		{
			color(radio.getInteraction(), "white");
			radio.setInteracted(true);
		}
		else if (currentScene == door.getScene() && k_door.foundWords() == true)
		{
			if (radio.getInteracted() == true)
			{
				if (inventoryCheckFor(key.getName()) == true)
				{
					color("You insert your key into the keyhole. You turn it with an audible *click* and the door opens.", "white");
					door.setInteracted(true);
				}
				else
					color(door.getInteraction(), "white");
			}
			else
			{
				color("You think about using the key, but feel like you're overlooking something important.", "white");
			}
		}
		// default message when object not found
		else {
			color("You don't see that!", "dred");
			std::cout << std::endl;
			userComandInterface();

		}
	}
}

void pickUpItem()
{
	if (currentScene == key.getScene() && k_key.foundWords() == true && key.getAquirable() == true)
	{
		addToInventory(key.getName());
		key.setScene(-1);
	}
		else {
		color("You can't do that!", "dred");
		std::cout << std::endl;
		userComandInterface();
	}
}

// defaults all variables
void clear()
{
	// universal
	save.foundWords(false);
	load.foundWords(false);
	look.foundWords(false);
	textspeed.foundWords(false);
	interact.foundWords(false);
	pickUp.foundWords(false);
	turnOn.foundWords(false);
	drink.foundWords(false);

	// specific
	k_tv.foundWords(false);
	k_waterbottle.foundWords(false);
	k_radio.foundWords(false);
	k_gascanister.foundWords(false);
	k_key.foundWords(false);
}

