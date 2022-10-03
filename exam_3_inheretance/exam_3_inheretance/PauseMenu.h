#pragma once
#include "MenuMenager.h"

class PauseMenu : public MenuMenager {
private:
public:
	virtual void Start() override {};
	virtual void Update()override {};
	virtual void DrawText() override {


		std::cout << "pause " << std::endl;
	};
	virtual void End(unsigned int& targetscene, bool& keepPlaying) override {};
};

