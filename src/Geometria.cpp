#include "Geometria.h"

float Geometria::orientacion_tripleta(Punto p, Punto q, Punto r) {
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

float Geometria::distancia(Punto p, Punto q) {
    return (q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y);
}
