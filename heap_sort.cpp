#include <iostream>  
#include <algorithm>  

using namespace std;

// Función para mantener la propiedad de Max-Heap
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
      largest = right;

    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
}

// Función principal de HeapSort
void heapSort(int arr[], int n) {
    // 1. Construir el montículo (reorganizar el arreglo)
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    // 2. Extraer elementos uno por uno del montículo
    for (int i = n - 1; i >= 0; i--) {
      // Mover la raíz actual al final
      swap(arr[0], arr[i]);
      // Llamar a heapify en el montículo reducido
      heapify(arr, i, 0);
    }
}

// Función auxiliar para imprimir el arreglo
void mostrarArreglo(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    // Ejemplo de un arreglo desordenado
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Arreglo original: \n";
    mostrarArreglo(arr, n);

    // Ejecutamos el ordenamiento
    heapSort(arr, n);

    cout << "Arreglo ordenado de menor a mayor: \n";
    mostrarArreglo(arr, n);

    // Si quisieras el k-ésimo mayor después de ordenar:
    int k = 2; // El segundo más grande
    cout << "\nEl " << k << "-esimo mayor es: " << arr[n - k] << endl;

    return 0;
}
