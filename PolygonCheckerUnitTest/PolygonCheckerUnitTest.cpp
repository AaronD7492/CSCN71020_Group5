#include "pch.h"
#include "CppUnitTest.h"


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

			char actual[50];
			strncpy_s(actual, analyzeTriangle(3, 3, 3), 50);
			Assert::AreEqual("Equilateral triangle", actual);
		}

		TEST_METHOD(IsoscelesTriangleAnalysisFunctionality)
		{
			//Testing the analyze triangle functionality for Isosceles Triangles

			char actual[50];
			strncpy_s(actual, analyzeTriangle(10, 10, 15), 50);
			Assert::AreEqual("Isosceles triangle", actual);
		}

		TEST_METHOD(ScaleneTriangleAnalysisFunctionality)
		{
			//Testing the analyze triangle functionality for Scalene Triangles

			char actual[50];
			strncpy_s(actual, analyzeTriangle(3, 4, 5), 50);
			Assert::AreEqual("Scalene triangle", actual);
		}

		TEST_METHOD(IsATriangleAnalysisFunctionality)
		{
			//Testing the analyze triangle functionality for Isosceles Triangles

			bool actual = isATriangle(3, 4, 5);
			Assert::AreEqual(true, actual);
		}

		TEST_METHOD(IsATriangleAnalysisFunctionality2)
		{
			//Testing the analyze triangle functionality for Isosceles Triangles

			bool actual = isATriangle(4, 3, 8);
			Assert::AreEqual(false, actual);
		}

		TEST_METHOD(IsATriangleAnalysisFunctionality3)
		{
			//Testing the analyze triangle functionality for Isosceles Triangles

			bool actual = isATriangle(0, 0, 0);
			Assert::AreEqual(false, actual);
		}
	};
}
