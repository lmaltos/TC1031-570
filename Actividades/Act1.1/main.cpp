/**
 * {Descripcion breve del programa}
 * Autor:
 * Fecha:
 */
#include <iostream>

using namespace std;

// ¿Dónde evaluar la precondición?

// Nivel Lógico
int sumaIterativa(int);
int sumaRecursiva(int);
int sumaDirecta(int);

// Nivel Aplicacion
int main() {
    int n=0;
    // Capuramos n
    cout << "Ingrese un valor: ";
    cin >> n;

    // Llamamos a los metodos de suma
    cout << "Resultaod de sumaIterativa: " << sumaIterativa(n) << endl;
    cout << "Resultaod de sumaRecursiva: " << sumaRecursiva(n) << endl;
    cout << "Resultaod de sumaDirecta: " << sumaDirecta(n) << endl;
}

// Nivel Funcional
/**
 * Descripcion: suma los numeros de 1 a n
 * Parametros: @x es el numero hasta el que vamos a sumar
 * Retrorno: la suma de 1 a n
 * Complejidad: ???
 */
int sumaIterativa(int x ) {
    // ToDo
    return x;
}

int sumaRecursiva(int x) {
    // ToDo
    return x;
}

int sumaDirecta(int x) {
    // ToDo
    return x;
}