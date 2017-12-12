#include <iostream>
#include <string>


#include "Utils.h"
#include <sstream>

//OpenGL Mandatory Prereq Header
#include <GL/glew.h>
//OpenGL windowing Library
#include <GLFW/glfw3.h>
//OpenGL Mathematics Library (Linker Test)
#include <glm/glm.hpp>

using namespace std;

using LogType = Utils::LogType;

int main()
{
	//Initialize GLFW Init
	Utils::Log(LogType::Info, "Initializing GLFW...");
	if (!glfwInit())
	{
		Utils::Log(LogType::Error, "Failed to initialize GLFW");
		return -1;
	}
	Utils::Log("Success\n");
	//GLFW window setup
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	GLFWwindow* window;
	window = glfwCreateWindow(1024, 768, "HobRTS", NULL, NULL);
	Utils::Log(LogType::Info, "Initializing GLFW Window...");
	if (window == NULL)
	{
		Utils::Log(LogType::Error, "Failed to open GLFW window.");
		glfwTerminate();
		return -1;
	}
	Utils::Log("Success\n");


	glfwMakeContextCurrent(window); // Initialize GLEW
	glewExperimental = true; // Needed in core profile

	Utils::Log(LogType::Info, "Initializing GLEW...");
	if (glewInit() != GLEW_OK) {
		Utils::Log(LogType::Error, "Failed to initialize GLEW");
		return -1;
	}
	Utils::Log("Success\n");

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	do {

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

	return 0;
}