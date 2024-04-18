#pragma once
#include "Prerrequisites.h"

// Enumeraci�n que define los diferentes bytecodes posibles
enum Bytecode {
	JUMP = 1,
	ATTACK = 2,
	BLOCK = 3,
	SPECIAL = 4
};

// Clase que interpreta los bytecodes
class BytecodeInterpreter {
public:
	// M�todo para interpretar un bytecode
	void interpret(Bytecode bytecode) {
		// Selecciona la acci�n correspondiente al bytecode recibido
		switch (bytecode) {
		case JUMP:
			cout << "Jump!" << endl; // Realiza la acci�n de salto
			break;
		case ATTACK:
			cout << "Attack!" << endl; // Realiza la acci�n de ataque
			break;
		case BLOCK:
			cout << "Block!" << endl; // Realiza la acci�n de bloqueo
			break;
		case SPECIAL:
			cout << "Special!" << endl; // Realiza una acci�n especial
			break;
		default:
			cout << "Invalid bytecode" << endl; // Maneja bytecodes no reconocidos
		}
	}
};