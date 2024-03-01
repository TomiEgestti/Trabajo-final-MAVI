#include "Jugador.h"

Jugador::Jugador() {
	velY = 0.0;
	acelY = 0.0;
	velX = 0.0;
	acelX = 0.0;
	moving = false;
	red = false;
	yell = false;
	grn = false;
	maxvel = -4.5;
	spr.setPosition(450, 590);
	text.loadFromFile("cohete.png");
	inv.loadFromFile("coheteinv.png");
	spr.setTexture(text);
	spr.setScale(0.15, 0.15);
	pos = spr.getPosition();
	rojo.loadFromFile("triangrojo.png");
	ama.loadFromFile("triangama.png");
	verd.loadFromFile("triangverd.png");
	triang.setTexture(rojo);
	triang2.setTexture(ama);
	triang3.setTexture(verd);
    triang.setPosition(260, 610);
	triang2.setPosition(290, 610);
	triang3.setPosition(320, 610);
	triang.setScale(0.1f, 0.1f);
	triang2.setScale(0.1f, 0.1f);
	triang3.setScale(0.1f, 0.1f);
}

void Jugador::dibujar(RenderWindow* wind){
	wind->draw(spr);
}

void Jugador::moverarriba() {
	if (!moving && acelY >= -5.0) {
		acelY += -0.5f;
	}
}

void Jugador::moverizq() {
	if (acelX >= -4.0) {
		acelX += -1.2;
	}
}

void Jugador::moverder() {
	if (acelX <= 4.0) {
		acelX += 1.2;
	}
}

void Jugador::lanzar() {
	if (!moving && acelY < 0) {
		velY = acelY;
		if (velY < maxvel) {
			velY = maxvel;
		}
		if (pos.y < 680) {
			acelX = 0.0;
		}
		moving = true;
	}
}

void Jugador::moviendo() {
	velX = acelX;
	if (velX < -3.5) {
		velX = -3.5;
	}
	else if (velX > 3.5) {
		velX = 3.5;
	}
	if (pos.x < 0) {
		pos.x = 0;
	}

	if (pos.x > 1000 - spr.getGlobalBounds().width) {
		pos.x = 1000 - spr.getGlobalBounds().width;
	}
	pos.x += velX;
	if (moving) {

		pos.y += velY;

		if (pos.y < 0) {
			invertirY();
		}

	}
	spr.setPosition(pos);
};

void Jugador::invertirY() {
	
	if (acelY <= -1.5 && acelY > -2.5) {
		velY = 1.5;
		spr.setTexture(inv);
	}
	else if (acelY <= -2.5 && acelY > -4.0) {
		velY = 2.0;
		spr.setTexture(inv);
	}
	else if (acelY <= -4.0) {
		velY = 3.0;
		spr.setTexture(inv);
	}
}

Vector2f Jugador::getPosicion() {
	return spr.getPosition();
}

float Jugador::altmax() {
	float maxim = 0.0; 

	if (acelY <= -1.5 && acelY > -2.5) {
		maxim = 300;
		red = true;
	}
	else if (acelY <= -2.5 && acelY > -3.5) {
		maxim = 90;
		yell = true;
	}
	else if (acelY <= -4.0 && acelY >= -5.0) {
		maxim = 0;
		grn = true;
	}

	return maxim;
}

void Jugador::triangulos(RenderWindow* wind) {
	if (red && !moving) {
		wind->draw(triang);
	}
	if (yell && !moving) {
		wind->draw(triang2);
	}
	if (grn && !moving) {
		wind->draw(triang3);
	}
}

Sprite Jugador::getSprite() const {
	return spr;
}

void Jugador::reposicion() {
	spr.setTexture(text);
	spr.setPosition(450, 590);
	pos = spr.getPosition();
	velY = 0.0;
	acelY = 0.0;
	velX = 0.0;
	acelX = 0.0;
	moving = false;
	red = false;
	yell = false;
	grn = false;
}
