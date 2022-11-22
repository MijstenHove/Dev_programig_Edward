#pragma once

enum InerpolatorMode
{
	LINEAR,
	SIN,
	COS,
	SMOOTH
};
class Inerpolator
{
private:
	enum InerpolatorState { SHRINKING, MAX, MIN, GROWING };
	InerpolatorState state;

	float currentLerpTime;
	float totalLerpTime;

	float value;
	float inverse;
	const float e = 0.05f;

	InerpolatorMode mode;

public:
	Inerpolator(float LerpTime, InerpolatorMode mode = LINEAR);
	void ToMax();
	void ForceMax();
	void ToMin();
	void ForceMin();
	
	void Update(float dt);
	
	bool IsMax();
	bool IsMaxPrecise();
	
	bool IsMin();
	bool IsMinPrecise();

	float GetValue();
	float GetInverse();
};

