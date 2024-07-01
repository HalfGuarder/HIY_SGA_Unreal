#pragma once
class Cannon
{
public:
	Cannon();


private:
	shared_ptr<CircleCollider> _body; // 클래스 통일 필요
	shared_ptr<Line> _barrel;

	// float _barrelLength;
};

