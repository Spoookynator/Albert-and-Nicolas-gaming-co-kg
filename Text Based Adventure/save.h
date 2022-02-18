#pragma once
#include <vector>

extern std::vector<int> savedUserChoicesNumbered;
extern const std::string INVENTORY;
extern const std::string CHOICES;
extern const std::string FILENAME;
extern std::fstream saveFile;

void SAVE();

void LOAD();

void loadInventory(std::string fileString);

void loadChoices(std::string fileString);

std::string openFile();