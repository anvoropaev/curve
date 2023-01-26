#ifndef CURVE_202301262239310000
#define CURVE_202301262239310000

#include <stdexcept>
#include <ostream>

namespace Curve
{
// basic and auxiliary stuff

using Real = double;

using Error = std::domain_error;

extern const Real pi;

struct Vector
{
	Real x, y, z;
};

std::ostream& operator<<(std::ostream &o, const Vector &v);

// abstract curve class

class Curve
{
public:
	virtual Vector point(Real t) const = 0;

	virtual Vector derivative(Real t) const = 0;
};

// circle class

class Circle: public Curve
{
	Real r;
public:
	Circle(Real r);

	Real radius() const;

	Vector point(Real t) const override;

	Vector derivative(Real t) const override;
};

// ellipse class

class Ellipse: public Curve
{
	Real rx, ry;
public:
	Ellipse(Real rx, Real ry);

	Real xradius() const;

	Real yradius() const;

	Vector point(Real t) const override;

	Vector derivative(Real t) const override;
};

// helix class

class Helix: public Curve
{
	Real r, s;
public:
	Helix(Real r, Real s);

	Real radius() const;

	Real step() const;

	Vector point(Real t) const override;

	Vector derivative(Real t) const override;
};

}

#endif
