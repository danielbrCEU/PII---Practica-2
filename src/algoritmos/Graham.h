
#include <vector>
#include "../Punto.h"

class Graham
{
    Graham();
    virtual ~Graham() = default;

    void ordenar_puntos(std::vector<Punto>& puntos);
    float orientacion_tripleta(Punto p, Punto q, Punto r);
    float distancia(Punto p, Punto q);
};