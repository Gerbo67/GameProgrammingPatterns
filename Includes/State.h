#pragma once
#include "Prerrequisites.h"


#pragma region Profesorstate

// Clase base para los estados del personaje
class EstadoPersonaje {
public:
	virtual void atacar() = 0; // Método para realizar una acción de ataque
	virtual void moverse() = 0; // Método para realizar una acción de movimiento
};

// Estado concreto para el personaje en su estado normal
class EstadoNormal : public EstadoPersonaje {
public:
	void atacar() override {
		cout << "Ataque normal" << endl; // Ataque normal
	}

	void moverse() override {
		cout << "Movimiento normal" << endl; // Movimiento normal
	}
};

// Estado concreto para el personaje en su estado herido
class EstadoHerido : public EstadoPersonaje {
public:
	void atacar() override {
		cout << "Ataque con más fuerza" << endl; // Ataque con más fuerza
	}

	void moverse() override {
		cout << "Movimiento más lento" << endl; // Movimiento más lento
	}
};

// Estado concreto para el personaje en su estado enfurecido
class EstadoEnfurecido : public EstadoPersonaje {
public:
	void atacar() override {
		cout << "Ataque con furia" << endl; // Ataque con furia
	}

	void moverse() override {
		cout << "Movimiento más rápido" << endl; // Movimiento más rápido
	}
};

// Clase Contexto que utiliza el estado
class Personaje {
public:
	Personaje() : estado(new EstadoNormal()) {} // Inicializa el estado del personaje como normal

	// Método para establecer un nuevo estado para el personaje
	void setEstado(EstadoPersonaje* nuevoEstado) {
		estado = nuevoEstado; // Cambia el estado del personaje
	}

	// Métodos que delegan la acción al estado actual del personaje
	void atacar() {
		estado->atacar(); // Realiza la acción de ataque según el estado actual
	}

	void moverse() {
		estado->moverse(); // Realiza la acción de movimiento según el estado actual
	}

private:
	EstadoPersonaje* estado; // Estado actual del personaje
};

#pragma endregion


#pragma region VehiculoState

// Clase base para los estados del vehículo
class EstadoVehiculo {
public:
	virtual void acelerar() = 0; // Método para realizar una acción de aceleración
	virtual void frenar() = 0; // Método para realizar una acción de frenado
};

// Estado concreto para el vehículo en su estado de velocidad normal
class EstadoVelocidadNormal : public EstadoVehiculo {
public:
	void acelerar() override {
		cout << "Acelerando normal" << endl; // Aceleración normal
	}

	void frenar() override {
		cout << "Frenando normal" << endl; // Frenado normal
	}
};

// Estado concreto para el vehículo en su estado de velocidad reducida
class EstadoVelocidadReducido : public EstadoVehiculo {
public:
	void acelerar() override {
		cout << "Acelerando reducido" << endl; // Aceleración reducida
	}

	void frenar() override {
		cout << "Frenando reducido" << endl; // Frenado reducido
	}
};

// Clase Contexto que utiliza el estado
class Vehiculo {
public:
	Vehiculo() : estado(new EstadoVelocidadNormal()) {} // Inicializa el estado del vehículo como velocidad normal

	// Método para establecer un nuevo estado para el vehículo
	void setEstado(EstadoVehiculo* nuevoEstado) {
		estado = nuevoEstado; // Cambia el estado del vehículo
	}

	// Métodos que delegan la acción al estado actual del vehículo
	void acelerar() {
		estado->acelerar(); // Realiza la acción de aceleración según el estado actual
	}

	void frenar() {
		estado->frenar(); // Realiza la acción de frenado según el estado actual
	}

private:
	EstadoVehiculo* estado; // Estado actual del vehículo
};

#pragma endregion
