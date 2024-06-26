#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>


using namespace std;

// �̸� ������ �� ��� (Pre Compile Header)
// pch.h / pch.cpp ����
// pch.cpp #include "pch.h"
// pch.cpp �Ӽ� -> c/c++ -> �̸� ������ �� ��� ����� / pch.h
// ������Ʈ �Ӽ� -> c/c++ -> �̸� ������ �� ��� ����� / pch.h
// Ŭ���� ����

// ����ȭ ������ �� ��� �߰�
// ������Ʈ �Ӽ� -> VC++���͸� -> ���� ���͸� ���� -> $(ProjectDir) ����

#include "Contents\BattleSystem\AggroManage.h"

#include "Contents/Creature/Creature.h"
#include "Contents/Creature/Player.h"
#include "Contents/Creature/Monster.h"

#include "Contents/Creature/Player/Knight.h"
#include "Contents/Creature/Player/Archer.h"
#include "Contents/Creature/Player/Mage.h"

#include "Contents/Creature/Monster/M_Knight.h"
#include "Contents/Creature/Monster/M_Archer.h"
#include "Contents/Creature/Monster/M_Mage.h"
#include "Contents/Creature/Monster/Goblin.h"
#include "Contents\Creature\Monster\HobGoblin.h"

#include "Contents/World/World.h"