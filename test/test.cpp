#include "test.h"
#include "../index.h"
#include "termcolor.hpp"

#include <iostream>
#include <string>

using namespace std;

string boolString(bool value) {
	return value ? "TRUE" : "FALSE";
}

struct Option {
		bool toBe;
		int x1;
		int y1;
		int x2;
		int y2;
};

Option options[] = {
		{
				true,
				5,
				6,
				4,
				7
		},
		{
				false,
				3,
				3,
				3,
				4
		},
		{
				true,
				2,
				4,
				3,
				5
		},
		{
				false,
				5,
				2,
				2,
				5
		},
		{
				true,
				6,
				3,
				7,
				4
		},
		{
				false,
				2,
				3,
				3,
				5
		}
};

void printGreen(const string& test, const string& result) {
	cout << termcolor::green << "TEST " << "\"" << test << "\"" << " PASSED! RESULT: " << result;
}

void printRed(const string& test, const string& expected, const string& result) {
	cout << termcolor::red << "TEST " << "\"" << test << "\"" << " FAILED! EXPECTED: \"" << expected << "\" INSTEAD OF \"" << result << "\"!";
}

void test() {
	int optionsLength = sizeof(options) / sizeof(options[0]);

	for (int i = 0; i < optionsLength; i++) {
		Option option = options[i];

		int result = pawn(option.x1, option.y1, option.x2, option.y2);

		cout << endl;

		string testStr = to_string(option.x1) + ' ' + to_string(option.y1) + ", " + to_string(option.x2) + ' ' + to_string(option.y2);

		if (result == option.toBe) {
			printGreen(testStr, boolString(result));
		} else {
			printRed(testStr, boolString(option.toBe), boolString(result));
		}

		cout << endl;
	}
}