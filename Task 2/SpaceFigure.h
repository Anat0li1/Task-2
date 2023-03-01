#pragma once


#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include"math.h"
#include <iostream>
using namespace std;

class Figure abstract
{
public:
	virtual ~Figure() {}
	virtual double area() const abstract;

	virtual void printOn(ostream&) const abstract;
	bool operator>(const Figure& s) const
	{
		return this->area() > s.area();
	}
};
//--------------------------------------------

class PlaneFigure abstract : public Figure {
	virtual double perim() const abstract;
};

ostream& operator<<(ostream& os, const Figure& s);


class Rectangle : public PlaneFigure
{
protected:
	double a;
	double b;
public:
	Rectangle(double sideA = 1., double sideB = 1.) : a(sideA), b(sideB) {}
	double area() const override;
	double perim() const override;
	double getA() const;
	double getB() const;
	void setA(int a);
	void setB(int b);
	void printOn(ostream&) const override;
};

class Circle : public PlaneFigure
{
private:
	double r;
public:
	Circle(double radius = 1.) : r(radius) {}
	double area() const override;
	void setR(int r);
	double perim() const override;
	void printOn(ostream&) const override;
	double radius() const { return r; }
};

class Triangle : public PlaneFigure
{
private:
	double a;
	double b;
	int y;
	double angle() const { return M_PI * y / 180; }
public:
	Triangle(double sideA = 1., double sideB = 1., int angle = 90) : a(sideA), b(sideB), y(angle) {}
	double area() const override;
	double perim() const override;
	double getA() const;
	double getB() const;
	void setA(double a);
	void setB(double b);
	void setAngle(int y);

	int getAngle() const;
	void printOn(ostream&) const override;
};


class Square : public Rectangle
{
public:
	Square(double side = 1.) : Rectangle(side, side) {};
	void printOn(ostream&) const override;
};

//--------------------------------------------------------

class SpaceFigure abstract : public Figure
{
public:
	virtual double volume() const abstract;
	virtual double side_area() const abstract;
	virtual double base_area() const abstract;
};

class TrianglePyramid : public SpaceFigure {
private: Triangle T;
	   double m_h;
public:
	TrianglePyramid(double a = 1., double b = 1., int y = 90, double h = 1.0) : m_h(h) {
		T.setA(a); T.setB(b); T.setAngle(y);
	};
	double volume() const override;
	double base_area() const override;
	double side_area() const override;
	double area() const override;
	void printOn(std::ostream& os) const override;
};

class RectanglePyramid : public SpaceFigure {
private: Rectangle R;
	   double m_h;
public:
	RectanglePyramid(double a = 1., double b = 1., double h = 1.0) : m_h(h) {
		R.setA(a); R.setB(b);
	};
	double volume() const override;
	double base_area() const override;
	double side_area() const override;
	double area() const override;
	void printOn(std::ostream& os) const override;
};

class Cylinder : public SpaceFigure {
private: Circle C;
	   double m_h;
public:
	Cylinder(double r, double h = 1.0) :m_h(h) {
		C.setR(r);
	};
	double volume() const override;
	double base_area() const override;
	double side_area() const override;
	double area() const override;
	void printOn(std::ostream& os) const override;
};

class Cone : public SpaceFigure {
private: Circle C;
	   double m_h;
public:
	Cone(double r, double h = 1.0) :m_h(h) {
		C.setR(r);
	};
	double volume() const override;
	double base_area() const override;
	double side_area() const override;
	double area() const override;
	void printOn(std::ostream& os) const override;
};

class TrianglePrism : public SpaceFigure {
private: Triangle T;
	   double m_h;
public:
	TrianglePrism(double a = 1., double b = 1., int y = 90, double h = 1.0) : m_h(h) {
		T.setA(a); T.setB(b); T.setAngle(y);
	};
	double volume() const override;
	double base_area() const override;
	double side_area() const override;
	double area() const override;
	void printOn(std::ostream& os) const override;
};

class Parallelepiped : public SpaceFigure {
private: Rectangle R;
	   double m_h;
public:
	Parallelepiped(double a = 1., double b = 1., double h = 1.0) : m_h(h) {
		R.setA(a); R.setB(b);
	};
	double volume() const override;
	double base_area() const override;
	double side_area() const override;
	double area() const override;
	void printOn(std::ostream& os) const override;
};


