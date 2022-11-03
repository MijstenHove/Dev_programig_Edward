#include "SceneManager.h"

SceneManager* SceneManager::instanse = nullptr;

SceneManager::SceneManager() {

}

//adds a agregations to the scene  map 
void SceneManager::AddScene(std::string name, Scene* scene) {

	scenes.emplace(name,scene);
}
 
SceneManager* SceneManager::GetInstance() {
	if (instanse == nullptr) 
		instanse = new SceneManager();
	return instanse;
}

Scene* SceneManager::GetScene(std::string name) {
	auto scene = scenes.find(name);
	
	bool scenefound = scene != scenes.end();
	
	return scenefound ? scenes[name] : nullptr;
}
Scene* SceneManager::GetCurrentScene() {
	return currendScene;
}
void SceneManager::SetScene(std::string name) {
	auto scene = scenes.find(name);

	bool scenefound = scene != scenes.end();
	// stops the code to warn the dev 
	assert(scenefound);
	if (scenefound){
		if(currendScene!= nullptr)
			currendScene->OnExit();
		currendScene = scene->second;
		currendScene->OnEnter();
	}
}

//find a scene off a given class 
//template<class S> S* SceneManager::getScene() {
//	auto scene = scenes.find(typeid(S));
//	//std::map<std::string, Scene*>::iterator scene = scenes.find(typeid(S)); wat auto doet 
//	bool scenefound = scene != scenes.end();
//	return scenefound ? dynamic_cast<S*>(scene->second) : nullptr;
//// returnt een class? what does scond do and what does the ? do ?
//}