#include "pch.h"
#include "Program.h"

#include "Scene\LineScene.h"
#include "Scene\PaintScene.h"
#include "Scene\CollisionScene.h"

Program::Program()
{
    _scene = make_shared<CollisionScene>();
}

Program::~Program()
{
}

void Program::Update()
{
    _scene->Update();
}

void Program::Render(HDC hdc) // DX -> Direct Access -> GPU <- Render ... Update -> CPU
{
    _scene->Render(hdc);
}
