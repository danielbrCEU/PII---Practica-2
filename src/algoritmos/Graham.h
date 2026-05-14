#pragma once
#include <vector>
#include "../Punto.h"
#include "../Ventana.h"

class Graham
{
    public:
        void convex_hull(std::vector<Punto>& puntos, Ventana& ventana);
};