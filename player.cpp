// player.cpp

#include "player.hpp"
using namespace std;

Player::Player(Space* l, string one, string two, bool r)
{
	location = l;
	pocket1 = one;
	pocket2 = two;
	redAlert = r;
}

void Player::moveUp()
{
	location = location->getUp();
}

void Player::moveDown()
{
	location = location->getDown();
}

void Player::moveFront()
{
	location = location->getFront();
}

void Player::moveBack()
{
	location = location->getBack();
}

void Player::setPocket1()
{
	pocket1 = "Phaser";
}

void Player::setPocket2()
{
	pocket2 = "Dilithium Crystal";
}

Space* Player::getLocation()
{
	return location;
}

string Player::getPocket1()
{
	return pocket1;
}

string Player::getPocket2()
{
	return pocket2;
}

void Player::setLocation(Space* l)
{
	location = l;
}

bool Player::getRedAlert()
{
	return redAlert;
}

void Player::setRedAlert(bool r)
{
	redAlert = r;
}
