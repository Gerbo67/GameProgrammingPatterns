#pragma once
#include "Prerrequisites.h"


class DoubleBuffer {
public:
	DoubleBuffer() : buffer1(10), buffer2(10), activeBuffer(&buffer1) {} //Inicializacion de los 3 vectores indicando el tamano que contienen

	//Simular la actualiacion en el buffer activo

	void updateData() { //Se revisa el tamano del buffer activo, para recorrer todos sus puntos y luego multiplica i por 2, cada que pasa por un espacio de memoria
		for (int i = 0; i < activeBuffer->size(); i++) {
			//Actualizar los datos
			(*activeBuffer)[i] = i * 2;
		}
	}

	void swapBuffers() { //Cambio entre buffers, primero se verifica que el buffer activo es identico al primer buffer
		// si lo es, cambia al buffer 2 en caso de que no, regresa a ser el buffer 1
		activeBuffer = (activeBuffer == &buffer1) ? &buffer2 : &buffer1;
	}

	void printActive() { //Impresion de datos recorriendo todo el vector de buffer activos. 
		cout << "Datos en el buffer activo: " << endl;
		for (int val : *activeBuffer) {
			cout << val << " ";
		}
		cout << endl;
	}
private:
	vector<int> buffer1; // Primer Buffer
	vector<int> buffer2; // Segundo Buffer
	vector<int>* activeBuffer; // Buffer activo, servira para intercambiar los datos entre el primer y segundo buffer

};

//Practica de Double Buffer

class GameObject {
public:
	string  name;
	int posX;
	int posY;

public:
	GameObject(const string& name, int posX, int posY)
		: name(name), posX(posX), posY(posY) {}

	void UpdatePosition(int newX, int newY) {
		posX = newX;
		posY = newY;
	}

	void PrintInfo() const {
		cout << "Objeto: " << name << " | Posicion: (" << posX << ", " << posY << ")\n";
	}
};

class Game {
public:
	Game() : buffer1(), buffer2(), activeBuffer(&buffer1) {}

	void addGameObject(const GameObject& obj) {
		activeBuffer->push_back(obj);
	}

	void initializeBuffer() {
		// Inicia el buffer1 con algunos objetos
		buffer1.push_back(GameObject("Player", 10, 10));
		buffer1.push_back(GameObject("Enemy", 20, 20));
	}

	void updateGameObject() {
		//Simulacion de actualizacion de objetos en el buffer activo
		for (auto& obj : *activeBuffer) {
			obj.UpdatePosition(obj.posX + 1, obj.posY + 1);
		}
	}
	void swapBuffers() { //Cambio entre buffers, primero se verifica que el buffer activo es identico al primer buffer
		// si lo es, cambia al buffer 2 en caso de que no, regresa a ser el buffer 1
		activeBuffer = (activeBuffer == &buffer1) ? &buffer2 : &buffer1;
	}
	void printActiveObjects() const { //Impresion de datos recorriendo todo el vector de buffer activos. 
		cout << "Objetos en el buffer activo: " << endl;
		for (const auto& obj : *activeBuffer) {
			obj.PrintInfo();
		}
		cout << endl;
	}
private:
	vector<GameObject> buffer1;
	vector<GameObject> buffer2;
	vector<GameObject>* activeBuffer;
};

