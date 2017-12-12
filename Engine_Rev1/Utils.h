#pragma once
#include <string>
#include <Windows.h>
#include <sstream>
#include <ostream>
#include <iostream>
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
protected:
private:

};