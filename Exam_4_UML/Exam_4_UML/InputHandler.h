#pragma once
#include "Controller.h"
#include "Event.h"
#include <vector>
class InputHandler
{
private:
	std::vector<Controller> controllers;
public:
	void HandelEvent(const Event*);
	void AddController(Controller*);

};

