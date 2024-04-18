#pragma once
#include "Prerrequisites.h"

#pragma region ProfesorObserver

// Clase base para los observadores
class Observer {
public:
	virtual void update(int temperature) = 0; // Método de actualización que debe ser implementado por los observadores
};

// Clase Sujeto, que es el sensor de temperatura
class TemperatureSensor {
public:
	// Método para agregar observadores al sensor de temperatura
	void addObserver(Observer* observer) {
		observers.push_back(observer); // Agrega el observador a la lista de observadores
	}

	// Método para notificar a todos los observadores sobre un cambio en la temperatura
	void notifyObservers() {
		for (Observer* observer : observers) {
			observer->update(temperature); // Notifica a cada observador sobre el cambio de temperatura
		}
	}

	// Método para establecer la temperatura y notificar a los observadores
	void setTemperature(int temp) {
		temperature = temp; // Establece la nueva temperatura
		notifyObservers(); // Notifica a los observadores sobre el cambio de temperatura
	}

private:
	int temperature; // Temperatura actual
	vector<Observer*> observers; // Lista de observadores del sensor de temperatura
};

// Clase concreta de observador para dispositivos de visualización de temperatura
class DisplayDevice : public Observer {
public:
	// Método de actualización que muestra la temperatura
	void update(int temperature) override {
		cout << "Temperature: " << temperature << endl; // Imprime la temperatura
	}
};

#pragma endregion

#pragma region MensajeriaObserver

// Clase base para los observadores de mensajes
class MessageObserver {
public:
	virtual void notify(string message) = 0; // Método de notificación que debe ser implementado por los observadores
};

// Clase Sujeto, que es el servicio de mensajería
class MessageService {
public:
	// Método para agregar observadores al servicio de mensajería
	void addObserver(MessageObserver* observer) {
		observers.push_back(observer); // Agrega el observador a la lista de observadores
	}

	// Método para notificar a todos los observadores sobre un nuevo mensaje
	void notifyObservers() {
		for (MessageObserver* observer : observers) {
			observer->notify(message); // Notifica a cada observador sobre el nuevo mensaje
		}
	}

	// Método para establecer un nuevo mensaje y notificar a los observadores
	void setMessage(string msg) {
		message = msg; // Establece el nuevo mensaje
		notifyObservers(); // Notifica a los observadores sobre el nuevo mensaje
	}

private:
	string message; // Último mensaje recibido
	vector<MessageObserver*> observers; // Lista de observadores del servicio de mensajería
};

// Clases concretas de observadores para notificaciones de sonido, vibración y pantalla
class SoundNotification : public MessageObserver {
public:
	// Método de notificación que reproduce un sonido
	void notify(string message) override {
		cout << "Sonido: " << message << endl; // Imprime un mensaje con la notificación de sonido
	}
};

class VibrationNotification : public MessageObserver {
public:
	// Método de notificación que activa una vibración
	void notify(string message) override {
		cout << "Vibracion: " << message << endl; // Imprime un mensaje con la notificación de vibración
	}
};

class ScreenNotification : public MessageObserver {
public:
	// Método de notificación que muestra un mensaje en pantalla
	void notify(string message) override {
		cout << "Pantalla: " << message << endl; // Imprime un mensaje con la notificación en pantalla
	}
};

#pragma endregion
