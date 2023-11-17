#include "pch.h"
#include "CppUnitTest.h"
#include <string.h>
#define LENGTH 80


extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" bool isATriangle(int side1, int side2, int side3);

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
	};
}
