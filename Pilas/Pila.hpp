#ifndef PILA_HPP
#define PILA_HPP

#include <cstddef>

class NodoPila
{
public:
    NodoPila(int valor, NodoPila* siguiente = nullptr);
    ~NodoPila();

private:
    int valor;
    NodoPila* siguiente;
    friend class Pila;
};

typedef NodoPila* pNodoPila;

class Pila
{
public:
    Pila();
    ~Pila();
    void insertar(int valor);
    int extraer();
    int cima() const;
    void mostrar() const;
    int getLongitud() const;

private:
    pNodoPila ultimo;
    int longitud;
};

#endif
