#include "TokenProcessor.h"

void TokenProcessor::incrementCounter(unsigned int &counter)
{
	counter++;
}

void TokenProcessor::processInteger(int integer)
{
	cout << "Integer found: " << integer << endl;
	incrementCounter(intCounter);
}

void TokenProcessor::printResults()
{
	cout << "Results" << endl
		<< "The following types were found:" << endl
		<< "Integer: " << intCounter << endl;
}
