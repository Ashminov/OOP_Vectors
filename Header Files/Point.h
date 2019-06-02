#ifndef __POINT__H__
#define __POINT__H__

#include<iostream>
#include"Element.h"

class Point:public Element
{
public:

	Point();
	Point(double x, double y, double z);
	Point(const Point& other);
	Point& operator=(const Point& other);
	virtual~Point();

	virtual bool operator==(const Point&)const;
	

	virtual std::ostream& write(std::ostream&)const;

	void setX(double);
	void setY(double);
	void setZ(double);

	double getX()const;
	double getY()const;
	double getZ()const;

	virtual std::istream& input(std::istream&);

protected:

	double x;
	double y;
	double z;

};

std::ostream& operator<<(std::ostream& out, const Point&);
std::istream& operator>>(std::istream& in, Point&);
#endif // !__POINT__H__
