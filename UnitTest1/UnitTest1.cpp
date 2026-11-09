#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\qq\source\repos\laba7.1_it\laba7.1_it\laba7.1_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71Iter
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCalc)
        {
            int r0[] = { -3, 0, 3 };
            int r1[] = { 6, 2, -6 };
            int r2[] = { 1, 9, 4 };
            int* a[] = { r0, r1, r2 };

            int s, k;

            Calc(a, 3, 3, s, k);

            Assert::AreEqual(18, s);
            Assert::AreEqual(4, k);
            Assert::AreEqual(0, a[0][2]);
            Assert::AreEqual(0, a[1][0]);
            Assert::AreEqual(-3, a[0][0]);
        }

        TEST_METHOD(TestSort)
        {
            int r0[] = { 5, 7, 5 };
            int r1[] = { 2, 3, 2 };
            int r2[] = { 8, 4, 1 };
            int* a[] = { r0, r1, r2 };

            Sort(a, 3, 3);

            Assert::AreEqual(7, a[0][0]);
            Assert::AreEqual(5, a[0][1]);
            Assert::AreEqual(1, a[2][1]);
            Assert::AreEqual(8, a[2][2]);
        }
    };
}
