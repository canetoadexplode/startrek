// jefferies.hpp

#pragma once
#include "space.hpp"

class Jefferies : public Space{
	public:
		Jefferies(std::string n, std::string lleft, std:: string lright, 
				std::string lfront, std::string lback);
		void menu(Player*) override;
};
