#include "Persona.hpp"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

namespace
{
void inicializarGenerador()
{
    static const bool inicializado = []() {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        return true;
    }();
    (void)inicializado;
}

std::string generarDni()
{
    static const char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    static std::set<int> usados;
    int numero;
    do {
        numero = std::rand() % 100000000;
    } while (!usados.insert(numero).second);

    std::ostringstream resultado;
    resultado << std::setw(8) << std::setfill('0') << numero
              << letras[numero % 23];
    return resultado.str();
}
}

Persona::Persona(int edad) : mujer(false), edad(edad)
{
    inicializarGenerador();
    mujer = std::rand() % 2 == 1;
    const std::string identificador = generarDni();
    std::copy(identificador.begin(), identificador.end(), dni);
    dni[identificador.size()] = '\0';
}

Persona::~Persona() = default;

int Persona::getEdad() const
{
    return edad;
}

bool Persona::esMujer() const
{
    return mujer;
}

void Persona::setEdad(int nuevaEdad)
{
    edad = nuevaEdad;
}

void Persona::mostrar() const
{
    std::cout << "DNI: " << dni << ", género: "
              << (mujer ? "Mujer" : "Hombre")
              << ", edad: " << edad << std::endl;
}

