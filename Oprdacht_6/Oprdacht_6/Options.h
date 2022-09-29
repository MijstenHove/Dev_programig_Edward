#pragma once
#include "Scene.h"

class OptionsScene : public Scene {
public:
	virtual void Start() override{};
	virtual void Update()override {};
	virtual void Draw() override {


		std::cout << "options " << std::endl;
	};
	virtual void End(unsigned int& targetscene, bool& keepPlaying) override {};
};

