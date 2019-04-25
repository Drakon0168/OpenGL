#pragma once

#include "pch.h"

struct Point3D
{
public:
	float x;
	float y;
	float z;
	bool direction;

	Point3D();
	Point3D(float x, float y, float z);
	Point3D(float x, float y, float z, bool direction);
	Point3D(const Point3D& other);
	~Point3D();

	//Assignment operators
	void operator=(const Point3D& other);
	Point3D operator+=(const Point3D& other);
	Point3D operator-=(const Point3D& other);
	Point3D operator*=(const float& other);
	Point3D operator*=(const int& other);
	Point3D operator/=(const float& other);
	Point3D operator/=(const int& other);

	//Equality operators
	bool operator==(const Point3D& other);
	bool operator!=(const Point3D& other);

	//Arithmetic Operators
	Point3D operator+(const Point3D& other);
	Point3D operator-(const Point3D& other);
	Point3D operator*(const float & f1);
	Point3D operator/(const float& f1);
	Point3D operator*(const int& i1);
	Point3D operator/(const int& i1);

	//Stream operator
	friend std::ostream& operator<<(std::ostream& out, const Point3D& Point3D);
};

Point3D::Point3D()
{
	x = NULL;
	y = NULL;
	z = NULL;
	direction = false;
}

Point3D::Point3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	direction = false;
}

Point3D::Point3D(float x, float y, float z, bool direction) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->direction = direction;
}

Point3D::Point3D(const Point3D& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	direction = other.direction;
}

Point3D::~Point3D()
{
}

void Point3D::operator=(const Point3D& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	direction = other.direction;
}

Point3D Point3D::operator+=(const Point3D& other) {
	*this = Point3D(x + other.x, y + other.y, z + other.z);
	return *this;
}

Point3D Point3D::operator-=(const Point3D& other) {
	*this = Point3D(x - other.x, y - other.y, z - other.z);
	return *this;
}

Point3D Point3D::operator*=(const float& f) {
	*this = Point3D(x * f, y * f, z * f);
	return *this;
}

Point3D Point3D::operator*=(const int& i) {
	*this = Point3D(x * i, y * i, z * i);
	return *this;
}

Point3D Point3D::operator/=(const float& f) {
	*this = Point3D(x / f, y / f, z / f);
	return *this;
}

Point3D Point3D::operator/=(const int& i) {
	*this = Point3D(x / i, y / i, z / y);
	return *this;
}

bool Point3D::operator==(const Point3D& other)
{
	return (direction == other.direction && x == other.x && y == other.y && z == other.z);
}

bool Point3D::operator!=(const Point3D& other) {
	return (direction != other.direction || x != other.x || y != other.y || z != other.z);
}

Point3D Point3D::operator+(const Point3D& other) {
	return Point3D(x + other.x, y + other.y, z + other.z);
}

Point3D Point3D::operator-(const Point3D& other) {
	return Point3D(x - other.x, y - other.y, z - other.z);
}

Point3D Point3D::operator*(const float & f) {
	return Point3D(x * f, y * f, z * f);
}

Point3D Point3D::operator/(const float& f) {
	return Point3D(x / f, y / f, z / f);
}

Point3D Point3D::operator*(const int& i) {
	return Point3D(x * i, y * i, z * i);
}

Point3D Point3D::operator/(const int& i) {
	return Point3D(x / i, y / i, z / i);
}

std::ostream& operator<<(std::ostream& out, const Point3D& point3D) {
	out << "(" << point3D.x << ", " << point3D.y << ", " << point3D.z << ")";
	return out;
}