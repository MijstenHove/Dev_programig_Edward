#pragma once
#include <string>
#include<iostream>
class Scene{
public:
	int ID;
	std::string name;
	bool sceneFinished;

	Scene() { ID = -1; name = "invalid"; sceneFinished = false; };
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End(unsigned int& targetscene, bool& keepPlaying ) = 0 ;
};

