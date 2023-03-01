#include<iostream>
#include "SpaceFigure.h"
using namespace std;


int main() {
	TrianglePyramid t2(3., 4., 45, 5.0);
	TrianglePyramid t3;
	cout << t2 << endl;
	cout << t3 << endl;
	Parallelepiped r2(7., 8., 5.);
	cout << r2 << endl;
	cout << r2.volume() << " " << t2.volume();
}