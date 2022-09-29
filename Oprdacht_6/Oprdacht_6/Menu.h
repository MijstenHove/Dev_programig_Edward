#pragma once
#include "Scene.h"

class MenuScene : public Scene {
private:
	char choice;
public:
	MenuScene()
		:Scene() {
		ID = 0;
		name = "name";
		sceneFinished = false;
	};

	virtual void Start() override {};
	virtual void Update()override {
		std::cin >> choice;
		if (choice == '1' || choice == '2' || choice == '3')
		{
			sceneFinished = true;
		}
	};
	virtual void Draw() override {
		
		
		std::cout << "main menu welcome to juegazo!!\n\n" << std::endl;
		std::cout << "1- play" << std::endl;
		std::cout << "2- options" << std::endl;
		std::cout << "3- exit \n" << std::endl;

		std::cout << "enter choice: " << std::endl;
	};
	virtual void End(unsigned int& targetScene, bool& keepplaying) override {
		switch (choice) 
		{
		case '1':
			targetScene = 1; 
			break;
		case '2':
			targetScene = 2;
			break;
		case '3':
			keepplaying = false;
			break;
		}
	}



};

