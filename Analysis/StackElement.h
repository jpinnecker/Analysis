#pragma once
#include "Ram.h"

/**
	Element eines Stacks.
	Das kann eine automatische Variable sein, oder eine Funktion
*/
class StackElement
{
protected:
	/**
	Die Größe in Byte dieses DataElements. Wird vom Konstruktor initialisiert.
	*/
	size_t byteSize;
public:
	StackElement(size_t byteSize);
	/**
		Getter für byteSize;
	*/
	size_t getByteSize();
};

