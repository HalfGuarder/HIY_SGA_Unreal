#pragma once
class Cannon
{
public:
	Cannon();


private:
	shared_ptr<CircleCollider> _body; // Ŭ���� ���� �ʿ�
	shared_ptr<Line> _barrel;

	// float _barrelLength;
};

