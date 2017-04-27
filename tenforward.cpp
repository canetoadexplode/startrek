// tenforward.cpp

#include "tenforward.hpp"
#include <iostream>
#include "player.hpp"
#include "common.hpp"
using namespace std;

TenForward::TenForward(std::string n, std::string lleft, std::string lright, 
		std::string lfront, std::string lback)
{
	name = n;
	lookLeft = lleft;
	lookRight = lright;
	lookFront = lfront;
	lookBack = lback;
}

int TenForward::guinanMenu()
{
	int response;
	cout << endl;
	cout << "Guinan: 'Hey there, Data. What'll it be?" << endl;
	cout << "1) Saurian Brandy" << endl;
	cout << "2) Raktajino" << endl;
	cout << "3) Deus ex machina (the house special)" << endl;
	cout << "4) Back." << endl;

	while(true){
		response = getNumber(0, 3);
		return response;
	}
}

void TenForward::menu(Player* player)
{
	int response = player->getLocation()->roomMenu();
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
		cout << "Nothing to do here." << endl;
	}
	else if(response == 6){
		cout << "Nothing to do here." << endl;
	}
	else if(response == 7){
		// guinan menu
		int response = guinanMenu();
		if(hasOrderedCrystal){
			cout << "Guinan: 'Don't you think you'd better get out of here?"
				<< endl;
		}
		else{
			if(response < 3){
				cout << "You take your drink. Unfortunately, you lack "
					<< "the adequate sensors to mimic human taste, "
					<< "and synthehol has no effect on your "
					<< "positronic circuitry." << endl;
			}
			if(response == 3){
				cout << "Guinan: 'I think I've got just what you need"
				       	<< endl;
				cout << "You have aqcuired the Dilithium Crystal!" << endl;
				player->setPocket2();
				hasOrderedCrystal = true;
			}

		}
	}
	else if(response == 8){
		cout << "You enter the jefferies tube" << endl;
		player->setLocation(back);
	}
}
