#include <vector>

class Lanternfish
{
public:
	unsigned int daysUntilNewChild;

	Lanternfish(int initialNumberOfDays);

	bool canGiveBirth();

	void liveOneDay();

	Lanternfish giveBirth();
};

class LanternfishShoal
{
protected:
	std::vector<Lanternfish> initialShoal, currentShoal;

public:
	LanternfishShoal(std::vector<Lanternfish> initialShoal);
	void simulate(int days);
	std::vector<Lanternfish> getInitialShoal();
	std::vector<Lanternfish> getCurrentShoal();
};
