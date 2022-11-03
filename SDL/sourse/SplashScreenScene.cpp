#include "SplashScreenScene.h"

void SplashScreenScene::Update(float dt){
	if (IM->CheckKayState(SDLK_SPACE, PRESSED))
		SM->SetScene("MainMenu");
}

void SplashScreenScene::Render(){

}

void SplashScreenScene::OnEnter() {
	std::cout << "entering splach screen " << std::endl;
}
	
void SplashScreenScene::OnExit() {
	std::cout << "exeting splach screen " << std::endl;
}
