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

    _circle->_center = LERP(_circle->_center, mousePos, 0.1f); // ���� ����

    // ���� ���� ����

    _circle->Update();
}

void PaintScene::Render(HDC hdc)
{
    // �簢�� �׸���
    _rect->Render(hdc);

    // �ﰢ�� �׸���� ����


    // �� �׸���
    _circle->Render(hdc);


    // �� �׸���
    // LineTo(hdc, 200, 200);
}
