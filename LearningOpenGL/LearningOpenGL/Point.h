#pragma once

#include "pch.h"

struct Point
{
public:
	float x;
	float y;

	Point()
	{
		x = NULL;
		y = NULL;
	}

	Point(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Point(Point& other)
	{
		x = other.x;
		y = other.y;
	}

	~Point()
	{
	}

	void operator=(Point& other)
	{
		x = other.x;
		y = other.y;
	}

	Point& operator+=(Point& other) {
		return Point(x + other.x, y + other.y);
	}

	Point& operator-=(Point& other) {
		return Point(x - other.x, y - other.y);
	}

	Point& operator*=(float& other) {
		return Point(x * other, y * other);
	}

	Point& operator*=(int& other) {
		return Point(x * other, y * other);
	}

	Point& operator/=(float& other) {
		return Point(x / other, y / other);
	}

	Point& operator/=(int& other) {
		return Point(x / other, y / other);
	}

	bool operator==(Point& p1, Point& p2)
	{
		return (p1.x == p2.x && p1.y == p2.y);
	}

	bool operator!=(Point& p1, Point& p2) {
		return (p1.x != p2.x || p1.y != p2.y);
	}

	Point& operator+(Point& p1, Point& p2)
	{
		return Point(p1.x + p2.x, p1.y + p2.y);
	}

	Point& operator-(Point& p1, Point& p2)
	{
		return Point(p1.x - p2.x, p1.y - p2.y);
	}

	Point& operator*(Point& p1, float & f1)
	{
		return Point(p1.x * f1, p1.y * f1);
	}

	Point& operator/(Point& p1, float& f1)
	{
		return Point(p1.x / f1, p1.y / f1);
	}

	Point& operator*(Point& p1, int& i1)
	{
		return Point(p1.x * f1, p1.y * i1);
	}

	Point& operator/(Point& p1, int& i1)
	{
		return Point(p1.x / f1, p1.y / i1);
	}

	std::ostream& operator<<(std::ostream& out, Point p1) {
		return out << "(" << x << ", " << y << ")";
	}
};

