#pragma once
class CannonScene : public Scene
{
public:
	CannonScene();
	~CannonScene();


	// Scene��(��) ���� ��ӵ�
	void Update() override;

	void Render(HDC hdc) override;

private:

};

