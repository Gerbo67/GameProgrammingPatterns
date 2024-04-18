#pragma once
#include "Prerrequisites.h"

#pragma region ProfesorObserver

// Clase base para los observadores
class Observer {
public:
	virtual void update(int temperature) = 0; // M�todo de actualizaci�n que debe ser implementado por los observadores
};

// Clase Sujeto, que es el sensor de temperatura
class TemperatureSensor {
public:
	// M�todo para agregar observadores al sensor de temperatura
	void addObserver(Observer* observer) {
		observers.push_back(observer); // Agrega el observador a la lista de observadores
	}

	// M�todo para notificar a todos los observadores sobre un cambio en la temperatura
	void notifyObservers() {
		for (Observer* observer : observers) {
			observer->update(temperature); // Notifica a cada observador sobre el cambio de temperatura
		}
	}

	// M�todo para establecer la temperatura y notificar a los observadores
	void setTemperature(int temp) {
		temperature = temp; // Establece la nueva temperatura
		notifyObservers(); // Notifica a los observadores sobre el cambio de temperatura
	}

private:
	int temperature; // Temperatura actual
	vector<Observer*> observers; // Lista de observadores del sensor de temperatura
};

// Clase concreta de observador para dispositivos de visualizaci�n de temperatura
class DisplayDevice : public Observer {
public:
	// M�todo de actualizaci�n que muestra la temperatura
	void update(int temperature) override {
		cout << "Temperature: " << temperature << endl; // Imprime la temperatura
	}
};

#pragma endregion

#pragma region MensajeriaObserver

// Clase base para los observadores de mensajes
class MessageObserver {
public:
	virtual void notify(string message) = 0; // M�todo de notificaci�n que debe ser implementado por los observadores
};

// Clase Sujeto, que es el servicio de mensajer�a
class MessageService {
public:
	// M�todo para agregar observadores al servicio de mensajer�a
	void addObserver(MessageObserver* observer) {
		observers.push_back(observer); // Agrega el observador a la lista de observadores
	}

	// M�todo para notificar a todos los observadores sobre un nuevo mensaje
	void notifyObservers() {
		for (MessageObserver* observer : observers) {
			observer->notify(message); // Notifica a cada observador sobre el nuevo mensaje
		}
	}

	// M�todo para establecer un nuevo mensaje y notificar a los observadores
	void setMessage(string msg) {
		message = msg; // Establece el nuevo mensaje
		notifyObservers(); // Notifica a los observadores sobre el nuevo mensaje
	}

private:
	string message; // �ltimo mensaje recibido
	vector<MessageObserver*> observers; // Lista de observadores del servicio de mensajer�a
};

// Clases concretas de observadores para notificaciones de sonido, vibraci�n y pantalla
class SoundNotification : public MessageObserver {
public:
	// M�todo de notificaci�n que reproduce un sonido
	void notify(string message) override {
		cout << "Sonido: " << message << endl; // Imprime un mensaje con la notificaci�n de sonido
	}
};

class VibrationNotification : public MessageObserver {
public:
	// M�todo de notificaci�n que activa una vibraci�n
	void notify(string message) override {
		cout << "Vibracion: " << message << endl; // Imprime un mensaje con la notificaci�n de vibraci�n
	}
};

class ScreenNotification : public MessageObserver {
public:
	// M�todo de notificaci�n que muestra un mensaje en pantalla
	void notify(string message) override {
		cout << "Pantalla: " << message << endl; // Imprime un mensaje con la notificaci�n en pantalla
	}
};

#pragma endregion
