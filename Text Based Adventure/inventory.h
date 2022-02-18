#pragma once
#include <iostream>
#include <vector>

extern std::vector<std::string> inventory;

void outputInventory(std::vector<std::string>& v);
void editInventory(std::string name, std::string option);
bool inventoryCheckFor(std::string name);
