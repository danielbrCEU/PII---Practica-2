#pragma once

struct Punto {
    int x;
    int y;

    bool operator==(const Punto& other) const {
        return y == other.y && x == other.x;
    }

    bool operator<(const Punto& other) const {
        return y < other.y || (y == other.y && x < other.x);
    }

    bool operator>(const Punto& other) const {
        return other < *this; // reutiliza el 
    }

    bool operator<=(const Punto& other) const {
        return y <= other.y || (y == other.y && x <= other.x);
    }

    bool operator>=(const Punto& other) const {
        return other <= *this;
    }
};