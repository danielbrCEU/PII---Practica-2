#include <SFML/Graphics.hpp>
#include <iostream>
#include "Punto.h"
#include "algoritmos/Graham.h"
#include "algoritmos/MergeSort.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({400, 400}), "Four dots");

    sf::CircleShape dot(5.f);
    dot.setFillColor(sf::Color::White);
    dot.setOrigin({5.f, 5.f});

    std::vector<Punto> puntos = {{100, 100}, {300, 100}, {100, 300}, {300, 300}, {200, 200}, {210, 210}};


    MergeSort ms;
    ms.ordenar(puntos);

    for (const auto& p : puntos)
        std::cout << "(" << p.x << ", " << p.y << ")\n";

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        for (const auto& punto : puntos)
        {
            dot.setPosition({static_cast<float>(punto.x), static_cast<float>(punto.y)});
            window.draw(dot);
        }

        window.display();
    }
}
