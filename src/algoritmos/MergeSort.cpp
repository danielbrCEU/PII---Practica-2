#include "MergeSort.h"
#include "../Geometria.h"

void MergeSort::ordenar_por_y(std::vector<Punto> &puntos)
{
    if (puntos.size() <= 1) return;
    merge_sort(puntos, 0, puntos.size() - 1);
}

void MergeSort::merge_sort(std::vector<Punto> &puntos, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    merge_sort(puntos, left, mid);
    merge_sort(puntos, mid + 1, right);
    merge(puntos, left, mid, right);
}

void MergeSort::merge(std::vector<Punto> &puntos, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    std::vector<Punto> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = puntos[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = puntos[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    
    // Merge the temp vectors back
    // into arr[left..right]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            puntos[k] = L[i];
            i++;
        }
        else
        {
            puntos[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1)
    {
        puntos[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2)
    {
        puntos[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort::ordenar_por_angulo(std::vector<Punto> &puntos, Punto referencia)
{
    if (puntos.size() <= 1) return;
    merge_sort_angulo(puntos, 0, puntos.size() - 1, referencia);
}

void MergeSort::merge_sort_angulo(std::vector<Punto> &puntos, int left, int right, Punto referencia)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    merge_sort_angulo(puntos, left, mid, referencia);
    merge_sort_angulo(puntos, mid + 1, right, referencia);
    merge_angulo(puntos, left, mid, right, referencia);
}

void MergeSort::merge_angulo(std::vector<Punto> &puntos, int left, int mid, int right, Punto referencia)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Punto> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = puntos[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = puntos[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        float orient = Geometria::orientacion_tripleta(referencia, L[i], R[j]);
        // L[i] va antes si orient < 0 (antihorario), o si colineales y mas cercano
        if (orient < 0 || (orient == 0 && Geometria::distancia(referencia, L[i]) <= Geometria::distancia(referencia, R[j])))
        {
            puntos[k] = L[i];
            i++;
        }
        else
        {
            puntos[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        puntos[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        puntos[k] = R[j];
        j++;
        k++;
    }
}
