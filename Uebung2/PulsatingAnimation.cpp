#include "PulsatingAnimation.h"
constexpr auto PI = 3.14159265;

PulsatingAnimation::PulsatingAnimation(int x, int y, int min, int max): posX{x}, posY{y}, minSize{min}, maxSize{max}
{
	midPoint = (minSize + maxSize) / 2;
	halfDifference = (maxSize - minSize) / 2.f;
}

void PulsatingAnimation::animate(ViewPortGL& vp, Shape& s)
{
	const auto p1 = std::chrono::system_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(p1.time_since_epoch()).count();
	double currentSin = sin(time * 0.001) * halfDifference + midPoint;
	s.prepare(vp, posX, posY, currentSin);
}