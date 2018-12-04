#include <iostream.h>
const double PI=3.1415926;
class Circle
{
public:
	//系统接口
	Circle(double Ra=0)	{ Radius=Ra;}

	//用户接口
	double Area(){return PI*Radius*Radius;}
	double PeriMeter(){return 2*PI*Radius;}
private:
	double Radius;
};
void main()
{
	double r;
	cin>>r;

	Circle c1(r),c2(r+3);

	cout<<c1.Area()<<endl;


}