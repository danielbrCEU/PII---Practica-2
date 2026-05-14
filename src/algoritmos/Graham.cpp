#include "Graham.h"
#include "../Punto.h"
#include "../Geometria.h"
#include "MergeSort.h"

void Graham::convex_hull(std::vector<Punto>& puntos, Ventana& ventana) {

    int n = puntos.size();
    if (n < 3) {
        return;
    }

    // 1: Ordenar puntos (el mas bajo queda en puntos[0])
    MergeSort ms;
    ms.ordenar_por_y(puntos);
    Punto pivot = puntos[0];

    // 2: Ordenar los n-1 puntos restantes por angulo polar respecto a pivot
    std::vector<Punto> restantes(puntos.begin() + 1, puntos.end());
    ms.ordenar_por_angulo(restantes, pivot);
    for (int i = 0; i < (int)restantes.size(); i++) {
        puntos[i + 1] = restantes[i];
    }

    // 3: Eliminar puntos con el mismo angulo excepto el mas lejano
    std::vector<Punto> filtrados;
    filtrados.push_back(puntos[0]);
    for (int i = 1; i < n; i++) {
        // Saltar puntos con mismo angulo que el siguiente (quedarse con el ultimo = mas lejano)
        while (i < n - 1 && Geometria::orientacion_tripleta(pivot, puntos[i], puntos[i + 1]) == 0) {
            i++;
        }
        filtrados.push_back(puntos[i]);
    }

    int m = filtrados.size();
    if (m < 3) {
        return;
    }

    // 4: Crear pila (vector) y empujar los 3 primeros
    std::vector<Punto> pila;
    pila.push_back(filtrados[0]);
    pila.push_back(filtrados[1]);
    pila.push_back(filtrados[2]);

    ventana.dibujar_envolvente(puntos, pila);

    // 5: Procesar los m-3 puntos restantes
    for (int i = 3; i < m; i++) {
        // 5.1: Quitar puntos mientras no giren a la izquierda (antihorario)
        while (pila.size() > 1) {
            Punto top = pila.back();
            Punto second = pila[pila.size() - 2];

            float orient = Geometria::orientacion_tripleta(second, top, filtrados[i]);
            if (orient < 0) {
                // Giro antihorario: top es valido
                break;
            }
            // Giro horario o colineal: sacamos top
            pila.pop_back();
            ventana.dibujar_envolvente(puntos, pila);
        }
        // 5.2: Empujar punto actual
        pila.push_back(filtrados[i]);
        ventana.dibujar_envolvente(puntos, pila);
    }
}
