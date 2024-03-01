#pragma once
#include <iostream>
#include <SFML/Window.hpp>  
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Jugador.h"
#include <vector>
#include "Planetas.h"
#include "Escenas.h"
using namespace sf;

class Juego
{
	RenderWindow* wind;
	Jugador* player;
	Planetas* star;
	Planetas* rock;
	Escenas* esc;
	Texture txtr, inicio;
	Sprite fondo, ini;
	SoundBuffer buffer, b2;
	Sound puntoss, up;
	Music musica;
	std::vector<Planetas> planetasVector;
	Font fuente;
	Text score, lives;
	int intentos, puntos, extras;
	bool reinidone, listo;

public:

	Juego();
	~Juego();
	void loop();
	void eventos();
	void actualizar();
	void dibujar();
	void verificarColisiones();
	void reiniciar();
	void expl();
	void ending();
	void vidaextra();
};

