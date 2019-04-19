#pragma once

#include "pch.h"
#include "Point3D.h"

static class Helper {
public:
	//Converts a vector of Point3D's to an array of floats
	static shared_ptr<GLfloat[]> Point3D_Vector_To_Float_Array(vector<Point3D> points) {
		shared_ptr<GLfloat[]> floats = shared_ptr<GLfloat[]>(new GLfloat[points.size() * 3]);

		for (int i = 0; i < points.size(); i++) {
			floats[i * 3] = points[i].x;
			floats[i * 3 + 1] = points[i].y;
			floats[i * 3 + 2] = points[i].z;
			cout << "Index: " << i << ", " << points[i] << endl;
		}

		return floats;
	}
};