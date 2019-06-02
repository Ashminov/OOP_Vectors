#ifndef __ELEMENT__H__
#define __ELEMENT__H__

#include<iostream>
class Element
{


	friend::std::ostream& operator<<(std::ostream&, const Element&);
	friend::std::istream& operator>>(std::istream&, Element&);

	
	virtual std::ostream& write(std::ostream&)const=0;
	virtual std::istream& input(std::istream&)=0;
	
};
std::ostream& operator<<(std::ostream&,const Element&);
std::istream& operator>>(std::istream&, Element&);
#endif