//main

#include "space.hpp"
#include "bridge.hpp"
#include "jefferies.hpp"
#include "medical.hpp"
#include "tenforward.hpp"
#include "engineering.hpp"
#include "player.hpp"
#include "common.hpp"
#include <string>
#include <iostream>
#include <unistd.h>
using namespace std;

const int DELAY = 40000;

int runSim()
{
	string response;

	while(response != "y" || response != "n"){
		cout << endl;
		slow_print("Would you like to start a game? (y/n)", DELAY);
		getline(cin, response);

		if(response == "y"){
			return 1;
		}
		else if(response == "n"){
			cout << endl;
			slow_print("Ok, bye!", DELAY);
			return 0;
		}
		else{
			cout << endl;
			slow_print("Invalid response. Byee! ", DELAY);
			return 0;
		}
	}

	return 0;
}

void statusReport(Player player)
{
	cout << "~~~~~~~~~~~~~~~~~~~~ " << endl;
	slow_print(("You are in " + player.getLocation()->getName() + "."), DELAY);
	slow_print(("Your pockets contain: " + player.getPocket1() + " and " + player.getPocket2()), DELAY);
	cout << "~~~~~~~~~~~~~~~~~~~~ " << endl;
}

int main(){

	cout << endl;
	slow_print("Welcome to Helen's Final Project/Game! ", DELAY);

	while(runSim() == 1){

		Space* bridge = new Bridge("The Bridge", "the comm", "the turbolift", 
				"the viewscreen", "a hatch", false);
		Space* j1 = new Jefferies("Jefferies Tube- Section 1-B", "a smooth wall", 
				"a smooth wall", "the ladder", "a hatch");
		Space* j2 = new Jefferies("Jefferies Tube- Section 2-B", "a smooth wall", 
				"a smooth wall", "the ladder", "a hatch");
		Space* medical = new Medical("The Medical Bay", "a hospital bed. It seems like "
				"a security officer is recovering there",
				"an intruder!", "Dr. Crusher", "a hatch", true, true);
		Space* j3 = new Jefferies("Jefferies Tube- Section 3-B", "a smooth wall",
				"a smooth wall", "the ladder", "a hatch");
		Space* ten = new TenForward("Ten Forward", "nothing really, just "
				"empty tables", 
				"nothing really, just empty tables", 
				"Guinan is tending bar", "a hatch");
		Space* j4 = new Jefferies("Jefferies Tube- Section 4-A", "a smooth wall", 
				"a smooth wall", "the ladder", "a smooth wall");
		Space* j5 = new Jefferies("Jefferies Tube Section 5-B", "a smooth wall", 
				"a smooth wall", "the ladder", "a hatch");
		Space* engineering = new Engineering("Engineering", "Jordi", 
				"the Warp Core. It looks a little dim.", "nothing much.", 
				"a hatch");

		bridge->setUp(nullptr);
		bridge->setDown(nullptr);
		bridge->setFront(nullptr);
		bridge->setBack(j1);

		j1->setUp(nullptr);
		j1->setDown(j2);
		j1->setFront(nullptr);
		j1->setBack(bridge);

		j2->setUp(j1);
		j2->setDown(j3);
		j2->setFront(nullptr);
		j2->setBack(medical);

		medical->setUp(nullptr);
		medical->setDown(nullptr);
		medical->setFront(nullptr);
		medical->setBack(j2);

		j3->setUp(j2);
		j3->setDown(j4);
		j3->setFront(nullptr);
		j3->setBack(ten);

		ten->setUp(nullptr);
		ten->setDown(nullptr);
		ten->setFront(nullptr);
		ten->setBack(j3);

		j4->setUp(j3);
		j4->setDown(j5);
		j4->setFront(nullptr);
		j4->setBack(nullptr);

		j5->setUp(j4);
		j5->setDown(nullptr);
		j5->setFront(nullptr);
		j5->setBack(engineering);

		engineering->setUp(nullptr);
		engineering->setDown(nullptr);
		engineering->setFront(nullptr);
		engineering->setBack(j5);

		Player player = Player(bridge, "Nothing", "Nothing", true);

		// Here is where the menus start

		cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
		slow_print("Captains Log: Star Date 32623.5", DELAY);
		slow_print("We are in a state of red alert.", DELAY);
		slow_print("There has been a failure in the warp core. Cause unknown. ", DELAY);
		slow_print("While Jordi works to repair it, we are running minimal life support. ", DELAY);
		slow_print("We have taken damage, and internal sensors are inoperable. ", DELAY);
		slow_print("We cannot determine the extent of the damage, or how it was inflicted. ", DELAY);
		slow_print("Before the shutdown, there were indications of intruders on board. ", DELAY);
		slow_print("It is imperative that we get the engines back on line. ", DELAY);
		slow_print("I have dispatched Data to search the ship for a dilithium crystal and bring it to Jordi on the Engineering Deck. ", DELAY);
		slow_print(". . .", DELAY);
		slow_print("Data, make it so. ", DELAY);
		cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
		slow_print(". . .", DELAY);
		cout << "~~~~~~~~~~~~~~~~~~~~" << endl;	
		slow_print("Game Instructions: Use the menus to navigate through the ship. ", DELAY);
		slow_print("You must find the dilithium crystal, and bring it to Jordi on the Engineering deck. ", DELAY);
		slow_print("You only have two pockets, each can hold one item. ", DELAY);
		slow_print("You have 100 turns to complete the game. ", DELAY);
		cout << "~~~~~~~~~~~~~~~~~~~~ " << endl;
		cout << endl;
		
		int counter = 0;
		while(player.getRedAlert()){
			statusReport(player);
			player.getLocation()->menu(&player);
			counter ++;
			if(counter == 100){
				cout << endl;
				cout << "Time's up!" << endl;
				return 0;
			}
		}
		delete bridge;
		delete medical;
		delete ten;
		delete engineering;
		delete j1;
		delete j2;
		delete j3;
		delete j4;
		delete j5;
	}

return 0;
}





