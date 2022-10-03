#pragma once
#pragma once
#include "MenuMenager.h"
class Leaderboard : public MenuMenager {
private:
public:
	virtual void Start() override {};
	virtual void Update()override {};
	virtual void DrawText() override {
		std::cout << " welcome to leaderbord\n\n" << std::endl;
		std::cout << "mymy - time - 2:02:40" << std::endl;
		std::cout << "mymy - time - 1:03:00" << std::endl;
		std::cout << "mymy - time - 4:02:12" << std::endl;
		std::cout << "mymy - time - 8:14:02" << std::endl;
		std::cout << "M for menu \n" << std::endl;

		std::cout << "enter choice: " << std::endl;
	};
	virtual void End(unsigned int& targetscene, bool& keepPlaying) override {};
};
