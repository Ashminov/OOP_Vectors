#ifndef __SEGMENT__H__
#define __SEGMENT__H__

#include<iostream>
#include"Line.h"
class Segment:public Line
{

public:

	Segment();
	Segment(const Line& l,double start,double end);
	Segment(const Segment& other);
	Segment& operator=(const Segment& other);
	~Segment();

	double SegmentLength()const;
	Point SegmentCentre()const;
	bool operator==(const Point& p)const;

	virtual std::ostream& write(std::ostream&)const;
	virtual std::istream& input(std::istream&);

private:

	double start;
	double end;
	Point  X;
	Point Y;
};
#endif // !__SEGMENT__H__
