#pragma once
#include "Ram.h"

/**
	Klasse zur Repr�sentation der gefundenen Tokens und deren Gr��e.
*/
class DataElement
{
private:
	/**
		Pointer auf den zu beeinflussenden Ram. Wird vom Konstruktor initialisiert.
	*/
	Ram* ramPointer;
	/**
		Die Gr��e in Byte des Tokens f�r welches dieses DataElement steht. Wird vom Konstruktor initialisiert.
	*/
	size_t byteSize;
public:
	/**
		Der Konstruktor initialisiert die Attribute mit den Parametern.
		Daraufhin wird increaseStackSize des vom ramPointer ausgewiesenen Ram aufgerufen und die stackSize dessen um byteSize erh�ht.
	*/
	DataElement(size_t byteSize, Ram* ramPointer);
	/**
		Um die Daten konsistent zu halten darf der Kopierkonstruktor nicht versehentlich verwendet werden.
		Da das leicht geschehen kann, wird er hier verboten.
	*/
	DataElement(const DataElement&) = delete;
	/**
		Der Destruktor ruft decreaseStackSize des vom ramPointer ausgewiesenen Ram auf und dessen stackSize wird um byteSize verringert.
	*/
	~DataElement();
	/**
		Getter f�r ramPointer.
	*/
	Ram* getRampointer() const;
	/**
		Getter f�r byteSize.
	*/
	size_t getByteSize() const;
};
