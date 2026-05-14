#include <cstdlib>
#include <ctime>
#include "algoritmos/Graham.h"
#include "Ventana.h"
#include "Geometria.h"


int main()
{
    const int NUM_PUNTOS = 20;
    const int COORD_MIN = 5;
    const int COORD_MAX = 395;

    // Semilla para rand() basada en el tiempo actual
    srand(time(0));
    std::vector<Punto> puntos = Geometria::generar_puntos(NUM_PUNTOS, COORD_MIN, COORD_MAX);

    Ventana ventana;
    ventana.iniciar();
    ventana.dibujar_puntos(puntos);

    Graham algoritmoGraham;
    std::vector<Punto> envolvente = algoritmoGraham.envolvente_convexo(puntos, ventana);

    while (ventana.esta_abierta())
    {
        ventana.procesar();
    }
}
