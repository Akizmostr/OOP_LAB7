#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <typeinfo>
#include <string>

//#define pi M_PI ;
//#define pi_2 M_PI_2;
//#define  pi_4 M_PI_4;

class TransException {
public:
	virtual std::string what() = 0;
protected:
	TransException(std::string error, double value) :m_error(error), val(value) {
	}
	double val;
	std::string m_error;
};

class TrigException : public TransException {
public:
	TrigException(std::string error, double value) : TransException(error, value) {
	}
	double getValue() { return val; }
	virtual std::string what() override {
		std::string error = "Trigonometric error." + m_error;
		return error;
	}
};

class LogException : public TransException {
public:
	LogException(std::string error, double value) : TransException(error, value) {
	}
	double getValue() { return val; }
	virtual std::string what() override {
		std::string error = "Logarithmic error." + m_error;
		return error;
	}
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
	double Lg(double);
};

double Trans::Sin(double angle) {
	double result = sin(angle);
	return result;
}

double Trans::Cos(double angle) {
	double result = cos(angle);
	return result;
}

double Trans::Tan(double angle) {
	if (angle > 2*M_PI || angle < 0) {
		throw TrigException("Invalid argument: angle of tan must be between 0 and 2PI. The angle is " + std::to_string(angle), angle);
	}
	if (angle == M_PI_2 || angle == 3 * M_PI_2) {
		throw TrigException("Invalid argument: tan is undefined. The angle is " + std::to_string(angle), angle);
	}
	double result = tan(angle);
	return result;
}

double Trans::Asin(double arg) {
	if (arg > 1 || arg < -1) {
		throw TrigException("Invalid argument: asin argument must be between -1 and 1. The argument is " + std::to_string(arg), arg);
	}
	return asin(arg);
}

double Trans::Acos(double arg) {
	if (arg > 1 || arg < -1) {
		throw TrigException("Invalid argument: acos argument must be between -1 and 1. The argument is " + std::to_string(arg), arg);
	}
	
	return acos(arg);
}

double Trans::Atan(double arg) {
	return atan(arg);
}

double Trans::Ln(double arg) {
	if (arg <= 0) {
		throw LogException("Invalid argument: ln argument must be more than 0. The argument is " + std::to_string(arg), arg);
	}
	return log(arg);
}

double Trans::Lg(double arg) {
	if (arg <= 0) {
		throw LogException("Invalid argument: lg argument must be more than 0. The argument is " + std::to_string(arg), arg);
	}
	return log10(arg);
}

int main()
{
	Trans k;

	try {
		std::cout << "tan: " <<  k.Tan(M_PI/2) << std::endl;
		std::cout << "asin: " << k.Asin(1) << std::endl;
		std::cout << "acos: " << k.Acos(0) << std::endl;
		std::cout << "atan: " << k.Atan(1e+308) << std::endl;
		std::cout << "ln: " << k.Ln(0) << std::endl;
		std::cout << "lg: " << k.Lg(0) << std::endl;
		int f = 0;
		if (f == 0) {
			throw 0;
		}
		int x = 2 / f;
	}
	catch (TrigException& exception) {
		std::cout << exception.what() << std::endl;
	}
	catch (LogException& exception) {
		std::cout << exception.what() << std::endl;
	}
	catch (...) {
		std::cout << "Another exception" << std::endl;
	}
}
