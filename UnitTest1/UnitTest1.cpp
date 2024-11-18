#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.1_it/7.1.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCalc)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			// Ініціалізація тестового масиву
			a[0][0] = 14; a[0][1] = 28; a[0][2] = 6;
			a[1][0] = 8;  a[1][1] = 21; a[1][2] = 10;
			a[2][0] = 4;  a[2][1] = 12; a[2][2] = 7;

			int S = 0;
			int k = 0;

			// Виклик функції Calc
			Calc(a, rowCount, colCount, S, k);

			// Перевірка очікуваних значень
			Assert::AreEqual(40, S); // Очікувана сума (6 + 8 + 10 + 4 + 12)
			Assert::AreEqual(5, k);  // Очікувана кількість чисел, які відповідають умовам

			// Перевірка того, що потрібні елементи замінено на 0
			Assert::AreEqual(0, a[0][2]);
			Assert::AreEqual(0, a[1][0]);
			Assert::AreEqual(0, a[1][2]);
			Assert::AreEqual(0, a[2][0]);
			Assert::AreEqual(0, a[2][1]);

			// Звільнення пам'яті
			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}