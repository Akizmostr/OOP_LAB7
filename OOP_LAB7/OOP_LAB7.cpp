#include <iostream>
#include <cmath>
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

}

int main()
{
    std::cout << "Hello World!\n";
}
