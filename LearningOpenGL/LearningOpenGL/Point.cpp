#include "Point.h"

Point::Point()
{
	x = NULL;
	y = NULL;
}

Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
}

Point::Point(Point& other)
{
	x = other.x;
	y = other.y;
}

Point::~Point()
{
}

void Point::operator=(Point& other)
{
	x = other.x;
	y = other.y;
}

Point& Point::operator+=(Point& other) {
	return Point(x + other.x, y + other.y);
}

Point& Point::operator-=(Point& other) {
	return Point(x - other.x, y - other.y);
}

Point& Point::operator*=(float& other) {
	return Point(x * other, y * other);
}

Point& Point::operator*=(int& other) {
	return Point(x * other, y * other);
}

Point& Point::operator/=(float& other) {
	return Point(x / other, y / other);
}

Point& Point::operator/=(int& other) {
	return Point(x / other, y / other);
}

bool Point::operator==(Point& other)
{
	return (x == other.x && y == other.y);
}

bool Point::operator!=(Point& other) {
	return (x != other.x || y != other.y);
}

Point& Point::operator+(Point& other)
{
	return Point(x + other.x, y + other.y);
}

Point& Point::operator-(Point& other)
{
	return Point(x - other.x, y - other.y);
}

Point& Point::operator*(float & f1)
{
	return Point(x * f1, y * f1);
}

Point& Point::operator/(float& f1)
{
	return Point(x / f1, y / f1);
}

Point& Point::operator*(int& i1)
{
	return Point(x * i1, y * i1);
}

Point& Point::operator/(int& i1)
{
	return Point(x / i1, y / i1);
}

std::ostream& Point::operator<<(std::ostream& out) {
	return out << "(" << x << ", " << y << ")";
}