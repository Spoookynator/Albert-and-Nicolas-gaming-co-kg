#include <iostream>
#include <chrono>
#include <windows.h>
#include <string>
#include "dialogue.h"
#include "coloredText.h"
#include <mmsystem.h>

void narration(std::string input)
{
	color("|" + input, "grey");
	std::cout << std::endl;
	Sleep(1000);
}
	

void dialogue(std::string name, std::string text, std::string nameColor, std::string textColor, int textSpeed)
{
	color(name, nameColor, textSpeed);
	std::cout << ": ";
	color(text, textColor, textSpeed);
	std::cout << std::endl;
}

void output(std::string text, int textSpeed, bool dotPause)
{
	int x = 0;
	while (text[x] != '\0')
	{
		std::cout << text[x];
		if (text[x] == ',') Sleep(textSpeed * 2);
		if (text[x] == '.' && dotPause == true) Sleep(500 + (500 / textSpeed) * 20);
		Sleep(textSpeed);
		x++;
	}
}

void newLine(int lines, int delay)
{
	Sleep(delay);
	for (int i = 0; i < lines; i++)
	{
		std::cout << "\n";
	}
}

void title(std::string title)
{
	// fills line with '_'
	for (int i = 0; i < 120; i++)
	{
		std::cout << "_";
		Sleep(10);
	}
	std::cout << "\n" << std::endl;

	// centers the string in the middle
	int middle = 60 - title.length() / 2;
	
	// empty lines
	for (int i = 0; i < middle; i++)
	{
		std::cout << " ";
	}
	// puts title in the middle
	int x = 0;
	while (title[x] != '\0')
	{
		std::cout << title[x];
		Sleep(100);
		x++;
	}

	std::cout << std::endl;
	// fills line again
	for (int i = 0; i < 120; i++)
	{
		std::cout << "_";
		Sleep(10);
	}
	std::cout << "\n" << std::endl;
}
void fillLine(char character)
{
	for (int i = 0; i < 120; i++)
	{
		std::cout << character;
		Sleep(10);
	}
	std::cout << "\n" << std::endl;
}
void s(int sleep)
{
	Sleep(sleep);
}