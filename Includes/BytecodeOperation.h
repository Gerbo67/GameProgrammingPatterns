#pragma once
#include "Prerrequisites.h"

// Interfaz para las operaciones de bytecodes
class BytecodeOperation {
public:
	// Método virtual puro para ejecutar la operación del bytecode
	virtual void execute() = 0;
};

// Implementación concreta de una operación de bytecode: Saludo
class GreetingOperation : public BytecodeOperation {
public:
	// Implementación de la operación de saludo
	void execute() {
		cout << "Hello, it is a pleasure to meet you" << endl; // Imprime un saludo
	}
};

// Implementación concreta de una operación de bytecode: Despedida
class FarewellOperation : public BytecodeOperation {
public:
	// Implementación de la operación de despedida
	void execute() {
		cout << "Goodbye, see you soon" << endl; // Imprime una despedida
	}
};
