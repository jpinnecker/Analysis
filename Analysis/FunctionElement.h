#pragma once
#include "StackElement.h"
#include "Ram.h"
#include <stack>

/**
	Diese Klasse dient dem Verfolgen des Speicherbedarfs und später auch der Laufzeit einzelner Funktionen.
*/
class FunctionElement : StackElement
{
private:
	/**
		Jede Funktion besitzt einen Ram::Ram um die maximale Auswirkung auf den Speicher erkennen zu können.
	*/
	Ram ram;
	/**
		Der Stack an automatischen Variablen einer Funktion.
	*/
	std::stack<StackElement*> ramStack;
public:
	/**
		Konstruktor mit Elementinitialisierungsliste.
		Erhöht ram um den Rückgabewert der Funktion.
	*/
	FunctionElement(size_t byteSize);
	/**
		Lege ein neues StackElement auf den ramStack anhand von byteSize.
		Auch wird increaseStackSize(byteSize) aufgerufen um die Änderung im Ram festzuhalten.
	*/
	void pushRamStack(size_t byteSize);
	/**
		Entferne StackElement und verringere die StackSize.
	*/
	void popRamStack(size_t byteSize);
	/**
		Getter für ram.
	*/
	Ram* getRam();
};

