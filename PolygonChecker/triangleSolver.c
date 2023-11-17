#define _CRT_SECURE_NO_WARNINGS
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
		(side1 == side3 && side1 != side2) || (side2 == side3 && side2 != side1))
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
	if (side1 >= 1e5 || side2 >= 1e5 || side3 >= 1e5) {
		printf("The input(s) is a very large number. Handling as a special case.\n");
		angles[0] = angles[1] = angles[2] = 0.0;  // Handle as a special case
	}
	else {
		double angleA = acos((side2 * side2 + side3 * side3 - side1 * side1) / (2.0 * side2 * side3));
		double angleB = acos((side1 * side1 + side3 * side3 - side2 * side2) / (2.0 * side1 * side3));
		double angleC = acos((side1 * side1 + side2 * side2 - side3 * side3) / (2.0 * side1 * side2));

		angles[0] = angleA * (180 / M_PI);
		angles[1] = angleB * (180 / M_PI);
		angles[2] = angleC * (180 / M_PI);
	}
}


double calculateDistance(POINT p1, POINT p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

bool isRectangle(POINT p1, POINT p2, POINT p3, POINT p4) {
	double d1 = calculateDistance(p1, p3);
	double d2 = calculateDistance(p2, p4);

	if (d1 == d2) {
		return true;
	}

	return false;
}

double calculatePerimeter(POINT p1, POINT p2, POINT p3, POINT p4) {
	return calculateDistance(p1, p2) + calculateDistance(p2, p3) + calculateDistance(p3, p4) + calculateDistance(p4, p1);
}

double calculateArea(POINT p1, POINT p2, POINT p3, POINT p4) {
	double a = calculateDistance(p1, p2);
	double b = calculateDistance(p2, p3);
	return a * b;
}

void getRectanglePoints(POINT* points) {
	printf_s("Enter the x and y coordinates for each point of the rectangle: ");
	for (int i = 0; i < 4; i++)
	{
		while (scanf_s("%lf %lf", &points[i].x, &points[i].y) != 2) {
			printf("Invalid input. Please enter two numbers.\n");
			while (getchar() != '\n');
		}
	}
}

void setRectanglePoints(POINT* points, double coordinates[8]) {
	for (int i = 0; i < 4; i++) {
		points[i].x = coordinates[i * 2];
		points[i].y = coordinates[i * 2 + 1];
	}
}