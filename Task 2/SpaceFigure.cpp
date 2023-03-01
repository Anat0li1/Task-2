#include "SpaceFigure.h"
#include <iostream>
#include"math.h"

ostream& operator<<(ostream& os, const Figure& s)
{
	s.printOn(os);
	return os;
}

//--------------------------------------------

double Rectangle::area() const
{
	return a * b;
}

double Rectangle::perim() const
{
	return (a + b) * 2.;
}

double Rectangle::getA() const
{
	return a;
}

double Rectangle::getB() const
{
	return b;
}

void Rectangle::setA(int a)
{
	this->a = a;
}

void Rectangle::setB(int b)
{
	this->b = b;
}

void Rectangle::printOn(ostream& os) const
{
	os << "Rectangle of size ["
		<< a << " x " << b << "];";
}

//--------------------------------------------

double Circle::area() const
{
	return M_PI * r * r;
}

void Circle::setR(int r)
{
	this->r = r;
}

double Circle::perim() const
{
	return 2. * M_PI * r;
}

void Circle::printOn(ostream& os) const
{
	os << "Circle of radius ("
		<< r << ');';
}

//--------------------------------------------

double Triangle::area() const
{
	return 0.5 * a * b * std::sin(angle());
}

double Triangle::perim() const
{
	return a + b + std::sqrt(a * a + b * b - 2. * a * b * std::cos(angle()));
}

double Triangle::getA() const
{
	return a;
}

double Triangle::getB() const
{
	return b;
}

void Triangle::setA(double a)
{
	this->a = a;
}

void Triangle::setB(double b)
{
	this->b = b;
}


void Triangle::setAngle(int y)
{
	this->y = y;
}

int Triangle::getAngle() const
{
	return y;
}

void Triangle::printOn(ostream& os) const
{
	os << "Triangle of side <"
		<< a << ',' << b << "> with angle " << y << " degree;";
}

//--------------------------------------------

void Square::printOn(ostream& os) const
{
	os << "Square of side ["
		<< a << '];';
}

//--------------------------------------------

double TrianglePyramid::volume() const
{
	return (T.area() * m_h) / 3.;
}

double TrianglePyramid::base_area() const
{
	return T.area();
}

double TrianglePyramid::side_area() const
{
	double l1 = sqrt(m_h * m_h + ((T.getB() * T.getB()) / 4));
	double l2 = sqrt(m_h * m_h + ((T.getA() * T.getA()) / 4));
	double c = sqrt(T.getA() * T.getA() + T.getB() * T.getB() - 2. * T.getA() * T.getB() * std::cos((T.getAngle() * M_PI) / 180));
	double l3 = sqrt(m_h * m_h + ((c * c) / 4));
	double S = ((l1 * T.getB()) + (l2 * T.getA()) + (l3 * c)) / 2;
	return S;
}

double TrianglePyramid::area() const
{
	return base_area() + side_area();
}

void TrianglePyramid::printOn(std::ostream& os) const
{
	os << "Triangle Pyramid with height " << m_h << ", which base is ";
	T.printOn(os);
}


//--------------------------------------------


double RectanglePyramid::volume() const
{
	return (R.area() * m_h) / 3;
}

double RectanglePyramid::base_area() const
{
	return R.area();
}

double RectanglePyramid::side_area() const
{
	double l1 = sqrt(m_h * m_h + ((R.getB() * R.getB()) / 4));
	double l2 = sqrt(m_h * m_h + ((R.getA() * R.getA()) / 4));
	double S = (l1 * R.getB()) + (l2 * R.getA());
	return S;
}

double RectanglePyramid::area() const
{
	return base_area() + side_area();
}

void RectanglePyramid::printOn(std::ostream& os) const
{
	os << "Rectangle Pyramid with height " << m_h << ", which base is ";
	R.printOn(os);
}


//--------------------------------------------


double Cylinder::volume() const
{
	return C.area() * m_h;
}

double Cylinder::base_area() const
{
	return C.area();
}

double Cylinder::side_area() const
{
	return C.perim() * m_h;
}

double Cylinder::area() const
{
	return base_area() + side_area();
}

void Cylinder::printOn(std::ostream& os) const
{
	os << "Cylinder with height " << m_h << ", which base is ";
	C.printOn(os);
}

//--------------------------------------------

double Cone::volume() const
{
	return (C.area() * m_h) / 3.;
}

double Cone::base_area() const
{
	return C.area();
}

double Cone::side_area() const
{
	double l = (C.radius() * C.radius()) + (m_h * m_h);
	double S = M_PI * C.radius() * l;
	return S;
}

double Cone::area() const
{
	return base_area() + side_area();
}

void Cone::printOn(std::ostream& os) const
{
	os << "Cone with height " << m_h << ", which base is ";
	C.printOn(os);
}

//--------------------------------------------



double TrianglePrism::volume() const
{
	return T.area() * m_h;
}

double TrianglePrism::base_area() const
{
	return T.area();
}

double TrianglePrism::side_area() const
{
	return T.perim() * m_h;
}

double TrianglePrism::area() const
{
	return base_area() + side_area();
}

void TrianglePrism::printOn(std::ostream& os) const
{
	os << "Triangle Prism with height " << m_h << ", which base is ";
	T.printOn(os);
}

//--------------------------------------------


double Parallelepiped::volume() const
{
	return R.area() * m_h;
}

double Parallelepiped::base_area() const
{
	return R.area();
}

double Parallelepiped::side_area() const
{
	return R.perim() * m_h;
}

double Parallelepiped::area() const
{
	return base_area() + side_area();
}

void Parallelepiped::printOn(std::ostream& os) const
{
	os << "Parallelepiped with height " << m_h << ", which base is ";
	R.printOn(os);
}

