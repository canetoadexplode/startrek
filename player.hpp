// player.hpp

#pragma once
#include "space.hpp"
#include <string>

class Player{
	private:
		std::string pocket1;
		std::string pocket2;
		Space* location;
		bool redAlert;
	public:
		Player(Space* l, std::string one, std::string two, bool r);
		void moveUp();
		void moveDown();
		void moveFront();
		void moveBack();
		void setPocket1();
		void setPocket2();
		std::string getPocket1();
		std::string getPocket2();
		Space* getLocation();
		void setLocation(Space* l);
		bool getRedAlert();
		void setRedAlert(bool r);

		
};
