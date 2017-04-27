// bridge.hpp

#pragma once
#include "space.hpp"

class Bridge : public Space{
	private:
		bool isOpen;
	public:
		Bridge(std::string n, std::string lleft, std::string lright, 
			std::string lfront, std::string lback, bool o);
		bool getIsOpen();
		void open();
		void close();
		void menu(Player* p) override;
};
