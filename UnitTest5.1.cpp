#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.1A/FloatRange.h"
#include "../Lab5.1A/FloatRange.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest21
{
	TEST_CLASS(UnitTest21)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			FloatRange TEST(2, 10);
			Assert::AreEqual(TEST.rangeCheck(TEST, 2.111), true);
			Assert::AreEqual(TEST.rangeCheck(TEST, 1.999), false);
			Assert::AreEqual(TEST.rangeCheck(TEST, 9.99), true);
			Assert::AreEqual(TEST.rangeCheck(TEST, 10.0001), false);
		}
	};
}
