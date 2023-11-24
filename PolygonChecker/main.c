#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"


int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			if (isATriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2])){											//Checks if the function is a triangle
				double angles[3];
				calculateTriangleAngle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], angles);							//Calls the function to calculate the angles
				char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
				printf("The angles of the triangle are: %0.3lf, %0.3lf, %0.3lf\n", angles[0], angles[1], angles[2]);
				printf_s("It is a %s\n", result);
			}
			else {
				printf("The given sides do not form a triangle\n");
			}
			break;
		case 2:
			printf_s("Rectangle selected.\n");
			POINT points[4] = { 0, 0 , 0, 0 };
			POINT* pointsPtr = getRectanglePoints(points);
			if (isRectangle(pointsPtr[0], pointsPtr[1], pointsPtr[2], pointsPtr[3])) {																// checks if the function is a rectangle
				printf("The given points form a rectangle.\n");
				printf("The perimeter of the rectangle is: %.2lf\n", calculatePerimeter(pointsPtr[0], pointsPtr[1], pointsPtr[2], pointsPtr[3]));	// Calls fucntion to calculate permieter
				printf("The area of the rectangle is: %.2lf\n", calculateArea(pointsPtr[0], pointsPtr[1], pointsPtr[2], pointsPtr[3]));				// Calls fucntion to calculate area
			}
			else {
				printf("The given points do not form a rectangle.\n");
			}
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			while (getchar() != '\n');
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	while (scanf_s("%d", &shapeChoice) != 1) {
		printf("Invalid input. Please enter a number.\n");
		while (getchar() != '\n');
	}

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		while (scanf_s("%d", &triangleSides[i]) != 1) {
			printf("Invalid input. Please enter a number.\n");
			while (getchar() != '\n'); 
		}
	}
	return triangleSides;
}