#include <vector>
#include "../Punto.h"

class MergeSort
{
    public:
        void ordenar_por_y(std::vector<Punto>& puntos);
        void ordenar_por_angulo(std::vector<Punto>& puntos, Punto pivot);

    private:
        void merge_sort(std::vector<Punto>& puntos, int left, int right);
        void merge(std::vector<Punto>& puntos, int left, int mid, int right);

        void merge_sort_angulo(std::vector<Punto>& puntos, int left, int right, Punto pivot);
        void merge_angulo(std::vector<Punto>& puntos, int left, int mid, int right, Punto pivot);
};