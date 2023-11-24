#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	double x;
	double y;
} POINT;

char* analyzeTriangle(int side1, int side2, int side3);
void calculateTriangleAngle(int side1, int side2, int side3, double angles[]);
bool isATriangle(int side1, int side2, int side3);
double calculateDistance(POINT p1, POINT p2);
void calculateQuadrilateralAngles(POINT p1, POINT p2, POINT p3, POINT p4, double angles[]);
bool isRectangle(POINT p1, POINT p2, POINT p3, POINT p4);
double calculatePerimeter(POINT p1, POINT p2, POINT p3, POINT p4);
double calculateArea(POINT p1, POINT p2, POINT p3, POINT p4);
POINT* getRectanglePoints(POINT* points);