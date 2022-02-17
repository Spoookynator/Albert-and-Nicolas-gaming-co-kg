#pragma once
#include <iostream>
#include "coloredText.h"

void narration(std::string);

void dialogue(std::string name, std::string text, std::string nameColor = "default", std::string textColor = "default");

void output(std::string text);

void newLine();