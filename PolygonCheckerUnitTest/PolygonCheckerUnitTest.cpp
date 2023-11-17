#include "pch.h"
#include "CppUnitTest.h"
#include <string.h>
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

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerUnitTest
{
	TEST_CLASS(PolygonCheckerUnitTest)
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

		TEST_METHOD(CalculateTriangleAngleFunctionality)
		{
			//Testing the fucntionality of the calculateTriangleAngle function to determine acurate angles are returned

			int side1 = 3, side2 = 4, side3 = 5;
			double expectedAngles[] = { 36.8699, 90.0, 53.1301 };
			double actualAngles[3];

			calculateTriangleAngle(side1, side2, side3, actualAngles);

			for (int i = 0; i < 3; i++) {
				Assert::AreEqual(expectedAngles[i], actualAngles[i], 0.0001);
			}
		}

		TEST_METHOD(CalculateDistanceFunctionality)
		{
			//Testing functionality of the calcuateDistance function to determine distance between points is accurate
			
			POINT p1 = { 0, 0 };
			POINT p2 = { 3, 4 };
			double expected = 5.0;

			double actual = calculateDistance(p1, p2);

			Assert::AreEqual(expected, actual, 0.0001);
		}

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
	};
}
