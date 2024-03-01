#pragma once
#include <iostream>
#include <SFML/Window.hpp>  
#include <SFML/Graphics.hpp>
using namespace sf;

class Escenas
{
	Texture inicio, bronz, silver, gold, plat, bg;
	Sprite ini, medal, fondo;
	Font fuente;
	Text congr, cong2, cont;
	bool listo;

	public:

		Escenas();
		void introduccion(RenderWindow* wind);
		bool end(int points, RenderWindow* wind);
};

