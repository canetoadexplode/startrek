// medical.cpp

#include "medical.hpp"
#include "common.hpp"
#include "player.hpp"
#include <iostream>
using namespace std;

Medical::Medical(std::string n, std::string lleft, std::string lright, 
		std::string lfront, std::string lback, bool i, bool p)
{
	name = n;
	lookLeft = lleft;
	lookRight = lright;
	lookFront = lfront;
	lookBack = lback;
	isIntruder = i;
	isPhaser = p;
}

int Medical::phaserMenu()
{
	int response;
	cout << endl;
	cout << "Your choices are:" << endl;
	cout << "1) Speak to the security officer" << endl;
	cout << "2) Back." << endl;

	while(true){
		response = getNumber(0, 3);
		return response;
	}
}

int Medical::intruderMenu()
{
	if(isPhaser){
		cout << "You're not equipped for this yet" << endl;
		return -1;
	}
	else{
		int response;
		cout << endl;
		cout << "Your choices are:" << endl;
		cout << "1) Shoot the intruder" << endl;
		cout << "2) Back." << endl;

		while(true){
			response = getNumber(0, 3);
			return response;
		}
	}
}

void Medical::menu(Player* player)
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
		// phaser menu
		if(isPhaser){
			int response = phaserMenu();
			if(response == 1){
				cout << "The security officer hands you his phaser." << endl;
				cout << "You've acquired the phaser!" << endl;
				player->setPocket1();
				isPhaser = false;
			}
		}
		else{
			cout << "He's fallen back asleep." << endl;
		}
	}
	else if(response == 6){
		// intruder menu
		if(isIntruder){
			int response = intruderMenu();
			if(response == 1){
				cout << "You set your phaser to maximum and shoot" 
					<< " the intruder." << endl;
				cout << ".....it works! He's down." << endl;
				isIntruder = false;
			}
		}
		else{
			cout << "...was that? ...is he twitching?" << endl;
			cout << "Probably not. Let's just get out of here" << endl;
		}
	}
	else if(response == 7){
		if(isPhaser){
			cout << "Dr.Crusher: Data, you've got to find the phaser "
				<< "in the room and shoot the intruder!" << endl;
		}
		else{
			if(isIntruder){
				cout << "Dr. Crusher: 'Data, shoot the intruder!" 
					<< endl;
			}
			else{
				cout << "Dr.Crusher: 'Data, you've got to find the "
					<< "crystal and get it to Jordi!" << endl;
			}
		}
	}
	else if(response == 8){
		cout << "You enter the jefferies tube" << endl;
		player->setLocation(back);

	}
}
