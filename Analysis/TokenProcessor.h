#pragma once
#include <iostream>
using namespace std;

class TokenProcessor
{
private:
	unsigned int lineCounter = 0;

	unsigned int intCounter = 0;
	unsigned int floatCounter = 0;
	unsigned int stringCounter = 0;

	unsigned long long stackSize = 0;
	unsigned long long heapSize = 0;
	unsigned long long ramSize = 0;
	unsigned long long ramMax = 0;

	void incrementCounter(unsigned int &);
	void incrementStack(size_t);
	void incrementHeap(size_t);
	void updateRamSize();
public:
	void incrementLine();

	void processInteger();
	void processFloat();
	void processString(string);

	void printResults();
};

