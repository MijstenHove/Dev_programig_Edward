#include "Scene.h"
#include "UIText.h"
#include <SDL_ttf.h>
#include "InputManager.h"
#include "SceneManager.h"
#include <cassert>
class MainMenuScene : public Scene {
private:
	UIText sampleText;
	TTF_Font* fond;
	float buttonAngle;

public:

	virtual void Update(float dt) override;
	virtual void Render(SDL_Renderer*) override;
	virtual void OnEnter() override;
	virtual void OnExit() override;



};