#include "TokenProcessor.h"

void TokenProcessor::incrementCounter(unsigned int &counter)
{
	counter++;
}

void TokenProcessor::incrementStack(size_t size)
{
	stackSize += size;
	updateRamSize();
}

void TokenProcessor::incrementHeap(size_t size)
{
	heapSize += size;
	updateRamSize();
}

/*
* Has to be called every time Stack or Heap change.
*/
void TokenProcessor::updateRamSize()
{
	ramSize = stackSize + heapSize;
	if (ramSize > ramMax)
		ramMax = ramSize;
}

void TokenProcessor::incrementLine()
{
	lineCounter++;
}

void TokenProcessor::processInteger()
{
	//Debugging Message.
	cout << "Integer found." << endl;
	incrementStack(sizeof(int));
	incrementCounter(intCounter);
}

void TokenProcessor::processFloat()
{
	//Debugging Message.
	cout << "Float found." << endl;
	incrementStack(sizeof(float));
	incrementCounter(floatCounter);
}

/*TODO
*Difficult. We have to account for SSO.
*
*/
void TokenProcessor::processString(string String)
{
	//Debugging Message.
	cout << "String found: " << String << endl;
	cout << "String size: " << sizeof(String) << endl;
	incrementStack(sizeof(char*));
	incrementHeap(sizeof(String));
	incrementCounter(stringCounter);
}

void TokenProcessor::printResults()
{
	cout << "Results over " << lineCounter << " lines." << endl
		<< "The following types were found:" << endl
		<< "Integer: " << intCounter << endl
		<< "Float: " << floatCounter << endl
		<< "String: " << stringCounter << endl
		<< "MaxRAM: " << ramMax << " Bytes" << endl;
}
