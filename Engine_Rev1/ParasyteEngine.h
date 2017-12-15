#pragma once
#include <iostream>
#include <string>

#include <sstream>

#include "OpenGL.h"

#include "Utils.h"
#include "Scene.h"

using namespace std;
using LogType = Utils::LogType;


class ParasyteEngine {

public:
	ParasyteEngine();
	~ParasyteEngine();

	void StartUp();

	void LoadScene(Scene* scene);

	void Run();
	void ShutDown();
protected:
private:
	//Variables//
	GLFWwindow* window;
	//===========
	
	void SetupWindow();//Create Window Context




	void Render(GLuint programID, GLuint vertexBuffer);
	void Update();
};