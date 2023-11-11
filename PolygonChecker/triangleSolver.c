#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

bool isATriangle(int side1, int side2, int side3) {
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		return false;
	}

	if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
		return true;
	}

	return false;
}


void calculateTriangleAngle(int side1, int side2, int side3, double angles[]) {
	double angleA = acos((side2 * side2 + side3 * side3 - side1 * side1) / (2.0 * side2 * side3));
	double angleB = acos((side2 * side2 + side1 * side1 - side3 * side3) / (2.0 * side2 * side1));
	double angleC = acos((side1 * side1 + side3 * side3 - side2 * side2) / (2.0 * side1 * side3));

	angles[0] = angleA * 180 / M_PI;
	angles[1] = angleB * 180 / M_PI;
	angles[2] = angleC * 180 / M_PI;
}