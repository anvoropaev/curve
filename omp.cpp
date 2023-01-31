#include <cstdlib>
#include <vector>
#include <iostream>

#include <omp.h>

#include "curve.h"

int main(int argc, char *argv[])
{
// circles

	auto n{argc < 2 ? 0 : std::strtoul(argv[1],{},10)};

	std::vector<Curve::Circle> circles(n,1.0);

// sum of circles' radii

	Curve::Real s{};

#pragma omp parallel for ordered reduction(+:s)

	for(const auto &c : circles)

#pragma omp ordered

		s += c.radius();

	std::cout << s << '\n';
}
