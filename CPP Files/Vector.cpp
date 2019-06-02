#include<iostream>
#include<string>
#include"Vector.h"

VectorLengthException::VectorLengthException(const char* r)
	:reason(r)
{}
const char* VectorLengthException::what()const
{
	return reason;
}


Vector::Vector(double x, double y, double z)
	:Point(x,y,z)
{
	
}

Vector::Vector(const Point &a, const Point &b)
	:A(a)
	,B(b)
{
	
	x = B.getX() - A.getX();
	y = B.getY() - A.getY();
	z = B.getZ() - A.getZ();

}

Vector::Vector(const Vector& other)
	:Point(other)
	,A(other.A)
	,B(other.B)
{}

Vector&Vector::operator=(const Vector& other)
{
	if (this != &other)
	{
		Point::operator=(other);
		A = other.A;
		B = other.B;
	}

	return *this;

}

double Vector:: VectorLength()const
{
	
	return (sqrt(x * x + y * y + z * z));
	
}
Vector Vector::VectorDirection()const
{
	try
	{
		
		if (VectorLength() <= 0)
		{
			throw VectorLengthException("Illegal Value");
		}
		else
		{
			return Vector((x / VectorLength()), (y / VectorLength()), (z / VectorLength()));

		}

	}
	catch (VectorLengthException& e)
	{
		std::cerr << "Caught Exception:" << e.what() << std::endl;
		std::cerr << "Type:" << typeid(e).name() << std::endl;
 		return *this;
	}
		
	
}

bool Vector::VectorNull()const
{
	if (x == 0 && y == 0 && z == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Vector::VectorPrallelism(const Vector&v)const
{
	try
	{
		if (VectorLength() <= 0 || v.VectorLength()<=0)
		{
			throw VectorLengthException("Null Length");
		}
		else
		{
				
			if ((x / v.x) == (y / v.y) && (x / v.x) == (z / v.z) && (y / v.y) == (z / v.z))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	catch (VectorLengthException& e)
	{
		std::cerr << "Caught Exception:" << e.what() << std::endl;
		std::cerr << "Type:" << typeid(e).name() << std::endl;

	}

	
}

bool Vector::VectorPerpendi(const Vector& v)const
{
	try
	{
		if (VectorNull() == true || v.VectorNull()==true)
		{
			throw VectorLengthException("Null Vector");
		}
		else
		{
			if (x * v.x + y * v.y + z * v.z == 0)
			{
				return true;
				
			}
			else
			{
				return false;
			}
		}

	}
	catch (VectorLengthException& e)
	{
		std::cerr << "Caught Exception:" << e.what() << std::endl;
		std::cerr << "Type:" << typeid(e).name() << std::endl;

	}
}

Vector Vector::operator+(const Vector& other)const
{
	return Vector(x + other.x, y + other.y, z + other.z);
}
Vector Vector::operator-(const Vector& other)const
{
	return Vector(x - other.x, y - other.y, z - other.z);
}

Vector operator*(double r, const Vector& rhs)
{
	return Vector(r * rhs.getX(), r * rhs.getY(), r * rhs.getZ());

}

double Vector::operator*(const Vector& other)const
{
	return (x * other.x + y*other.y + z * other.z);
}

Vector Vector::operator^(const Vector& other)const
{
	return Vector(y * other.z - z * other.y, -x * other.z + z * other.x, x * other.y - y * other.x);

}

double Vector::operator()(const Vector& v, const Vector& w)const
{
	
	return  x * v.y * w.z + y * v.z * w.x + z * v.x * w.y - x * v.z * w.y - y * v.x * w.z - z * v.y * w.x;
}


std::istream& Vector::input(std::istream& in)
{
	Point::input(in);

	return in;
}

std::ostream& Vector::write(std::ostream& out)const
{
	Point::write(out);
	return out;
}

Vector::~Vector()
{}

