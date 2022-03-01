#include "app.h"
#include "storyLinker.h"
#include "coloredText.h"
#include "windows.h"
using namespace std;

void runApp()
{
	HANDLE hInput;
	DWORD prev_mode;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));

	color("ds", "hwhite");
	linkedStory();
}
