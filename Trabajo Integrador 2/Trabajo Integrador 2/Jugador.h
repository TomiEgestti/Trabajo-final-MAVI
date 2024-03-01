#pragma once
#include <SFML/Window.hpp>  
#include <SFML/Graphics.hpp>
using namespace sf;

class Jugador
{
	Texture text, rojo, ama, verd, inv;
	Sprite spr, triang, triang2, triang3;
	float velY, velX;
	float acelY, acelX;
	float maxvel, maxim;
	bool moving, red,yell,grn;
	Vector2f pos;

public:
	Jugador();
	void dibujar(RenderWindow* wind);
	void moverarriba();
	void moverizq();
	void moverder();
	void lanzar();
	void moviendo();
	void invertirY();
	float altmax();
	void triangulos(RenderWindow* wind);
	Vector2f getPosicion();
	Sprite getSprite() const;
	void reposicion();
};

