#include <iostream>
#include <string>
#include <vector>
#include "userInput.h"
#include "coloredText.h"
#include "save.h"
#include "init.h"


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
void userComandInterface()
{
	std::string input;
	getline(std::cin, input);

	while (std::cin.fail())
	{
		color("I can't do that", "dread");
		std::cin.clear();
		std::cin.ignore(256, '\n');
		getline(std::cin, input);
	}

	size_t pos = 0;

	
		while ((pos = input.find(" ")) != std::string::npos) {
			// saves the item to the split string
			splitInput.push_back(input.substr(0, pos));
			input.erase(0, pos + INVENTORY.length());
		}


	std::cout << splitInput.at(0);


	if (splitInput[0] == "save")
	{
		SAVE();
	}
	if (splitInput[0] == "load")
	{
		LOAD();
	}
	if (splitInput[0] == "look")
	{
		lookOptions();
	}
} 

void lookOptions()
{
	if (currentScene == 1)
	{
		if (splitInput[2] == "tree")
		{
			tree.getDescription();
		}
		else if (splitInput[2] == "rock")
		{
			rock.getDescription();
		}
	}
	else if (currentScene == 2)
	{

	}
	else if (currentScene == 3)
	{

	}
	else {
		color("I dont see a \"" + splitInput[3] + "\"!", "dred");
	}
}


