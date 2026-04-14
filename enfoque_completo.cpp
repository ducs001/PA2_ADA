#include <iostream>
#include <vector>
#include <algorithm>

// Función para mantener la propiedad de Max-Heap
void maxHeapify(std::vector<int>& A, int i, int n) {
    int izq = 2 * i + 1;
    int der = 2 * i + 2;
    int mayor = i;

    if (izq < n && A[izq] > A[mayor]) mayor = izq;
    if (der < n && A[der] > A[mayor]) mayor = der;

    if (mayor != i) {
        std::swap(A[i], A[mayor]);
        maxHeapify(A, mayor, n);
    }
}

// Construye el Max-Heap inicial
void construirMaxHeap(std::vector<int>& A, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(A, i, n);
    }
}

// Procedimiento HeapSort 
void heapSort(std::vector<int>& A, int n) {
    construirMaxHeap(A, n);
    for (int i = n - 1; i >= 1; i--) {
        std::swap(A[0], A[i]); // Intercambiar A[0] con A[i]
        maxHeapify(A, 0, i);   // El heap efectivo se reduce en 1
    }
}

// Ordenamiento completo + acceso directo
int kesimoMayor_Completo(std::vector<int> A, int n, int k) {
    heapSort(A, n);          // Ordena ascendentemente
    return A[n - k];         // k-ésimo mayor
}

int main() {
    std::vector<int> datos = {12, 3, 5, 7, 19, 1};
    int k = 2; // Queremos el segundo más grande (el 12)
    
    int resultado = kesimoMayor_Completo(datos, datos.size(), k);
    
    std::cout << "El " << k << "-esimo mayor es: " << resultado << std::endl;
    
    return 0;
}
