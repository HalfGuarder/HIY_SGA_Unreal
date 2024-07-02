#pragma once
class A_Block : public RectCollider
{
public:
	enum class A_BlockType
	{
		NONE,
		DESTROY,
		NONDESTROY
	};

	A_Block();
	~A_Block();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetPositon(Vector2 pos);
	void SetBlockType(A_BlockType type);

private:
	A_BlockType _type = A_BlockType::NONE;

	vector<HBRUSH> _brushes;
};

