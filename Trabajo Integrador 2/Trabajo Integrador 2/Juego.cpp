#include "Juego.h"


Juego::Juego(): planetasVector(20) {
	wind = new RenderWindow(VideoMode(1000, 700), "Jueguito");
	player = new Jugador();
	rock = new Planetas();
	star = new Planetas();
	rock = new Planetas();
	esc = new Escenas();
	intentos = 3;
	extras = 0;
	fuente.loadFromFile("Oswald.ttf");
	score.setFont(fuente);
	lives.setFont(fuente);
	score.setString("Puntaje: ");
	lives.setString("Intentos: ");
	score.setPosition(60, 610);
	lives.setPosition(830, 610);
	wind->setFramerateLimit(60);
	txtr.loadFromFile("fondo.jpg");
	fondo.setTexture(txtr);
	for (int i = 0; i < planetasVector.size(); ++i) {
		planetasVector[i].randtex(); 
		planetasVector[i].randpos();
	}
	reinidone = false;
	listo = false;
	if (!buffer.loadFromFile("puntos.wav")) {

	}
	if (!b2.loadFromFile("up.wav")) {

	}
	up.setBuffer(b2);
	puntoss.setBuffer(buffer);
	if (!musica.openFromFile("musica.ogg"))
	{
		
	}
	musica.setLoop(true);
}

Juego::~Juego() {
	delete wind;
	delete player;
	delete star;
	delete rock;
	delete esc;
}

void Juego::loop() {
	musica.play();
	do {
		Vector2f cohete = player->getPosicion();
		if (cohete.y > 740 && !reinidone) {
			reiniciar();
			reinidone = true;
		}

		actualizar();
		verificarColisiones();
		dibujar();
		eventos();

		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			reinidone = false;
		}
		if (intentos == 0) {
			ending();
		}
	} while ((wind->isOpen() && intentos > 0));
}

void Juego::eventos() {
	Event eve;

	while (wind->pollEvent(eve)) {
		switch (eve.type) {
		case Event::Closed:
			wind->close();
			break;
		case Event::KeyPressed: 
			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				player->moverarriba();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Space)) {
				player->lanzar();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Left)) {
				player->moverizq();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right)) {
				player->moverder();
			}
			break;
			}
		}
	}

void Juego::actualizar() {
	player->moviendo();
	if (player->getPosicion().y < player->altmax()) {
		player->invertirY();
	}
	if (extras >= 120) {
		vidaextra();
	}
	star->actualistar();
	rock->actualirock();
}

void Juego::dibujar() {
	wind->clear();
	wind->draw(fondo);
	player->dibujar(wind);
	for (int i = 0; i < planetasVector.size(); i++)
	{
			planetasVector[i].dibujo(wind);
	}

	player->triangulos(wind);
	star->dibustar(wind);
	rock->diburock(wind);
	score.setString("Puntaje: " + std::to_string(puntos));
	lives.setString("Vidas: " + std::to_string(intentos));
	wind->draw(score);
	wind->draw(lives);
	wind->display();
}

void Juego::verificarColisiones() {
	for (int i = 0; i < planetasVector.size(); i++) {
		if (planetasVector[i].verificarColision(player->getSprite())) {
			planetasVector[i].reposicionarsi(player->getSprite());
			puntos += 10;
			extras += 10;
			puntoss.play();
		}
	}

	if (star->verificarcolstar(player->getSprite())) {
		
		star->repostar();
		puntos += 50;
		extras += 50;
		puntoss.play();
	}

	if (rock->verificarcolrock(player->getSprite())) {
		puntos -= 1;
	}
}

void Juego::reiniciar() {
	star->volverstar();
	player->reposicion();
	reinidone = false; 
	intentos--; 
	for (int i = 0; i < planetasVector.size(); ++i) {
		planetasVector[i].randtex();
		planetasVector[i].randpos();
	}
}

void Juego::expl() {
	esc->introduccion(wind);
}

void Juego::ending() {
	
	if (esc->end(puntos, wind) == true) {
		intentos = 4;
		puntos = 0;
		extras = 0;
		reiniciar();
	}
	else {
		
	}
}

void Juego::vidaextra() {
	intentos += 1;
	extras = 0;
	up.play();
}