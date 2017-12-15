#include "ParasyteEngine.h"

#include "TriangleScene.h"
void Demo1()
{
	Scene *scene = new TriangleScene();

	ParasyteEngine parasyteEngine;
	parasyteEngine.StartUp();
	parasyteEngine.LoadScene(scene); //Load the Scene
	parasyteEngine.Run();
	parasyteEngine.ShutDown();

	delete scene;
}


int main()
{
	Demo1();

	return 0;
}





