// engineering.hpp

#pragma once
#include "space.hpp"

class Engineering : public Space{
	private:
	public:
		Engineering(std::string n, std::string lleft, std::string lright, 
			std::string lfront, std::string lback);
		int coreMenu();
		void menu(Player* player)override;
};
