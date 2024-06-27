#include "pch.h"
#include "LineScene.h"

LineScene::LineScene()
{
	_line1 = make_shared<Line>(Vector2(100, 500), Vector2(1000, 400));
	_line2 = make_shared<Line>(Vector2(100, 450), Vector2(0, 0));

	_line3 = make_shared<Line>(Vector2(100, 470), Vector2(150, 470));
}

LineScene::~LineScene()
{
}

// A = 2, B = 1
void LineScene::Update() // 내적 투영
{
	_line2->_end = mousePos;

	float dot = _line2->_end.Dot(_line1->_end);
	Vector2 normalize = _line1->_end.NormalVector2();
	float length = _line1->_end.Length();

	_line3->_end = Vector2(normalize * dot / length);
	
	


	_line1->Update();
	_line2->Update();
	_line3->Update();

}

void LineScene::Render(HDC hdc)
{

	_line1->Render(hdc);
	_line2->Render(hdc);
	_line3->Render(hdc);
}
