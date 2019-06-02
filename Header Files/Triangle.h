#ifndef __TRIANGLE__H__
#define __TRIANGLE__H__

#include<iostream>
#include<fstream>
#include"Point.h"

class EqualPointException :public std::exception
{
public:

	EqualPointException(const char* r);
	const char* what()const;

private:

	const char* reason;
};


class Triangle:public Point
{

public:

	Triangle();
	Triangle(const Point& a, const Point& b, const Point& c);
	Triangle(const Triangle& other);
	Triangle& operator=(const Triangle& other);
	~Triangle();

	void TriangleType()const;
	double TriangleArea()const;
	double TrianglePerimeter()const;
	Point TriagnleMedi()const;

	bool operator<(const Point&P)const;
	bool operator>(const Point& P)const;
	bool operator==(const Point& P)const;

	virtual std::ostream& write(std::ostream&)const;
	virtual std::istream& input(std::istream&);

private:

	Point A;
	Point B;
	Point C;

};
#endif // !__TRIANGLE__H__
