#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>


using namespace std;

// 미리 컴파일 된 헤더 (Pre Compile Header)
// pch.h / pch.cpp 생성
// pch.cpp #include "pch.h"
// pch.cpp 속성 -> c/c++ -> 미리 컴파일 된 헤더 만들기 / pch.h
// 프로젝트 속성 -> c/c++ -> 미리 컴파일 된 헤더 만들기 / pch.h
// 클래스 생성

// 폴더화 시켰을 때 경로 추가
// 프로젝트 속성 -> VC++디렉터리 -> 포함 디렉터리 편집 -> $(ProjectDir) 적용

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