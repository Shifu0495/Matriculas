#pragma once
#ifndef Persona_hpp
#define Persona_hpp

#include <stdio.h>
#include "Librerias.h"
class Persona {

protected:
    string nombre;
    int telefono;
    string correo;
    long long cedula;
public:

    Persona(long long _cedula, string _nombre, int _telefono, string _correo)
    {
        this->cedula = _cedula;
        this->nombre = _nombre;
        this->telefono = _telefono;
        this->correo = _correo;
    }

    void setCedula(int _cedula) { this->cedula = _cedula; }

    void setNombre(string _nombre) { this->nombre = _nombre; }

    void setTelefono(int _telefono) { this->telefono = _telefono; }

    void setCorreo(string _correo) { this->correo = _correo; }

    const long long getCedula() const { return this->cedula; }

    const string getNombre() const { return this->nombre; }

    const int getTelefono() const { return this->telefono; }

    const string getCorreo() const { return this->correo; }

};


#endif /* Persona_hpp */
