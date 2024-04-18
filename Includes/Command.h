#pragma once
#include "Prerrequisites.h"

#pragma region ProfesorComando

// Interfaz de comando
class Command {
public:
	virtual void ejecutar() = 0; // Método para ejecutar la operación del comando
	virtual void deshacer() = 0; // Método para deshacer la operación del comando
};

// Clase receptora que representa un dispositivo, en este caso una luz
class Luz {
public:
	void encender() {
		cout << "Luz encendida" << endl; // Método para encender la luz
	}

	void apagar() {
		cout << "Luz apagada" << endl; // Método para apagar la luz
	}
};

// Comandos concretos que implementan la interfaz Command para operaciones específicas con la luz
class ComandoEncenderLuz : public Command {
public:
	// Constructor que recibe una referencia a la luz para poder ejecutar la operación
	ComandoEncenderLuz(Luz& luz) : m_luz(luz) {}

	void ejecutar() override {
		m_luz.encender(); // Ejecuta la operación de encender la luz
	}

	void deshacer() override {
		m_luz.apagar(); // Deshace la operación apagando la luz
	}

private:
	Luz& m_luz; // Referencia a la luz sobre la que se ejecutará la operación
};

// Clase concreta para apagar la luz
class ComandoApagarLuz : public Command {
public:
	// Constructor que recibe una referencia a la luz
	ComandoApagarLuz(Luz& luz) : m_luz(luz) {}

	void ejecutar() override {
		m_luz.apagar(); // Ejecuta la operación de apagar la luz
	}

	void deshacer() override {
		m_luz.encender(); // Deshace la operación encendiendo la luz
	}

private:
	Luz& m_luz; // Referencia a la luz
};

// Invocador que ejecuta y mantiene un historial de comandos
class ControlRemoto {
public:
	// Método para presionar un botón, ejecutar el comando y agregarlo al historial
	void presionarBoton(Command* comando) {
		comando->ejecutar(); // Ejecuta el comando recibido
		m_historial.push_back(comando); // Agrega el comando al historial
	}

	// Método para deshacer el último comando ejecutado
	void deshacer() {
		if (!m_historial.empty()) {
			m_historial.back()->deshacer(); // Deshace el último comando en el historial
			m_historial.pop_back(); // Elimina el último comando del historial
		}
	}

private:
	vector<Command*> m_historial; // Historial de comandos ejecutados
};

#pragma endregion

#pragma region FernandoComando

// Clase base Operacion con funciones virtuales para ejecutar y deshacer operaciones matemáticas
class Operacion {
public:
	virtual void ejecutar() = 0; // Método virtual puro para ejecutar la operación
	virtual void deshacer() = 0; // Método virtual puro para deshacer la operación
};

// Clases derivadas que implementan operaciones matemáticas específicas
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

// Calculadora que utiliza el patrón Command para ejecutar y deshacer operaciones matemáticas
class Calculadora {
public:
	// Método para realizar una operación matemática y agregarla al historial
	void realizarOperacion(Operacion* operacion) {
		operacion->ejecutar(); // Ejecuta la operación recibida
		m_historial.push_back(operacion); // Agrega la operación al historial
	}

	// Método para deshacer la última operación realizada
	void deshacerOperacion() {
		if (!m_historial.empty()) {
			m_historial.back()->deshacer(); // Deshace la última operación en el historial
			m_historial.pop_back(); // Elimina la última operación del historial
		}
	}

	// Método para rehacer la última operación deshecha
	void reahacerOperacion() {
		if (!m_historial.empty()) {
			m_historial.back()->ejecutar(); // Ejecuta nuevamente la última operación deshecha
			m_historial.pop_back(); // Elimina la operación del historial
		}
	}

private:
	vector<Operacion*> m_historial; // Historial de operaciones realizadas
};

#pragma endregion
