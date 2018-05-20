#include "polynom.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <string.h>

Polynom::Polynom() {
	variable = 'x';
	coeff.resize(0);
	degree = 0;
}

Polynom::Polynom(std::vector<std::pair<double, int>> & _coeff, char _variable) {
	variable = _variable;
	std::sort(_coeff.begin(), _coeff.end(), [](auto &left, auto &right) {
		return left.second < right.second;
	});
	degree = _coeff.begin() -> second;
	for (int i = 0; i <= degree; ++i) {
		auto j = _coeff.begin();
		if (j -> second != i)
			coeff.push_back(std::make_pair(0, i));
		else
			coeff.push_back(std::make_pair((j++) -> first, i));
	}
}

Polynom::~Polynom() {}

std::istream & operator>>(std::istream & is, Polynom & p) {
	std::vector<std::pair<double, int>> _coeff;
	char spol[STR_MAX_SIZE];
	is.getline(spol, STR_MAX_SIZE);
	char *pstr = spol;
	double a = strtod(pstr, &pstr);
	char var = pstr[0];
	int deg = strtol(pstr, &pstr, 10);
	_coeff.push_back(std::make_pair(a, deg));
	for (unsigned int i = 0; i < strlen(pstr); ++i) {
		a = strtod(pstr, &pstr);
		deg = strtol(pstr, &pstr, 10);
		_coeff.push_back(std::make_pair(a, deg));
	}
	p = Polynom(_coeff, var);
	return is;
}

std::ostream & operator<<(std::ostream & os, const Polynom & p) {
	os << p.coeff[p.degree].first << p.variable << '^' << p.coeff[p.degree].second;
	for (int i = p.degree - 1; i >= 0; --i)
		if (p.coeff[p.degree].second)
			os << (p.coeff[p.degree].first > 0 ? "+" : "") 
			<< p.coeff[p.degree].first << p.variable << '^' << p.coeff[p.degree].second;
	return os;
}

Polynom Polynom::operator+(const Polynom & p) const {
	Polynom q;
	q.degree = (degree > p.degree ? degree : p.degree);
	q.variable = variable;
	for (int i = 0; i <= (degree < p.degree ? degree : p.degree); ++i)
		q.coeff.push_back(std::make_pair(coeff[i].first + p.coeff[i].first, i));
	return q;
}

Polynom Polynom::operator-(const Polynom & p) const {
	Polynom q;
	q.degree = (degree > p.degree ? degree : p.degree);
	q.variable = variable;
	for (int i = 0; i <= (degree < p.degree ? degree : p.degree); ++i)
		q.coeff.push_back(std::make_pair(coeff[i].first - p.coeff[i].first, i));
	return q;
}
// Change it
Polynom Polynom::operator*(const Polynom & p) const {
	Polynom q;
	q.variable = variable;
	q.degree = degree + p.degree;
	for (int i = q.degree; i >= 0; --i) {
		double a = 0;
		for (int j = q.degree - i; j >= 0; --j) {
			int deg1 = degree;
			int deg2 = p.degree - j;
			a += coeff[deg1--].first * p.coeff[deg2++].first;
		}
		q.coeff.push_back(std::make_pair(a, i));
	}
	std::sort(q.coeff.begin(), q.coeff.end(), [](auto &left, auto &right) {
	return left.second < right.second;
	});
	return q;
}

Polynom & Polynom::operator=(const Polynom & p) {
	variable = p.variable;
	degree = p.degree;
	coeff = p.coeff;
	return *this;
}

Polynom Polynom::operator*(const double k) const {
	Polynom q;
	q.degree = degree;
	q.variable = variable;
	for (int i = 0; i <= degree; ++i)
		q.coeff[i].first *= k;
	return q;
}

Polynom operator*(const double k, const Polynom & p) {
	return p * k;
}

Polynom & Polynom::operator+=(const Polynom & p) {
	*this = *this + p;
	return *this;
}

Polynom & Polynom::operator-=(const Polynom & p) {
	*this = *this - p;
	return *this;	
}

Polynom & Polynom::operator*=(const Polynom & p) {
	*this = *this * p;
	return *this;	
}

Polynom Polynom::exponent(Polynom & p, int n) {
	*this = p;
	degree *= n;
	--n;
	while (n) {
		if (n % 2)
			*this *= p;
		p *= p;
		n >>= 1;
	}
	return *this;
}

Polynom Polynom::change_var(Polynom p) {
	Polynom q;
	q.variable = p.variable;
	for (int i = 1; i <= degree; ++i) {
		q += p * coeff[i].first;
		p *= p;
	}
	return q;
}

Polynom & Polynom::derivative() {
	for (int i = degree; i > 0; --i) {
		
	}
	return ;
}

