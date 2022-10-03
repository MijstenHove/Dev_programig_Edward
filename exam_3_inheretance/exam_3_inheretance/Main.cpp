#include "RenderMenager.h"
#include "Animation2D.h"
#include "Image.h"
#include "Model3D.h"


int main(){

	unsigned int currendScene = 0;
	
	Image image;
	Animation2D animation2d;
	Model3D model3d;

	std::vector<RenderMenager*> rendermenager;
	//what am i diong here 
	rendermenager.push_back(&image);
	rendermenager.push_back(&animation2d);
	rendermenager.push_back(&model3d);
	

	rendermenager[currendScene]->Draw();
	std::cout << "end" << std::endl;
	return 0;
}