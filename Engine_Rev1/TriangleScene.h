#pragma once
#include "Scene.h"
class TriangleScene : public Scene {

public:
	TriangleScene();
		~TriangleScene();

	bool Load(); //Loads the Scene into the Game
	bool UnLoad(); //Unloads the Scene from the Game 
};