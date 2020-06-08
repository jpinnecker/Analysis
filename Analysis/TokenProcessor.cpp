#include "TokenProcessor.h"

void TokenProcessor::incrementCounter(unsigned int &counter)
{
	counter++;
}

void TokenProcessor::prntPrc()
{
	cout << "Token processed on line " << getLine() << "." << endl;
}

void TokenProcessor::incrementLine()
{
	lineCounter++;
}

unsigned int TokenProcessor::getLine()
{
	return lineCounter;
}

/*
* Creates new dataElement with given size and puts it on the stack.
*/
void TokenProcessor::processToken(size_t byteSize, string message)
{
	cout << message;
	ramStack.push(new DataElement(byteSize,&ram));
	prntPrc();
}

void TokenProcessor::printResults()
{
	cout << "Results over " << getLine() << " lines." << endl
		//<< "The following types were found:" << endl
		//<< "Integer: " << intCounter << endl
		//<< "Short: " << shortCounter << endl
		//<< "Long: " << longCounter << endl
		//<< "Long Long: " << longLongCounter << endl
		//<< "Float: " << floatCounter << endl
		//<< "Double: " << doubleCounter << endl
		//<< "Long Double: " << longDoubleCounter << endl
		//<< "Character: " << charCounter << endl
		<< "MaxRAM: " << ram.getRamMax() << " Bytes" << endl;
}
