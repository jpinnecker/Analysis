#pragma once
#include <iostream>
using namespace std;

class TokenProcessor
{
private:
	unsigned int intCounter = 0;

	void incrementCounter(unsigned int &);
public:
	void processInteger(int);
	void printResults();
};

