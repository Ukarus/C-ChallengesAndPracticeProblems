#include "TimeYearConverter.h"
#include <iostream>
#include <format>

void TimeYearConverter::ToYears(int days)
{
	int y = days / 365;
	int w = (days / 7) - (y * 52);
	// TODO: Fix years calculations
	int d = days - ((w * 7) + y * 365);

	//auto s = std::format("My variable has value {}", myVariable);
	std::cout << y << " years " << w << " weeks " << d << " days";
	//std::cout << std::format("My variable has value {} ")
}
