#pragma once
#include "Prerrequisites.h"


#pragma region Profesorstate

// Clase base para los estados del personaje
class EstadoPersonaje {
public:
	virtual void atacar() = 0; // M�todo para realizar una acci�n de ataque
	virtual void moverse() = 0; // M�todo para realizar una acci�n de movimiento
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
		cout << "Ataque con m�s fuerza" << endl; // Ataque con m�s fuerza
	}

	void moverse() override {
		cout << "Movimiento m�s lento" << endl; // Movimiento m�s lento
	}
};

// Estado concreto para el personaje en su estado enfurecido
class EstadoEnfurecido : public EstadoPersonaje {
public:
	void atacar() override {
		cout << "Ataque con furia" << endl; // Ataque con furia
	}

	void moverse() override {
		cout << "Movimiento m�s r�pido" << endl; // Movimiento m�s r�pido
	}
};

// Clase Contexto que utiliza el estado
class Personaje {
public:
	Personaje() : estado(new EstadoNormal()) {} // Inicializa el estado del personaje como normal

	// M�todo para establecer un nuevo estado para el personaje
	void setEstado(EstadoPersonaje* nuevoEstado) {
		estado = nuevoEstado; // Cambia el estado del personaje
	}

	// M�todos que delegan la acci�n al estado actual del personaje
	void atacar() {
		estado->atacar(); // Realiza la acci�n de ataque seg�n el estado actual
	}

	void moverse() {
		estado->moverse(); // Realiza la acci�n de movimiento seg�n el estado actual
	}

private:
	EstadoPersonaje* estado; // Estado actual del personaje
};

#pragma endregion


#pragma region VehiculoState

// Clase base para los estados del veh�culo
class EstadoVehiculo {
public:
	virtual void acelerar() = 0; // M�todo para realizar una acci�n de aceleraci�n
	virtual void frenar() = 0; // M�todo para realizar una acci�n de frenado
};

// Estado concreto para el veh�culo en su estado de velocidad normal
class EstadoVelocidadNormal : public EstadoVehiculo {
public:
	void acelerar() override {
		cout << "Acelerando normal" << endl; // Aceleraci�n normal
	}

	void frenar() override {
		cout << "Frenando normal" << endl; // Frenado normal
	}
};

// Estado concreto para el veh�culo en su estado de velocidad reducida
class EstadoVelocidadReducido : public EstadoVehiculo {
public:
	void acelerar() override {
		cout << "Acelerando reducido" << endl; // Aceleraci�n reducida
	}

	void frenar() override {
		cout << "Frenando reducido" << endl; // Frenado reducido
	}
};

// Clase Contexto que utiliza el estado
class Vehiculo {
public:
	Vehiculo() : estado(new EstadoVelocidadNormal()) {} // Inicializa el estado del veh�culo como velocidad normal

	// M�todo para establecer un nuevo estado para el veh�culo
	void setEstado(EstadoVehiculo* nuevoEstado) {
		estado = nuevoEstado; // Cambia el estado del veh�culo
	}

	// M�todos que delegan la acci�n al estado actual del veh�culo
	void acelerar() {
		estado->acelerar(); // Realiza la acci�n de aceleraci�n seg�n el estado actual
	}

	void frenar() {
		estado->frenar(); // Realiza la acci�n de frenado seg�n el estado actual
	}

private:
	EstadoVehiculo* estado; // Estado actual del veh�culo
};

#pragma endregion
