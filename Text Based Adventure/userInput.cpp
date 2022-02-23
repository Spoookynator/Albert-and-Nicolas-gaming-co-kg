#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "userInput.h"
#include "coloredText.h"
#include "save.h"
#include "init.h"
#include "objects.h"


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
Keyword look(false, { "look", "look,", "look.", "look!", "look?" });
Keyword interact(false, { "interact", "interact,","interact.", "interact!", "interact?" });
Keyword pickUp(false, { "take", "take,", "take.", "take!", "take?" });

// specific words or objects
Keyword k_tree(false, { "tree", "tree,", "tree.", "tree!", "tree?" });
Keyword k_rock(false, { "rock", "rock,", "rock.", "rock!", "rock?" });

void userComandInterface()
{
	std::string input;
	splitInput.clear();

	getline(std::cin, input);

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
		lookOptions();
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

	}
}
void lookOptions()
{
	// limits objects to specific scenes (so they cant be accessed before or after)
	if (currentScene == 1)
	{
		if (k_tree.foundWords() == true)
		{
			std::cout << tree.getDescription();
		}
		else if (k_rock.foundWords() == true)
		{
			std::cout << rock.getDescription();
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


