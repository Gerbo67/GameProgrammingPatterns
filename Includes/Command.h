#pragma once
#include "Prerrequisites.h"

#pragma region ProfesorComando

// Interfaz de comando
class Command {
public:
	virtual void ejecutar() = 0; // M�todo para ejecutar la operaci�n del comando
	virtual void deshacer() = 0; // M�todo para deshacer la operaci�n del comando
};

// Clase receptora que representa un dispositivo, en este caso una luz
class Luz {
public:
	void encender() {
		cout << "Luz encendida" << endl; // M�todo para encender la luz
	}

	void apagar() {
		cout << "Luz apagada" << endl; // M�todo para apagar la luz
	}
};

// Comandos concretos que implementan la interfaz Command para operaciones espec�ficas con la luz
class ComandoEncenderLuz : public Command {
public:
	// Constructor que recibe una referencia a la luz para poder ejecutar la operaci�n
	ComandoEncenderLuz(Luz& luz) : m_luz(luz) {}

	void ejecutar() override {
		m_luz.encender(); // Ejecuta la operaci�n de encender la luz
	}

	void deshacer() override {
		m_luz.apagar(); // Deshace la operaci�n apagando la luz
	}

private:
	Luz& m_luz; // Referencia a la luz sobre la que se ejecutar� la operaci�n
};

// Clase concreta para apagar la luz
class ComandoApagarLuz : public Command {
public:
	// Constructor que recibe una referencia a la luz
	ComandoApagarLuz(Luz& luz) : m_luz(luz) {}

	void ejecutar() override {
		m_luz.apagar(); // Ejecuta la operaci�n de apagar la luz
	}

	void deshacer() override {
		m_luz.encender(); // Deshace la operaci�n encendiendo la luz
	}

private:
	Luz& m_luz; // Referencia a la luz
};

// Invocador que ejecuta y mantiene un historial de comandos
class ControlRemoto {
public:
	// M�todo para presionar un bot�n, ejecutar el comando y agregarlo al historial
	void presionarBoton(Command* comando) {
		comando->ejecutar(); // Ejecuta el comando recibido
		m_historial.push_back(comando); // Agrega el comando al historial
	}

	// M�todo para deshacer el �ltimo comando ejecutado
	void deshacer() {
		if (!m_historial.empty()) {
			m_historial.back()->deshacer(); // Deshace el �ltimo comando en el historial
			m_historial.pop_back(); // Elimina el �ltimo comando del historial
		}
	}

private:
	vector<Command*> m_historial; // Historial de comandos ejecutados
};

#pragma endregion

#pragma region FernandoComando

// Clase base Operacion con funciones virtuales para ejecutar y deshacer operaciones matem�ticas
class Operacion {
public:
	virtual void ejecutar() = 0; // M�todo virtual puro para ejecutar la operaci�n
	virtual void deshacer() = 0; // M�todo virtual puro para deshacer la operaci�n
};

// Clases derivadas que implementan operaciones matem�ticas espec�ficas
class Suma : public Operacion {
public:
	// Constructor que recibe dos operandos para la suma
	Suma(int a, int b) : m_a(a), m_b(b) {}

	void ejecutar() override {
		cout << "Suma: " << m_a + m_b << endl; // Realiza la suma e imprime el resultado
	}

	void deshacer() override {
		cout << "Resta: " << m_a - m_b << endl; // Deshace la suma (realiza la resta) e imprime el resultado
	}

private:
	int m_a, m_b; // Operandos de la suma
};

class Resta : public Operacion {

	public:
	Resta(int a, int b) : m_a(a), m_b(b) {}

	void ejecutar() override {
		cout << "Resta: " << m_a - m_b << endl;
	}

	void deshacer() override {
		cout << "Suma: " << m_a + m_b << endl;
	}

	private:
		int m_a, m_b;
};

class Multiplicacion : public Operacion {

	public:
	Multiplicacion(int a, int b) : m_a(a), m_b(b) {}

	void ejecutar() override {
		cout << "Multiplicacion: " << m_a * m_b << endl;
	}

	void deshacer() override {
		cout << "Division: " << m_a / m_b << endl;
	}

	private:
		int m_a, m_b;
};

class Division : public Operacion {

	public:
	Division(int a, int b) : m_a(a), m_b(b) {}

	void ejecutar() override {
		cout << "Division: " << m_a / m_b << endl;
	}

	void deshacer() override {
		cout << "Multiplicacion: " << m_a * m_b << endl;
	}

	private:
		int m_a, m_b;
};

// Implementaciones similares para Resta, Multiplicacion y Division...

// Calculadora que utiliza el patr�n Command para ejecutar y deshacer operaciones matem�ticas
class Calculadora {
public:
	// M�todo para realizar una operaci�n matem�tica y agregarla al historial
	void realizarOperacion(Operacion* operacion) {
		operacion->ejecutar(); // Ejecuta la operaci�n recibida
		m_historial.push_back(operacion); // Agrega la operaci�n al historial
	}

	// M�todo para deshacer la �ltima operaci�n realizada
	void deshacerOperacion() {
		if (!m_historial.empty()) {
			m_historial.back()->deshacer(); // Deshace la �ltima operaci�n en el historial
			m_historial.pop_back(); // Elimina la �ltima operaci�n del historial
		}
	}

	// M�todo para rehacer la �ltima operaci�n deshecha
	void reahacerOperacion() {
		if (!m_historial.empty()) {
			m_historial.back()->ejecutar(); // Ejecuta nuevamente la �ltima operaci�n deshecha
			m_historial.pop_back(); // Elimina la operaci�n del historial
		}
	}

private:
	vector<Operacion*> m_historial; // Historial de operaciones realizadas
};

#pragma endregion
