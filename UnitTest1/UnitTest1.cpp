#include "pch.h"
#include "CppUnitTest.h"
#include "../5.3/5.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Z_BigX)
		{
			Assert::AreEqual(0.611742, z(1.0), 1e-5);
			Assert::AreEqual(0.052664, z(-1.0), 1e-5);
			Assert::AreEqual(0.034859, z(2.0), 1e-5);
		}

		TEST_METHOD(Z_SmallX)
		{
			Assert::AreEqual(1.0, z(0.0), 1e-5);
			Assert::AreEqual(2.116824, z(0.5), 1e-5);
			Assert::AreEqual(0.286642, z(-0.5), 1e-5);
		}

		TEST_METHOD(Z_ExpressionFromMain)
		{
			double p = 1.0;
			double res = z(p * p + 1.0) - z(p * p - 1.0) + 2.0 * z(p);
			Assert::AreEqual(0.258343, res, 1e-5);
		}
	};
}