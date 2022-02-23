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


std::vector<std::string> splitInput;

// use for story progression choices

int userChoiceNumbered(int options)
{
	int input;
	std::cin >> input;

	while (std::cin.fail() || input <= 0 || input > options)
	{
		color("Only numbers between 1 and " + std::to_string(options) + " are valid, please try again!\n", "dred");
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> input;
	}

	savedUserChoicesNumbered.push_back(input);
	return input;
}
// use for story progression choices

// conditionals for word finding in input
// also find synonmys for words = more input variation
// universal words
Keyword save(false, { "save", "save,", "save.", "save!", "save?" });
Keyword load(false, { "load", "load,", "load.", "load!", "load?" });
Keyword look(false, { "look", "look,", "look.", "look!", "look?", "inspect", "inspect,", "inspect.", "inspect!", "inspect?", "examine", "examine,", "examine.", "examine!", "examine?" });
Keyword interact(false, { "interact", "interact,","interact.", "interact!", "interact?", "touch", "touch,","touch.", "touch!", "touch?", "interact", "interact,","interact.", "interact!", "interact?" });
Keyword pickUp(false, { "take", "take,", "take.", "take!", "take?" });
Keyword playerInventory(false, { "inventory", "inventory,", "inventory.", "inventory!", "inventory?",  "backpack", "backpack,", "backpack.", "backpack!", "backpack?", "bag", "bag,", "bag.", "bag!", "bag?" });

// specific words or objects
Keyword k_tree(false, { "tree", "tree,", "tree.", "tree!", "tree?" });
Keyword k_rock(false, { "rock", "rock,", "rock.", "rock!", "rock?" });
Keyword k_stick(false, { "stick", "stick,", "stick.", "stick!", "stick?" });
Keyword k_leaf(false, { "leaf", "leaf,", "leaf.", "leaf!", "leaf?" });


void userComandInterface()
{
	std::string input;
	splitInput.clear();
	getline(std::cin, input);

	std::cin.clear();

	// input validation
	while (std::cin.fail())
	{
		color("I can't do that", "dread");
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

	// uses keywords from before
	if (save.foundWords() == true)
	{
		SAVE();
	}
	else if (load.foundWords() == true)
	{
		LOAD();
	}
	else if (look.foundWords() == true)
	{
		lookOptions(true);
	}
	else if (interact.foundWords() == true)
	{
		lookOptions(false);
	}
	else if (playerInventory.foundWords() == true)
	{
		outputInventory();
	}
	else {
		color("I cant do that!\n", "dred");
		userComandInterface();
	}
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
		for (std::string instance : pickUp.getKeywords())
		{
			if (instance == words) pickUp.foundWords(true);
		}
		for (std::string instance : playerInventory.getKeywords())
		{
			if (instance == words) playerInventory.foundWords(true);
		}
#pragma endregion
		// specific words

		for (std::string instance : k_tree.getKeywords())
		{
			if (instance == words) k_tree.foundWords(true);
		}
		for (std::string instance : k_rock.getKeywords())
		{
			if (instance == words) k_rock.foundWords(true);
		}
		for (std::string instance : k_stick.getKeywords())
		{
			if (instance == words) k_stick.foundWords(true);
		}
		for (std::string instance : k_leaf.getKeywords())
		{
			if (instance == words) k_leaf.foundWords(true);
		}

	}
}
void lookOptions(bool look)
{
	// limits objects to specific scenes (so they cant be accessed before or after)

	if (currentScene == 1)
	{
		if (look == true)
		{
			if (k_tree.foundWords() == true)
			{
				std::cout << tree.getDescription();
			}
			else if (k_rock.foundWords() == true)
			{
				std::cout << rock.getDescription();
			}
			else if (k_stick.foundWords() == true)
			{
				std::cout << stick.getDescription();
			}
			else if (k_leaf.foundWords() == true)
			{
				std::cout << leaf.getDescription();
			}

		}
		else
		{
			if (k_tree.foundWords() == true)
			{
				std::cout << tree.getInteraction();
			}
			else if (k_rock.foundWords() == true)
			{
				std::cout << rock.getInteraction();
			}
			else if (k_stick.foundWords() == true)
			{
				std::cout << stick.getInteraction();
			}
			else if (k_leaf.foundWords() == true)
			{
				std::cout << leaf.getInteraction();
			}
		}

	}
	else if (currentScene == 2)
	{

	}
	else if (currentScene == 3)
	{

	}

	// default message when object not found
	else {
		color("I dont see a \"" + splitInput.at(2) + "\"!", "dred");
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
	interact.foundWords(false);
	pickUp.foundWords(false);

	// specific
	k_tree.foundWords(false);
	k_tree.foundWords(false);

}