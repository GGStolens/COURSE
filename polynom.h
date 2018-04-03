#ifndef POLYNOM_H_
#define POLYNOM_H_

#include <vector>
#include <utility>
#include <iostream>

const int STR_MAX_SIZE = 1000;

class Polynom {
private:
	std::vector<std::pair<double, int>> coeff;
	char variable;
	int degree;
public:
	Polynom();
	Polynom(std::vector<std::pair<double, int>> &, char);
	~Polynom();
	Polynom operator+(const Polynom &) const;
	Polynom operator-(const Polynom &) const;
	Polynom operator*(const Polynom &) const;
	Polynom & operator=(const Polynom & p);
	Polynom & operator+=(const Polynom & p);
	Polynom & operator-=(const Polynom & p);
	Polynom & operator*=(const Polynom & p);
	friend std::istream & operator>>(std::istream &, Polynom &);
	friend std::ostream & operator<<(std::ostream &, const Polynom &);
	Polynom exponent(int);
	Polynom & change_var(const Polynom &);
	Polynom & derivative();
};

#endif