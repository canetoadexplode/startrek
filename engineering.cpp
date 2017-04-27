// engineering.cpp

#include "engineering.hpp"
#include "common.hpp"
#include "player.hpp"
#include <iostream>
using namespace std;

Engineering::Engineering(std::string n, std::string lleft, std::string lright, 
		std::string lfront, std::string lback)
{
	name = n;
	lookLeft = lleft;
	lookRight = lright;
	lookFront = lfront;
	lookBack = lback;
}

int Engineering::coreMenu()
{
	int response;
	cout << endl;
	cout << "1) Place the crystal in the warp core" << endl;
	cout << "2) Back." << endl;

	while(true){
		response = getNumber(0, 3);
		return response;
	}
}

void Engineering::menu(Player* player)
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
		if(player->getPocket2() == "Nothing"){
			cout << "Data- you've got to get that crystal, fast!" << endl;
		}
		else{
			cout << "Jordi: 'Oh thank goodness you've found it! Listen, "
				<< "Data- I've been attacked. I lost my visor in the "
				<< "struggle. You'll have to place the crystal yourself." 
				<< endl;
		}
	}
	else if(response == 6){
		if(player->getPocket2() == "Nothing")
			cout << "Nothing to do here. Once you give the crystal to Jordi- "
				<< "he can fix this." << endl;
		else{
			int response = coreMenu();
			if(response == 1){
				cout << "Picard: 'Picard to Data'" << endl;
				cout << "Go ahead, Captain" << endl;
				cout << "Picard: 'Data, you've done it! You have my sincere "
					<< "gratitude.'" << endl;
				cout << "Thank you, Captain. I will return to my " 
					<< "station at once." << endl;
				cout << endl;
				cout << "Computer, end program." << endl;
				player->setRedAlert(false);
				player->setLocation(back);
			}
		}
	}
	else if(response == 7){
		cout << "Nothing to do here." << endl;
	}
	else if(response == 8){
		cout << "You enter the jefferies tube" << endl;
		player->setLocation(back);
	}
}
