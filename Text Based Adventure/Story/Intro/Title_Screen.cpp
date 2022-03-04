#include <Windows.h>
#include "Title_Screen.h"
#include "..\..\dialogue.h"
#include "..\..\userInput.h"
#include "..\..\variables.h"
#include "..\..\save.h"

void titleScreen()
{
	
	short int menuChoice;

	do
	{
		system("cls");

		newLine(8, 0);
		output("                        ___       _,.---._      ,--.-.,-.      _,.---._      ,--.-.,-.      _,.---._     ", 0); newLine(1, 1);
		output("                 .-._ .'=.'\\    ,-.' , -  `.   /==/- |\\  \\   ,-.' , -  `.   /==/- |\\  \\   ,-.' , -  `.   ", 0); newLine(1, 1);
		output("                /==/ \\==|  |  /==/_,  ,  -  \\  |==|_ `/_ /  /==/_,  ,  - \\  |==|_ `/_ /  /==/_,  ,  - \\  ", 0); newLine(1, 1);
		output("                |==|,|  / - | |==|   .=.     | |==| ,   /  |==|   .=.     | |==| ,   /  |==|   .=.     | ", 0); newLine(1, 1);
		output("                |==|  \\/  , | |==|_ : ;=:  - | |==|-  .|   |==|_ : ;=:  - | |==|-  .|   |==|_ : ;=:  - | ", 0); newLine(1, 1);
		output("                |==|- ,   _ | |==| , '='     | |==| _ , \\  |==| , '='     | |==| _ , \\  |==| , '='     | ", 0); newLine(1, 1);
		output("                |==| _ /\\   |  \\==\\ -    ,_ /  /==/  '\\  |  \\==\\ -    ,_ /  /==/  '\\  |  \\==\\ -    ,_ /  ", 0); newLine(1, 1);
		output("                /==/  / / , /   '.='. -   .'   \\==\\ /\\=\\.'   '.='. -   .'   \\==\\ /\\=\\.'   '.='. -   .'   ", 0); newLine(1, 1);
		output("                `--`./  `--`      `--`--''      `--`           `--`--''      `--`           `--`--''     ", 0); newLine(2, 1);


		output("                   .-------------.        ", 0); output(".-------------.        ", 0); output(".---------------.        ", 0); output(".---------.\n", 0); 
		output("                   | Continue[1] |        ", 0); output("| New Game[2] |        ", 0); output("| Text Speed[3] |        ", 0); output("| Quit[4] |\n", 0);
		output("                   '-------------'        ", 0); output("'-------------'        ", 0); output("'---------------'        ", 0); output("'---------'\n", 0);



		menuChoice = 0;
		menuChoice = userChoiceNumbered(4);
		
		if (menuChoice == 1)
		{
			LOAD();
			s(2000);
			system("cls");
		}
		else if (menuChoice == 2)
		{
			output("Do you really want to start a new game? Your old save will be deleted!"); newLine();
			output("Yes[1] No[2]"); newLine(2, 0);

			int choice2 = userChoiceNumbered(2);

			if (choice2 == 1)
			{
				SAVE();
				s(2000);
				system("cls");
			}
			else
			{
				menuChoice = 4;
			}
		}
		else if (menuChoice == 3)
		{

			int redoChoice = 0;
			int textSpeedChoice = 0;
			do
			{
				output("Which text speed do you want to choose: \n");
				output("Slow [1]  Default[2]  Fast[3]"); newLine(2, 0);

				textSpeedChoice = userChoiceNumbered(3);

				if (textSpeedChoice == 1)
				{
					defaultTextSpeed = 80;
					output("This, is the slow text speed.\n"); 
					output("Do you want to continue with the slow text speed?\n");
					output("Yes[1] No[2]"); newLine(2, 0);

					redoChoice = userChoiceNumbered(2);
				}
				else if (textSpeedChoice == 2)
				{
					defaultTextSpeed = 50;
					output("This, is the default text speed.\n");
					output("Do you want to continue with the default text speed?\n");
					output("Yes[1] No[2]"); newLine(2, 0);

					redoChoice = userChoiceNumbered(2);

				}
				else if (textSpeedChoice == 3)
				{
					defaultTextSpeed = 20;
					output("This, is the fast text speed.\n");
					output("Do you want to continue with the fast text speed?\n");
					output("Yes[1] No[2]"); newLine(2, 0);

					redoChoice = userChoiceNumbered(2);
				}

			} while (redoChoice == 2);
		}
		else
			{
				exit(EXIT_SUCCESS);
			}
	} while (menuChoice >= 3);

}