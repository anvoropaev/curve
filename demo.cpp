#include <cstdlib>
#include <random>
#include <functional>
#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>

#include "curve.h"

int main(int argc, char *argv[])
{
// random number generators

	using Engine = std::default_random_engine;

	Engine engine{argc == 1 ? Engine::default_seed : std::atoi(argv[1])};

	// It is likely that the uniform_int_distribution object specified below
	// would downscale the first return value of the default_random_engine,
	// e.g. minstd_rand0, to zero for small seeds.

	engine(); // Skip to the second value.

	auto random_int{std::bind(std::uniform_int_distribution<>{0,20},engine)};

	auto random_real{std::bind(std::uniform_real_distribution<>{0.1,10.0},engine)};

// curves

	using Curve_ptr = std::unique_ptr<Curve::Curve>;

	std::vector<Curve_ptr> curves;

	for(int n{random_int()}; n; n--)

		switch(random_int() % 3)
		{
			case 0:
				curves.push_back(Curve_ptr{

					new Curve::Circle{random_real()}});
				break;

			case 1:
				curves.push_back(Curve_ptr{

					new Curve::Ellipse{random_real(),random_real()}});
				break;

			case 2:
				curves.push_back(Curve_ptr{

					new Curve::Helix{random_real(),random_real()}});
		}

// curves' properties at pi/4

	for(const auto &c : curves)

		std::cout << c->point(Curve::pi / 4) << ' '

			<< c->derivative(Curve::pi / 4) << ' '

			<< typeid(*c.get()).name() << '\n';

// circles

	std::vector<Curve::Circle*> circles;

	for(const auto &c : curves)

		if(auto *d{dynamic_cast<Curve::Circle*>(c.get())})

			circles.push_back(d);

// sorted circles

	std::sort(circles.begin(),circles.end(),

		[](auto c, auto d) { return c->radius() < d->radius(); });

	for(auto c : circles)

		std::cout << c->radius() << '\n';

// sum of circles' radii

	auto s{std::accumulate(circles.cbegin(),circles.cend(),Curve::Real{},

		[](auto a, auto c) { return a + c->radius(); })};

	std::cout << s << '\n';
}
