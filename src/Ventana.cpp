#include <SFML/Graphics.hpp>
#include <vector>
#include "Punto.h"
#include "Ventana.h"

Ventana::Ventana()
{
    window.create(sf::VideoMode({400, 400}), "Four dots");
    sf::View view(sf::FloatRect({0.f, 400.f}, {400.f, -400.f}));
    window.setView(view);
}

void Ventana::iniciar() {
    process_events();
    window.clear(sf::Color::Black);
}

void Ventana::display() {
    window.display();
}

void Ventana::process_events() {
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

bool Ventana::esta_abierta() {
    return window.isOpen();
}

void Ventana::render_punto_rojo(Punto punto) {
    sf::CircleShape dot(5.f);
    dot.setFillColor(sf::Color::Red);
    dot.setOrigin({5.f, 5.f});
    dot.setPosition({static_cast<float>(punto.x), static_cast<float>(punto.y)});
    window.draw(dot);
}

void Ventana::render_puntos(std::vector<Punto>& puntos) {
    sf::CircleShape dot(5.f);
    dot.setFillColor(sf::Color::White);
    dot.setOrigin({5.f, 5.f});
    
    for (const auto& punto : puntos)
    {
        dot.setPosition({static_cast<float>(punto.x), static_cast<float>(punto.y)});
        window.draw(dot);
    }
}

void Ventana::render_linea(Punto a, Punto b) {
    sf::Vertex line[] = {
        sf::Vertex{sf::Vector2f{static_cast<float>(a.x), static_cast<float>(a.y)}, sf::Color::Green},
        sf::Vertex{sf::Vector2f{static_cast<float>(b.x), static_cast<float>(b.y)}, sf::Color::Green}
    };
    window.draw(line, 2, sf::PrimitiveType::Lines);
}