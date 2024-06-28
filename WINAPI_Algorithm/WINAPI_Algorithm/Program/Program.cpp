#include "pch.h"
#include "Program.h"


#include "Scene\PaintScene.h"
#include "Scene\CollisionScene.h"
#include "Scene\LineScene.h"
#include "Scene\Line2Scene.h"

Program::Program()
{
    _scene = make_shared<Line2Scene>();
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
