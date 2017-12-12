#include <iostream>
#include <string>


#include "Utils.h"
//#include <sstream>

using namespace std;
int main()
{
	string anykeyPause = "";
	cout << "This Message appears in the Console" << endl;
	
	Utils::Log(Utils::LogType::Debug, "This Message is written to VS output");

	cin >> anykeyPause;
	return 0;
}