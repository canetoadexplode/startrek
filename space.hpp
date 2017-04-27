// space.hpp

#pragma once
#include <string>

class Player;
class Space{
	protected:
		Space* up;
		Space* down;
		Space* front;
		Space* back;
		std::string name;
		std::string lookLeft;
		std::string lookRight;
		std::string lookFront;
		std::string lookBack;
	public:
		virtual ~Space(){}
		Space* getUp();
		Space* getDown();
		Space* getFront();
		Space* getBack();
		std::string getName();
		void setUp(Space* u);
		void setDown(Space* d);
		void setFront(Space* f);
		void setBack(Space* b);
		std::string getLookLeft();
		std::string getLookRight();
		std::string getLookFront();
		std::string getLookBack();
		virtual void menu(Player*){}
		std::string menuChoice(int r);
		int roomMenu();
};
