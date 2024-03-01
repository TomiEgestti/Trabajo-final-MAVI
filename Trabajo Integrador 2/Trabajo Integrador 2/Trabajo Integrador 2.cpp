#include <iostream>
#include <SFML/Window.hpp>  
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Juego.h"
#include <ctime>

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    Juego mijuego;
    mijuego.expl();
    mijuego.loop();
}
