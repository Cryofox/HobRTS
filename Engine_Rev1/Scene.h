#pragma once

class Scene {

public:
	Scene() {};
	virtual ~Scene() {}

	virtual bool Load() = 0; //Loads the Scene into the Game
	virtual bool UnLoad() = 0; //Unloads the Scene from the Game 
};