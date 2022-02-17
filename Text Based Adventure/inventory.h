#pragma once
#include <iostream>
#include <vector>

extern std::vector<std::string> inventory;

void outputInventory(std::vector<std::string>& v);
void editInventory(std::vector<std::string>& inventory, std::string name, std::string option);
void saveOrLoadInventory(std::vector<std::string>& inventory, std::string option);
bool inventoryCheckFor(std::vector<std::string>& inventory, std::string name);
