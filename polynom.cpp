#include "polynom.h"
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

template <typename T>
T exp(T t1, int n) {
	T res = 1;
	while (n > 0) {
		if (!(n % 2))
			res *= t1;
		t1 *= t1;
		n /= 2;
	}
	return res;
}

Polynom::Polynom() {
	name = "";
	var = 'x';
	deg = 0;
	coef.push_back(0);
}

Polynom::Polynom(const std::string & _name, const char _var, const std::vector<double> & _coef) {
	name = _name;
	var = _var;
	coef = _coef;
	deg = coef.size();
}

Polynom::Polynom(const Polynom & p) {
	name = p.name;
	var = p.var;
	deg = p.deg;
	for (int i = 0; i <= deg; ++i)
		coef[i] = p.coef[i];
}

Polynom::Polynom(std::string & str) {
	name = "";
	auto it = str.begin();
	while (*it != '(')
		name += *(it++);
	var = *(it + 1);
	deg = 0;
	std::cout << name << " " << var << std::endl;
	it += 4;
	while (it < str.end()) {
		std::size_t index;
		if (*it == '*' || *it == '^' || *it == var) {
			it++;
			continue;
		}
		str.erase(str.begin(), it);
		std::cout << str << std::endl;
		double a = std::stod(str, & index);
		it += index;
		if (*it == '*') {
			str.erase(str.begin(), ++it);
			int n = std::stoi(str, & index);
			it += index;
			if (n > deg) {
				coef.resize(n + 1, 0);
				deg = n;
			}
			coef[n] = a;
		}
		else
			coef[0] = a;
	}
}

Polynom::Polynom(int k) {
	name = "";
	var = 'x';
	deg = 0;
	coef.push_back(k);
}

Polynom::~Polynom() {}

const Polynom & operator+(const Polynom & p) {
	return p;
}

const Polynom operator+(const Polynom & p, const Polynom & q) {
	int max_deg = p.deg > q.deg ? p.deg : q.deg;
	std::vector<double> coef(max_deg + 1);
	for (auto it = coef.begin(); it != coef.end(); ++it)
		*it = *(p.coef.begin() + 1) + *(q.coef.begin() + 1);
	return Polynom(p.name, p.var, coef);
}

const Polynom operator-(const Polynom & p) {
	std::vector<double> coef = p.coef;
	for (auto it = coef.begin(); it != coef.end(); ++it)
		*it = -(*it);
	return Polynom(p.name, p.var, coef);
}

const Polynom operator-(const Polynom & p, const Polynom & q) {
	return p + (-q);
}

const Polynom operator*(const Polynom & p, const Polynom & q) {
	int deg = p.deg + q.deg;
	std::vector<double> coef(deg);
	for (int i = 0; i <= deg; ++i) {
		coef[i] = 0;
		for (int j = i; j >= 0; --j)
			coef[i] += p.coef[j] * q.coef[i - j];
	}
	return Polynom(p.name, p.var, coef);
}

std::istream & operator>>(std::istream & is, Polynom & p) {
	std::string str;
	std::getline(is, str);
	p = Polynom(str);
	return is;
}

std::ostream & operator<<(std::ostream & os, Polynom & p) {
	os << p.name << '(' << p.var << ")=";
	for (int i = p.deg; i >= 0; ++i)
		if (p.coef[i] != 0)
			os << p.coef[i] << '*' << p.var << '^' << i;
	return os;
}

Polynom & Polynom::operator=(const Polynom & p) {
	name = p.name;
	var = p.var;
	deg = p.deg;
	for (int i = 0; i < deg; ++i)
		coef[i] = p.coef[i];
	return *this;
}

Polynom & Polynom::operator=(int k) {
	name = "";
	var = 'x';
	deg = 0;
	coef.push_back(k);
	return *this;
}

Polynom & operator+=(Polynom & p, const Polynom & q) {
	p = p + q;
	return p;
}

Polynom & operator-=(Polynom & p, const Polynom & q) {
	p = p + (-q);
	return p;
}

Polynom & operator*=(Polynom & p, const Polynom & q) {
	p = p * q;
	return p;
}

Polynom & Polynom::change_name(char *new_name) {
	name = new_name;
	return *this;
}

Polynom Polynom::change_var(const Polynom & p) {
	Polynom a = p;
	Polynom res = coef[0];
	for (int i = 1; i <= deg; ++i) {
		res += a * coef[i];
		a *= p;
	}
	return res;
}

Polynom Polynom::derivative() {
	Polynom p = *this;
	for (int i = 0; i < p.deg; ++i)
		p.coef[i] = i * p.coef[i + 1];
	--p.deg;
	return p;
}