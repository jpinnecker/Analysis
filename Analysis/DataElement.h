#pragma once
#include "Ram.h"

class DataElement
{
private:
	Ram* ramPointer;
	size_t byteSize;
public:
	DataElement(size_t byteSize, Ram* ramPointer);
	DataElement(const DataElement&) = delete;
	~DataElement();
	Ram* getRampointer() const;
	size_t getByteSize() const;
};
