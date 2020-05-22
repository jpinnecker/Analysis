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

void TokenProcessor::prntPrc()
{
	cout << "Token processed." << endl;
}

void TokenProcessor::incrementLine()
{
	lineCounter++;
}

unsigned int TokenProcessor::getLine()
{
	return ++lineCounter;
}

void TokenProcessor::processInteger()
{
	//Debugging Message.
	cout << "Integer found... ";
	incrementStack(sizeof(int));
	incrementCounter(intCounter);
	prntPrc();
}

void TokenProcessor::processShort()
{
	//Debugging Message.
	cout << "Short found... ";
	incrementStack(sizeof(short));
	incrementCounter(shortCounter);
	prntPrc();
}

void TokenProcessor::processLong()
{
	//Debugging Message.
	cout << "Long found... ";
	incrementStack(sizeof(long));
	incrementCounter(longCounter);
	prntPrc();
}

void TokenProcessor::processLongLong()
{
	//Debugging Message.
	cout << "Long Long found... ";
	incrementStack(sizeof(long long));
	incrementCounter(longLongCounter);
	prntPrc();
}

void TokenProcessor::processFloat()
{
	//Debugging Message.
	cout << "Float found... ";
	incrementStack(sizeof(float));
	incrementCounter(floatCounter);
	prntPrc();
}

void TokenProcessor::processDouble()
{
	//Debugging Message.
	cout << "Double found... ";
	incrementStack(sizeof(double));
	incrementCounter(doubleCounter);
	prntPrc();
}

void TokenProcessor::processLongDouble()
{
	//Debugging Message.
	cout << "Long Double found... ";
	incrementStack(sizeof(long double));
	incrementCounter(longDoubleCounter);
	prntPrc();
}

void TokenProcessor::processCharacter()
{
	//Debugging Message.
	cout << "Character found... ";
	incrementStack(sizeof(char));
	incrementCounter(charCounter);
	prntPrc();
}

/*TODO
*In c this is simply a character array terminated by '\0'
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
	cout << "Results over " << ++lineCounter << " lines." << endl
		<< "The following types were found:" << endl
		<< "Integer: " << intCounter << endl
		<< "Short: " << shortCounter << endl
		<< "Long: " << longCounter << endl
		<< "Long Long: " << longLongCounter << endl
		<< "Float: " << floatCounter << endl
		<< "Double: " << doubleCounter << endl
		<< "Long Double: " << longDoubleCounter << endl
		<< "Character: " << charCounter << endl
		<< "MaxRAM: " << ramMax << " Bytes" << endl;
}
