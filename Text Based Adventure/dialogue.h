#pragma once
#include <iostream>

extern int defaultTextSpeed;

void narration(std::string);

void dialogue(std::string name, std::string text, std::string nameColor = "default", std::string textColor = "default", int textSpeed = 50);

void output(std::string text, int textSpeed = 50, bool dotPause = true);

void newLine(int lines = 1, int delay = 1300);

void fillLine(char character);

void s(int sleep = 1500);

void title(std::string title);