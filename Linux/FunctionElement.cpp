#include "FunctionElement.h"

FunctionElement::FunctionElement(size_t byteSize) : StackElement(byteSize)
{
	//Erh�he ram um den R�ckgabewert der Funktion.
	ram.increaseStackSize(byteSize);
}

void FunctionElement::pushRamStack(size_t byteSize)
{
	ramStack.push(new StackElement(byteSize));
	ram.increaseStackSize(byteSize);
}

void FunctionElement::popRamStack(size_t byteSize)
{
	ramStack.pop(); //calls destructor, so no delete needed
	ram.decreaseStackSize(byteSize);
}

Ram* FunctionElement::getRam()
{
	return &ram;
}
