#pragma once
//
//  Curso.hpp
//  Proyecto Programación l
//
//  Created by Frander Carrillo Torres on 8/10/23.
//

#ifndef Curso_hpp
#define Curso_hpp

#include <stdio.h>
#include "Librerias.h"


class Curso {

private:

    string codigo;
    string nombre;
    int creditos;
    int cupo;
    string horario;

public:

    Curso(string _codigo, string _nombre, int _creditos, string _horario, int _cupo)
    {
        this->codigo = _codigo;
        this->nombre = _nombre;
        this->creditos = _creditos;
        this->horario = _horario;
        this->cupo = _cupo;
    }

    void setCodigo(string _codigo) { this->codigo = _codigo; }

    void setAcutalizar(string _nombre, int _creditos, string _horario, int _cupo)
    {
        this->nombre = _nombre;
        this->creditos = _creditos;
        this->horario = _horario;
        this->cupo = _cupo;
    }

    const string getCodigo() const { return this->codigo; }

    const string getNombre() const { return this->nombre; }

    const int getCreditos() const { return this->creditos; }

    const int getCupo() const { return this->cupo; }

    const string getHorario() const { return this->horario; }

    void getDatos()
    {
        cout << "___________________________________\n";
        cout << "| Nombre:    " << this->nombre << endl;
        cout << "| Código:    " << this->codigo << endl;
        cout << "| Créditos:  " << this->creditos << endl;
        cout << "| Horario:   " << this->horario << endl;
        cout << "| Cupo:      " << this->cupo << endl;
        cout << "___________________________________\n";
    }
    int setAumentarCupo()
    {
        return this->cupo + 1;
    }
    int setDisminuirCupo()
    {
        return this->cupo - 1;
    }

};

#endif /* Curso_hpp */
