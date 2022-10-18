#pragma once
#include "Event.h"

class Controller
{
public:
	virtual void HandelEvent(const Event*) = 0 ;
	virtual bool GetButtonDown(int actionld) = 0;
	virtual bool GetButtonUp(int actionld) = 0;
}; 


