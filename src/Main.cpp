#include <SFML/Graphics.hpp>
#include <iostream>
#include "Punto.h"
#include "algoritmos/Graham.h"
#include "algoritmos/MergeSort.h"
#include "Ventana.h"

int main()
{
    Ventana ventana;

    std::vector<Punto> puntos = {{100, 100}, {300, 100}, {100, 300}, {300, 300}, {200, 200}, {210, 210}, {5,5}, {395, 395}};

     // Render initial points
    ventana.iniciar();
    ventana.render_puntos(puntos);

    MergeSort ms;
    ms.ordenar(puntos);

    for (const auto& p : puntos)
        std::cout << "(" << p.x << ", " << p.y << ")\n";


    Graham algoritmoGraham;
    algoritmoGraham.convex_hull(puntos, ventana);

    // Keep window open
    while (ventana.esta_abierta())
    {
        ventana.process_events();
    }
}
