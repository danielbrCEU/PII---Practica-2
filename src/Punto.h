#pragma once

struct Punto {
    int x;
    int y;

    bool operator==(const Punto& other) const {
        return x == other.x && y == other.y;
    }

    bool operator<(const Punto& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }

    bool operator>(const Punto& other) const {
        return other < *this; // reutiliza el 
    }
};