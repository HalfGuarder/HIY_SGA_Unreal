#pragma once

class HResult;

class Line
{
public:
	Line(Vector2 start, Vector2 end);
	~Line();

	void Update();
	void Render(HDC hdc);

	HResult IsCollision(shared_ptr<Line> other);

	void SetBlack() { _curPen = _pens[0]; }
	void SetRed() { _curPen = _pens[1]; }
	void SetGreen() { _curPen = _pens[2]; }

public:
	vector<HPEN> _pens;
	HPEN _curPen;

	Vector2 _start;
	Vector2 _end;
};

