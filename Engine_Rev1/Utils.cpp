#include "Utils.h"
#include <Windows.h>

#include <sstream>
#include <ostream>
void Utils::Log(Utils::LogType logType, string message)
{
	string prefix;
	switch (logType)
	{
	case LogType::Debug:
		prefix = "[DEBUG]";
		break;
	case LogType::Info:
		prefix = "[INFO]";
		break;
	case LogType::Warning:
		prefix = "[WARNING]";
		break;
	case LogType::Error:
		prefix = "[ERROR]";
		break;
	default:
		break;
	}
	prefix.append(message);
	message = prefix;

	std::wstring wideMessage(message.length(),L' ');
	//Copy String to wideString for Windows


	std::copy(message.begin(), message.end(), wideMessage.begin());
	OutputDebugString(wideMessage.c_str());
}


