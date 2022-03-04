#pragma once
#include <iostream>
#include "variables.h"

void narration(std::string);

void dialogue(std::string name, std::string text, std::string nameColor = "default", std::string textColor = "default", int textSpeed = defaultTextSpeed);

void output(std::string text, int textSpeed = defaultTextSpeed, bool dotPause = true);

void newLine(int lines = 1, int delay = defaultTextSpeed * 26);

void fillLine(char character, int spaces = 0);

void s(int sleep = defaultTextSpeed * 30);

void title(std::string title);