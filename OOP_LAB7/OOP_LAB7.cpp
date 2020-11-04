#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <typeinfo>

//#define pi M_PI ;
//#define pi_2 M_PI_2;
//#define  pi_4 M_PI_4;

class TransException:public std::exception {
public:
	TransException(std::string error):m_error(error) {
	}
	const char* what() noexcept {
		return m_error.c_str();
	}
private:
	std::string m_error;
};


class Trans {
public:
	double Sin(double);
	double Cos(double);
	double Tan(double);
	double Asin(double);
	double Acos(double);
	double Atan(double);
	double Ln(double);
private:

};

double Trans::Sin(double angle) {
	double result = sin(angle);
	if (result > 1 || result < 1) {
		throw TransException("Result error");
	}
}

double Trans::Cos(double angle) {
	double result = Cos(angle);
	if (result > 1 || result < 1) {
		throw TransException("Result error");
	}
}

double Trans::Tan(double angle) {
	if (angle > 2*M_PI || angle < 0) {
		throw TransException("Invalid argument");
	}
	if (angle == M_PI_2 || angle == 3 * M_PI_2) {
		throw TransException("Invalid argument");
	}
	double result = tan(angle);
	return result;
}

double Trans::Asin(double arg) {
	if (arg > 1 || arg < -1) {
		throw TransException("Invalid argument");
	}
	return asin(arg);
}

double Trans::Acos(double arg) {
	if (arg > 1 || arg < -1) {
		throw TransException("Invalid argument");
	}
	
	return acos(arg);
}

double Trans::Atan(double arg) {
	return atan(arg);
}


double Trans::Ln(double arg) {
	if (arg <= 0) {
		throw TransException("Invalid argument");
	}
	return log(arg);
}

int main()
{
	Trans k;
	std::cout << k.Tan(M_PI/4) << std::endl;
	std::cout << k.Asin(1) << std::endl;
	std::cout << k.Acos(0) << std::endl;
	std::cout << k.Atan(1e+308) << std::endl;
	std::cout << k.Ln(0) << std::endl;
}
