#include "MainMenu.h"
#include "Leaderbord.h"
#include "PauseMenu.h"
#include "MenuManager.h"
#include "Image.h"
#include "RenderManager.h"

int main() {
		RenderManager rm = RenderManager();

		Image* image;
		//rm.renderers.push_back(&image);

		rm.Draw();

	return 0; 
};