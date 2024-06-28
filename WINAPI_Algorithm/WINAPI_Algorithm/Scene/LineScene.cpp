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

	/*float dot = _line2->_end.Dot(_line1->_end);
	Vector2 normalize = _line1->_end.NormalVector2();
	float length = _line1->_end.Length();*/

	/*Vector2 point = _line1->_end;
	float sin = 0.f, cos = 0.f;
	point = Vector2(cos, sin) * _line1->_end._y;
	
	
	Vector2 unitV = (_line1->_end - _line1->_start).NormalVector2();
	Vector2 u = point - _line1->_start;
	Vector2 projV = unitV * (u.Dot(unitV));
	Vector2 projectedPoint = _line1->_start + projV;
	float distance = (projectedPoint - point).Length();

	_line3->_end = Vector2(projectedPoint);*/

	Vector2 a = (_line2->_end - _line2->_start); // A
	Vector2 b = (_line1->_end - _line1->_start); // B

	Vector2 bNormal = b.NormalVector2(); // B의 단위 벡터

	float line2Length = a.Dot(bNormal); // 그림자의 길이 ... 투영 됐을 때 길이

	Vector2 line3Delta = bNormal * line2Length;
	_line3->_end = _line3->_start + line3Delta;


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
