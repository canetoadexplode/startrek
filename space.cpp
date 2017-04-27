//space.cpp

#include "space.hpp"
#include "common.hpp"
#include <iostream>
using namespace std;

Space* Space::getUp()
{
	return up;
}

Space* Space::getDown()
{
	return down;
}

Space* Space::getFront()
{
	return front;
}

Space* Space::getBack()
{
	return back;
}

string Space::getName()
{
	return name;
}

void Space::setUp(Space* u)
{
	up = u;
}

void Space::setDown(Space* d)
{
	down = d;
}

void Space::setFront(Space* f)
{
	front = f;
}

void Space::setBack(Space* b)
{
	back = b;
}

string Space::getLookLeft()
{
	return lookLeft;
}

string Space::getLookRight()
{
	return lookRight;
}

string Space::getLookFront()
{
	return lookFront;
}

string Space::getLookBack()
{
	return lookBack;
}

int Space::roomMenu()
{
	int response;

	cout << endl;
	cout << "Your choices are: " << endl;
	cout << "1) Look left." << endl;
	cout << "2) Look right." << endl;
	cout << "3) Look front." << endl;
	cout << "4) Look back." << endl;
	cout << "5) Move left." << endl;
	cout << "6) Move right." << endl;
	cout << "7) Move front." << endl;
	cout << "8) Move back." << endl;

	while(true){
		response = getNumber(0, 9);
		return response;
	}
}

string Space::menuChoice(int r)
{
  if (r == 1) return "You look to the left";
  if (r == 2) return "You look to the right";
  if (r == 3) return "You look ahead";
  if (r == 4) return "You look back";
  if (r == 5) return "You move to your right";
  if (r == 6) return "You move to your left";
  if (r == 7) return "You move forward";
  if (r == 8) return "You move backwards";
  return "";
}

