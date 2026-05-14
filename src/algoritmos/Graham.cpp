#include "Graham.h"
#include "MergeSort.h"
#include "../Geometria.h"
#include <thread>
#include <chrono>

static void animar(Ventana& ventana, const std::vector<Punto>& puntos, const std::vector<Punto>& envolvente) {
    ventana.dibujar_envolvente(puntos, envolvente);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

std::vector<Punto> Graham::envolvente_convexo(std::vector<Punto>& puntos, Ventana& ventana) {

    int n = puntos.size();
    if (n < 3) {
        return {};
    }

    // 1: Ordenar puntos (el mas bajo queda en puntos[0])
    MergeSort ms;
    ms.ordenar_por_y(puntos);
    Punto referencia = puntos[0];

    // 2: Ordenar los n-1 puntos restantes por angulo polar respecto a referencia
    std::vector<Punto> restantes(puntos.begin() + 1, puntos.end());
    ms.ordenar_por_angulo(restantes, referencia);
    for (int i = 0; i < (int)restantes.size(); i++) {
        puntos[i + 1] = restantes[i];
    }

    // 3: Eliminar puntos con el mismo angulo excepto el mas lejano
    std::vector<Punto> filtrados;
    filtrados.push_back(puntos[0]);
    for (int i = 1; i < n; i++) {
        // Saltar puntos con mismo angulo que el siguiente (quedarse con el ultimo = mas lejano)
        while (i < n - 1 && Geometria::orientacion_tripleta(referencia, puntos[i], puntos[i + 1]) == 0) {
            i++;
        }
        filtrados.push_back(puntos[i]);
    }

    int m = filtrados.size();
    if (m < 3) {
        return {};
    }

    // 4: Crear envolvente (usada como pila) y empujar los 3 primeros
    std::vector<Punto> envolvente;
    envolvente.push_back(filtrados[0]);
    envolvente.push_back(filtrados[1]);
    envolvente.push_back(filtrados[2]);

    animar(ventana, puntos, envolvente);

    // 5: Procesar los m-3 puntos restantes
    for (int i = 3; i < m; i++) {
        // 5.1: Quitar puntos mientras no giren a la izquierda (antihorario)
        while (envolvente.size() > 1) {
            Punto top = envolvente.back();
            Punto second = envolvente[envolvente.size() - 2];

            float orient = Geometria::orientacion_tripleta(second, top, filtrados[i]);
            if (orient < 0) {
                // Giro antihorario: top es valido
                break;
            }
            // Giro horario o colineal: sacamos top
            envolvente.pop_back();
            animar(ventana, puntos, envolvente);
        }
        // 5.2: Empujar punto actual
        envolvente.push_back(filtrados[i]);
        animar(ventana, puntos, envolvente);
    }

    return envolvente;
}
