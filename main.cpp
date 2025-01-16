/*
 * Programa "divide y vencerás", para ordenar números de mayor a menor utilizando Merge Sort.
 * Autores: Andrés Cabrera Alvarado - A01798681
 * José Eduardo Rosas Poncio - A01784461
 * Yael Octavio Pérez Méndez - A01799842
 * Fecha de creación: 09/01/25
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * Función para fusionar dos subarreglos en orden descendente.
 * Parámetros:
 * array: referencia al vector que contiene los elementos.
 * left: izquierda del subarreglo.
 * mid: medio del subarreglo.
 * right: derecha del subarreglo.
 */
void merge(vector<double>& array, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    vector<double> leftArray(leftSize), rightArray(rightSize);
    for (int i = 0; i < leftSize; ++i) {
        leftArray[i] = array[left + i];
    }
    for (int i = 0; i < rightSize; ++i) { //copia datos a los subarreglos
        rightArray[i] = array[mid + 1 + i];
    }
    int i = 0, j = 0, k = left; // junta los subarreglos en orden descendente
    while (i < leftSize && j < rightSize) {
        if (leftArray[i] >= rightArray[j]) {
            array[k++] = leftArray[i++];
        } else {
            array[k++] = rightArray[j++];
        }
    }
    while (i < leftSize) { //copia los datos restantes
        array[k++] = leftArray[i++];
    }
    while (j < rightSize) {
        array[k++] = rightArray[j++];
    }
}

/*
 * Función recursiva para ordenar un vector utilizando Merge Sort.
 * Parámetros:
 * array: vector con elementos.
 * left: izquierda del subarreglo.
 * right: derecha del subarreglo.
 */
void mergeSort(vector<double>& array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid); // ordena una mitad
        mergeSort(array, mid + 1, right); // ordena la otra mitad
        merge(array, left, mid, right); // junta ambas partes ordenadas
    }
}

int main() {
    int numberOfValues;
    cout << "Ingrese el numero de valores a ordenar: ";
    cin >> numberOfValues;
    vector<double> values(numberOfValues);
    cout << "\nIngrese " << numberOfValues << " valores (reales o enteros), uno por linea:\n"; // lee los valores
    for (int i = 0; i < numberOfValues; ++i) {
        cin >> values[i];
    }
    mergeSort(values, 0, numberOfValues - 1); // ordena el vector
    cout << "\nResultado:\nValores ordenados de mayor a menor:\n"; // resultado
    for (double value : values) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}
