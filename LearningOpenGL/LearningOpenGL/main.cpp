#include "pch.h"
#include "Helper.h"
#include "Point2D.h"
#include "Point3D.h"

#include "loadShader.h"

//typedef basic_ios<char> ios;

//Following a Tutorial, http://www.opengl-tutorial.org/beginners-tutorials/

int main()
{
	shared_ptr<vector<Point3D>> triangle = shared_ptr<vector<Point3D>>(new vector<Point3D>());
	triangle->push_back(Point3D(0, 0.5, 0));
	triangle->push_back(Point3D(-0.5, -0.5, 0));
	triangle->push_back(Point3D(0.5, -0.5, 0));

	shared_ptr<GLfloat[]> floats = Helper::Point3D_Vector_To_Float_Array(*triangle);

	glewExperimental = true;
	if (!glfwInit()) {
		cout << "Failed to initialize GLFW" << endl;
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	GLFWwindow* window;
	window = glfwCreateWindow(1024, 768, "Learning OpenGL", NULL, NULL);

	if (window == NULL) {
		cout << "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials." << endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		cout << "Failed to initialize GLEW" << endl;
		return -1;
	}

	//Set up the triangle
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	//Set the points
	static const GLfloat g_vertex_buffer_data[] = {
		(*triangle)[0].x, (*triangle)[0].y, (*triangle)[0].z,
		(*triangle)[1].x, (*triangle)[1].y, (*triangle)[1].z,
		(*triangle)[2].x, (*triangle)[2].y, (*triangle)[2].z,
	};

	//Setup the buffer
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	GLuint programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	do {
		//Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(programID);

		//Draw
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);

		//Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}