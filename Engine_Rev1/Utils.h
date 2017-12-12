#pragma once
#include <string>

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

protected:
private:

};