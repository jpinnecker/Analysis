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
	Die Gr��e in Byte dieses DataElements. Wird vom Konstruktor initialisiert.
	*/
	size_t byteSize;
public:
	StackElement(size_t byteSize);
	/**
		Getter f�r byteSize;
	*/
	size_t getByteSize();
};

