//#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" {
    void setLength(int input, int* length);
    void setWidth(int input, int* width);
}

namespace Task2_RectangleTests
{
    TEST_CLASS(Task2)
    {
    public:
        TEST_METHOD(T2_SetLength50)
        {
            int l = 10;
            setLength(50, &l);
            Assert::AreEqual(50, l);
        }

        TEST_METHOD(T2_SetLength1)
        {
            int l = 10;
            setLength(1, &l);
            Assert::AreEqual(1, l);
        }

        TEST_METHOD(T2_SetLength0)
        {
            int l = 10;
            setLength(0, &l);
            Assert::AreEqual(10, l);
        }

        TEST_METHOD(T2_SetWidth42)
        {
            int w = 5;
            setWidth(42, &w);
            Assert::AreEqual(42, w);
        }

        TEST_METHOD(T2_SetWidth99)
        {
            int w = 5;
            setWidth(99, &w);
            Assert::AreEqual(99, w);
        }

        TEST_METHOD(T2_SetWidth100)
        {
            int w = 5;
            setWidth(100, &w);
            Assert::AreEqual(5, w);
        }
    };
}
