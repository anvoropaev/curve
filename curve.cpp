#include <cmath>
#include <stdexcept>

#include "curve.h"

namespace Curve
{
// auxiliary stuff

using std::sin, std::cos;

const Real pi{4 * std::atan(1.0)};

std::ostream& operator<<(std::ostream &o, const Vector &v)
{
	return o << v.x << ' ' << v.y << ' ' << v.z;
}

// circle constructor and methods

Circle::Circle(Real r): r{r}
{
	if(r <= Real{})

		throw Error{"Circle"};
}

Real Circle::radius() const
{
	return r;
}

Vector Circle::point(Real t) const
{
	return {r*cos(t),r*sin(t),{}};
}

Vector Circle::derivative(Real t) const
{
	return {-r*sin(t),r*cos(t),{}};
}

// ellipse constructor and methods

Ellipse::Ellipse(Real rx, Real ry): rx{rx}, ry{ry}
{
	if(rx <= Real{} || ry <= Real{})

		throw Error{"Ellipse"};
}

Real Ellipse::xradius() const
{
	return rx;
}

Real Ellipse::yradius() const
{
	return ry;
}

Vector Ellipse::point(Real t) const
{
	return {rx*cos(t),ry*sin(t),{}};
}

Vector Ellipse::derivative(Real t) const
{
	return {-rx*sin(t),ry*cos(t),{}};
}

// helix constructor and methods

Helix::Helix(Real r, Real s): r{r}, s{s}
{
	if(r <= Real{} || s <= Real{})

		throw Error{"Helix"};
}

Real Helix::radius() const
{
	return r;
}

Real Helix::step() const
{
	return s;
}

Vector Helix::point(Real t) const
{
	return {r*cos(t),r*sin(t),s*t/2/pi};
}

Vector Helix::derivative(Real t) const
{
	return {-r*sin(t),r*cos(t),s/2/pi};
}

}
