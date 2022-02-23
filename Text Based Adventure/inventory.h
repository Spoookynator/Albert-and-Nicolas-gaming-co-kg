#pragma once
#include <iostream>
#include <vector>

extern std::vector<std::string> inventory;

void outputInventory();
void addToInventory(std::string name);
void removeFromInventory(std::string name);
bool inventoryCheckFor(std::string name);
