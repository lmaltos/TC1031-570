#include <iostream>
#include <ctime>
#define SIZE 100000
#define MAX 500000
using namespace std;

int busquedaSecuencial(int [], int, int);
int busquedaBinaria(int [], int, int);
void ordenaInsercion(int [], int);
void quickSort(int [], int);

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
    int A[SIZE],B[SIZE];
    cout << "time: " << time(0) << endl;
    srand(time(0));
    // Llenamos arreglo
    for (int i = 0; i < SIZE; i++) {
        A[i] = rand() % MAX; // valores entre 0 y 499
        B[i] = A[i];
    }
    // Ver arreglo print(A,SIZE);
    // Ordenamos arreglo
    print(A,100);
    cout << "Ordenando arreglo por insercion" << endl;
    ordenaInsercion(A,SIZE);
    cout << "Arreglo ordenado" << endl;
    print(A,100);
    cout << "Ordenando arreglo por quickSort" << endl;
    quickSort(B,SIZE);
    cout << "Arreglo ordenado" << endl;
    print(B,100);
    //print(A,SIZE);
    /*
    int pos = -1;
    int count = 0;
    for (int clave = 0; clave < MAX; clave++) {
        pos = busquedaBinaria(A,SIZE,clave);
        if (pos > -1) {
            count++;
        }
    }
    cout << "Se encontraron: " << count << " numeros con busqueda binaria" << endl;
    
    count = 0;
    for (int clave = 0; clave < MAX; clave++) {
        pos = busquedaSecuencial(A,SIZE,clave);
        if (pos > -1) {
            count++;
        }
    }
    cout << "Se encontraron: " << count << " numeros con busqueda secuencial" << endl;
    */
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
        //cout << "[" << bajo << ", " << central << ", " << alto << "]: " << valorCentral << endl;
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

int quickSortParticion(int A[], int inicio, int fin) {
    int aux;
    int elemPivote = A[inicio];
    int j = inicio;
    for(int i = inicio+1; i <= fin; i++) {
        if (A[i] < elemPivote) {
            j++;
            aux = A[j];
            A[j] = A[i];
            A[i] = aux;
        }
    }
    A[inicio] = A[j];
    A[j] = elemPivote;
    return j;
}

void quickSortR(int A[], int inicio, int fin) {
    if (inicio < fin) {
        int pivote = quickSortParticion(A,inicio,fin);
        quickSortR(A,inicio,pivote-1);
        quickSortR(A,pivote+1,fin);
    }
} 

void quickSort(int A[], int n) {
    quickSortR(A,0,n-1);
}