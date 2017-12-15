#pragma once
#include <string>
#include <Windows.h>
#include <sstream>
#include <ostream>
#include <iostream>

#include <fstream>


#include "OpenGL.h"
using namespace std;

class Utils
{
public:
	enum LogType
	{
		Debug=0, 
		Info, 
		Warning, 
		Error
	};

	static void Log(LogType logtype, string message);
	static void Log(string message);


	static GLuint Utils::LoadShaders(const char * vertex_file_path, const char * fragment_file_path);
protected:
private:

};