#include <iostream>

int factorial(int);
int factorialI(int);
int fibonacci(int);
int fibonacciI(int);

int main() {
    int n;
    std::cout << "Indique numero para secuencia fibonacci: ";
    std::cin >> n;
    int f = fibonacciI(n);
    std::cout << "fibonacci(" << n << ") = " << f << std::endl;
    
    return 0;
}

// Regresa el producto de todos los numeros de 1 a n
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

int factorialI(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
        std::cout << ans << std::endl;
    }
    return ans;
}

// Regresa el elemento en posision n de la Secuencia de Fibonacci 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
int fibonacci(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacciI(int n) {
    int ant = 1;
    int act = 1;
    int aux;
    while (n > 2) {
        aux = ant + act;
        ant = act;
        act = aux;
        n--;
    }
    return act;
}