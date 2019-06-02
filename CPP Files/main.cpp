#include<iostream>
#include"Point.h"
#include"Line.h"
#include"Element.h"
#include"Triangle.h"
#include"Vector.h"
#include"Segment.h"
#include<string>
#include<fstream>
using namespace std;

void createVectorFromFile(Vector&, ifstream&, ofstream&);
void createVector(Vector& v, ofstream& output);

ifstream& GotoLine(ifstream& file, unsigned int num) {
	file.seekg(std::ios::beg);
	for (int i = 0; i < num - 1; ++i) {
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return file;
}

int main()
{

	char choice;
	cout << "Do you want to write in a console or in a file c/f?" << endl;
	cin >> choice;

	int type = 0;

	if (choice == 'f')
	{
		ofstream output("output.txt");
		if (!output)
		{
			cerr << "Cannot open this file!" << endl;
			return -10;
		}

		ifstream file("vector.txt");
		if (!file.is_open())
		{
			cerr << "Not found this file!" << endl;
			return -2;
		}
		int shape;

		file >> shape;
		cout << endl;

		do
		{
			if (shape == 1)
			{

				Point p;
				file >> p;

				char con = 'y';
				while (con == 'y')
				{



					cout << "Point A:" << p << endl;
					output << "Point A:" << p << endl;

					cout << "Do you want new operation:" << endl;
					cin >> con;
					if (con == 'y')
					{

						Point p1;
						file >> p1;
						cout << "Point B:" << p1 << endl;
						output << "Point B:" << p1 << endl;
						cout << "A==B?" << endl;
						output << "A==B?" << endl;
						cout << boolalpha << (p == p1) << endl;
						output << boolalpha << (p == p1) << endl;

						GotoLine(file, 4);
					}


					cout << endl;


				}

				cout << "Do you want to check another object:y/n" << endl;
				char obj;
				cin >> obj;
				if (obj == 'y')
				{
					GotoLine(file, 1);
					file >> shape;


				}
				else if(obj=='n')
				{
					type = 7;
				}


			}
			if (shape == 2)
			{
				Vector b;
				createVectorFromFile(b, file, output);

				char con = 'y';
				while (con == 'y')
				{
					int oper;

					cout << "Please choose operation:" << endl;
					cout << "1. VectorLength" << endl;
					cout << "2.VectorDirection" << endl;
					cout << "3.Check is it Vector Null" << endl;
					cout << "4.Check for Parellism" << endl;
					cout << "5.Check for Perpendicular" << endl;
					cout << "6.Sum of 2 Vectors:" << endl;
					cout << "7.Sub of 2 Vectors:" << endl;
					cout << "8.Multi of Vector with Number:" << endl;
					cout << "9.Skalar Multi:" << endl;
					cout << "10.Vector Multi:" << endl;
					cout << "11.Mixed Multi:" << endl;
					GotoLine(file, 3);
					file >> oper;
					GotoLine(file, 2);
					cout << endl;
					if (oper == 1)
					{
						cout << "You choose 1." << endl;
						output << "You choose 1." << endl;

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << b.VectorLength() << endl;
						output << b.VectorLength() << endl;
					}
					else if (oper == 2)
					{
						cout << "You choose 2." << endl;
						output << "You choose 2." << endl;

						cout << "Result is:" << endl;
						output << "Result is:" << endl;

						cout << b.VectorDirection() << endl;
						output << b.VectorDirection() << endl;
					}
					else if (oper == 3)
					{
						cout << "You choose 3." << endl;
						output << "You choose 3." << endl;

						cout << "Result is:" << endl;
						output << "Result is:" << endl;

						cout << boolalpha << b.VectorNull() << endl;
						output << boolalpha << b.VectorNull() << endl;
					}
					else if (oper == 4)
					{
						cout << "You choose 4." << endl;
						output << "You choose 4." << endl;

						GotoLine(file, 4);
						Vector v1;
						createVectorFromFile(v1, file, output);


						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << boolalpha << b.VectorPrallelism(v1) << endl;
					}
					else if (oper == 5)
					{
						cout << "You choose 5." << endl;
						output << "You choose 5." << endl;
						GotoLine(file, 4);
						Vector v1;
						createVectorFromFile(v1, file, output);
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << boolalpha << b.VectorPerpendi(v1) << endl;
						output << boolalpha << b.VectorPerpendi(v1) << endl;
					}
					else if (oper == 6)
					{
						cout << "You choose 6." << endl;
						output << "You choose 6." << endl;

						Vector v1;
						GotoLine(file, 4);
						createVectorFromFile(v1, file, output);


						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << "Vector:" << b + v1 << endl;
						output << "Vector:" << b + v1 << endl;
					}
					else if (oper == 7)
					{
						GotoLine(file, 4);
						cout << "You choose 7." << endl;
						output << "You choose 7." << endl;
						Vector v1;
						createVectorFromFile(v1, file, output);

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << "Vector:" << b - v1 << endl;
						output << "Vector:" << b - v1 << endl;
					}
					else if (oper == 8)
					{
						GotoLine(file, 4);
						cout << "You choose 8." << endl;
						output << "You choose 8." << endl;
						double num;
						cout << "Please input a number:" << endl;
						file >> num;
						cout << endl;


						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << "Vector:" << num * b << endl;
						output << "Vector:" << num * b << endl;

					}
					else if (oper == 9)
					{

						GotoLine(file, 4);
						Vector v1;
						createVectorFromFile(v1, file, output);

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << "Vector:" << b * v1 << endl;
						output << "Vector:" << b * v1 << endl;

					}
					else if (oper == 10)
					{

						cout << "You choose 10." << endl;
						output << "You choose 10." << endl;

						GotoLine(file, 4);
						Vector v1;
						createVectorFromFile(v1, file, output);

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << "Vector:" << (b ^ v1) << endl;
						output << "Vector:" << (b ^ v1) << endl;
					}
					else if (oper == 11)
					{
						cout << "You choose 11." << endl;
						output << "You choose 11." << endl;
						GotoLine(file, 4);
						Vector v1;
						createVectorFromFile(v1, file, output);

						GotoLine(file, 4);
						Vector v2;
						createVectorFromFile(v2, file, output);

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << b(v1, v2) << endl;
						output << b(v1, v2) << endl;
					}

					cout << "Do you want to choose new operation:y/n" << endl;
					cin >> con;
					if (con == 'y')
					{
						GotoLine(file, 3);
					}
					cout << endl;

				}
				cout << "Do you want to check another object:y/n" << endl;
				char obj;
				cin >> obj;
				if (obj == 'y')
				{
					GotoLine(file, 1);
					file >> shape;


				}
				else if (obj == 'n')
				{
					type = 7;
				}

			}
			if (shape == 3)
			{
				char con = 'y';

				Line l;
				cout << "How do you want to create a line:" << endl;
				cout << "1. with 2 Points:" << endl;
				cout << "2.with one Point and Vector:" << endl;
				int type;
				cin >> type;
				if (type == 1)
				{

					Point p;
					file >> p;
					cout << "Point one:" << p << endl;
					output << "Point one:" << p << endl;

					Point p2;
					file >> p2;
					cout << "Point two:" << p2 << endl;
					output << "Point two:" << p2 << endl;

					l = Line(p, p2);
					cout << l << endl;
					output << l << endl;


				}
				else if (type == 2)
				{

					Point p;
					file >> p;
					cout << "Point one:" << p << endl;
					output << "Point one:" << p << endl;

					Vector v2;
					createVectorFromFile(v2, file, output);

					l = Line(p, v2);
					cout << l << endl;
					output << l << endl;

				}

				while (con == 'y')
				{
					int oper;
					cout << "Please choose operation:" << endl;
					cout << "1.Line Direction:" << endl;
					cout << "2.Normal Vector:" << endl;
					cout << "3.Find Angle between two lines:" << endl;
					cout << "4.Check that one Point is on the line:" << endl;
					cout << "5.Check that one Line is parallel to another Line:" << endl;
					cout << "6.Check that one Line is equal to another Line:" << endl;
					cout << "7.Check that one Line crosses another:" << endl;
					cout << "8.Check that two Lines intersect:" << endl;
					cout << "9.Check that one Line is perpendicular to another:" << endl;
					GotoLine(file, 3);
					file >> oper;
					GotoLine(file, 4);
					cout << endl;

					if (oper == 1)
					{
						cout << "You choose 1." << endl;
						output << "You choose 1." << endl;
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << l.LineDirection() << endl;
						output << l.LineDirection() << endl;

					}
					else if (oper == 2)
					{
						cout << "You choose 2." << endl;
						output << "You choose 2." << endl;
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << l.normal() << endl;
						output << l.normal() << endl;


					}
					else if (oper == 3)
					{

						GotoLine(file, 4);
						cout << "You choose 3." << endl;
						output << "You choose 3." << endl;
						Line l2;
						cout << "How do you want to create a line:" << endl;
						cout << "1. with 2 Points:" << endl;
						cout << "2.with one Point and Vector:" << endl;
						cin >> type;
						if (type == 1)
						{
							Point p;
							file >> p;
							cout << "Point one:" << p << endl;
							output << "Point one:" << p << endl;
							Point p2;
							file >> p2;
							cout << "Point two:" << p2 << endl;
							output << "Point two:" << p2 << endl;

							l2 = Line(p, p2);
							cout << l2 << endl;
							output << l2 << endl;


						}
						else if (type == 2)
						{

							Point p;
							file >> p;
							cout << "Point one:" << p << endl;
							output << "Point one:" << p << endl;

							Vector v2;
							createVectorFromFile(v2, file, output);

							l2 = Line(p, v2);
							cout << l2 << endl;
							output << l2 << endl;



						}

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << l.CalculateAngle(l2) << endl;
						output << l.CalculateAngle(l2) << endl;

					}
					else if (oper == 4)
					{
						GotoLine(file, 4);
						cout << "You choose 4." << endl;
						output << "You choose 4." << endl;

						Point p;
						file >> p;
						cout << p << endl;
						output << p << endl;

						cout << "Is Point is on the line?" << endl;
						cout << boolalpha << l + p << endl;
						output << boolalpha << l + p << endl;

					}
					else if (oper == 5)
					{
						GotoLine(file, 4);
						cout << "You choose 5." << endl;
						output << "You choose 5." << endl;

						Line l2;
						cout << "How do you want to create a line:" << endl;
						cout << "1. with 2 Points:" << endl;
						cout << "2.with one Point and Vector:" << endl;
						cin >> type;
						if (type == 1)
						{
							Point p;
							file >> p;
							cout << "Point one:" << p << endl;
							output << "Point one:" << p << endl;

							Point p2;
							file >> p2;
							cout << "Point two:" << p2 << endl;
							output << "Point two:" << p2 << endl;

							l2 = Line(p, p2);
							cout << l2 << endl;
							output << l2 << endl;


						}
						else if (type == 2)
						{
							Point p;
							file >> p;
							cout << "Point one:" << p << endl;
							output << "Point one:" << p << endl;

							Vector v2;
							createVectorFromFile(v2, file, output);

							l2 = Line(p, v2);
							cout << l2 << endl;
							output << l2 << endl;

						}

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << (l || l2) << endl;
						output << (l || l2) << endl;

					}
					else if (oper == 7)
					{
						cout << "Result is" << endl;
					}
					else if (oper == 8)
					{
						cout << "Result is" << endl;
					}
					else if (oper == 9)
					{
						cout << "Result is:" << endl;
					}
					else if (oper == 6)

					{
						cout << "Result is:" << endl;

					}
					cout << "Do you want to continue with operation: y/n" << endl;
					cin >> con;
					if (con == 'y')
					{
						GotoLine(file, 3);
					}
				}
				cout << "Do you want to check another object:y/n" << endl;
				char obj;
				cin >> obj;
				if (obj == 'y')
				{
					GotoLine(file, 1);
					file >> shape;


				}
				else if (obj == 'n')
				{
					type = 7;
				}


			}
			if (shape == 4)
			{
				char con = 'y';
				Line l;
				cout << "How do you want to create a line:" << endl;
				cout << "1. with 2 Points:" << endl;
				cout << "2.with one Point and Vector:" << endl;
				int type;
				cin >> type;
				if (type == 1)
				{
					Point p;
					file >> p;
					cout << "Point one:" << p << endl;
					output << "Point one:" << p << endl;

					Point p2;
					file >> p2;
					cout << "Point two:" << p2 << endl;
					output << "Point two:" << p2 << endl;

					l = Line(p, p2);
					cout << l << endl;
					output << l << endl;


				}
				else if (type == 2)
				{
					Point p;
					file >> p;
					cout << "Point one:" << p << endl;
					output << "Point one:" << p << endl;

					Vector v2;
					createVectorFromFile(v2, file, output);

					l = Line(p, v2);
					cout << l << endl;
					output << l << endl;

				}
				cout << "Include t:" << endl;
				double start, end;
				file >> start;
				cout << "T start:" << start << endl;
				output << "T start:" << start << endl;
				file >> end;
				cout << "T end:" << end << endl;
				output << "T end:" << end << endl;
				Segment AB(l, start, end);
				cout << AB << endl;
				output << AB << endl;
				while (con == 'y')
				{
					int oper;
					cout << "Please choose operation:" << endl;
					cout << "1.Length of Segment:" << endl;
					cout << "2.Middle of Segment:" << endl;
					cout << "3.Is Point is on the Segment:" << endl;
					GotoLine(file, 3);
					file >> oper;
					GotoLine(file, 4);
					cout << endl;
					if (oper == 1)
					{
						cout << "You choose 1." << endl;
						output << "You choose 1." << endl;
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << AB.SegmentLength() << endl;
						output << AB.SegmentLength() << endl;
					}
					else if (oper == 2)
					{

						cout << "You choose 2." << endl;
						output << "You choose 2." << endl;
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << AB.SegmentCentre() << endl;
						output << AB.SegmentCentre() << endl;
					}
					else if (oper == 3)
					{
						cout << "You choose 3." << endl;
						output << "You choose 3." << endl;
						GotoLine(file, 4);

						Point p;
						file >> p;
						cout << p << endl;
						output << p << endl;
						cout << "Is Point is on the Segment:" << endl;
						output << "Is Point is on the Segment:" << endl;
						output << boolalpha << (AB == p) << endl;
						cout << boolalpha << (AB == p) << endl;
					}

					cout << "Do you want new operation:y/n" << endl;
					cin >> con;
					if (con == 'y')
					{
						GotoLine(file, 3);
					}
				}

				cout << "Do you want to check another object:y/n" << endl;
				char obj;
				cin >> obj;
				if (obj == 'y')
				{
					GotoLine(file, 1);
					file >> shape;


				}
				else if (obj == 'n')
				{
					type = 7;
				}

			}
			if (shape == 5)
			{

				char con = 'y';
				Point p;
				file >> p;
				cout << p << endl;
				output << p << endl;

				Point p2;
				file >> p2;
				cout << p2 << endl;
				output << p2 << endl;

				Point p3;
				file >> p3;
				cout << p3 << endl;
				output << p3 << endl;

				Triangle abc(p, p2, p3);
				cout << abc << endl;
				output << abc << endl;

				while (con == 'y')
				{
					int oper;
					cout << "Please choose operation:" << endl;
					cout << "1.Type of Triangle:" << endl;
					cout << "2.Area of Triangle:" << endl;
					cout << "3.Perimeter of Triangle:" << endl;
					cout << "4.Medicentre of Triangle:" << endl;
					cout << "5.Is Point is in the Triangle:" << endl;
					cout << "6. Is Point is in the one side of Triangle:" << endl;
					cout << "7.Is Point is not in the Triangle:" << endl;
					GotoLine(file, 3);
					file >> oper;
					GotoLine(file, 4);
					cout << endl;
					if (oper == 1)
					{
						cout << endl;
						cout << "You choose 1." << endl;
						output << "You choose 1." << endl;
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						abc.TriangleType();
					}
					else if (oper == 2)
					{
						cout << endl;
						cout << "You choose 2." << endl;
						output << "You choose 2." << endl;
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << abc.TriangleArea() << endl;
						output << abc.TriangleArea() << endl;

					}
					else if (oper == 3)
					{
						cout << endl;
						cout << "You choose 3." << endl;
						output << "You choose 3." << endl;
						cout << "Result is:" << endl;
						output << "Result is:" << endl;

						cout << abc.TrianglePerimeter() << endl;
						output << abc.TrianglePerimeter() << endl;
					}
					else if (oper == 4)
					{
						cout << endl;
						cout << "You choose 4." << endl;
						output << "You choose 4." << endl;
						cout << "Result is:" << endl;
						output << "Result is:" << endl;

						cout << abc.TriagnleMedi() << endl;
						output << abc.TriagnleMedi() << endl;
					}
					else if (oper == 5)
					{
						GotoLine(file, 4);
						cout << endl;
						cout << "You choose 5." << endl;
						output << "You choose 5." << endl;

						Point a;
						file >> a;
						cout << a << endl;
						output << a << endl;

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << (abc < a) << endl;
						output << (abc < a) << endl;
					}
					else if (oper == 6)
					{
						GotoLine(file, 4);
						cout << endl;
						cout << "You choose 6." << endl;
						output << "You choose 6." << endl;
						Point a;
						file >> a;

						cout << a << endl;
						output << a << endl;

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << (abc > a) << endl;
						output << (abc > a) << endl;
					}
					else if (oper == 7)
					{
						GotoLine(file, 4);
						cout << endl;
						cout << "You choose 7." << endl;
						output << "You choose 7." << endl;

						Point a;
						file >> a;
						cout << a << endl;
						output << a << endl;

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << (abc == a) << endl;
						output << (abc == a) << endl;
					}

					cout << "Do you want new operation:y/n" << endl;
					cin >> con;
					if (con == 'y')
					{
						GotoLine(file, 3);
					}
				}
				cout << "Do you want to check another object:y/n" << endl;
				char obj;
				cin >> obj;
				if (obj == 'y')
				{
					GotoLine(file, 1);
					file >> shape;
				}
				else if (obj == 'n')
				{
					type = 7;
				}
			}
		} while(type!= 7);

		output.close();
		char choice;
		cout << "Do you want to save data in a text file? : y/n" << endl;
		cin >> choice;
		if (choice == 'y')
		{
			return 0;
		}
		else if (choice == 'n')
		{
			output.open("output.txt", ios::trunc);
			output.close();
		}

	}
	else
	if (choice == 'c')
	{
		ofstream output("output.txt");
		if (!output)
		{
			cerr << "Cannot open this file!" << endl;
			return -10;
		}

		int shape;

		cout << "Input shape:" << endl;
		cin >> shape;
		cout << endl;

		do
		{
			if (shape == 1)
			{

				cout << "Insert Point:" << endl;
				Point p;
				cin >> p;

				char con = 'y';
				while (con == 'y')
				{



					cout << "Point A:" << p << endl;
					output << "Point A:" << p << endl;

					cout << "Do you want new operation:" << endl;
					cin >> con;
					if (con == 'y')
					{

						cout << "Insert Point:" << endl;
						Point p1;
						cin >> p1;
						cout << "Point B:" << p1 << endl;
						output << "Point B:" << p1 << endl;
						cout << "A==B?" << endl;
						output << "A==B?" << endl;
						cout << boolalpha << (p == p1) << endl;
						output << boolalpha << (p == p1) << endl;
					}


					cout << endl;


				}

				cout << "Do you want to check another object:y/n" << endl;
				char obj;
				cin >> obj;
				if (obj == 'n')
				{
					break;
				}
				else if (obj == 'n')
				{
					type = 7;
				}


			}
			if (shape == 2)
			{
				Vector b;
				createVector(b, output);

				char con = 'y';
				while (con == 'y')
				{
					int oper;

					cout << "Please choose operation:" << endl;
					cout << "1. VectorLength" << endl;
					cout << "2.VectorDirection" << endl;
					cout << "3.Check is it Vector Null" << endl;
					cout << "4.Check for Parellism" << endl;
					cout << "5.Check for Perpendicular" << endl;
					cout << "6.Sum of 2 Vectors:" << endl;
					cout << "7.Sub of 2 Vectors:" << endl;
					cout << "8.Multi of Vector with Number:" << endl;
					cout << "9.Skalar Multi:" << endl;
					cout << "10.Vector Multi:" << endl;
					cout << "11.Mixed Multi:" << endl;
					cin >> oper;
					cout << endl;
					if (oper == 1)
					{
						cout << "You choose 1." << endl;
						output << "You choose 1." << endl;

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << b.VectorLength() << endl;
						output << b.VectorLength() << endl;
					}
					else if (oper == 2)
					{
						cout << "You choose 2." << endl;
						output << "You choose 2." << endl;

						cout << "Result is:" << endl;
						output << "Result is:" << endl;

						cout << b.VectorDirection() << endl;
						output << b.VectorDirection() << endl;
					}
					else if (oper == 3)
					{
						cout << "You choose 3." << endl;
						output << "You choose 3." << endl;

						cout << "Result is:" << endl;
						output << "Result is:" << endl;

						cout << boolalpha << b.VectorNull() << endl;
						output << boolalpha << b.VectorNull() << endl;
					}
					else if (oper == 4)
					{
						cout << "You choose 4." << endl;
						output << "You choose 4." << endl;
						Vector v1;
						createVector(v1, output);
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << boolalpha << b.VectorPrallelism(v1) << endl;
					}
					else if (oper == 5)
					{
						cout << "You choose 5." << endl;
						output << "You choose 5." << endl;

						Vector v1;
						createVector(v1, output);
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << boolalpha << b.VectorPerpendi(v1) << endl;
						output << boolalpha << b.VectorPerpendi(v1) << endl;
					}
					else if (oper == 6)
					{
						cout << "You choose 6." << endl;
						output << "You choose 6." << endl;

						Vector v1;
						createVector(v1, output);
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << "Vector:" << b + v1 << endl;
						output << "Vector:" << b + v1 << endl;
					}
					else if (oper == 7)
					{

						cout << "You choose 7." << endl;
						output << "You choose 7." << endl;
						Vector v1;
						createVector(v1, output);

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << "Vector:" << b - v1 << endl;
						output << "Vector:" << b - v1 << endl;
					}
					else if (oper == 8)
					{

						cout << "You choose 8." << endl;
						output << "You choose 8." << endl;
						double num;
						cout << "Please input a number:" << endl;
						cin >> num;
						cout << endl;


						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << "Vector:" << num * b << endl;
						output << "Vector:" << num * b << endl;

					}
					else if (oper == 9)
					{
						Vector v1;
						createVector(v1, output);
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << "Vector:" << b * v1 << endl;
						output << "Vector:" << b * v1 << endl;

					}
					else if (oper == 10)
					{

						cout << "You choose 10." << endl;
						output << "You choose 10." << endl;
						Vector v1;
						createVector(v1, output);
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << "Vector:" << (b ^ v1) << endl;
						output << "Vector:" << (b ^ v1) << endl;
					}
					else if (oper == 11)
					{
						cout << "You choose 11." << endl;
						output << "You choose 11." << endl;
						Vector v1;
						createVector(v1, output);
						Vector v2;
						createVector(v2, output);
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << b(v1, v2) << endl;
						output << b(v1, v2) << endl;
					}

					cout << "Do you want to choose new operation:y/n" << endl;
					cin >> con;
					if (con == 'n')
					{
						break;
					}
					cout << endl;

				}
				cout << "Do you want to check another object:y/n" << endl;
				char obj;
				cin >> obj;
				if (obj == 'y')
				{
					cin >> shape;
				}
				else if (obj == 'n')
				{
					type = 7;
				}

			}
			if (shape == 3)
			{
				char con = 'y';

				Line l;
				cout << "How do you want to create a line:" << endl;
				cout << "1. with 2 Points:" << endl;
				cout << "2.with one Point and Vector:" << endl;
				int type;
				cin >> type;
				if (type == 1)
				{
					Point p;
					cin >> p;
					cout << "Point one:" << p << endl;
					output << "Point one:" << p << endl;

					Point p2;
					cin >> p2;
					cout << "Point two:" << p2 << endl;
					output << "Point two:" << p2 << endl;

					l = Line(p, p2);
					cout << l << endl;
					output << l << endl;


				}
				else if (type == 2)
				{

					Point p;
					cin >> p;
					cout << "Point one:" << p << endl;
					output << "Point one:" << p << endl;

					Vector v2;
					createVector(v2, output);
					l = Line(p, v2);
					cout << l << endl;
					output << l << endl;

				}

				while (con == 'y')
				{
					int oper;
					cout << "Please choose operation:" << endl;
					cout << "1.Line Direction:" << endl;
					cout << "2.Normal Vector:" << endl;
					cout << "3.Find Angle between two lines:" << endl;
					cout << "4.Check that one Point is on the line:" << endl;
					cout << "5.Check that one Line is parallel to another Line:" << endl;
					cout << "6.Check that one Line is equal to another Line:" << endl;
					cout << "7.Check that one Line crosses another:" << endl;
					cout << "8.Check that two Lines intersect:" << endl;
					cout << "9.Check that one Line is perpendicular to another:" << endl;
					cin >> oper;
					cout << endl;

					if (oper == 1)
					{
						cout << "You choose 1." << endl;
						output << "You choose 1." << endl;
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << l.LineDirection() << endl;
						output << l.LineDirection() << endl;

					}
					else if (oper == 2)
					{
						cout << "You choose 2." << endl;
						output << "You choose 2." << endl;
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << l.normal() << endl;
						output << l.normal() << endl;


					}
					else if (oper == 3)
					{
						cout << "You choose 3." << endl;
						output << "You choose 3." << endl;
						Line l2;
						cout << "How do you want to create a line:" << endl;
						cout << "1. with 2 Points:" << endl;
						cout << "2.with one Point and Vector:" << endl;
						cin >> type;
						if (type == 1)
						{
							Point p;
							cin >> p;
							cout << "Point one:" << p << endl;
							output << "Point one:" << p << endl;
							Point p2;
							cin >> p2;
							cout << "Point two:" << p2 << endl;
							output << "Point two:" << p2 << endl;

							l2 = Line(p, p2);
							cout << l2 << endl;
							output << l2 << endl;


						}
						else if (type == 2)
						{

							Point p;
							cin >> p;
							cout << "Point one:" << p << endl;
							output << "Point one:" << p << endl;

							Vector v2;
							createVector(v2, output);
							l2 = Line(p, v2);
							cout << l2 << endl;
							output << l2 << endl;
						}

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << l.CalculateAngle(l2) << endl;
						output << l.CalculateAngle(l2) << endl;

					}
					else if (oper == 4)
					{
						cout << "You choose 4." << endl;
						output << "You choose 4." << endl;

						Point p;
						cin >> p;
						cout << p << endl;
						output << p << endl;

						cout << "Is Point is on the line?" << endl;
						cout << boolalpha << l + p << endl;
						output << boolalpha << l + p << endl;

					}
					else if (oper == 5)
					{
						cout << "You choose 5." << endl;
						output << "You choose 5." << endl;

						Line l2;
						cout << "How do you want to create a line:" << endl;
						cout << "1. with 2 Points:" << endl;
						cout << "2.with one Point and Vector:" << endl;
						cin >> type;
						if (type == 1)
						{
							Point p;
							cin >> p;
							cout << "Point one:" << p << endl;
							output << "Point one:" << p << endl;

							Point p2;
							cin >> p2;
							cout << "Point two:" << p2 << endl;
							output << "Point two:" << p2 << endl;

							l2 = Line(p, p2);
							cout << l2 << endl;
							output << l2 << endl;


						}
						else if (type == 2)
						{
							Point p;
							cin >> p;
							cout << "Point one:" << p << endl;
							output << "Point one:" << p << endl;

							Vector v2;
							createVector(v2, output);
							l2 = Line(p, v2);
							cout << l2 << endl;
							output << l2 << endl;

						}

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << (l || l2) << endl;
						output << (l || l2) << endl;

					}
					else if (oper == 7)
					{
						cout << "Result is" << endl;
					}
					else if (oper == 8)
					{
						cout << "Result is" << endl;
					}
					else if (oper == 9)
					{
						cout << "Result is:" << endl;
					}
					else if (oper == 6)

					{
						cout << "Result is:" << endl;

					}
					cout << "Do you want to continue with operation: y/n" << endl;
					cin >> con;
					if (con == 'n')
					{
						break;
					}
				}
				cout << "Do you want to check another object:y/n" << endl;
				char obj;
				cin >> obj;
				if (obj == 'y')
				{
					cin >> shape;

				}
				else if (obj == 'n')
				{
					type = 7;
				}

			}
			if (shape == 4)
			{
				char con = 'y';
				Line l;
				cout << "How do you want to create a line:" << endl;
				cout << "1. with 2 Points:" << endl;
				cout << "2.with one Point and Vector:" << endl;
				int type;
				cin >> type;
				if (type == 1)
				{
					Point p;
					cin >> p;
					cout << "Point one:" << p << endl;
					output << "Point one:" << p << endl;

					Point p2;
					cin >> p2;
					cout << "Point two:" << p2 << endl;
					output << "Point two:" << p2 << endl;

					l = Line(p, p2);
					cout << l << endl;
					output << l << endl;


				}
				else if (type == 2)
				{
					Point p;
					cin >> p;
					cout << "Point one:" << p << endl;
					output << "Point one:" << p << endl;

					Vector v2;
					createVector(v2, output);
					l = Line(p, v2);
					cout << l << endl;
					output << l << endl;

				}
				cout << "Include t:" << endl;
				double start, end;
				cin >> start;
				cout << "T start:" << start << endl;
				output << "T start:" << start << endl;
				cin >> end;
				cout << "T end:" << end << endl;
				output << "T end:" << end << endl;
				Segment AB(l, start, end);
				cout << AB << endl;
				output << AB << endl;
				while (con == 'y')
				{
					int oper;
					cout << "Please choose operation:" << endl;
					cout << "1.Length of Segment:" << endl;
					cout << "2.Middle of Segment:" << endl;
					cout << "3.Is Point is on the Segment:" << endl;
					cin >> oper;
					cout << endl;
					if (oper == 1)
					{
						cout << "You choose 1." << endl;
						output << "You choose 1." << endl;
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << AB.SegmentLength() << endl;
						output << AB.SegmentLength() << endl;
					}
					else if (oper == 2)
					{

						cout << "You choose 2." << endl;
						output << "You choose 2." << endl;
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << AB.SegmentCentre() << endl;
						output << AB.SegmentCentre() << endl;
					}
					else if (oper == 3)
					{
						cout << "You choose 3." << endl;
						output << "You choose 3." << endl;

						Point p;
						cin >> p;
						cout << p << endl;
						output << p << endl;
						cout << "Is Point is on the Segment:" << endl;
						output << "Is Point is on the Segment:" << endl;
						output << boolalpha << (AB == p) << endl;
						cout << boolalpha << (AB == p) << endl;
					}

					cout << "Do you want new operation:y/n" << endl;
					cin >> con;
					if (con == 'n')
					{
						break;
					}
				}

				cout << "Do you want to check another object:y/n" << endl;
				char obj;
				cin >> obj;
				if (obj == 'y')
				{
					cin >> shape;


				}
				else if(obj=='n')
				{
					type = 7;
				}



			}
			if (shape == 5)
			{

				char con = 'y';
				Point p;
				cin >> p;
				cout << p << endl;
				output << p << endl;

				Point p2;
				cin >> p2;
				cout << p2 << endl;
				output << p2 << endl;

				Point p3;
				cin >> p3;
				cout << p3 << endl;
				output << p3 << endl;

				Triangle abc(p, p2, p3);
				cout << abc << endl;
				output << abc << endl;

				while (con == 'y')
				{
					int oper;
					cout << "Please choose operation:" << endl;
					cout << "1.Type of Triangle:" << endl;
					cout << "2.Area of Triangle:" << endl;
					cout << "3.Perimeter of Triangle:" << endl;
					cout << "4.Medicentre of Triangle:" << endl;
					cout << "5.Is Point is in the Triangle:" << endl;
					cout << "6. Is Point is in the one side of Triangle:" << endl;
					cout << "7.Is Point is not in the Triangle:" << endl;
					cin >> oper;
					cout << endl;
					if (oper == 1)
					{
						cout << endl;
						cout << "You choose 1." << endl;
						output << "You choose 1." << endl;
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						abc.TriangleType();
					}
					else if (oper == 2)
					{
						cout << endl;
						cout << "You choose 2." << endl;
						output << "You choose 2." << endl;
						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << abc.TriangleArea() << endl;
						output << abc.TriangleArea() << endl;

					}
					else if (oper == 3)
					{
						cout << endl;
						cout << "You choose 3." << endl;
						output << "You choose 3." << endl;
						cout << "Result is:" << endl;
						output << "Result is:" << endl;

						cout << abc.TrianglePerimeter() << endl;
						output << abc.TrianglePerimeter() << endl;
					}
					else if (oper == 4)
					{
						cout << endl;
						cout << "You choose 4." << endl;
						output << "You choose 4." << endl;
						cout << "Result is:" << endl;
						output << "Result is:" << endl;

						cout << abc.TriagnleMedi() << endl;
						output << abc.TriagnleMedi() << endl;
					}
					else if (oper == 5)
					{

						cout << endl;
						cout << "You choose 5." << endl;
						output << "You choose 5." << endl;

						Point a;
						cin >> a;
						cout << a << endl;
						output << a << endl;

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << (abc < a) << endl;
						output << (abc < a) << endl;
					}
					else if (oper == 6)
					{

						cout << endl;
						cout << "You choose 6." << endl;
						output << "You choose 6." << endl;
						Point a;
						cin >> a;

						cout << a << endl;
						output << a << endl;

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << (abc > a) << endl;
						output << (abc > a) << endl;
					}
					else if (oper == 7)
					{

						cout << endl;
						cout << "You choose 7." << endl;
						output << "You choose 7." << endl;

						Point a;
						cin >> a;
						cout << a << endl;
						output << a << endl;

						cout << "Result is:" << endl;
						output << "Result is:" << endl;
						cout << (abc == a) << endl;
						output << (abc == a) << endl;
					}

					cout << "Do you want new operation:y/n" << endl;
					cin >> con;
					if (con == 'n')
					{
						break;
					}
				}
				cout << "Do you want to check another object:y/n" << endl;
				char obj;
				cin >> obj;
				if (obj == 'y')
				{
					cin >> shape;
				}
				else if(obj=='n')
				{
					type = 7;
				}


			}
		} while (type != 7);

		output.close();
		char choice;
		cout << "Do you want to save data in a text file? : y/n" << endl;
		cin >> choice;
		if (choice == 'y')
		{
			return 0;
		}
		else if (choice == 'n')
		{
			output.open("output.txt", ios::trunc);
			output.close();
		}
	}
	
		return 0;

}


void createVectorFromFile(Vector& v, ifstream& file, ofstream& output)
{

	int type;
	Vector b;
	cout << "How do you want to realise Vector:" << endl;
	cout << "1.With 3 values" << endl;
	cout << "2.With 2 Points" << endl;
	cin >> type;
	cout << endl;
	if (type == 1)
	{
		
		Vector c;
		file >> c;
		b = c;
		cout << "Vector:" << b << endl;
		output << "Vector:" << b << endl;
		v = b;
	}
	else
	{

	
		cout << "Please insert x,y,z for Point:" << endl;
		Point p1;
		file >> p1;
		cout << "Please insert x,y,z for Point 2:" << endl;
		Point p2;
		file >> p2;
		b = Vector(p1, p2);
		cout << "Vector:" << b << endl;
		output << "Vector:" << b << endl;
		v = b;
	}

}


void createVector(Vector& v, ofstream& output)
{

	int type;
	Vector b;
	cout << "How do you want to realise Vector:" << endl;
	cout << "1.With 3 values" << endl;
	cout << "2.With 2 Points" << endl;
	cin >> type;
	cout << endl;
	if (type == 1)
	{

		Vector c;
		cin >> c;
		b = c;
		cout << "Vector:" << b << endl;
		output << "Vector:" << b << endl;
		v = b;
	}
	else
	{


		cout << "Please insert x,y,z for Point:" << endl;
		Point p1;
		cin >> p1;
		cout << "Please insert x,y,z for Point 2:" << endl;
		Point p2;
		cin >> p2;
		b = Vector(p1, p2);
		cout << "Vector:" << b << endl;
		output << "Vector:" << b << endl;
		v = b;
	}

}

