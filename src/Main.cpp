#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Punto.h"
#include "algoritmos/Graham.h"
#include "algoritmos/MergeSort.h"
#include "Ventana.h"

std::vector<Punto> generar_puntos(int n, int min, int max) {
    std::vector<Punto> puntos;
    srand(time(0));

    for (int i = 0; i < n; i++) {
        int x = rand() % (max - min + 1) + min;
        int y = rand() % (max - min + 1) + min;
        puntos.push_back({x, y});
    }
    return puntos;
}

int main()
{
    
    Ventana ventana;
    ventana.iniciar();
    
    std::vector<Punto> puntos = generar_puntos(18, 5, 395);
    ventana.dibujar_puntos(puntos);

    MergeSort ms;
    ms.ordenar_por_y(puntos);

    for (const Punto& p : puntos)
        std::cout << "(" << p.x << ", " << p.y << ")\n";


    Graham algoritmoGraham;
    algoritmoGraham.convex_hull(puntos, ventana);

    while (ventana.esta_abierta())
    {
        ventana.procesar();
    }
}
