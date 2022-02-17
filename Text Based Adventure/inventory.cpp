#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "inventory.h"
#include "debugLog.h"

// editInventory options: (inventory to change, item name, "add" or "remove")
std::vector<std::string> inventory; 

void editInventory(std::vector<std::string>& inventory, std::string name, std::string option)
{
	if (option == "add")
	{
		inventory.push_back(name);
	}
	else if (option == "remove")
	{
		// checks if item name == inventory name for every slot. When its the same, delete the entry.
		for (int i = 0; i < inventory.size(); i++)
		{
			if (name == inventory.at(i))
			{
				inventory.erase(inventory.begin() + i);
				break;
			}
			// if item to be deleted not found
			if (i == inventory.size() - 1)
			{
				LOG("No \"" + name + "\" in Inventory.\n");
			}
		}
	}

}

void outputInventory(std::vector<std::string>& vector)
{
	std::cout << "Inventory contains: ";
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector.at(i);
		if (i < vector.size() - 1)
		{
			std::cout << ", ";
		}
		if (i == vector.size() - 1)
		{
			std::cout << ".";
		}

	}
	std::cout << "\n";
}

void saveOrLoadInventory(std::vector<std::string>& inventory, std::string option)
{

	if (option == "save")
	{
		std::ofstream SaveFile;
		SaveFile.open("saveFile.txt");

		for (int i = 0; i < inventory.size(); i++)
		{
			SaveFile << inventory.at(i);
			if (i < inventory.size())
			{
				SaveFile << "\n";
			}
		}
		SaveFile.close();
	}
	else if (option == "load")
	{
		std::fstream LoadFile;
		LoadFile.open("saveFile.txt");

		inventory.clear();
		std::string line;
		while (std::getline(LoadFile, line))
		{
			editInventory(inventory, line, "add");
		}
		LoadFile.close();
	}
}

bool inventoryCheckFor(std::vector<std::string>& inventory, std::string name)
{
	// checks if item name == inventory name for every slot. When its the same, then true
	for (int i = 0; i < inventory.size(); i++)
	{
		if (name == inventory.at(i))
		{
			LOG("inventoryCheckFor(" + name + ") = TRUE");
			return true;
		}

	}
	LOG("inventoryCheckFor(" + name + ") = FALSE");

	return false;
}
