#include <vector>
#include "../Punto.h"

class MergeSort
{
    public:
        void ordenar(std::vector<Punto>& puntos);

    private:
        void merge_sort(std::vector<Punto>& puntos, int left, int right);
        void merge(std::vector<Punto>& puntos, int left, int mid, int right);
};