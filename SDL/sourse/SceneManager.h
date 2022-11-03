#pragma once
#include <map>
#include <string>
#include "Scene.h"
#include <assert.h>

#define SM SceneManager::GetInstance()
class SceneManager {
public:
	void AddScene(std::string name,Scene* scene);
	//template<class S> S* getScene();
	//getters
	Scene* GetScene(std::string name);
	Scene* GetCurrentScene();

	template<class S> void SetScene(); //impoment if we have time
	//setter
	void SetScene(std::string name);

	static SceneManager* GetInstance();

private:
	SceneManager();
	static SceneManager* instanse;

	//scene mangagemant 
	std::map<std::string, Scene*> scenes;
	Scene* currendScene;
};
