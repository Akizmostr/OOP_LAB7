#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

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
private:

};

double Trans::Sin(double angle) {
	double result = sin(angle);
	if (result > 1 || result < 1) {
		throw TransException("Sin is going beyond limit values");
	}
}

double Trans::Cos(double angle) {
	double result = Cos(angle);
	if (result > 1 || result < 1) {
		throw TransException("Cos is going beyond limit values");
	}
}

double Trans::Tan(double angle) {
	double tt = angle / M_PI_2;
	std::cout << tt << std::endl;
	if (fabs(angle/M_PI_2 - round(angle/M_PI_2)) < 1e-16){
		std::cout << "bad";
	}
	double result = tan(angle);
	return result;
}

int main()
{
	Trans k;
	std::cout << tan(M_PI_2) << std::endl;
	std::cout << k.Tan(M_PI_2*4) << std::endl;
}
