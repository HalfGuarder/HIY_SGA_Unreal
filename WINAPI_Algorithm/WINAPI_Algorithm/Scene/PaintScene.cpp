#include "pch.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
    _rect = make_shared<RectCollider>(Vector2(0.0f, 0.0f), Vector2(50.0f, 50.0f));
    _circle = make_shared<CircleCollider>(Vector2(100.0f, 100.0f), 10.0f);
}

PaintScene::~PaintScene()
{

}

void PaintScene::Update()
{
    _rect->_center = _rect->_center + Vector2(0.5f, 0.5f);

    _rect->Update();

    _circle->_center = LERP(_circle->_center, mousePos, 0.1f); // 선형 보간

    // 원형 보간 조사

    _circle->Update();
}

void PaintScene::Render(HDC hdc)
{
    // 사각형 그리기
    _rect->Render(hdc);

    // 삼각형 그리기는 없음


    // 원 그리기
    _circle->Render(hdc);


    // 선 그리기
    // LineTo(hdc, 200, 200);
}
