#include "Scene.h"
#include "Options.h"
#include "Menu.h"
#include "GameScene.h"

#include <vector>
int main() 
{
	unsigned int currendScene = 0;
	bool isPlaying = true;

	MenuScene menu;
	GameScene gamescene;
	OptionsScene optionscene;

	std::vector<Scene*> scenes;
	//what am i diong here 
	scenes.push_back(&menu);
	scenes.push_back(&gamescene);
	scenes.push_back(&optionscene);

	while (isPlaying) {
		//change scene?
		if (scenes[currendScene]->sceneFinished)
		{
			scenes[currendScene]->End(currendScene, isPlaying);
			if (!isPlaying)
			{
				break;
			}
			scenes[currendScene]->Start();
		};

		//render scene
		scenes[currendScene]->Draw();
		// update scene
		scenes[currendScene]->Update();
	};
	return 0; 

}