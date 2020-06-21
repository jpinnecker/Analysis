#include "StackElement.h"

StackElement::StackElement(size_t byteSize)
{
    this->byteSize = byteSize;
}

size_t StackElement::getByteSize()
{
    return byteSize;
}
