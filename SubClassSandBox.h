#pragma once
#include "Prerrequisites.h"

class Sound {
public:
	virtual void reproducir() = 0;
};


class MusicaFondo : public Sound {
public:
	void reproducir() override {
		cout << "Reproduciendo musica de fondo" << endl;
	}
};

class SFX : public Sound {
public:
	void reproducir() override {
		cout << "Reproduciendo fectos de sonido" << endl;
	}
};