#include<iostream>
#include"Segment.h"

Segment::Segment()
	:start(0)
	,end(1)
{}
Segment::Segment(const Line& l, double start, double end)
	:Line(l)
	,start(start)
	,end(end)
{
	X.setX(A.getX() + l.getX() * start);
	X.setY(A.getY() + l.getY() * start);
	X.setZ(A.getZ() + l.getZ() * start);

	Y.setX(A.getX() + l.getX() * end);
	Y.setY(A.getY() + l.getY() * end);
	Y.setZ(A.getZ() + l.getZ() * end);


}
Segment::Segment(const Segment& other)
	:Line(other)
	,start(other.start)
	,end(other.end)
	,X(other.X)
	,Y(other.Y)
{}
Segment& Segment::operator=(const Segment& other)
{
	if (this != &other)
	{
		Line::operator=(other);
		start = other.start;
		end = other.end;
		X = other.X;
		Y = other.Y;

	}
	
	return*this;
}
Segment::~Segment(){}

std::istream& Segment::input(std::istream&in)
{
	
		std::cout << "Line:\n ";
		Line l;
		l.input(in);
		std::cout << "Start:\n ";
		in >> start;
		std::cout << "End:\n ";
		in >> end;

		X.setX(A.getX() + l.getX() * start);
		X.setY(A.getY() + l.getY() * start);
		X.setZ(A.getZ() + l.getZ() * start);

		Y.setX(A.getX() + l.getX() * end);
		Y.setY(A.getY() + l.getY() * end);
		Y.setZ(A.getZ() + l.getZ() * end);

		return in;
	

}
std::ostream& Segment::write(std::ostream&out)const
{
	out << "Segment:";
	out <<"X="<<"("<< X.getX()<<"," << X.getY()<<"," << X.getZ()<<")";
	out << "Y=" << "(" << Y.getX() << "," << Y.getY() << "," << Y.getZ() << ")";
	out << std::endl;

	return out;
}

Point Segment::SegmentCentre()const
{
	return Point((X.getX() + Y.getX()) / 2, (X.getY() + Y.getY()) / 2, (X.getZ() + Y.getZ()) / 2);


}

double Segment::SegmentLength()const
{
	Vector t(X, Y);

	return t.VectorLength();
	

}


bool Segment::operator==(const Point& p)const
{
	
	
	Vector ab(X, Y);
	Vector ap(X, p);
	Vector bp(p, Y);
	if (ab.VectorLength() == ap.VectorLength() + bp.VectorLength())
	{
		return true;
	}
	else
	{
		return false;
	}
	

}
