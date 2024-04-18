#pragma once
#include "Prerrequisites.h"

// Interfaz para las operaciones de bytecodes
class BytecodeOperation {
public:
	// M�todo virtual puro para ejecutar la operaci�n del bytecode
	virtual void execute() = 0;
};

// Implementaci�n concreta de una operaci�n de bytecode: Saludo
class GreetingOperation : public BytecodeOperation {
public:
	// Implementaci�n de la operaci�n de saludo
	void execute() {
		cout << "Hello, it is a pleasure to meet you" << endl; // Imprime un saludo
	}
};

// Implementaci�n concreta de una operaci�n de bytecode: Despedida
class FarewellOperation : public BytecodeOperation {
public:
	// Implementaci�n de la operaci�n de despedida
	void execute() {
		cout << "Goodbye, see you soon" << endl; // Imprime una despedida
	}
};
