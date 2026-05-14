#include "Graham.h"
#include "../Punto.h"
#include "MergeSort.h"
#include <stack>
#include <thread>
#include <chrono>
#include <algorithm>

// Helper: copia el stack a un vector para poder iterar
static std::vector<Punto> stack_a_vector(std::stack<Punto> pila) {
    std::vector<Punto> resultado;
    while (!pila.empty()) {
        resultado.push_back(pila.top());
        pila.pop();
    }
    // Invertir para tener el orden correcto (base a tope)
    std::reverse(resultado.begin(), resultado.end());
    return resultado;
}

static void dibujar_estado(Ventana& ventana, std::vector<Punto>& puntos, std::stack<Punto>& pila) {
    ventana.iniciar();
    ventana.render_puntos(puntos);

    std::vector<Punto> hull = stack_a_vector(pila);
    // Dibujar lineas entre puntos del hull
    for (int j = 0; j < (int)hull.size() - 1; j++) {
        ventana.render_linea(hull[j], hull[j + 1]);
    }
    // Dibujar puntos del hull en rojo
    for (const auto& p : hull) {
        ventana.render_punto_rojo(p);
    }

    ventana.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Graham::convex_hull(std::vector<Punto>& puntos, Ventana& ventana) {

    if (puntos.size() < 3) {
        return;
    }

    // 1: Ordenar puntos
    MergeSort ms;
    ms.ordenar(puntos);

    std::vector<Punto> hull;

    // 2: Construir la parte inferior del envolvente
    for (int i = 0; i < (int)puntos.size(); i++) {
        while (hull.size() >= 2) {
            Punto second = hull[hull.size() - 2];
            Punto top = hull[hull.size() - 1];
            float orient = orientacion_tripleta(second, top, puntos[i]);
            if (orient < 0) {
                break;
            }
            hull.pop_back();
            // Convertir hull a stack para dibujar
            std::stack<Punto> pila_temp;
            for (const auto& p : hull) pila_temp.push(p);
            dibujar_estado(ventana, puntos, pila_temp);
        }
        hull.push_back(puntos[i]);
        std::stack<Punto> pila_temp;
        for (const auto& p : hull) pila_temp.push(p);
        dibujar_estado(ventana, puntos, pila_temp);
    }

    // 3: Construir la parte superior del envolvente
    int lower_size = hull.size();
    for (int i = (int)puntos.size() - 2; i >= 0; i--) {
        while ((int)hull.size() > lower_size) {
            Punto second = hull[hull.size() - 2];
            Punto top = hull[hull.size() - 1];
            float orient = orientacion_tripleta(second, top, puntos[i]);
            if (orient < 0) {
                break;
            }
            hull.pop_back();
            std::stack<Punto> pila_temp;
            for (const auto& p : hull) pila_temp.push(p);
            dibujar_estado(ventana, puntos, pila_temp);
        }
        hull.push_back(puntos[i]);
        std::stack<Punto> pila_temp;
        for (const auto& p : hull) pila_temp.push(p);
        dibujar_estado(ventana, puntos, pila_temp);
    }
}

// Si devuelve valor positivo rota en sentido horario, y valor negativo antihorario. 
float Graham::orientacion_tripleta(Punto p, Punto q, Punto r) {
    return (q.y-p.y)*(r.x-q.x) -(q.x-p.x)*(r.y-q.y);
}

float Graham::distancia(Punto p, Punto q) {
    return 0.0f;
}