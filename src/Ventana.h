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
        void dibujar_puntos(const std::vector<Punto>& puntos);
        void dibujar_punto_rojo(Punto punto);
        void dibujar_linea(Punto a, Punto b);
        void dibujar_envolvente(const std::vector<Punto>& puntos, const std::vector<Punto>& envolvente);

    private:
        sf::RenderWindow window;
};