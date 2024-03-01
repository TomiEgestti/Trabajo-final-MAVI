#include "Escenas.h"

Escenas::Escenas() {
	inicio.loadFromFile("Rocketfall.png");
	bronz.loadFromFile("bronz.png");
	silver.loadFromFile("silver.png");
	gold.loadFromFile("gold.png");
	plat.loadFromFile("platinum.png");
	bg.loadFromFile("fondi.png");
	fondo.setTexture(bg);
	fondo.setPosition(0, 0);
	ini.setTexture(inicio);
	ini.setPosition(0, 0);
	fuente.loadFromFile("Oswald.ttf");
	congr.setFont(fuente);
	cong2.setFont(fuente);
	cont.setFont(fuente);
	cont.setString("Para volver a jugar, presiona enter, para salir, escape");
	cont.setPosition(220, 570);
	congr.setPosition(410, 70);
	cong2.setPosition(320, 110);
	medal.setPosition(260, 140);
	listo = false;
}

void Escenas::introduccion(RenderWindow* wind) {
		wind->clear();
		wind->draw(ini);
		wind->display();
		Event eve;
		while (listo == false) {
			while (wind->pollEvent(eve)) {
				if (eve.type == sf::Event::Closed) {
					wind->close();
				}
				else if (eve.type == sf::Event::KeyPressed && eve.key.code == sf::Keyboard::Enter) {
					listo = true;
				}
			}
		}
	}

bool Escenas::end(int points, RenderWindow* wind) {
	wind->clear();
	wind->draw(fondo);
	if (points <= 100) {
		congr.setString("Buen trabajo!");
		cong2.setString("Cantidad de puntos obtenidos: " + std::to_string(points));
		medal.setTexture(bronz);
		wind->draw(medal);
	}
	else if(points > 100 && points <= 200){
		congr.setString("Gran partida!");
		cong2.setString("Cantidad de puntos obtenidos: " + std::to_string(points));
		medal.setTexture(silver);
		wind->draw(medal);
		wind->draw(congr);
		wind->draw(cong2);
		wind->draw(cont);
	}
	else if (points > 200 && points <= 250) {
		congr.setString("Excelente partida!");
		cong2.setString("Cantidad de puntos obtenidos: " + std::to_string(points));
		medal.setTexture(gold);
		wind->draw(medal);
		wind->draw(congr);
		wind->draw(cong2);
		wind->draw(cont);
	}
	else if (points > 250) {
		congr.setString("Sos una leyenda!");
		cong2.setString("Cantidad de puntos obtenidos: " + std::to_string(points));
		medal.setTexture(plat);
		wind->draw(medal);
		wind->draw(congr);
		wind->draw(cong2);
		wind->draw(cont);
	}
	wind->display();
	Event eve;
	while (true) {
		while (wind->pollEvent(eve)) {
			if (eve.type == sf::Event::Closed) {
				wind->close();
			}
			else if (eve.type == sf::Event::KeyPressed && eve.key.code == sf::Keyboard::Enter) {
				return true;
			}
			else if (eve.type == sf::Event::KeyPressed && eve.key.code == sf::Keyboard::Escape) {
				return false;
			}
		}
	}
}