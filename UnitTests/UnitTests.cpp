#include "pch.h"
#include "CppUnitTest.h"
#include "..\Project1\Point.h"
#include "..\Project1\Validator.h"
#include "..\Project1\Point.cpp"
#include "..\Project1\Validator.cpp"
#include "..\Project1\Fields.h"
#include <string>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework; 

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
		Point p;
		Validator validator;
		Fields fields;
		vector<string> valid_points = { "1.1 2.1 green", "2.42 3.21 red", "5.322 4.11 blue", "8.9999 9.8888 red", "99.11 23.333 green" };
		vector<string> invalid_points = { "a b green", "2.42 red", "05.322 4.11 blue", "8.9999 09.8888 red", "99.11 23.333", "5.322 4.11 Blue", "5.3a22 4.11 blue", "5.322 4.a11 blue", "5.322 4.11 c" };
		stringstream stream;
	public:
		
		TEST_METHOD(printPoint)
		{
			string str = "1 1 green";
			string expect = "1 1 green\n";
			p.SetPoint(str);
			p.PrintPoint(0, stream);
			Assert::AreEqual(expect, stream.str());
			p.DeletePoints();
			stream.str(string());
		}
		TEST_METHOD(deletePoint)
		{
			string expect = "1.1 2.1 green\n2.42 3.21 red\n8.9999 9.8888 red\n99.11 23.333 green\n";
			for (auto i : valid_points)
				p.SetPoint(i);
			p.DeletePoint(2);
			p.PrintPoints(stream);
			Assert::AreEqual(expect, stream.str());
			p.DeletePoints();
			stream.str(string());
		}
		TEST_METHOD(deletePoints)
		{
			for (auto i : valid_points)
				p.SetPoint(i);
			p.DeletePoints();
			p.PrintPoints(stream);
			Assert::AreEqual(string(), stream.str());
			stream.str(string());
		}
		TEST_METHOD(validPoints)
		{
			string expect = "1.1 2.1 green\n2.42 3.21 red\n5.322 4.11 blue\n8.9999 9.8888 red\n99.11 23.333 green\n";
			for (auto i : valid_points)
				p.SetPoint(i);
			p.PrintPoints(stream);
			Assert::AreEqual(expect, stream.str());
			p.DeletePoints();
			stream.str(string());
		}
		TEST_METHOD(invalidPoints)
		{
			for (auto i : invalid_points)
				p.SetPoint(i);
			p.PrintPoints(stream);
			Assert::AreEqual(string(), stream.str());
			p.DeletePoints();
			stream.str(string());
		}
	};
}