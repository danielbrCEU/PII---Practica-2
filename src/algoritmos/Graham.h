
#include <vector>
#include "../Punto.h"
#include "../Ventana.h"

class Graham
{
    public:
        void convex_hull(std::vector<Punto>& puntos, Ventana& ventana);

    private:
        float orientacion_tripleta(Punto p, Punto q, Punto r);
        float distancia(Punto p, Punto q);
};