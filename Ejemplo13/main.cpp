#include "Persona.hpp"

#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::array<Persona*, 10> personas{};

    for (int i = 0; i < 10; ++i) {
        personas[static_cast<std::size_t>(i)] = new Persona(18 + i);
    }

    std::cout << "Diez personas con edades distintas (18 a 27):\n";
    for (const Persona* persona : personas) {
        persona->mostrar();
    }

    int mujeres = 0;
    int hombres = 0;
    for (const Persona* persona : personas) {
        if (persona->esMujer()) {
            ++mujeres;
        } else {
            ++hombres;
        }
    }
    std::cout << "Total: " << mujeres << " mujeres y " << hombres
              << " hombres.\n";

    for (Persona* persona : personas) {
        delete persona;
    }
    return 0;
}
