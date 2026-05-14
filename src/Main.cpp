#include <cstdlib>
#include <ctime>
#include "algoritmos/Graham.h"
#include "Ventana.h"
#include "Geometria.h"


int main()
{
    srand(time(0));
    std::vector<Punto> puntos = Geometria::generar_puntos(20, 5, 395);

    Ventana ventana;
    ventana.iniciar();
    ventana.dibujar_puntos(puntos);

    Graham algoritmoGraham;
    algoritmoGraham.convex_hull(puntos, ventana);

    while (ventana.esta_abierta())
    {
        ventana.procesar();
    }
}
