#pragma once

#include "pch.h"

struct Point
{
public:
	float x;
	float y;

	Point();
	Point(float x, float y);
	Point(Point& other);
	~Point();

	//Assignment operators
	void operator=(Point& other);
	Point& operator+=(Point& other);
	Point& operator-=(Point& other);
	Point& operator*=(float& other);
	Point& operator*=(int& other);
	Point& operator/=(float& other);
	Point& operator/=(int& other);

	//Equality operators
	bool operator==(Point& other);
	bool operator!=(Point& other);

	//Arithmetic Operators
	Point& operator+(Point& other);
	Point& operator-(Point& other);
	Point& operator*(float & f1);
	Point& operator/(float& f1);
	Point& operator*(int& i1);
	Point& operator/(int& i1);

	//Stream operator
	std::ostream& operator<<(std::ostream& out);
};

