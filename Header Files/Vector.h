#ifndef __VECTOR__H__
#define __VECTOR__H__

#include"Point.h"
#include <exception>
#include"Element.h"

class VectorLengthException:public std::exception
{
public:

	VectorLengthException(const char* r);
	const char* what()const;

private:

	const char*reason;
};

class Vector:public Point
{

public:

	
	Vector(double=0., double=0., double=0.);
	Vector(const Point &A, const Point &B);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	virtual ~Vector();

	double VectorLength()const;
	Vector VectorDirection()const;
	
	bool VectorNull()const;
	bool VectorPrallelism(const Vector&)const;
	bool VectorPerpendi(const Vector&)const;

	Vector operator+(const Vector& other)const;
	Vector operator-(const Vector& other)const;
	double operator*(const Vector& other)const;
	Vector operator^(const Vector& other)const;
	double operator()(const Vector& v, const Vector& w)const;
	virtual std::ostream& write(std::ostream& out)const;
	virtual std::istream& input(std::istream& in);

private:

	Point A;
	Point B;
};
Vector operator*(double, const Vector&);

#endif