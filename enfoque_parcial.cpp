#include <iostream>
#include <vector>
#include <algorithm>

// Función MaxHeapify: mantiene la propiedad de Max-Heap
void MaxHeapify(std::vector<int>& A, int i, int tamanio) {
    int mayor = i;
    int izq = 2 * i + 1;
    int der = 2 * i + 2;

    if (izq < tamanio && A[izq] > A[mayor]) {
        mayor = izq;
    }
    if (der < tamanio && A[der] > A[mayor]) {
        mayor = der;
    }

    if (mayor != i) {
        std::swap(A[i], A[mayor]);
        MaxHeapify(A, mayor, tamanio);
    }
}

// Procedimiento ConstruirMaxHeap: organiza el arreglo como un montón máximo
void ConstruirMaxHeap(std::vector<int>& A, int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        MaxHeapify(A, i, n);
    }
}

// ENFOQUE 1: Extracción parcial para hallar el k-ésimo mayor
int KesimoMayor_Parcial(std::vector<int> A, int n, int k) {
    ConstruirMaxHeap(A, n);
    int tamanio = n;

    // Extraemos el máximo k-1 veces
    for (int i = 1; i <= k - 1; i++) {
        std::swap(A[0], A[tamanio - 1]);
        tamanio = tamanio - 1;
        MaxHeapify(A, 0, tamanio);
    }

    // Al final, la raíz (índice 0) es el k-ésimo elemento más grande
    return A[0];
}

int main() {
    std::vector<int> datos = {12, 3, 5, 7, 19, 1};
    int k = 3; // Ejemplo: Queremos el 3er más grande (el 7)

    int resultado = KesimoMayor_Parcial(datos, datos.size(), k);

    std::cout << "El " << k << "-esimo mayor elemento es: " << resultado << std::endl;

    return 0;
}
