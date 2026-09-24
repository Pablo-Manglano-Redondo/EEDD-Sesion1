#include "Cola.hpp"

#include <iostream>

int main()
{
    Cola cola;
    cola.insertar(1);
    cola.insertar(2);
    cola.insertar(3);
    cola.insertar(4);
    cola.mostrar();

    int primero = cola.verPrimero();
    cola.eliminar();
    std::cout << "\tDespues de extraer el primero (" << primero << ")...\n";
    cola.mostrar();

    cola.eliminar();
    cola.mostrar();
    cola.insertar(5);
    cola.mostrar();

    while (cola.verPrimero() != 0 && cola.eliminar() != 0) {
        cola.mostrar();
    }
    return 0;
}
