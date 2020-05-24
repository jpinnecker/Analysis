#include "Ram.h"

void Ram::updateRamSize()
{
	ramSize = stackSize + heapSize;
	if (ramSize > ramMax)
		ramMax = ramSize;
}

void Ram::increaseStackSize(size_t size)
{
	stackSize += size;
	updateRamSize();
}

void Ram::decreaseStackSize(size_t size)
{
	stackSize -= size;
	updateRamSize();
}

unsigned long long Ram::getStackSize() const
{
	return stackSize;
}

unsigned long long Ram::getRamMax() const
{
	return ramMax;
}
