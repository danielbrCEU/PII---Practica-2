#pragma once
#include <vector>
#include "../Punto.h"

class MergeSort
{
    public:
        // Ordernar vector de Puntos por coordenada y, y en segundo orden por x
        void ordenar_por_y(std::vector<Punto>& puntos);
        // Ordenar vector de Puntos por angulo polar
        void ordenar_por_angulo(std::vector<Punto>& puntos, Punto referencia);

    private:
        void merge_sort(std::vector<Punto>& puntos, int left, int right);
        void merge(std::vector<Punto>& puntos, int left, int mid, int right);

        void merge_sort_angulo(std::vector<Punto>& puntos, int left, int right, Punto referencia);
        void merge_angulo(std::vector<Punto>& puntos, int left, int mid, int right, Punto referencia);
};