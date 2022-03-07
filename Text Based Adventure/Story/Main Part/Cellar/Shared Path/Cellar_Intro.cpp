#include "Cellar_Intro.h"
#include "..\..\..\..\userInput.h"
#include "..\..\..\..\dialogue.h"
#include "..\..\..\..\coloredText.h"
#include "..\..\..\..\init.h"


Object radio(3, "radio", "It’s an old radio. Doesn’t look like it still works, but who knows?", false, "You search for the on / off switch. After fondling it for a while, you hit the spotand turn it on. Luckily, the frequency is already perfectly tuned, and you start to hear a familiar voice.");
Keyword k_radio(false, { "radio", "radio,", "radio.", "radio!", "radio?" });

Object gascanister(3, "gascanister", "A gas canister. It smells like diesel. While inspecting it, you hit it with your foot and a metal sound echoes out of it. Maybe you should check inside it", false, "You open the canister and pour its contents out on the floor. With all the gas leaving the mechanism used to store car energy, there is also a key which makes a loud clinking sound as it hits the ground.");

Keyword k_gascanister(false, { "gascanister", "gascanister,", "gascanister.", "gascanister!", " gascanister?", "canister", "canister,", "canister.", "canister!", "canister?" });

Object key(4, "key", "A key. It’s has the smell of a gas-station. No wonder since it just came out of a gas canister. ", true, "You put the wet and disgusting key into your pocket. You are sure it will come in handy! ");
Keyword k_key(false, { "key", "key,", "key.", "key!", "key?" });

Object door(3, "door", "It's a door. It looks pretty old, but still sturdy.", false, "As you try to push down the hinge, you realizea that it is locked. You try to push down the door, but your weak arms can't handle it. There has to be a key somewhere.");
Keyword k_door(false, { "door", "door,", "door.", "door!", "door?" });

void cellarIntro()
{
	if (currentScene == 3)
	{
		// Intro + no key

		title("???");

		output("*an unknown amount of time later*"); newLine(3);

		output("You slowly start to open your eyes. Your head is hurting like someone just blasted\n10 hours of Deutsch-rap into your ears."); newLine(2);

		output("You take a deep breath. Immediately your lungs begin to sting and you feel the freezing air on your skin.\nYou don't know where you are, how you got here or what happened after you lost your grip on reality."); newLine(2);
		output("Slowly your eyes start to adjust to the darkness.\nYou hear lots of muffled noises.\nUnable to tell where they come from, you try to make out their origins."); newLine(2);
		
		color("You fail.", "dred", 250); newLine(2);
		output("After accepting your failure, you start slendering through this unknown environment, trying to make out where you are.\nAs you are walking around aimlessly, you run into a wall.\nYou let your hand run along the wall in hope to find something."); newLine(2);
		output("Luckily, your hand brushes against something sticking out from the wall.\nIt seems to be a light switch, but you aren't quite sure."); newLine(2);
		output("Do you want to try to flip the switch?\nYes[1] No[2]"); newLine(2, 0);
		
		int choice = 1;
		int iteration = 1;
		do
		{
			choice = userChoiceNumbered(2);

			if (choice == 2)
			{
				if (iteration == 1) output("Why wouldn't you want to flip the switch? Do you have a better idea?\n\n");
				else if (iteration == 2) output("Why are you so stubborn? You cant see anything, it's your only chance of escape!\n\n");
				else if (iteration == 3) output("You are freezing, you should probably try the switch and find a way outside!\n\n");
				else if (iteration > 3) output("... i give up. please, just turn on the light...\n\n"); 
			}
			

			iteration++;
		} while (choice == 2);
		
		if (iteration > 3) output("Thank God. You finally decide to flip the switch. I thought you were going to die in here..."); newLine(2);
		output("You flip the switch, expecting to finally see an explosion of light brighten up the room...");
		newLine(2);

		output("End of demo");
		/*
		while (gascanister.getInteracted() == false)
		{
			userComandInterface();
			if (radio.getInteracted() == true)
			{
				output("");
				radio.setInteracted(false);
			}
		}
		gascanister.setDescription("It's empty now.");
		gascanister.setInteracted("You turn the empty canister around and shake it vigorously. The last remainign drops get flung out of the contanier.");

		while (door.getInteracted() == false)
		{
			userComandInterface();
		}
		output("After quickly peeking ahead, you proceed through the door.");
		*/
	}
}