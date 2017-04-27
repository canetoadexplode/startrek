// tenforward.hpp

#pragma once
#include "space.hpp"

class TenForward : public Space{
	private:
		bool hasOrderedCrystal = false;
	public:
		TenForward(std::string n, std::string lleft, std::string lright, 
			std::string lfront, std::string lback);
		void menu(Player* p) override;
		int guinanMenu();
};
