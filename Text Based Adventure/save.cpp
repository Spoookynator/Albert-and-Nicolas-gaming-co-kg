#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "save.h"
#include "inventory.h"
#include "debugLog.h"
#include "coloredText.h"


std::vector<int> savedUserChoicesNumbered = {};

const std::string INVENTORY = "%";
const std::string CHOICES = "&";
const std::string FILENAME = "saveFile.dat";



void LOAD()
{
	const std::string FILE_STRING = openFile();
	if (FILE_STRING == "Error")
	{
		char temp;
		color("Unable to open Save File! It might not exist, or be renamed! Do you want to save now? Y/N\n", "dred");
		std::cin >> temp;

		while (std::cin.fail() || (!(temp == 'y') && !(temp == 'Y') && !(temp == 'n') && !(temp == 'N')))
		{
			color("Error: Illegal character\n", "dred");
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> temp;
		}
		switch (temp)
		{
		case 'y':
			SAVE();
			break;
		case 'Y':
			SAVE();
			break;
		default:
			color("Gamedata not saved!\n", "dred");
			break;
		}
	}
	loadInventory(FILE_STRING);
	loadChoices(FILE_STRING);


	for (const auto& str : inventory) {
		LOG(str);
	}
	for (const auto& str : savedUserChoicesNumbered) {
		LOG(str);
	}
}

void SAVE()
{
	std::ofstream newSaveFile;
	newSaveFile.open(FILENAME);

	// for everyr element of the inventory, store it, seperated by INVENTORY 
	for (int i = 0; i < inventory.size(); i++)
	{
		newSaveFile << inventory.at(i);
		if (i < inventory.size())
		{
			newSaveFile << INVENTORY;
		}
	}

	for (int i = 0; i < savedUserChoicesNumbered.size(); i++)
	{
		newSaveFile << savedUserChoicesNumbered.at(i);
		if (i < savedUserChoicesNumbered.size())
		{
			newSaveFile << CHOICES;
		}
	}
	newSaveFile.close();
	std::cout << "Done!\n";
}

std::string openFile()
{
	std::string fileString;
	std::ifstream loadFile;


	// opens file, if possible
	loadFile.open(FILENAME);
	if (loadFile.is_open())
	{
		std::getline(loadFile, fileString);

		return fileString;
		loadFile.close();
	}

	// when file cant be opened;
	return "Error";
}

void loadInventory(std::string fileString)
{
	// clears current inventory to avoid duplicates
	inventory.clear();
	size_t pos = 0;
	
	//finds the special character INVENTORY in the file and gets the word before it
	while ((pos = fileString.find(INVENTORY)) != std::string::npos) {
		// saves the item to the inventory
		inventory.push_back(fileString.substr(0, pos));
		fileString.erase(0, pos + INVENTORY.length());
	}
}

void loadChoices(std::string fileString)
{
	// clears current choices to avoid duplicates
	savedUserChoicesNumbered.clear();

	// string after completion to int
	int convertedString = 0;

	// converts string to int
	std::stringstream stringToInt(convertedString);

	size_t pos = 0;

	//finds the special character CHOICES in the file and gets the word before it
	while ((pos = fileString.find(CHOICES)) != std::string::npos) {

		// saves the gotten word to a string
		std::string temp = (fileString.substr(0, pos));
		std::stringstream stringToInt(temp);
		stringToInt >> convertedString;

		// converts string to int
		// stringToInt >> temp;

		// saves int to choices
		if (convertedString != 0)
		savedUserChoicesNumbered.push_back(convertedString);

		fileString.erase(0, pos + CHOICES.length());
	}
}