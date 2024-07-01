#pragma once
class CannonScene : public Scene
{
public:
	CannonScene();
	~CannonScene();


	// Scene을(를) 통해 상속됨
	void Update() override;

	void Render(HDC hdc) override;

private:

};

