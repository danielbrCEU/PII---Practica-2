#pragma once
#include <vector>
#include "../Punto.h"
#include "../Ventana.h"

class Graham
{
    public:
        std::vector<Punto> envolvente_convexo(std::vector<Punto>& puntos, Ventana& ventana);
};