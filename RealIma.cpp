#include<iostream>

using namespace std;

class Complex
{
public:
	Complex()
	{
		_real = 0;
		_imag = 0;
	}
	Complex(double real, double imag)
	{
		_real = real;
		_imag = imag;
	}

	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);
	friend void print(const Complex& c);
private:
	double _real;
	double _imag;
};

inline Complex Complex::operator+(const Complex& c) //复数相加
{
	Complex c1(_real + c._real, _imag + c._imag);
	return c1;
	//return Complex(_real + c._real, _imag + c._imag);
}
inline Complex Complex:: operator-(const Complex& c) //复数相减
{
	return Complex(_real - c._real, _imag - c._imag);
}
inline Complex Complex::operator/(const Complex& c) //复数相除
{
	return Complex((_real*c._real + _imag*c._imag) / (c._real*c._real + c._imag*c._imag),
		(-_real*c._imag + _imag*c._real) / (c._real*c._real + c._imag*c._imag));
}
inline Complex Complex::operator*(const Complex& c)//复数相乘
{
	return Complex(_real*c._real - _imag*c._imag, _imag*c._real + _real*c._imag);
}
void print(const Complex& c)
{
	if (c._imag < 0)
	{
		cout << c._real << c._imag << "i"<<endl;
	}
	else
		cout << c._real << "+" << c._imag << "i"<<endl;
}
int main()
{
	Complex c1(2.0, 3.0);
	Complex c2(4.0, -2.0);
	Complex c3;

	cout << "c1+c2=";
	c3 = c1 + c2;
	print(c3);

	cout << "c1-c2=";
	c3 = c1 - c2;
	print(c3);

	cout << "c1*c2=";
	c3 = c1*c2;
	print(c3);

	cout << "c1/c2=";
	c3 = c1 / c2;
	print(c3);

	c3 = (c1 + c2)*(c1 - c2)*c2 / c1;
	cout << "(c1 + c2)*(c1 - c2)*c2 / c1=";
	print(c3);
	system("pause");
	return 0;

}