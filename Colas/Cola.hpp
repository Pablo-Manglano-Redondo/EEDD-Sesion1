#ifndef COLA_HPP
#define COLA_HPP

#include <cstddef>

class NodoCola
{
public:
    NodoCola(int valor, NodoCola* siguiente = nullptr);
    ~NodoCola();

private:
    int valor;
    NodoCola* siguiente;
    friend class Cola;
};

typedef NodoCola* pNodoCola;

class Cola
{
public:
    Cola();
    ~Cola();
    void insertar(int valor);
    int eliminar();
    void mostrar() const;
    int verPrimero() const;

private:
    pNodoCola primero;
    pNodoCola ultimo;
    int longitud;
};

#endif
