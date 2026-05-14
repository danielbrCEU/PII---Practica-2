#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Punto.h"

class Ventana
{
    public:
        Ventana();
        void iniciar();
        void display();
        void process_events();
        bool esta_abierta();
        void render_puntos(std::vector<Punto>& puntos);
        void render_punto_blanco(Punto punto);
        void render_punto_rojo(Punto punto);
        void render_linea(Punto a, Punto b);

    private:
        sf::RenderWindow window;
};