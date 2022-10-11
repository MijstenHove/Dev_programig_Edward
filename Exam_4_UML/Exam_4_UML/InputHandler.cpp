#include "InputHandler.h"


void InputHandler::HandelEvent(const Event* event)
{
	// loop through all the Controllers and call their HandleEvent function passing the event.

	for (int i = 0; i < controllers.size(); i++)
	{
		controllers[i].HandelEvent(event);
	}
}

void InputHandler::AddController(Controller*)
{
 

}
