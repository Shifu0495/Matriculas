#pragma once
#pragma once

#include "Librerias.h"
#include "Persona.h"


class Estudiantes : public Persona {
private:
    string direccion;
public:
    Estudiantes(long long _cedula, string _nombre, int _telefono, string _correo, string _direccion) : Persona(_cedula, _nombre, _telefono, _correo) {
        this->direccion = _direccion;
    }

    void setDireccion(string _direccion) {
        this->direccion = _direccion;
    }

    const string getDireccion()const {
        return this->direccion;
    }

    void getEstudiantes() {
        cout << "Cedula:    " << this->cedula << endl;
        cout << "Nombre:    " << this->nombre << endl;
        cout << "Telefono:  " << this->telefono << endl;
        cout << "Correo:    " << this->correo << endl;
        cout << "Direccion: " << this->direccion << endl;
    }
};
