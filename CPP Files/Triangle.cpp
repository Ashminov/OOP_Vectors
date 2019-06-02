#include<iostream>
#include<fstream>
#include"Triangle.h"
#include"Vector.h"

EqualPointException::EqualPointException(const char* r)
	:reason(r)
{}
const char* EqualPointException::what()const
{
	return reason;
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
	:A(a)
	,B(b)
	,C(c)
{

	try
	{
		if (A.operator==(B))
		{

			throw EqualPointException("Point A=Point B");
		}
		if (A.operator==(C))
		{
			throw EqualPointException("Point A=Point C");
		}
		if (B.operator==(C))
		{
			throw EqualPointException("Point B=Point C");
		}
		
	}
	catch (EqualPointException& e)
	{
		std::cerr << "Caught exception:" << e.what() << std::endl;
		std::cerr << "Type:" << typeid(e).name() << std::endl;
	}
	
}
Triangle:: Triangle(const Triangle& other)
	:Point(other)
	,A(other.A)
	,B(other.B)
	,C(other.C)
{


}
Triangle&Triangle::operator=(const Triangle& other)
{
	if (this != &other)
	{
		Point::operator=(other);
		A = other.A;
		B = other.B;
		C = other.C;
	}

	return*this;

}

Triangle::~Triangle()
{}

void Triangle::TriangleType()const
{
	Vector AB(A, B);
	Vector AC(A, C);
	Vector BC(B, C);
	
	Vector CA(C, A);
	Vector CB(C, B);
	Vector BA(B, A);

	std::ofstream output("output.txt");
	

	if (AB.VectorLength() == AC.VectorLength() && AB.VectorLength()== BC.VectorLength() && BC.VectorLength()==AC.VectorLength())
	{
		std::cout << "Triangle is equilateral" << std::endl;
		output << "Triangle is eqilateral" << std::endl;
	}
	else if (AB.VectorLength() == AC.VectorLength() || AB.VectorLength() == BC.VectorLength() || AC.VectorLength() == BC.VectorLength())
	{
		std::cout << "Triangle is isosceles" << std::endl;
		output << "Triangle is isosceles" << std::endl;

	}

	double angle1 = 0.;
	angle1 = (AC * AB) / (AC.VectorLength() * AB.VectorLength());

	double angle2 = 0.;
	angle2 = (BC * BA) / (BC.VectorLength() * BA.VectorLength());

	double angle3 = 0.;
	angle3 = (CA * CB) / (CA.VectorLength() * CB.VectorLength());

	if (angle1 > 0. && angle2 > 0. && angle3 > 0.)
	{
		std::cout << "Triangle is acute - angled" << std::endl;
		output << "Triangle is acute - angled" << std::endl;

	}
	 if (angle1 < 0. || angle2 < 0. || angle3 < 0.)
	{
		std::cout << "Triangle is octagonal" << std::endl;
		output << "Triangle is octagonal" << std::endl;

	}
	 if (angle1 == 0. || angle2 == 0. || angle3 == 0.)
	{
		std::cout << "Triangle is rectangular" << std::endl;
		output<< "Triangle is rectangular" << std::endl;
	 }

}


double Triangle::TriangleArea()const
{

	Vector AB(A, B);
	Vector AC(A, C);
	
	Vector C = (AB ^ AC);

	return (C.VectorLength()/ 2);


}

double Triangle::TrianglePerimeter()const
{
	Vector AB(A, B);
	Vector AC(A, C);
	Vector BC(B, C);

	return(AB.VectorLength() + AC.VectorLength() + BC.VectorLength());

}

Point Triangle:: TriagnleMedi()const
{

	return Point((A.getX() + B.getX() + C.getX()) / 3, (A.getY() + B.getY() + C.getY()) / 3, (A.getZ() + B.getZ() + C.getZ())/ 3);
}

bool Triangle::operator<(const Point& P)const
{
	
	Triangle abc(A, B, C);
	Triangle abp(A, B, P);
	Triangle bcp(B, C, P);
	Triangle acp(A, C, P);

	if (abc.TriangleArea() == (abp.TriangleArea() + bcp.TriangleArea() + acp.TriangleArea()))
	{
		return true;
	}
	else
	{
		return false;
	}

}
bool Triangle::operator>(const Point& P)const
{

	Triangle abc(A, B, C);
	Triangle abp(A, B, P);
	Triangle bcp(B, C, P);
	Triangle acp(A, C, P);

	if (abc.TriangleArea() != (abp.TriangleArea() + bcp.TriangleArea() + acp.TriangleArea()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Triangle::operator==(const Point& P)const
{
	Triangle abp(A, B, P);
	Triangle acp(A, C, P);
	Triangle bcp(B, C, P);

	if (abp.TriangleArea() == 0 || acp.TriangleArea() == 0 || bcp.TriangleArea() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Triangle::Triangle()
{}
std::istream&Triangle::input(std::istream& in)
{

	A.input(in);
	B.input(in);
	C.input(in);

	return in;

}
std::ostream& Triangle::write(std::ostream &out)const
{
	out<< "Triangle ABC:" << std::endl;
	out<< "(" << A.getX() << "," << A.getY() << "," << A.getZ() << ")" << std::endl;
	out << "(" << B.getX() << "," << B.getY() << "," << B.getZ() << ")" << std::endl;
	out << "(" << C.getX() << "," << C.getY() << "," << C.getZ() << ")" << std::endl;
	return out;
}
