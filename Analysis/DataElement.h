#pragma once
#include "Ram.h"

class DataElement
{
private:
	Ram* stackPointer;
	size_t byteSize;
public:
	DataElement(size_t byteSize, Ram* stackPointer);
	DataElement(const DataElement&) = delete;
	~DataElement();
	Ram* getStackpointer() const;
	size_t getByteSize() const;
};
