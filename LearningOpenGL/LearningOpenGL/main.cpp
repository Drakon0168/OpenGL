#include "pch.h"
#include "Helper.h"
#include "Point2D.h"
#include "Point3D.h"

int main()
{
	shared_ptr<vector<Point3D>> triangle = shared_ptr<vector<Point3D>>(new vector<Point3D>());
	triangle->push_back(Point3D(0, 0.5, 0));
	triangle->push_back(Point3D(-0.5, -0.5, 0));
	triangle->push_back(Point3D(0.5, -0.5, 0));

	shared_ptr<GLfloat[]> floats = Helper::Point3D_Vector_To_Float_Array(*triangle);

	cout << "Triangle Array: " << endl;

	for (int i = 0; i < sizeof(floats) / sizeof(float); i++) {
		cout << floats[i] << ", ";
	}

	cout << endl << "Triangle Vector: " << endl;

	for (int i = 0; i < triangle->size(); i++) {
		cout << (*triangle)[i] << endl;
	}

    GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit()) {
		return -1;
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Learning OpenGL", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}