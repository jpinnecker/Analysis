#pragma once
#include "StackElement.h"
#include "Ram.h"
#include <stack>

/**
	Diese Klasse dient dem Verfolgen des Speicherbedarfs und sp�ter auch der Laufzeit einzelner Funktionen.
*/
class FunctionElement : StackElement
{
private:
	/**
		Jede Funktion besitzt einen Ram::Ram um die maximale Auswirkung auf den Speicher erkennen zu k�nnen.
	*/
	Ram ram;
	/**
		Der Stack an automatischen Variablen einer Funktion.
	*/
	std::stack<StackElement*> ramStack;
public:
	/**
		Konstruktor mit Elementinitialisierungsliste.
		Erh�ht ram um den R�ckgabewert der Funktion.
	*/
	FunctionElement(size_t byteSize);
	/**
		Lege ein neues StackElement auf den ramStack anhand von byteSize.
		Auch wird increaseStackSize(byteSize) aufgerufen um die �nderung im Ram festzuhalten.
	*/
	void pushRamStack(size_t byteSize);
	/**
		Entferne StackElement und verringere die StackSize.
	*/
	void popRamStack(size_t byteSize);
	/**
		Getter f�r ram.
	*/
	Ram* getRam();
};

