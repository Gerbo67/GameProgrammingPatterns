#pragma once
#include "Prerrequisites.h"

class Component {
public:
	virtual void init() = 0; // Inicializaci�n del componente
	virtual void update() = 0; // Actualizaci�n del componente
	virtual void render() = 0; // Renderizaci�n del componente
	virtual void destroy() = 0; // Destrucci�n del componente
	virtual ~Component() {}; // Destructor virtual para la clase base
};

// Componente concreto para el renderizado
class RenderComponent : public Component {
public:
	void init() override {
		cout << "Se inicializa el render" << endl;
	}

	void update() override {
		// No se implementa en este caso
	}

	void render() override {
		cout << "Se actualiza la posici�n de la malla" << endl;
	}

	void destroy() override {
		// No se implementa en este caso
	}
};

// Componente concreto para la f�sica
class PhysicsComponent : public Component {
public:
	void init() override {
		cout << "Se inicializa el componente de f�sica" << endl;
	}

	void update() override {
		cout << "Se actualiza el proceso matem�tico" << endl;
	}

	void render() override {
		cout << "Se actualiza la f�sica del objeto" << endl;
	}

	void destroy() override {
		// No se implementa en este caso
	}
};

// Componente concreto para la inteligencia artificial (IA)
class IAComponent : public Component {
public:
	void init() override {
		cout << "Se inicializa el componente de IA" << endl;
	}

	void update() override {
		cout << "Se actualiza el proceso de IA" << endl;
	}

	void render() override {
		cout << "Se actualiza la IA del objeto" << endl;
	}

	void destroy() override {
		// No se implementa en este caso
	}
};

// Clase Entidad que utiliza componentes para definir su funcionalidad
class Entity {
public:
	// M�todo para agregar un componente a la entidad
	void addComponent(Component* component) {
		components.push_back(component); // Agrega el componente a la lista de componentes
	}

	// M�todo para inicializar todos los componentes de la entidad
	void initComponent() {
		for (auto component : components) {
			component->init(); // Inicializa cada componente
		}
	}

	// M�todo para actualizar todos los componentes de la entidad
	void updateComponent() {
		for (auto component : components) {
			component->update(); // Actualiza cada componente
		}
	}

	// M�todo para renderizar todos los componentes de la entidad
	void renderComponent() {
		for (auto component : components) {
			component->render(); // Renderiza cada componente
		}
	}

	// M�todo para destruir todos los componentes de la entidad
	void destroyComponent() {
		for (auto component : components) {
			component->destroy(); // Destruye cada componente
		}
	}

private:
	vector<Component*> components; // Lista de componentes de la entidad
};
