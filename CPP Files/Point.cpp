#include<iostream>
#include"Point.h"

Point::Point()
	:x(0)
	,y(0)
	,z(0)
{}
Point::Point(double x, double y, double z)
	:x(x)
	,y(y)
	,z(z)
{}
Point::Point(const Point& other)
	:x(other.x)
	,y(other.y)
	,z(other.z)
{}
Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}

	return *this;
}
Point::~Point()
{}

bool Point:: operator==(const Point&p)const
{
	if (x == p.x && y == p.y && z == p.z)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void Point:: setX(double X)
{
	x = X;
}
void Point:: setY(double Y)
{
	y=Y;
}
void Point:: setZ(double Z)
{
	z = Z;
}

double Point:: getX()const
{
	return x;
}
double Point:: getY()const
{
	return y;
}
double Point:: getZ()const
{
	return z;

}



std::ostream& Point::write(std::ostream&out)const
{
	 out<< "(" << x << "," << y << "," << z << ")";
	out << std::endl;
	return out;
}

std::istream& Point::input(std::istream& in)
{
	std::cout << "Input x:" << std::endl;
	in >> x;
	std::cout << std::endl;

	std::cout << "Input y:" << std::endl;
	in >> y;
	std::cout << std::endl;

	std::cout << "Input z:" << std::endl;
	in >> z;
	std::cout << std::endl;

	return in;
}

std::istream& operator>>(std::istream& in, Point& p)
{
	p.input(in);
	return in;
}

std::ostream& operator<<(std::ostream& out,  const Point& p)
{
	p.write(out);
	return out;
}
