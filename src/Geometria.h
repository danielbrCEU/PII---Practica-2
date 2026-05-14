#pragma once
#include <vector>
#include "Punto.h"


class Geometria
{
    public:
        // Si devuelve valor positivo rota en sentido horario, y valor negativo antihorario.
        static float orientacion_tripleta(Punto p, Punto q, Punto r);
        // Distancia al cuadrado entre dos puntos
        static float distancia(Punto p, Punto q);
        static std::vector<Punto> generar_puntos(int n, int min, int max);
};
