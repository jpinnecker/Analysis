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

void TokenProcessor::processToken(size_t byteSize, string message)
{
	cout << message;
	functionIterator->second->pushRamStack(byteSize);
	cout << byteSize << " Bytes | ";
	prntPrc();
}

void TokenProcessor::processFunction(string fnctName)
{
	cout << "Functioncall... " << fnctName << " ";
	//Finde Funktion und beachte den Maximalverbrauch.
	size_t feRamMax = functionMap.find(fnctName)->second->getRam()->getRamMax();
	functionIterator->second->pushRamStack(feRamMax);
	functionIterator->second->popRamStack(feRamMax);
	cout << feRamMax << " Bytes processed." << endl;
}

void TokenProcessor::registerFunction(size_t returnSize, string fnctName)
{
	//Füge der map eine neue Funktion hinzu und setze den Iterator auf diese.
	cout << "Function found... " << fnctName;
	functionIterator = functionMap.insert(functionMap.end(), make_pair(fnctName, new FunctionElement(returnSize)));
	cout << " registered." << endl;
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
		<< "MaxRAM: " << functionMap.find("main")->second->getRam()->getRamMax() << " Bytes" << endl;
}
