#include "Planetas.h"

Planetas::Planetas() {
	sat.loadFromFile("saturn.png");
	lun.loadFromFile("moon.png");
	mart.loadFromFile("mars.png");
	mete.loadFromFile("meteoro.png");
	estr.loadFromFile("star.png");
	spr.setScale(0.2f,0.2f);
	rock.setScale(0.7, 0.7);
	rock.setPosition(-5, -5);
	rock2.setTexture(mete);
	rock2.setPosition(1000, 20);
	rock2.setScale(0.7, 0.7);
	s1 = -5.0;
	r1 = 4.5;
	r2 = 2;
	r3 = -4.5;
	r4 = -2;
	change = 1;
	rock.setTexture(mete);
	star.setPosition(870, 30);
	star.setTexture(estr);
	star.setScale(0.2, 0.2);
	spos1 = star.getPosition();
	rpos1 = rock.getPosition();
	rpos2 = rock2.getPosition();
	reloj.restart();
	relorock.restart();
	movv = true;
	relorock2.restart();
}

void Planetas::randpos() {
	float x = static_cast<float>(rand() % 890+30); 
	float y = static_cast<float>(rand() % 400+30);
	spr.setPosition(x, y);
}

void Planetas::randtex() {
	int num = rand() % 3 + 1;
	switch (num) {
	case 1:
		spr.setTexture(sat);
		break;
	case 2:
		spr.setTexture(lun);
		spr.setScale(0.3, 0.3);
		break;
	case 3:
		spr.setTexture(mart);
		break;
	}
}

void Planetas::dibujo(RenderWindow* wind) {
	wind->draw(spr);
	}

void Planetas::invdir() {
		s1 = -s1;
}

void Planetas::actualistar() {
	if (movv) {
		spos1.x += s1;
		star.setPosition(spos1);
		if (reloj.getElapsedTime().asSeconds() >= 3.9 || spos1.x < 0 || spos1.x > 1000) {
			invdir();
			reloj.restart();
		}
	}
}

void Planetas::actualirock() {
	if (change == 1) {
		rpos1.x += r1;
		rpos1.y += r2;
		rock.setPosition(rpos1);
		if (relorock.getElapsedTime().asSeconds() >= 3.4 || rpos1.y > 720 || rpos1.x > 980 ) {
			relorock.restart();
			change = 2;
		}
	}
	else {
		rpos1.x += r3;
		rpos1.y += r4;
		rock.setPosition(rpos1);
		if (relorock.getElapsedTime().asSeconds() >= 3.4 || rpos1.y < 0) {
			relorock.restart();
			change = 1;
		}
	}
}

void Planetas::dibustar(RenderWindow* wind) {
		wind->draw(star);
}

void Planetas::diburock(RenderWindow* wind) {
	wind->draw(rock);
	wind->draw(rock2);
}

bool Planetas::verificarColision(const Sprite& jugador) {
	Vector2f jugadorPos = jugador.getPosition();
	Vector2f planetaPos = spr.getPosition();

	float radioJugador = jugador.getGlobalBounds().width / 2.0f;
	float radioPlaneta = spr.getGlobalBounds().width / 2.0f;

	return std::abs(jugadorPos.x + radioJugador - planetaPos.x - radioPlaneta) < 0.2 * (radioJugador + radioPlaneta) &&
		std::abs(jugadorPos.y + radioJugador - planetaPos.y - radioPlaneta) < 0.2 * (radioJugador + radioPlaneta);
}

void Planetas::reposicionarsi(const Sprite& jugador) {
	if (verificarColision(jugador)) {
		reposicionar();
	}
}

void Planetas::reposicionar() {
	float x = -100.0f;
	float y = -100.0f;
	spr.setPosition(x, y);

}

bool Planetas::verificarcolstar(const Sprite& jugador) {
	sf::Vector2f jugadorPos = jugador.getPosition();
	sf::Vector2f starPos = star.getPosition();

	float radioJugador = jugador.getGlobalBounds().width / 2.0f;
	float radioEstrella = star.getGlobalBounds().width / 2.0f;

	if (std::abs(jugadorPos.x + radioJugador - starPos.x - radioEstrella) < 0.2 * (radioJugador + radioEstrella) &&
		std::abs(jugadorPos.y + radioJugador - starPos.y - radioEstrella) < 0.2 * (radioJugador + radioEstrella)) {
		
		return true;
	}

	return false;
}

bool Planetas::verificarcolrock(const Sprite& jugador) {
	sf::Vector2f jugadorPos = jugador.getPosition();
	sf::Vector2f rockPos = rock.getPosition();

	float radioJugador = jugador.getGlobalBounds().width / 2.0f;
	float radioRock = rock.getGlobalBounds().width / 2.0f;

	return std::abs(jugadorPos.x + radioJugador - rockPos.x - radioRock) < 0.2 * (radioJugador + radioRock) &&
		std::abs(jugadorPos.y + radioJugador - rockPos.y - radioRock) < 0.2 * (radioJugador + radioRock);
}

void Planetas::repostar() {
	star.setPosition(-1000.0f, -1000.0f);
	movv = false;
}

void Planetas::volverstar() {
	star.setPosition(870, 30);
	reloj.restart();
	movv = true;
}


