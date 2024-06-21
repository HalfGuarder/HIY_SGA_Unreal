#include "pch.h"
#include "Player.h"

Player::Player(string name, int hp, int mp, int atk, int exp)
	:Creature(name, hp, mp, atk, exp)
	//_exp(exp)
{
}

Player::~Player()
{
}