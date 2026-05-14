#include "Graham.h"
#include "../Punto.h"
#include "../Geometria.h"
#include "MergeSort.h"
#include <stack>
#include <algorithm>

// Helper: copia el stack a un vector para poder iterar
static std::vector<Punto> stack_a_vector(std::stack<Punto> pila) {
    std::vector<Punto> resultado;
    while (!pila.empty()) {
        resultado.push_back(pila.top());
        pila.pop();
    }
    std::reverse(resultado.begin(), resultado.end());
    return resultado;
}

static void dibujar_envolvente(Ventana& ventana, std::vector<Punto>& puntos, std::stack<Punto>& pila) {
    std::vector<Punto> hull = stack_a_vector(pila);
    ventana.dibujar_envolvente(puntos, hull);
}

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

    // 5: Crear pila y empujar los 3 primeros
    std::stack<Punto> pila;
    pila.push(filtrados[0]);
    pila.push(filtrados[1]);
    pila.push(filtrados[2]);

    dibujar_envolvente(ventana, puntos, pila);

    // 6: Procesar los m-3 puntos restantes
    for (int i = 3; i < m; i++) {
        // 6.1: Quitar puntos mientras no giren a la izquierda (antihorario)
        while (pila.size() > 1) {
            Punto top = pila.top();
            pila.pop();
            Punto second = pila.top();
            pila.push(top);

            float orient = Geometria::orientacion_tripleta(second, top, filtrados[i]);
            if (orient < 0) {
                // Giro antihorario: top es valido
                break;
            }
            // Giro horario o colineal: sacamos top
            pila.pop();
            dibujar_envolvente(ventana, puntos, pila);
        }
        // 6.2: Empujar punto actual
        pila.push(filtrados[i]);
        dibujar_envolvente(ventana, puntos, pila);
    }
}
