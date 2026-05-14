#include "Ventana.h"
#include <thread>
#include <chrono>

Ventana::Ventana()
{
    window.create(sf::VideoMode({400, 400}), "Practica Algoritmo de Graham");
    sf::View view(sf::FloatRect({0.f, 400.f}, {400.f, -400.f}));
    window.setView(view);
}

void Ventana::iniciar() {
    procesar();
    window.clear(sf::Color::Black);
}

void Ventana::mostrar() {
    window.display();
}

void Ventana::procesar() {
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

bool Ventana::esta_abierta() {
    return window.isOpen();
}

void Ventana::dibujar_punto_rojo(Punto punto) {
    sf::CircleShape dot(5.f);
    dot.setFillColor(sf::Color::Red);
    dot.setOrigin({5.f, 5.f});
    dot.setPosition({static_cast<float>(punto.x), static_cast<float>(punto.y)});
    window.draw(dot);
}

void Ventana::dibujar_puntos(std::vector<Punto>& puntos) {
    sf::CircleShape dot(5.f);
    dot.setFillColor(sf::Color::White);
    dot.setOrigin({5.f, 5.f});
    
    for (const auto& punto : puntos)
    {
        dot.setPosition({static_cast<float>(punto.x), static_cast<float>(punto.y)});
        window.draw(dot);
    }
}

void Ventana::dibujar_linea(Punto a, Punto b) {
    sf::Vertex line[] = {
        sf::Vertex{sf::Vector2f{static_cast<float>(a.x), static_cast<float>(a.y)}, sf::Color::Green},
        sf::Vertex{sf::Vector2f{static_cast<float>(b.x), static_cast<float>(b.y)}, sf::Color::Green}
    };
    window.draw(line, 2, sf::PrimitiveType::Lines);
}

void Ventana::dibujar_envolvente(std::vector<Punto>& puntos, std::vector<Punto>& envolvente) {
    iniciar();
    dibujar_puntos(puntos);

    for (int j = 0; j < (int)envolvente.size() - 1; j++) {
        dibujar_linea(envolvente[j], envolvente[j + 1]);
    }
    // Cerrar el hull si tiene mas de 2 puntos
    if (envolvente.size() > 2) {
        dibujar_linea(envolvente.back(), envolvente.front());
    }
    for (const Punto& p : envolvente) {
        dibujar_punto_rojo(p);
    }

    mostrar();

    // Introducimos sleep para ver paso a paso el algoritmo
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
