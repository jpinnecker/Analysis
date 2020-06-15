#pragma once
#include <iostream>
#include <stack>
#include "DataElement.h"
using namespace std;

/**
	Klasse zur Verarbeitung der gefundenen Tokens.
*/
class TokenProcessor
{
private:
	/**
		Der TokenProcessor besitzt einen Ram::Ram, der dazu verwendet wird den ben�tigten Speicherbedarf abzubilden.
	*/
	Ram ram;
	/**
		Der ramStack dient dazu einen Stack an automatischen Variablen zu simulieren.
		Beim Entfernen der Stackelemente (ramStack.pop()) muss darauf geachtet werden zuerst ein delete auf die dazugeh�rigen DataElements auszuf�hren.
	*/
	stack<DataElement*> ramStack;

	/**
		Der lineCounter dient dazu zu verfolgen bei welcher Zeile ein Token gefunden wurde. Das ist hilfreich bei der Fehlersuche.
	*/
	unsigned int lineCounter = 1;

	//Die Z�hler werden momentan nicht benutzt.
	//Sie stehen hier als Idee, f�r den Fall, dass sich das mal �ndert.
	//unsigned int intCounter = 0;
	//unsigned int shortCounter = 0;
	//unsigned int longCounter = 0;
	//unsigned int longLongCounter = 0;
	//unsigned int floatCounter = 0;
	//unsigned int doubleCounter = 0;
	//unsigned int longDoubleCounter = 0;
	//unsigned int charCounter = 0;
	//unsigned int stringCounter = 0;

	/**
		Erwartet wird ein Counter als Argument (Referenz). Dieser wird inkrementiert.
		Sollten �berpr�fungen f�llig werden k�nnen diese hier implementiert werden.
		Momentan unbenutzt.
	*/
	void incrementCounter(unsigned int &counter);

	/**
		Eine Methode zur Ausgabe der Zeile, an der ein Token gefunden wurde.
		Wird aufgerufen nach der Verarbeitung des Tokens.
		Zu debugging Zwecken.
	*/
	void prntPrc();
public:
	/**
		Inkrementiert den lineCounter.
		Wird von dem Parser aufgerufen und kann deshalb nicht �ber incrementCounter implementiert werden.
	*/
	void incrementLine();
	/**
		Hat den momentanen Zustand des lineCounters als R�ckgabewert.
	*/
	unsigned int getLine();
	/**
		Wird vom Parser aufgerufen. Die �bergebene message wird ausgegeben.
		Anhand von byteSize wird ein neues Datenelement auf den ramStack gelegt.
	*/
	void processToken(size_t byteSize, string message);
	/**
		Ausgabe der Ergebnisse.
	*/
	void printResults();
};