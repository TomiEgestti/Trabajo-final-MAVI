#pragma once
#include <iostream>
#include <SFML/Window.hpp>  
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

class Planetas
{
	Texture sat, lun, mart, mete, estr;
	Sprite rock,rock2, star, spr;
	float s1, r1, r2, r3, r4;
	int change;
	Clock reloj, relorock, relorock2;
	Vector2f spos1, rpos1, rpos2;
	bool reposicionado, movv;

public:
	Planetas();
	void randpos();
	void randtex();
	void dibujo(RenderWindow* wind);
	void dibustar(RenderWindow* wind);
	void diburock(RenderWindow* wind);
	void actualistar();
	void invdir();
	bool verificarColision(const Sprite& jugador);
	void reposicionarsi(const Sprite& jugador);
	void reposicionar();
	bool verificarcolstar(const Sprite& jugador);
	void repostar();
	void volverstar();
	void actualirock();
	bool verificarcolrock(const Sprite& jugador);
};

