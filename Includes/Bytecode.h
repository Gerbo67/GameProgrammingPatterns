#pragma once
#include "Prerrequisites.h"

// Enumeración que define los diferentes bytecodes posibles
enum Bytecode {
	JUMP = 1,
	ATTACK = 2,
	BLOCK = 3,
	SPECIAL = 4
};

// Clase que interpreta los bytecodes
class BytecodeInterpreter {
public:
	// Método para interpretar un bytecode
	void interpret(Bytecode bytecode) {
		// Selecciona la acción correspondiente al bytecode recibido
		switch (bytecode) {
		case JUMP:
			cout << "Jump!" << endl; // Realiza la acción de salto
			break;
		case ATTACK:
			cout << "Attack!" << endl; // Realiza la acción de ataque
			break;
		case BLOCK:
			cout << "Block!" << endl; // Realiza la acción de bloqueo
			break;
		case SPECIAL:
			cout << "Special!" << endl; // Realiza una acción especial
			break;
		default:
			cout << "Invalid bytecode" << endl; // Maneja bytecodes no reconocidos
		}
	}
};