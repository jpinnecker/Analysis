#pragma once

/**
	Die Klasse um den Speicherbedarf zu verfolgen.
*/
class Ram
{
private:
	/**
		Speichert die momentane Größe aller ramStacks in Bytes.
		Wird durch die Methoden increaseStackSize und decreaseStackSize aktualisiert.
	*/
	unsigned long long stackSize = 0;
	/**
		Speichert die momentane Größe des Heaps in Bytes. Zurzeit ohne Verwendung.
	*/
	unsigned long long heapSize = 0;
	/**
		Speichert die momentane Gesamtgröße des benötigten Speichers.
		Besteht aus stackSize + heapSize und wird durch updateRamSize aktuell gehalten.
		Theoretisch fehlt hier noch die Größe des in den Arbeitsspeicher kopierten Maschinencodes.
	*/
	unsigned long long ramSize = 0;
	/**
		Speichert den Maximalzustand von ramSize und wird durch updateRamSize gesetzt.
	*/
	unsigned long long ramMax = 0;

	/**
		Bildet den neuen ramSize anhand von stackSize und heapSize und muss demzufolge bei jeder Änderung aufgerufen werden.
		Wird von increaseStackSize und decreaseStackSize aufgerufen.
		Wird ramSize größer als ramMax wird ramMax auf die Größe von ramSize angepasst.
	*/
	void updateRamSize();
public:
	/**
		Erhöht stackSize um size. Ruft updateRamSize auf.
	*/
	void increaseStackSize(size_t byteSize);
	/**
		Verringert stackSize um size. Ruft updateRamSize auf.
	*/
	void decreaseStackSize(size_t byteSize);
	/**
		Füge byteSize ramMax hinzu.
	*/
	void increaseRamMax(size_t byteSize);
	/**
		Hat stackSize als Rückgabewert.
	*/
	unsigned long long getStackSize() const;
	/**
		Hat ramMax als Rückgabewert.
	*/
	unsigned long long getRamMax() const;
};

