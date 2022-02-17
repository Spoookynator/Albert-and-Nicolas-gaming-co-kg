#include "dialogue.h"
#include <iostream>
#include "coloredText.h"

void narration(std::string input)
{
	color("|" + input, "grey");
	std::cout << std::endl;
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

void newLine()
{
	std::cout << std::endl;
}