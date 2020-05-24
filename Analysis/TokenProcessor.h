#pragma once
#include <iostream>
#include <stack>
#include "DataElement.h"
using namespace std;

class TokenProcessor
{
private:
	Ram ram;
	//Remember to delete top before pop
	stack<DataElement*> ramStack;

	unsigned int lineCounter = 1;

	unsigned int intCounter = 0;
	unsigned int shortCounter = 0;
	unsigned int longCounter = 0;
	unsigned int longLongCounter = 0;
	unsigned int floatCounter = 0;
	unsigned int doubleCounter = 0;
	unsigned int longDoubleCounter = 0;
	unsigned int charCounter = 0;
	unsigned int stringCounter = 0;

	void incrementCounter(unsigned int &);

	void prntPrc();
public:
	void incrementLine();
	unsigned int getLine();

	void processToken(size_t, string);

	void printResults();
};