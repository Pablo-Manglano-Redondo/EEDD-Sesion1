#ifndef PERSONA_HPP
#define PERSONA_HPP

class Persona
{
public:
    explicit Persona(int edad);
    ~Persona();

    int getEdad() const;
    bool esMujer() const;
    void setEdad(int edad);
    void mostrar() const;

private:
    bool mujer;
    int edad;
    char dni[10];
};

#endif
