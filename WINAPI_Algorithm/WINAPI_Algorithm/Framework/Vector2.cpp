#include "pch.h"
#include "Vector2.h"

float Vector2::Length() const
{
	float result = sqrt((this->_x * this->_x) + (this->_y * this->_y));

	return result;
}

float Vector2::Distance(Vector2 other) const
{
	Vector2 temp = other - *this;

	return temp.Length();
}

void Vector2::Normalize()
{
	this->_x = this->_x / sqrt((this->_x * this->_x) + (this->_y * this->_y));
	this->_y = this->_y / sqrt((this->_x * this->_x) + (this->_y * this->_y));
}

Vector2 Vector2::NormalVector2(const Vector2& other)
{
	Vector2 result= *this;
	// result._x = (this->_x * other._y - this->_y * other._x)
		// sqrt((this->_x * this->_y - this->_y * this->_x) + (other._x * other._y - other._y * other._x));
	
	// 모르겠어요...

	result.Normalize();

	return result;
}
