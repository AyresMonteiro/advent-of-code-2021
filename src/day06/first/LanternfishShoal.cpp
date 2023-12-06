#include <queue>
#include <vector>
#include <iostream>
#include "Lanternfish.h"

LanternfishShoal::LanternfishShoal(std::vector<Lanternfish> shoal)
{
	this->initialShoal = shoal;
}

std::vector<Lanternfish> LanternfishShoal::getInitialShoal()
{
	return this->initialShoal;
}

std::vector<Lanternfish> LanternfishShoal::getCurrentShoal()
{
	return this->currentShoal;
}

void LanternfishShoal::simulate(int days)
{
	this->currentShoal = this->initialShoal;

	for (int i = 1; i <= days; i++)
	{
		std::queue<Lanternfish> pendent;

		for (Lanternfish &lf : this->currentShoal)
		{
			if (lf.canGiveBirth())
			{
				pendent.push(lf.giveBirth());
			}

			lf.liveOneDay();
		}

		while (!pendent.empty())
		{
			this->currentShoal.push_back(pendent.front());
			pendent.pop();
		}
	}
}