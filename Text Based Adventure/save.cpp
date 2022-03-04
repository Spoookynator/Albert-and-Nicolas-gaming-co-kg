#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include "save.h"
#include "inventory.h"
#include "debugLog.h"
#include "coloredText.h"
#include "init.h"
#include "endingPoints.h"
#include "dialogue.h"


std::vector<int> savedUserChoicesNumbered = {};

const std::string INVENTORY = "%";
const std::string CHOICES = "&";
const std::string FILENAME = "saveFile.dat";


void LOAD()
{

	const std::string FILE_STRING = openFile("one");
	const std::string FILE_LINE_TWO = openFile("two");
	const std::string FILE_LINE_TREE = openFile("three");
	const std::string FILE_LINE_FOUR = openFile("four");

	if (FILE_STRING == "Error")
	{
		char temp;
		color("Unable to open Save File! It might not exist, or be renamed! Do you want to save now? Y/N\n", "dred");
		std::cin >> temp;

		// clear cin since it had problems with implementing in other files
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		 
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
	loadScene(FILE_LINE_TWO);
	loadPoints(FILE_LINE_TREE);
	loadPoints(FILE_LINE_FOUR);


	std::cout << "Save file successfully loaded!" << std::endl;
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

	// scene
	newSaveFile << "\n";
	newSaveFile << currentScene << "\n";

	newSaveFile << endingPoints << "\n";

	newSaveFile << defaultTextSpeed;

	newSaveFile.close();
	std::cout << "Done!\n";
}

std::string openFile(std::string line)
{
	std::string fileString;
	std::ifstream loadFile;
	std::string lineTwo;
	std::string lineThree;
	std::string lineFour;

	// opens file, if possible
	loadFile.open(FILENAME);
	if (loadFile.is_open())
	{

		std::getline(loadFile, fileString);
		std::getline(loadFile, lineTwo);
		std::getline(loadFile, lineThree);
		std::getline(loadFile, lineFour);


	if (line == "one")
		return fileString;
	else if (line == "two")
		return lineTwo;
	else if (line == "three")
		return lineThree;
	else if (line == "four")
		return lineFour;


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

void loadPoints(std::string fileString)
{
	int convertedString = 0;

	// converts string to int
	std::stringstream stringToInt(fileString);
	stringToInt >> convertedString;

	endingPoints = convertedString;
}

void loadScene(std::string fileString)
{
	int convertedString = 0;

	// converts string to int
	std::stringstream stringToInt(fileString);
	stringToInt >> convertedString;

	currentScene = convertedString;
} 

void loadDefaultTextSpeed(std::string fileString)
{
	int convertedString = 0;

	// converts string to int
	std::stringstream stringToInt(fileString);
	stringToInt >> convertedString;

	defaultTextSpeed = convertedString;
}