#include "pch.h"
#include "Monster.h"

Monster::Monster(string name, int hp, int mp, int atk, int exp)
:Creature(name, hp, mp, atk, exp)
{
}

Monster::~Monster()
{
}