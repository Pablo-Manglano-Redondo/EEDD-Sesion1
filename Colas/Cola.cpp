#include "Cola.hpp"

#include <iostream>

NodoCola::NodoCola(int v, NodoCola* sig) : valor(v), siguiente(sig) {}
NodoCola::~NodoCola() = default;

Cola::Cola() : primero(nullptr), ultimo(nullptr), longitud(0) {}

void Cola::insertar(int v)
{
    pNodoCola nuevo = new NodoCola(v);
    if (ultimo) {
        ultimo->siguiente = nuevo;
    }
    ultimo = nuevo;
    if (!primero) {
        primero = nuevo;
    }
    ++longitud;
}

int Cola::eliminar()
{
    if (!primero) return 0;
    pNodoCola nodo = primero;
    int v = nodo->valor;
    primero = primero->siguiente;
    if (!primero) {
        ultimo = nullptr;
    }
    --longitud;
    delete nodo;
    return v;
}

void Cola::mostrar() const
{
    pNodoCola aux = primero;
    std::cout << "\tEl contenido de la cola es: ";
    while (aux) {
        std::cout << "-> " << aux->valor << ' ';
        aux = aux->siguiente;
    }
    std::cout << std::endl;
}

int Cola::verPrimero() const
{
    if (!primero) return 0;
    return primero->valor;
}

Cola::~Cola()
{
    while (primero) {
        pNodoCola aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    ultimo = nullptr;
}
