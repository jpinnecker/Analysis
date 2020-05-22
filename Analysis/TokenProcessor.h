#pragma once
#include <iostream>
using namespace std;

class TokenProcessor
{
private:
	unsigned int lineCounter = 0;

	unsigned int intCounter = 0;
	unsigned int shortCounter = 0;
	unsigned int longCounter = 0;
	unsigned int longLongCounter = 0;
	unsigned int floatCounter = 0;
	unsigned int doubleCounter = 0;
	unsigned int longDoubleCounter = 0;
	unsigned int charCounter = 0;
	unsigned int stringCounter = 0;

	unsigned long long stackSize = 0;
	unsigned long long heapSize = 0;
	unsigned long long ramSize = 0;
	unsigned long long ramMax = 0;

	void incrementCounter(unsigned int &);
	void incrementStack(size_t);
	void incrementHeap(size_t);
	void updateRamSize();

	void prntPrc();
public:
	void incrementLine();
	unsigned int getLine();

	void processInteger();
	void processShort();
	void processLong();
	void processLongLong();
	void processFloat();
	void processDouble();
	void processLongDouble();
	void processCharacter();
	void processString(string);

	void printResults();
};