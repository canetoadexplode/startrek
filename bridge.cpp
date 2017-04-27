//bridge.cpp

#include "bridge.hpp"
#include "common.hpp"
#include <iostream>
#include "player.hpp"
using namespace std;

Bridge::Bridge(std::string n, std::string lleft, std::string lright, 
		std::string lfront, std::string lback, bool o)
{
	name = n;
	lookLeft = lleft;
	lookRight = lright;
	lookFront = lfront;
	lookBack = lback;
	isOpen = o;
		
}
bool Bridge::getIsOpen()
{
	return isOpen;
}

void Bridge::open()
{
	isOpen = true;
}

void Bridge::close()
{
	isOpen = false;
}

int comMenuOpen()
{
	int response;
	cout << endl;
	slow_print("Your choices are:", 35000);
	cout << "1) Close the hailing frequency." << endl;
	cout << "2) Back." << endl;

	while(true){
		response = getNumber(0, 3);
		return response;
	}
}

int comMenuClosed()
{
	int response;
	cout << endl;
	slow_print("Your choices are:", 35000);
	cout << "1) Open a hailing frequency." << endl;
	cout << "2) Back." << endl;

	while(true){
		response = getNumber(0, 3);
		return response;
	}
}

void Bridge::menu(Player* player)
{
	int response = roomMenu();

	if(response == 1){
	  	 slow_print(menuChoice(1), 35000);
		slow_print(("You see " + player->getLocation()->getLookLeft()), 35000);
	}
	else if(response == 2){
	  	 slow_print(menuChoice(2), 35000);
		slow_print(("You see " + player->getLocation()->getLookRight()), 35000);
	}
	else if(response == 3){ 
	  	 slow_print(menuChoice(3), 35000);
		slow_print(("You see " + player->getLocation()->getLookFront()), 35000);
	}
	else if(response == 4){
	  	 slow_print(menuChoice(4), 35000);
		slow_print(("You see " + player->getLocation()->getLookBack()), 35000);
	}
	else if(response == 5){
	  	 slow_print(menuChoice(5), 35000);
		// com menu
		if(getIsOpen()){
			int response = comMenuOpen();
			if(response == 1){
			  	slow_print("You signal the comm off", 35000);
				slow_print("Frequency is closed, sir", 35000);
				close();
			}
		}
		else{
			int response = comMenuClosed();
			if(response == 1){
			slow_print("A channel is open...No response, sir", 35000);
			open();
			}
		}
	}
	else if(response == 6){
	  	 slow_print(menuChoice(6), 35000);
		slow_print("The turbolift is jammed.", 35000); 
	}
	else if(response == 7){
	  	slow_print(menuChoice(7), 35000);
		slow_print("Nothing to do here", 35000);
	}
	else if(response == 8){
	  	slow_print(menuChoice(8), 35000);
		slow_print("You enter the jefferies tube", 3500);
		player->setLocation(back);
	}
}

