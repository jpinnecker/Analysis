#pragma once

class Ram
{
private:
	unsigned long long stackSize = 0;
	unsigned long long heapSize = 0;
	unsigned long long ramSize = 0;
	unsigned long long ramMax = 0;

	//Call every time ramSize has to change.
	void updateRamSize();
public:
	//Only call by constructor of DataElement
	void increaseStackSize(size_t size);
	//Only call by destructor of DataElement
	void decreaseStackSize(size_t size);

	unsigned long long getStackSize() const;
	unsigned long long getRamMax() const;
};

