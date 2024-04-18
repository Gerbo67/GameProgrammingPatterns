#pragma once
#include "Prerrequisites.h"

// Clase abstracta que representa la parte compartida del objeto
class FlyWeight {
public:
	virtual void draw(int x, int y) = 0; // Método para dibujar el objeto en las coordenadas especificadas
};

// Clase concreta que implementa el objeto compartido
class ConcreteFlyWeight : public FlyWeight {
public:
	ConcreteFlyWeight(char _symbol) : m_symbol(_symbol) {} // Constructor que inicializa el símbolo del objeto

	// Método para dibujar el objeto en las coordenadas especificadas
	void draw(int x, int y) override {
		cout << m_symbol << " drawn at " << x << ", " << y << endl; // Imprime el símbolo del objeto y sus coordenadas
	}

private:
	char m_symbol; // Símbolo del objeto
};

// Fábrica que gestiona la creación de los objetos compartidos (FlyWeights)
class FlyWeightFactory {
public:
	// Método para obtener un objeto FlyWeight dado un símbolo
	FlyWeight* getFlyWeight(char _symbol) {
		// Si el símbolo no existe en el mapa de FlyWeights
		if (m_flyweights.find(_symbol) == m_flyweights.end()) {
			// Crea un nuevo objeto ConcreteFlyWeight con el símbolo dado
			m_flyweights[_symbol] = new ConcreteFlyWeight(_symbol);
		}

		// Devuelve el FlyWeight asociado al símbolo
		return m_flyweights[_symbol];
	}

private:
	unordered_map<char, FlyWeight*> m_flyweights; // Mapa que mapea símbolos a FlyWeights
};
