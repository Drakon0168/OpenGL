#pragma once

#include "pch.h"

struct Point2D
{
public:
	float x;
	float y;

	Point2D();
	Point2D(float x, float y);
	Point2D(const Point2D& other);
	~Point2D();

	//Assignment operators
	void operator=(const Point2D& other);
	Point2D operator+=(const Point2D& other);
	Point2D operator-=(const Point2D& other);
	Point2D operator*=(const float& other);
	Point2D operator*=(const int& other);
	Point2D operator/=(const float& other);
	Point2D operator/=(const int& other);

	//Equality operators
	bool operator==(const Point2D& other);
	bool operator!=(const Point2D& other);

	//Arithmetic Operators
	Point2D operator+(const Point2D& other);
	Point2D operator-(const Point2D& other);
	Point2D operator*(const float & f1);
	Point2D operator/(const float& f1);
	Point2D operator*(const int& i1);
	Point2D operator/(const int& i1);

	//Stream operator
	friend std::ostream& operator<<(std::ostream& out, const Point2D& Point2D);
};

Point2D::Point2D()
{
	x = NULL;
	y = NULL;
}

Point2D::Point2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

Point2D::Point2D(const Point2D& other)
{
	x = other.x;
	y = other.y;
}

Point2D::~Point2D()
{
}

void Point2D::operator=(const Point2D& other)
{
	x = other.x;
	y = other.y;
}

Point2D Point2D::operator+=(const Point2D& other) {
	*this = Point2D(x + other.x, y + other.y);
	return *this;
}

Point2D Point2D::operator-=(const Point2D& other) {
	*this = Point2D(x - other.x, y - other.y);
	return *this;
}

Point2D Point2D::operator*=(const float& f) {
	*this = Point2D(x * f, y * f);
	return *this;
}

Point2D Point2D::operator*=(const int& i) {
	*this = Point2D(x * i, y * i);
	return *this;
}

Point2D Point2D::operator/=(const float& f) {
	*this = Point2D(x / f, y / f);
	return *this;
}

Point2D Point2D::operator/=(const int& i) {
	*this = Point2D(x / i, y / i);
	return *this;
}

bool Point2D::operator==(const Point2D& other)
{
	return (x == other.x && y == other.y);
}

bool Point2D::operator!=(const Point2D& other) {
	return (x != other.x || y != other.y);
}

Point2D Point2D::operator+(const Point2D& other) {
	return Point2D(x + other.x, y + other.y);
}

Point2D Point2D::operator-(const Point2D& other) {
	return Point2D(x - other.x, y - other.y);
}

Point2D Point2D::operator*(const float & f) {
	return Point2D(x * f, y * f);
}

Point2D Point2D::operator/(const float& f) {
	return Point2D(x / f, y / f);
}

Point2D Point2D::operator*(const int& i) {
	return Point2D(x * i, y * i);
}

Point2D Point2D::operator/(const int& i) {
	return Point2D(x / i, y / i);
}

std::ostream& operator<<(std::ostream& out, const Point2D& point2D) {
	out << "(" << point2D.x << ", " << point2D.y << ")";
	return out;
}