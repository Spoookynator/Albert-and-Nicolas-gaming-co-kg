#include "..\..\userInput.h"
#include "..\..\dialogue.h"
#include "..\..\coloredText.h"
#include "..\..\init.h"
// Objects/Keywords in scene 1
Object tv(1, "TV", "It's your old TV. Looks like can it can be turned on", false, "You turn on the TV, it's flickering and producing nothing but white noise. Suddenly, the news channel turns on.");
Keyword k_tv(false, { "television", "television,", "television.", "television!", "television?", "tv", "tv,", "tv.", "tv!", "tv?" });

//scene 2
Object waterbottle(2, "Water bottle", "Your favourite water bottle.The water looks so juicy right now. \nYour thoughts fill with the urge to drink from it", false, "You start jugging the water like crazy, gobbling down all of it as fast as you can.");
Keyword k_waterbottle(false, { "waterbottle", "waterbottle,", "waterbottle.", "waterbottle!", "waterbottle?", "bottle", "bottle,", "bottle.", "bottle!", "bottle?" });

void intro()
{
	// sets scene at the beginning
	currentScene = 3;
	// ---------------------------

	// question if user wants to load save or start new one


	// SCENE 1 //
	if (currentScene == 1)
	{
		title("Your Room");

		output("You wake up...", 250); newLine(2);

		output("It's still dark outside."); newLine(2);

		output("You hear the damp sound of thick raindrops splashing against your window. \nIt's the same as back then..."); newLine(2);

		output("Your mom has nightshift today, you are all alone. You can't help but reminisce about the past.\nThe day your father went to buy milk, but never returned."); newLine(2);

		output("It's a painful memory."); newLine(2);

		output("You can remember the days after, you still had faith in him. \nEvery day you and your mom peeked outside your unbelievably small, disgusting, apartment, in hope that he would return."); newLine(2);

		output("But he never did.", 100); newLine(2);

		output("After that, your mom started coming home late."); newLine(2);

		fillLine('-');

		output("The overpowering smell of used tissues fills your nose. "); newLine(2);

		color("It's disgusting.", "dred", 250); newLine(2);

		output("The reason your dad left you is starting to become clearer to you now."); newLine(2);

		output("Maybe your bad hygiene made him reject you?"); newLine(2);

		output("You slowly crawl out of bed and immediately notice your trusty "); color("TV", "yellow"); output(" standing on a small cardboard box, \nat the opposite side of the room. "); newLine(2);

		output("It always helped you distract yourself from reality."); newLine(2); 

		output("Maybe you should "); color("turn it on", "cyan"); output(" and see whats on the news!"); newLine(2);

		// stops until user TURNS ON the TV or INTERACTS with it
		while (tv.getInteracted() == false)
		{
			userComandInterface();
		}
		newLine();

		currentScene = 2;
	}
	if (currentScene == 2)
	{
		output("You hear a female voice echoeing from the telly: "); newLine(2);

		fillLine('.');
		output("\"It is 10pm on this Saturday the 10th of March 2033, and you are watching BOX NEWS.\"", 20, false); newLine(2);

		output("\"I am your host of tonights show, Margret Thatcher!\"", 20, false); newLine(2);

		output("* BOX NEWS MELODY *", 125); newLine(2);
		output("\"The evacuation of our beloved nation is still in process.\"", 20, false); newLine(2);
		output("\"As of right now, about 80% of Mokokoians have made it onto the ", 20); color("SS Mokoko", "green", 275); output(" and-\"");  newLine(2);
		fillLine('.');

		color("*buzz*  *zap*", "dred", 20); newLine(2);

		output("The TV abruptly shuts down, accompanied by a loud zapping noise"); newLine(2);

		output("An intense, stinging pain shoots in your head, as if a hammer just swung down on you!");  newLine();
		output("You start feeling dizzy and your surroundings start to melt into a wobbling mess.\nYou try to stop yourself from loosing concousness, but your quickly loose your strength and feel your body \ngetting heavier by the second."); newLine(2);

		output("In this state of continuos cumbrain, you see a "); color("water bottle ", "yellow"); output("sitting on your desk. "); newLine(2);

		output("Your vision starts to get blurry. You desperatly want to slurp all of the water in hope, \nthat it will make you feel better."); newLine(2);

		fillLine('>', 1);
		while (waterbottle.getInteracted() == false)
		{
			userComandInterface();
		}
		newLine();
	
		output("You feel refreshed. But only for a brief moment.\nYou start to flounder, slowly loosing more of your consciousness until you start to tumble, \nstubbing your toe on your desk in the process and falling to the ground");

		currentScene = 3;
	}
}