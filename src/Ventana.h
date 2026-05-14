#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Punto.h"

class Ventana
{
    public:
        Ventana();
        void iniciar();
        void mostrar();
        void procesar();
        bool esta_abierta();
        void dibujar_puntos(std::vector<Punto>& puntos);
        void dibujar_punto_rojo(Punto punto);
        void dibujar_linea(Punto a, Punto b);
        void dibujar_envolvente(std::vector<Punto>& puntos, std::vector<Punto>& hull);

    private:
        sf::RenderWindow window;
};