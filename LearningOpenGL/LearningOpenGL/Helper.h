#pragma once

#include "pch.h"
#include "Point3D.h"

GLfloat* Point3D_Vector_To_Float_Array(vector<Point3D> points){
	GLfloat floats[9];

	for (int i = 0; i < points.size(); i++) {
		floats[i] = points[i].x;
		floats[i + 1] = points[i].y;
		floats[i + 2] = points[i].z;
	}

	return floats;
}