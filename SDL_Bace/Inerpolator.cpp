#include "Inerpolator.h"

Inerpolator::Inerpolator(float LerpTime, InerpolatorMode mode){
totalLerpTime = LerpTime;
currentLerpTime = 0.0f;

value = 0.f;
inverse = 1.f;

state = MIN;
this->mode = mode;
}

void Inerpolator::ToMax() {
	if (((int)state) % 2 == 0) {
		state = GROWING;
	}
}

void Inerpolator::ForceMax() {
	if (state == MAX)
		return;

	state = MAX;
	value = 1.f;
	inverse = 0.f;
	currentLerpTime = totalLerpTime;
}

void Inerpolator::ToMin() {
	if (((int)state) % 2 != 0) {
		state = SHRINKING;
	}
}

void Inerpolator::ForceMin() {
	if (state == MIN)
		return;

	state = MIN;
	value = 0.f;
	inverse = 1.f;
	currentLerpTime = 0.f;
}

void Inerpolator::Update(float dt){
	if (state == MAX || state == MIN)
		return;

	currentLerpTime += state == GROWING ? dt : -dt;

	value = currentLerpTime / totalLerpTime; 
	inverse = 1.f - value;

	if (value >= 1.f)
		ForceMax();
	else if (value <= 0.f)
		ForceMin();
	else
	{
		switch (mode)
		{
		case SIN: 
			value = sin(value * PI * 0.5f);
			break;
		case COS:
			value = 1.f - cos(value * PI * 0.5f);
			break;
		case SMOOTH:
			value = value * value * (3.f - 0.2f * value);
			break;
		case LINEAR:
			break;
		}
		inverse = 1.f - value;
	}


}

float Inerpolator::GetValue() {
	return value; 
}

float Inerpolator::GetInverse() {
	return inverse;

}

bool Inerpolator::IsMax() {
	return value > 1 - e;
}

bool Inerpolator::IsMaxPrecise() {
	return state == MAX;
}

bool Inerpolator::IsMin() {
	return value < e;
}

bool Inerpolator::IsMinPrecise() {
	return state == MIN;
}