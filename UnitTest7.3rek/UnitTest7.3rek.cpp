#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 7.3 rek/lab 7.3 rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73rek
{
	TEST_CLASS(UnitTest73rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int ROW = 3;
			int COL = 3;

			int** arr = new int* [ROW];

			for (int i = 0; i < ROW; i++)
				arr[i] = new int[COL];

			int expected = 0;

			for (int i = 0; i < ROW; i++)
				for (int j = 0; j < COL; j++)
					arr[i][j] = j;

			int functionResult = rowSum(arr, 2, 2, 0, 0);

			Assert::AreEqual(expected, functionResult);
		}
	};
}
