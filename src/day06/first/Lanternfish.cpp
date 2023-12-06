#include "Lanternfish.h"

Lanternfish::Lanternfish(int initialNumberOfDays)
{
	this->daysUntilNewChild = initialNumberOfDays;
}

bool Lanternfish::canGiveBirth()
{
	return this->daysUntilNewChild == 0;
}

void Lanternfish::liveOneDay()
{
	this->daysUntilNewChild--;
}

Lanternfish Lanternfish::giveBirth()
{
	this->daysUntilNewChild = 7;

	return Lanternfish(8);
}
