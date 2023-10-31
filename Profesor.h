#pragma once
#include "Librerias.h"

class Profesor {
	private:
		int codigo;
		string nombre;
		int telefono;
		string correo;
		string codigoCurso;
	public:
		Profesor(int _codigo, string _nombre, int _telefono, string _correo, string _codigoCurso) {
			codigo = _codigo;
			nombre = _nombre;
			telefono = _telefono;
			correo = _correo;
			codigoCurso = _codigoCurso;
		}
		void setCodigo(int code) { this->codigo = code; }
		void actualizarDatos(string _nombre, int _telefono, string _correo, string _codigoCurso) {
			nombre = _nombre;
			telefono = _telefono;
			correo = _correo;
			codigoCurso = _codigoCurso;
		}
		void mostrarDatos() {
			cout << "-----------------------" << endl;
			cout << "Codigo: " << codigo << endl;
			cout << "Nombre: " << nombre << endl;
			cout << "Correo: " << correo << endl;
			cout << "Codigo del curso: " << codigoCurso << endl;
			cout << "-----------------------" << endl;
		}
		const int getcodigo()const {
			return codigo;
		}
		const string getnombre()const {
			return nombre;
		}
		const int gettelefono() const{
			return telefono;
		}
		const string getcorreo()const {
			return correo;
		}
		const string getcodigoCurso() const {
			return codigoCurso;
		}
};

