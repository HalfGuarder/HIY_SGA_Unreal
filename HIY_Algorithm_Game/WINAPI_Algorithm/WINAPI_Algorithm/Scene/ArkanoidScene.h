#pragma once
class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();

	void Update() override;
	void Render(HDC hdc) override;



private:
	shared_ptr<class Map> _map;
	shared_ptr<class Bar> _bar;
	shared_ptr<class Ball> _ball;
};

