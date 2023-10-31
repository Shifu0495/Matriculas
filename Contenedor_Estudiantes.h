#pragma once
#pragma once
#include "Librerias.h"
#include "Estudiantes.h"

class Contenedor_Estudiantes {
private:
	vector<Estudiantes> ListaEstudiante;
public:
	void AgregarEstudiante(Estudiantes nuevoEstudiante) { //metodo que agrega a los estudiantes
		this->ListaEstudiante.push_back(nuevoEstudiante);
	}
	const vector<Estudiantes>& getvector()const
	{
		return ListaEstudiante;
	}

	void ActualizarEstudiante() { //metodo para actualizar los datos de un estudiante
		int cedulabuscar = 0;
		if (this->ListaEstudiante.empty()) {
			cout << "No se han encontrado estudiantes..." << endl;
		}
		else {
			cout << "Ingrese la cedula del estudiante para actualizar sus datos: " << endl;
			cin >> cedulabuscar;
			for (int i = 0; i < this->ListaEstudiante.size(); i++) {
				if (this->ListaEstudiante[i].getCedula() == cedulabuscar) {
					string _nombre, _correo, _direccion;
					int _Telefono = 0;

					cout << "Ingrese el nombre del estudiante: ";
					cin >> _nombre;
					cout << "Ingrese el numero de telefono del estudiante: ";
					cin >> _Telefono;
					cin.ignore();
					cout << "Ingrese el correo del estudiante: ";
					getline(cin, _correo);
					cout << "Ingrese la direccion del estudiantes: ";
					getline(cin, _direccion);

					this->ListaEstudiante[i].setNombre(_nombre);
					this->ListaEstudiante[i].setTelefono(_Telefono);
					this->ListaEstudiante[i].setCorreo(_correo);
					this->ListaEstudiante[i].setDireccion(_direccion);

					cout << "\n Estudiante actualizado correctamente \n" << endl;

					cout << "-----Lista de Estudiantes-----" << endl;
					for (int f = 0; f < this->ListaEstudiante.size(); f++) {
						this->ListaEstudiante[f].getEstudiantes();
						cout << "---------------------------------" << endl;
					}
					cout << "Estudiantes registrados: " << ListaEstudiante.size() << endl;
				}
				else {
					cout << "Cedula ingresada no coincide con los estudiantes registrados" << endl;
					break;
				}
			}
		}

	}

	void MostrarEstudiantes() { //Muestra la lista de trabajadores
		if (this->ListaEstudiante.empty()) {
			cout << "No se han encontrado estudiantes..." << endl;
		}
		else {
			cout << "-----Lista de Estudiantes-----" << endl;
			for (int i = 0; i < this->ListaEstudiante.size(); i++) {
				this->ListaEstudiante[i].getEstudiantes();
				cout << "---------------------------------" << endl;
			}
			cout << "Estudiantes registrados: " << ListaEstudiante.size() << endl;
		}
	}

	void GuardarEnArchivo(const string& nombreArchivo) const {
		ofstream archivo(nombreArchivo);
		if (archivo.is_open()) {
			for (int i = 0; i < this->ListaEstudiante.size(); i++) {
				archivo << ListaEstudiante[i].getCedula() << "-" << ListaEstudiante[i].getNombre() << "-" << ListaEstudiante[i].getTelefono() <<
					"-" << ListaEstudiante[i].getCorreo() << "-" << ListaEstudiante[i].getDireccion() << endl;
			}
			archivo.close();
			cout << "Datos de los estudiantes almacenados en el archivo correctamente..." << endl;
		}
	}

	void CargarEnArchivo(const string& nombreArchivo) {
		ListaEstudiante.clear();
		ifstream archivo(nombreArchivo);
		if (archivo.is_open()) {
			string linea;
			while (getline(archivo, linea)) {
				stringstream ss(linea);
				string nombre, cedula, telefono, correo, direccion;

				// Leer los campos separados por guiones
				getline(ss, cedula, '-');
				int _cedula = stoi(cedula);

				getline(ss, nombre, '-');

				getline(ss, telefono, '-');
				int _telefono = stoi(telefono);

				getline(ss, correo, '-');

				getline(ss, direccion);

				Estudiantes estudiante(_cedula, nombre, _telefono, correo, direccion);
				AgregarEstudiante(estudiante);
			}
			archivo.close();
			cout << "Datos de los estudiantes cargados correctamente..." << endl;
		}
	}

	void MenuEstudiante() { //contiene el menu de la seccion de los estudiantes
		int Opcion;
		setlocale(LC_CTYPE, "Spanish");
		string nombreArchivo = "Estudiantes.txt";
		do
		{
			

			system("cls");
			cout << "Bienvenido a la seccion de estudiantes, seleccione una opcion" << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << "1 para registrar estudiantes" << endl;
			cout << "2 para modificar estudiantes" << endl;
			cout << "3 para consultar todos los estudiantes" << endl;
			cout << "4 para guardar los datos en un archivo" << endl;
			cout << "5 para recuperar los datos del archivo" << endl;
			cout << "6 para salir de esta seccion" << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << "Ingrese una opcion: ";
			cin >> Opcion;

			switch (Opcion) {
			case 1: {
				CargarEnArchivo(nombreArchivo);

				string _nombre, _correo, _direccion;
				int _telefono = 0;
				long long _cedula = 0;

				cin.ignore();
				cout << "Ingrese el nombre del estudiantes: " << endl;
				getline(cin, _nombre);
			inicio:
				cout << "Ingrese el numero de cedula del estudiante: " << endl;
				cin >> _cedula;
				if (_cedula > 999999999999999 || _cedula < 0) {
					cout << "El numero de cedula exede el limite de 15 digitos o el numero de cedula es negativa \npor favor ingresar un numero de cedula menor \n" << endl;
					goto inicio;
				}

				for (int i = 0; i < ListaEstudiante.size(); i++)
				{
					if (ListaEstudiante[i].getCedula() == _cedula)
					{
						cout << "Error ya hay un cliente con esa cedula. \n" << endl;
						goto inicio;
					}
				}

				cout << "Ingrese el numero de telefono del estudiante: " << endl;
				cin >> _telefono;
				cin.ignore();
				cout << "Ingrese el correo del estudiante: " << endl;
				getline(cin, _correo);

				cout << "Ingrese la direccion del estudiante: " << endl;
				getline(cin, _direccion);

				Estudiantes estudiante(_cedula, _nombre, _telefono, _correo, _direccion);
				AgregarEstudiante(estudiante);

				cout << "\nEstudiante ingresado correctamente! \n" << endl;

				cout << "\n-----Lista de Estudiantes-----" << endl;
				for (int i = 0; i < this->ListaEstudiante.size(); i++) {
					this->ListaEstudiante[i].getEstudiantes();
					cout << "---------------------------------" << endl;
				}
				cout << "Estudiantes registrados: " << ListaEstudiante.size() << endl;

				system("pause");
				break;
			}
			case 2: {
				ActualizarEstudiante();
				system("pause");
				break;
			}
			case 3: {
				MostrarEstudiantes();
				system("pause");
				break;
			}
			case 4: {
				GuardarEnArchivo(nombreArchivo);
				system("pause");
				break;
			}
			case 5: {
				CargarEnArchivo(nombreArchivo);
				system("pause");
				break;
			}
			case 6: {
			
				cout << "Volviendo..." << endl;
				system("pause");
				break;
			}
			default: {
				cout << "por favor ingrese una opcion valida " << endl;
				system("pause");
				break;
			}
			}
		} while (Opcion!=6); 
	}

};
