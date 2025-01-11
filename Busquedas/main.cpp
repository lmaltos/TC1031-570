#include <iostream>
#include <ctime>
#define SIZE 100
using namespace std;

int busquedaSecuencial(int [], int, int);
int busquedaBinaria(int [], int, int);
void ordenaInsercion(int [], int);

void print(int A[],int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
}

int main() {
    //const int size = 100;
    int A[SIZE];
    cout << "time: " << time(0) << endl;
    srand(time(0));
    // Llenamos arreglo
    for (int i = 0; i < SIZE; i++) {
        A[i] = rand() % 500; // valores entre 0 y 499
    }
    // Ver arreglo
    print(A,SIZE);
    // Ordenamos arreglo
    cout << "Ordenando arreglo" << endl;
    ordenaInsercion(A,SIZE);
    print(A,SIZE);
    int clave = 0;
    int pos = -1;
    while (pos < 0) {
        cout << "Valor a buscar: ";
        cin >> clave;
        pos = busquedaBinaria(A,SIZE,clave);
        if (pos == -1) {
            cout << "No se encontro el valor :" << clave << endl; 
        }
        else {
            cout << "Se encontron el valor " << clave << " en la posicion: " << pos << endl;
        }
    }
    return 0;
}

int busquedaSecuencial(int A[], int n, int clave) {
    for (int pos = 0; pos < n; pos++) {
        if (clave == A[pos]) {
            return pos;
        }
    }
    return -1;
}

int busquedaBinaria(int A[], int n, int clave) {
    int central,bajo,alto,valorCentral;
    bajo = 0;
    alto = n - 1;
    while (bajo <= alto) {
        central = (bajo + alto) / 2;
        valorCentral = A[central];
        cout << "[" << bajo << ", " << central << ", " << alto << "]: " << valorCentral << endl;
        if (clave == valorCentral) {
            return central;
        }
        else {
            if (clave < valorCentral) {
                alto = central - 1;
            }
            else {
                bajo = central + 1;
            }
        }
    }
    return -1;
}

void ordenaInsercion(int A[], int n) {
    int i,j,aux;
    for (i = 1; i < n; i++) {
        j = i;
        aux = A[i];
        while (j > 0 && aux < A[j-1]) {
            A[j] = A[j-1];
            j--;
        }
        A[j] = aux;
    }
}
