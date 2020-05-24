#include "DataElement.h"
#include <iostream>

DataElement::DataElement(size_t byteSize, Ram* stackPointer)
{
	this->byteSize = byteSize;
	this->stackPointer = stackPointer;
	this->stackPointer->increaseStackSize(this->byteSize);
}

DataElement::~DataElement()
{
	stackPointer->decreaseStackSize(byteSize);
}

Ram* DataElement::getStackpointer() const
{
	return stackPointer;
}

size_t DataElement::getByteSize() const
{
	return byteSize;
}
