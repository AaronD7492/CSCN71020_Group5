#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include "CppUnitTest.h"
#include <string.h>
#include <fstream>
#define LENGTH 80

typedef struct point {
	double x;
	double y;
} POINT;

extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" bool isATriangle(int side1, int side2, int side3);
extern "C" void calculateTriangleAngle(int side1, int side2, int side3, double angles[]);
extern "C" double calculateDistance(POINT p1, POINT p2);
extern "C" bool isRectangle(POINT p1, POINT p2, POINT p3, POINT p4);
extern "C" double calculatePerimeter(POINT p1, POINT p2, POINT p3, POINT p4);
extern "C" double calculateArea(POINT p1, POINT p2, POINT p3, POINT p4);
extern "C" POINT* getRectanglePoints(POINT * points);
extern "C" void calculateQuadrilateralAngles(POINT p1, POINT p2, POINT p3, POINT p4, double angles[]);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerUnitTest
{
	TEST_CLASS(AnalyzeTriangleUnitTest)
	{
	public:
		
		TEST_METHOD(EquilateralTriangleAnalysisFunctionality)
		{
			//Testing the analyze triangle functionality for Equilateral Triangles

			char actual[LENGTH];
			strncpy_s(actual, analyzeTriangle(3, 3, 3), LENGTH);
			Assert::AreEqual("Equilateral triangle", actual);
		}

		TEST_METHOD(S1S2IsoscelesTriangleAnalysisFunctionality)
		{
			//Testing the analyze triangle functionality for Isosceles Triangles with side1 and side2 being equal

			char actual[LENGTH];
			strncpy_s(actual, analyzeTriangle(10, 10, 15), LENGTH);
			Assert::AreEqual("Isosceles triangle", actual);
		}
		
		TEST_METHOD(S1S3IsoscelesTriangleAnalysisFunctionality)
		{
			//Testing the analyze triangle functionality for Isosceles Triangles with side1 and side3 being equal

			char actual[LENGTH];
			strncpy_s(actual, analyzeTriangle(23, 5, 23), LENGTH);
			Assert::AreEqual("Isosceles triangle", actual);
		}

		TEST_METHOD(S2S3IsoscelesTriangleAnalysisFunctionality)
		{
			//Testing the analyze triangle functionality for Isosceles Triangles with side2 and side3 being equal

			char actual[LENGTH];
			strncpy_s(actual, analyzeTriangle(5, 12, 12), LENGTH);
			Assert::AreEqual("Isosceles triangle", actual);
		}

		TEST_METHOD(ScaleneTriangleAnalysisFunctionality)
		{
			//Testing the analyze triangle functionality for Scalene Triangles

			char actual[LENGTH];
			strncpy_s(actual, analyzeTriangle(3, 4, 5), LENGTH);
			Assert::AreEqual("Scalene triangle", actual);
		}
	};

	TEST_CLASS(IsATriangleUnitTest)
	{
	public:

		TEST_METHOD(IsATriangleAnalysisFunctionalityValidTriangle)
		{
			//Testing the isATriangle Function for inputs that make a triangle

			bool actual = isATriangle(3, 4, 5);
			Assert::AreEqual(true, actual);
		}

		TEST_METHOD(IsATriangleAnalysisFunctionalityInvlaidTriangle)
		{
			//Testing the isATriangle Function for inputs that do not make a triangle

			bool actual = isATriangle(4, 3, 8);
			Assert::AreEqual(false, actual);
		}

		TEST_METHOD(IsATriangleAnalysisFunctionalityZeroes)
		{
			//Testing the isATriangle Function for zero inputs

			bool actual = isATriangle(0, 0, 0);
			Assert::AreEqual(false, actual);
		}

		TEST_METHOD(IsATriangleAnalysisFunctionalityNegatives)
		{
			//Testing the isATriangle Function for negative inputs

			bool actual = isATriangle(-5, 5, 5);
			Assert::AreEqual(false, actual);
		}
	};

	TEST_CLASS(CalculateTriangleAngleUnitTest)
	{
	public:
		TEST_METHOD(CalculateTriangleAngleFunctionality)
		{
			//Testing the fucntionality of the calculateTriangleAngle function to determine accurate angles are returned

			int side1 = 3, side2 = 4, side3 = 5;
			double expectedAngles[3] = { 36.8699, 53.1301, 90.0 };
			double actualAngles[3];

			calculateTriangleAngle(side1, side2, side3, actualAngles);

			for (int i = 0; i < 3; i++) {
				Assert::AreEqual(expectedAngles[i], actualAngles[i], 0.0001);
			}
		}

		TEST_METHOD(CalculateTriangleAngleFunctionalityEquilateral)
		{
			//Testing the fucntionality of the calculateTriangleAngle function to determine accurate angles are returned

			int side1 = 3, side2 = 3, side3 = 3;
			double expectedAngles[] = { 60.00, 60.00, 60.00 };
			double actualAngles[3];

			calculateTriangleAngle(side1, side2, side3, actualAngles);

			for (int i = 0; i < 3; i++) {
				Assert::AreEqual(expectedAngles[i], actualAngles[i], 0.01);
			}
		}

		TEST_METHOD(CalculateTriangleAngleFunctionalityLargeValues)
		{
			//Testing the fucntionality of the calculateTriangleAngle function to determine accurate angles are returned

			int side1 = 1e6, side2 = 1e6, side3 = 1e5;
			double expectedAngles[] = { 0.0, 0.0, 0.0 };
			double actualAngles[3];

			calculateTriangleAngle(side1, side2, side3, actualAngles);

			for (int i = 0; i < 3; i++) {
				Assert::AreEqual(expectedAngles[i], actualAngles[i], 0.01);
			}
		}
	};

	TEST_CLASS(CalculateDistanceUnitTest)
	{
	public:

		TEST_METHOD(CalculateDistanceFunctionalityDifferentPoints)
		{
			//Testing functionality of the calcuateDistance function to determine distance between points is accurate

			POINT p1 = { 0, 0 };
			POINT p2 = { 3, 4 };
			double expected = 5.0;

			double actual = calculateDistance(p1, p2);

			Assert::AreEqual(expected, actual, 0.0001);
		}

		TEST_METHOD(CalculateDistanceFunctionalitySamePoint)
		{
			//Testing functionality of the calcuateDistance function to determine distance between the same points is accurate
			POINT p1 = { 0.0, 0.0 };
			POINT p2 = { 0.0, 0.0 };
			double expectedDistance = 0.0;

			double actualDistance = calculateDistance(p1, p2);

			Assert::AreEqual(expectedDistance, actualDistance);
		}

		TEST_METHOD(CalculateDistanceFunctionalityDifferentPointsWithDecimal)
		{
			//Testing functionality of the calcuateDistance function to determine distance between points is accurate when there is a decimal
			POINT p1 = { 0.0, 0.0 };
			POINT p2 = { 3.0, 4.0 };
			double expectedDistance = 5.0;

			double actualDistance = calculateDistance(p1, p2);

			Assert::AreEqual(expectedDistance, actualDistance);
		}
	};

	TEST_CLASS(IsRectangleUnitTest)
	{
	public:

		TEST_METHOD(IsRectangleFunctionailtyValidRectangle)
		{
			//Testing isRectangle functionality for inputs that make a rectangle

			POINT p1 = { 0, 0 };
			POINT p2 = { 0, 1 };
			POINT p3 = { 1, 1 };
			POINT p4 = { 1, 0 };
			bool expected = true;

			bool actual = isRectangle(p1, p2, p3, p4);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(IsRectangleFunctionailtyInvalidRectangle)
		{
			//Testing isRectangle functionality for inputs that do not make a rectangle

			POINT p1 = { 0, 0 };
			POINT p2 = { 0, 1 };
			POINT p3 = { 2, 2 };
			POINT p4 = { 2, 0 };
			bool expected = false;

			bool actual = isRectangle(p1, p2, p3, p4);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(IsRectangleFunctionailtyInvalidNegativeValues)
		{
			//Testing isRectangle functionality for negative value inputs
			POINT p1 = { -1.0, 0.0 };
			POINT p2 = { 0.0, -1.0 };
			POINT p3 = { -1.0, -1.0 };
			POINT p4 = { 0.0, 0.0 };

			bool result = isRectangle(p1, p2, p3, p4);

			Assert::IsFalse(result);
		}

		TEST_METHOD(IsRectangleFunctionailtyInvalidZeroes)
		{
			//Testing isRectangle functionality for inputs that do not make a rectangle

			POINT p1 = { 0, 0 };
			POINT p2 = { 0, 0 };
			POINT p3 = { 0, 0 };
			POINT p4 = { 0, 0 };
			bool expected = false;

			bool actual = isRectangle(p1, p2, p3, p4);

			Assert::AreEqual(expected, actual);
		}
	};

	TEST_CLASS(CalculatePerimeterUnitTest)
	{
	public:

		TEST_METHOD(CalculatePerimeterFunctionalitySquare)
		{
			//Testing calculatePerimiter function for sqaure perimeter
			POINT p1 = { 0, 0 };
			POINT p2 = { 0, 1 };
			POINT p3 = { 1, 1 };
			POINT p4 = { 1, 0 };
			double expected = 4.0;

			double actual = calculatePerimeter(p1, p2, p3, p4);

			Assert::AreEqual(expected, actual, 0.0001);
		}

		TEST_METHOD(CalculatePerimeterFunctionalityRectangle)
		{
			//Testing calculatePerimiter function for rectangle perimeter

			POINT p1 = { 0, 0 };
			POINT p2 = { 0, 2 };
			POINT p3 = { 3, 2 };
			POINT p4 = { 3, 0 };
			double expected = 10.0;

			double actual = calculatePerimeter(p1, p2, p3, p4);

			Assert::AreEqual(expected, actual, 0.0001);
		}


		TEST_METHOD(CalculatePerimeterFunctionalityLine)
		{
			//Testing calculatePerimiter function for line perimeter

			POINT p1 = { 0, 0 };
			POINT p2 = { 0, 0 };
			POINT p3 = { 0, 0 };
			POINT p4 = { 0, 0 };
			double expected = 0.0;

			double actual = calculatePerimeter(p1, p2, p3, p4);

			Assert::AreEqual(expected, actual, 0.0001);
		}

		TEST_METHOD(CalculatePerimeterFunctionalityLargeValues)
		{
			//Testing calculatePerimiter function for larger values permiteter

			POINT p1 = { 0, 0 };
			POINT p2 = { 0, 1e6 };
			POINT p3 = { 1e6, 1e6 };
			POINT p4 = { 1e6, 0 };
			double expected = 4e6;

			double actual = calculatePerimeter(p1, p2, p3, p4);

			Assert::AreEqual(expected, actual, 0.0001);
		}
	};

	TEST_CLASS(CalculateAreaUnitTest)
	{
	public:

		TEST_METHOD(CalculateAreaFunctionalitySqaure)
		{
			//Testing calculateArea function for square area

			POINT p1 = { 0, 0 };
			POINT p2 = { 0, 1 };
			POINT p3 = { 1, 1 };
			POINT p4 = { 1, 0 };
			double expected = 1.0;

			double actual = calculateArea(p1, p2, p3, p4);

			Assert::AreEqual(expected, actual, 0.0001);
		}

		TEST_METHOD(CalculateAreaFunctionalityRectangle)
		{
			//Testing calculateArea function for rectangle area

			POINT p1 = { 0, 0 };
			POINT p2 = { 0, 2 };
			POINT p3 = { 3, 2 };
			POINT p4 = { 3, 0 };
			double expected = 6.0;

			double actual = calculateArea(p1, p2, p3, p4);

			Assert::AreEqual(expected, actual, 0.0001);
		}

		TEST_METHOD(CalculateAreaFunctionalityLargeValues)
		{
			//Testing calculateArea function for larger values area

			POINT p1 = { 0, 0 };
			POINT p2 = { 0, 1e6 };
			POINT p3 = { 1e6, 1e6 };
			POINT p4 = { 1e6, 0 };
			double expected = 1e12;

			double actual = calculateArea(p1, p2, p3, p4);

			Assert::AreEqual(expected, actual, 0.0001);
		}

		TEST_METHOD(CalculateAreaFunctionalityLine)
		{
			//Testing calculateArea function for line area

			POINT p1 = { 0, 0 };
			POINT p2 = { 0, 0 };
			POINT p3 = { 0, 0 };
			POINT p4 = { 0, 0 };
			double expected = 0;

			double actual = calculateArea(p1, p2, p3, p4);

			Assert::AreEqual(expected, actual, 0.0001);
		}
	};

	TEST_CLASS(GetRectnaglePointsUnitTest)
	{
	public:

		TEST_METHOD(GetRectanglePointsFunctionality)
		{
			//Testing getRectanglePoints function to see if expected values are returned when entered
			POINT points[4];
			POINT expectedPoints[4] = { {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0} };
			std::ofstream testInput("test_input.txt");
			testInput << "1.0 2.0\n3.0 4.0\n5.0 6.0\n7.0 8.0\n";
			testInput.close();
			FILE* stream;
			freopen_s(&stream, "test_input.txt", "r", stdin);

			POINT* actualPoints = getRectanglePoints(points);

			for (int i = 0; i < 4; i++)
			{
				Assert::AreEqual(expectedPoints[i].x, actualPoints[i].x);
				Assert::AreEqual(expectedPoints[i].y, actualPoints[i].y);
			}

			fclose(stream);
			remove("test_input.txt");
		}

		TEST_METHOD(GetRectanglePointsFunctionalityEmptyInput)
		{
			//Testing getRectanglePoints function for when empty inputs are entered
			POINT points[4];
			POINT expectedPoints[4] = { {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0} };
			std::ofstream testInput("test_input.txt");
			testInput << "0.0 0.0\n0.0 0.0\n0.0 0.0\n0.0 0.0\n";
			testInput.close();
			FILE* stream;
			freopen_s(&stream, "test_input.txt", "r", stdin);

			POINT* actualPoints = getRectanglePoints(points);

			for (int i = 0; i < 4; i++)
			{
				Assert::AreEqual(expectedPoints[i].x, actualPoints[i].x);
				Assert::AreEqual(expectedPoints[i].y, actualPoints[i].y);
			}

			fclose(stream);
			remove("test_input.txt");
		}

		TEST_METHOD(GetRectanglePointsFunctionalityNullInput)
		{
			//Testing getRectanglePoints function for when null inputs are entered
			POINT* points = NULL;

			POINT* result = getRectanglePoints(points);

			Assert::IsNull(result);
		}
	};

	TEST_CLASS(CalculateQuadrilateralAnglesUnitTest)
	{
	public:

		TEST_METHOD(CalculateQuadrilateralAnglesFunctionailtyRectangle)
		{
			//Testing the calculateQuadrilateralAngles function to see if it returns the expected angles for rectangles
			POINT p1 = { 0.0, 0.0 };
			POINT p2 = { 0.0, 4.0 };
			POINT p3 = { 6.0, 4.0 };
			POINT p4 = { 6.0, 0.0 };
			double expectedAngles[4] = { 90.0, 90.0, 90.0, 90.0 };

			double actualAngles[4];
			calculateQuadrilateralAngles(p1, p2, p3, p4, actualAngles);

			for (int i = 0; i < 4; i++)
			{
				Assert::AreEqual(expectedAngles[i], actualAngles[i], 1.0);
			}
		}

		TEST_METHOD(CalculateQuadrilateralAnglesFunctionailtySquare)
		{
			//Testing the calculateQuadrilateralAngles function to see if it returns the expected angles for squares
			POINT p1 = { 0.0, 0.0 };
			POINT p2 = { 0.0, 1.0 };
			POINT p3 = { 1.0, 1.0 };
			POINT p4 = { 1.0, 0.0 };
			double expectedAngles[4] = { 90.0, 90.0, 90.0, 90.0 };

			double actualAngles[4];
			calculateQuadrilateralAngles(p1, p2, p3, p4, actualAngles);

			for (int i = 0; i < 4; i++)
			{
				Assert::AreEqual(expectedAngles[i], actualAngles[i], 1.0);
			}
		}
	};
}
