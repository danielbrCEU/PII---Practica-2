#include "MergeSort.h"
#include "../Punto.h"


void MergeSort::ordenar(std::vector<Punto>& puntos) {
    
}

void MergeSort::merge_sort(std::vector<Punto>& puntos, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    merge_sort(puntos, left, mid);
    merge_sort(puntos, mid + 1, right);
    merge(puntos, left, mid, right);
}

void merge(std::vector<Punto>& puntos, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    std::vector<Punto> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++) L[i] = puntos[left + i];
    for (int j = 0; j < n2; j++) R[j] = puntos[mid + 1 + j];
    
    int i = 0, j = 0;
    int k = left;
    // Merge the temp vectors back
    // into arr[left..right]
}