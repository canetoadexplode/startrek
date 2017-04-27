// medical.hpp

#pragma once
#include "space.hpp"

class Medical : public Space{
	private:
		bool isIntruder;
		bool isPhaser;
	public:
		Medical(std::string n, std::string lleft, std::string lright, 
			std::string lfront, std::string lback, bool i, bool p);
		int phaserMenu();
		int intruderMenu();
		void menu(Player* player)override;

};
