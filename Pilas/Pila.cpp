#include "Pila.hpp"

#include <iostream>

NodoPila::NodoPila(int v, NodoPila* sig) : valor(v), siguiente(sig) {}
NodoPila::~NodoPila() = default;

Pila::Pila() : ultimo(nullptr), longitud(0) {}

void Pila::insertar(int v)
{
    ultimo = new NodoPila(v, ultimo);
    ++longitud;
}

int Pila::extraer()
{
    if (!ultimo) return 0;
    pNodoPila nodo = ultimo;
    int v = nodo->valor;
    ultimo = nodo->siguiente;
    --longitud;
    delete nodo;
    return v;
}

int Pila::cima() const
{
    if (!ultimo) return 0;
    return ultimo->valor;
}

void Pila::mostrar() const
{
    pNodoPila aux = ultimo;
    std::cout << "\tEl contenido de la pila es: ";
    while (aux) {
        std::cout << "-> " << aux->valor << ' ';
        aux = aux->siguiente;
    }
    std::cout << std::endl;
}

int Pila::getLongitud() const
{
    return longitud;
}

Pila::~Pila()
{
    while (ultimo) {
        pNodoPila aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux;
    }
}
