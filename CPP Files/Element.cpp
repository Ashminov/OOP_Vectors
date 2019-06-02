#include<iostream>
#include"Element.h"

std::ostream& operator<<(std::ostream& out, const Element& p)
{
	p.write(out);
	return out;
}

std::istream& operator>>(std::istream& in, Element& p)
{
	p.input(in);
	return in;
}
