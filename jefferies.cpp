// jefferies.cpp

#include "jefferies.hpp"
#include "player.hpp"
#include "common.hpp"
#include <iostream>
using namespace std;

Jefferies::Jefferies(std::string n, std::string lleft, std:: string lright, 
		std::string lfront, std::string lback)
{
	name = n;
	lookLeft = lleft;
	lookRight = lright;
	lookFront = lfront;
	lookBack = lback;
}
int jefferiesMenu()
{
	int response;

	cout << endl;
	cout << "Your choices are: " << endl;
	cout << "1) Look left." << endl;
	cout << "2) Look right." << endl;
	cout << "3) Look front." << endl;
	cout << "4) Look back." << endl;
	cout << "5) Move up" << endl;
	cout << "6) Move down" << endl;
	cout << "7) Move front." << endl;
	cout << "8) Move back." << endl;

	while(true){
		response = getNumber(0, 9);
		return response;
	}
}

void Jefferies::menu(Player* player)
{
	int response = jefferiesMenu();
	if(response == 1){
		cout << "You see " << player->getLocation()->getLookLeft() << endl;
	}
	else if(response == 2){
		cout << "You see " << player->getLocation()->getLookRight() << endl;
	}
	else if(response == 3){ 
		cout << "You see " << player->getLocation()->getLookFront() << endl;
	}
	else if(response == 4){
		cout << "You see " << player->getLocation()->getLookBack() << endl;
	}
	else if(response == 5){
		if(up == nullptr){
			cout << "Behind this hull is the cold void of space. Let's not." 
				<< endl;
		}
		else{
			cout << "You climb up the ladder" << endl;
			player->setLocation(player->getLocation()->getUp());
		}
	}
	else if(response == 6){
		if(down == nullptr){
			cout << "Damage to the ships hull has collapsed this part of the tube."
			       	<< endl; 
		}
		else{
			cout << "You climb down the ladder" << endl; 
			player->setLocation(player->getLocation()->getDown());
		}
	}
	else if(response == 7){
		cout << "Nowhere to go here" << endl;
	}
	else if(response == 8){
		if(back == nullptr){
			cout << "Nowhere to go here" 
				<< endl;
		}
		else{
			cout << "You enter the hatch" << endl;
			player->setLocation(player->getLocation()->getBack());
		}
	}	
}
