#include "stdafx.h"
#include "CppUnitTest.h"
#include <cassert>
#include "../Project7/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test1)
		{
			Queue<int> base;
			base.push(5, 1);
			int result = base.top();
			int actuel = 5;
			Assert::AreEqual(result, actuel);
		}
		TEST_METHOD(Test2)
		{
			Queue<char> base;
			base.push('a', 2);
			base.push('k', 1);
			char result = base.top();
			char actuel = 'a';
			Assert::AreEqual(result, actuel);
		}
		TEST_METHOD(Test3)
		{
			Queue<int> base;
			base.push(5, 1);
			base.push(17, 1);
			base.push(3, 1);
			base.pop();
			int result1 = base.getSize();
			int actuel1 = 4;
			Assert::AreEqual(result1, actuel1);
			int result2 = base.top();
			int actuel2 = 17;
			Assert::AreEqual(result2, actuel2);
		}
		TEST_METHOD(Test4)
		{
			Queue<int> base;
			base.push(5, 1);
			base.push(7, 3);
			base.push(6, 3);
			int result = base.top();
			int actuel = 7;
			Assert::AreEqual(result, actuel);
		}
		TEST_METHOD(Test5)
		{
			Queue<string> base;
			base.push("Andriy", 2);
			base.push("Kolja", 1);
			base.push("Norbert", 1);
			base.pop();
			string result = base.top();
			string actuel = "Kolja";
			Assert::AreEqual(result, actuel);
		}
		TEST_METHOD(Test6)
		{
			Queue<double> base;
			base.push(3.14, 1000);
			base.push(5.17, 15);
			base.pop();
			double result = base.top();
			double actuel = 5.17;
			Assert::AreEqual(result, actuel);
		}
		TEST_METHOD(Test7)
		{
			Queue<int> base;
			base.push(15, 2);
			base.push(12, 1);
			base.push(34, 5);
			base.push(8, 2);
			base.pop();
			base.pop();
			int result1 = base.top();
			int actuel1 = 8;
			Assert::AreEqual(result1, actuel1);
			bool result2 = base.isEmpty();
			bool actuel2 = false;
			Assert::AreEqual(result2, actuel2);
		}


	};
}