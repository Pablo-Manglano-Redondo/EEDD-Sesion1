#include "Pila.hpp"

#include <iostream>

int main()
{
    Pila pila;
    pila.insertar(1);
    pila.insertar(2);
    pila.insertar(3);
    pila.insertar(4);
    pila.mostrar();

    int cima = pila.cima();
    pila.extraer();
    std::cout << "\tDespues de extraer la cima (" << cima << ")...\n";
    pila.mostrar();

    pila.insertar(5);
    pila.mostrar();
    while (pila.getLongitud() > 0) {
        pila.extraer();
        pila.mostrar();
    }
    return 0;
}
