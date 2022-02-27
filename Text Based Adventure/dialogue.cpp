#include <iostream>
#include <chrono>
#include <windows.h>
#include "dialogue.h"
#include "coloredText.h"

void narration(std::string input)
{
	color("|" + input, "grey");
	std::cout << std::endl;
	Sleep(1000);
}
	

void dialogue(std::string name, std::string text, std::string nameColor, std::string textColor)
{
	color(name, nameColor);
	std::cout << ": ";
	color(text, textColor);
	std::cout << std::endl;
}

void output(std::string text)
{
	std::cout << text;
}

void newLine(int sleep)
{
	std::cout << std::endl;
	Sleep(sleep);
}

void s()
{
	Sleep(1500);
}