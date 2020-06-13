#include "DataElement.h"
#include <iostream>

DataElement::DataElement(size_t byteSize, Ram* ramPointer)
{
	this->byteSize = byteSize;
	this->ramPointer = ramPointer;
	this->ramPointer->increaseStackSize(this->byteSize);
}

DataElement::~DataElement()
{
	ramPointer->decreaseStackSize(byteSize);
}

Ram* DataElement::getRampointer() const
{
	return ramPointer;
}

size_t DataElement::getByteSize() const
{
	return byteSize;
}
