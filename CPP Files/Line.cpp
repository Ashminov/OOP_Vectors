#include<iostream>
#include"Line.h"
#include<cmath>

#define PI 3.14

Line::Line()
{}
Line::Line(const Point&a, const Vector& b):Vector(b)
{
	A = a;
	

}
Line::Line(const Point&a, const Point&b):Vector(a,b)
{
	A = a;

}

std::istream& Line::input(std::istream& in)
{
	A.input(in);
	Vector::input(in);
	return in;
}


std::ostream& Line::write(std::ostream&out)const
{
	
	out << "Line:";
	out << "(" << A.getX() << "," << A.getY() << "," << A.getZ() << ")" << "+";
	out<<"t("<<Vector::getX()<<","<<Vector::getY()<<","<<Vector::getZ()<<")";
	out << std::endl;
	return out;
}

Line::Line(const Line& other)
	:A(other.A)
	,Vector(other)
{}
Line& Line::operator=(const Line& other)
{

	if (this != &other)
	{
		A = other.A;
		Vector::operator=(other);
	}
		
	return*this;
}

Line::~Line()
{

}


Vector Line::LineDirection()const
{
	return Vector(x, y, z);
}

Vector Line::normal()const
{
	
	return Vector(x,y,z).VectorDirection();
}

double Line::CalculateAngle(const Line&l)const
{
	double cos = 0.;
	Vector t(x,y,z);
	Vector t1(l.x, l.y,l.z);
	cos = (t * t1) / (t.VectorLength() * t1.VectorLength());
	double res = 0.;

	res = (acos(cos)*180/PI)*PI/180;
	return res;
}

bool Line::operator||(const Line& l)const
{
	
	if (this->LineDirection().VectorPerpendi(l.LineDirection()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Line::operator+(const Point& other)const
{

	Point B(A.getX() + Vector::getX(), A.getY() + Vector::getY(), A.getZ() + Vector::getZ());

	//(x - x1) / (x2 - x1) = (y - y1) / (y2 - y1) = (z - z1) / (z2 - z1)
	if	(((other.getX() - A.getX()) / (B.getX() - A.getX())) == ((other.getY() - A.getY()) / (B.getY() - A.getY())) &&
		((other.getX() - A.getX()) / (B.getX() - A.getX())) == ((other.getZ() - A.getZ()) / (B.getZ() - A.getZ())) &&
		((other.getY() - A.getY()) / (B.getY() - A.getY())) == ((other.getZ() - A.getZ()) / (B.getZ() - A.getZ()))
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}
