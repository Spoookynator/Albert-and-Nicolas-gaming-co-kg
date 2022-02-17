#include "endingPoints.h";

short int endingPoints = 0;

void pointsAdd(int add)
{
	endingPoints += add;
}

void pointsRemove(int remove)
{
	endingPoints -= remove;
}

std::string pointsReturn()
{
	return (std::to_string(endingPoints));
}

bool requiredPoints(int requiredPoints)
{
	if (endingPoints >= requiredPoints)
		return true;
	else return false;
}