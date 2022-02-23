#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "inventory.h"
#include "debugLog.h"

// editInventory options: (inventory to change, item name, "add" or "remove")
std::vector<std::string> inventory; 


void addToInventory(std::string name)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (name == inventory.at(i))
		{
			inventory.erase(inventory.begin() + i);
			break;
		}
	}
	inventory.push_back(name);
}

void removeFromInventory(std::string name)
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

void outputInventory()
{
	if (inventory.empty() == true)
	{
		std::cout << "Your bag is empty...";
	}
	else
	{
		std::cout << "You take a look inside your bag and find: ";
		for (int i = 0; i < inventory.size(); i++)
		{
			std::cout << inventory.at(i);
			if (i < inventory.size() - 1)
			{
				std::cout << ", ";
			}
			if (i == inventory.size() - 1)
			{
				std::cout << ".";
			}

		}
	}

	std::cout << "\n";
}


bool inventoryCheckFor(std::string name)
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
