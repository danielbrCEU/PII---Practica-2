#include "Geometria.h"
#include <cstdlib>

float Geometria::orientacion_tripleta(Punto p, Punto q, Punto r) {
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

float Geometria::distancia(Punto p, Punto q) {
    return (q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y);
}

std::vector<Punto> Geometria::generar_puntos(int n, int min, int max) {
    std::vector<Punto> puntos;

    for (int i = 0; i < n; i++) {
        int x = rand() % (max - min + 1) + min;
        int y = rand() % (max - min + 1) + min;
        puntos.push_back({x, y});
    }
    return puntos;
}
