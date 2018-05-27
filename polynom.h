#ifndef POLYNOM_H_
#define POLYNOM_H_

#include <iostream>
#include <vector>
#include <string>

template <typename T>
T exp(T t1, int n);

class Polynom {
private:
	friend class Interface;
	std::string name;
	char var;
	int deg;
	std::vector<double> coef;
public:
	Polynom();
	Polynom(const std::string & _name, const char _var, const std::vector<double> & _coef);
	Polynom(const Polynom & p);
	Polynom(std::string & polynom);
	Polynom(int k);
	~Polynom();
	friend const Polynom & operator+(const Polynom & p);
	friend const Polynom operator+(const Polynom & p, const Polynom & q);
	friend const Polynom operator-(const Polynom & p);
	friend const Polynom operator-(const Polynom & p, const Polynom & q);
	friend const Polynom operator*(const Polynom & p, const Polynom & q);
	friend std::istream & operator>>(std::istream & is, Polynom & p);
	friend std::ostream & operator<<(std::ostream & os, Polynom & p);
	Polynom & operator=(const Polynom & p);
	Polynom & operator=(int k);
	friend Polynom & operator+=(Polynom & p, const Polynom & q);
	friend Polynom & operator-=(Polynom & p, const Polynom & q);
	friend Polynom & operator*=(Polynom & p, const Polynom & q);
	Polynom & change_name(char *new_name);
	Polynom change_var(const Polynom & sub);
	Polynom derivative();
};

#endif