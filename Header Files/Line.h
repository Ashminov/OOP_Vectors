#ifndef __LINE__H__
#define __LINE__H__

#include"Vector.h"
#include<iostream>

class Line :public Vector
{

public:

	Line();
	Line(const Point&,const Vector&);
	Line(const Point&,const Point&);
	Line(const Line& other);
	Line& operator=(const Line& other);
	virtual ~Line();


	Vector LineDirection()const;
	Vector normal()const;
	double CalculateAngle(const Line&l)const;

	bool operator||(const Line&l)const;
	bool operator+(const Point& p)const;

	virtual std::ostream& write(std::ostream&)const;
	virtual std::istream& input(std::istream&);


protected:

	Point A;

};
#endif // !__LINE__H__
