#pragma once
#include "Profesor.h"

class Contenedor_Profesor {
	private:
		vector<Profesor> lista;
		vector<Curso> listaCurso;
	public:
		void agregarProfesor() {
			bool agregar = false, encontrarCodCurso = false;
			Profesor profe = Profesor(0, "", 0, "", "");

			int codigo;
			string nombre;
			int telefono;
			string correo;
			string codigoCurso;
			while (true)
			{
				cout << "Digite la cédula del Profesor: ";
				cin >> codigo;

				if (cin.fail() || codigo > 9999999999 || codigo < 0)
				{
					cout << "Lo sentimos \n";
					cout << "No se permite ingresar cédulas negativas ni con más de 10 dígitos ni datos nulos.  \n";
					cin.clear();
				}
				else
				{
					profe.setCodigo(codigo);
					break;
				}

			} // verificar codigo


			for (int i = 0; i < lista.size(); i++)
			{
				if (lista[i].getcodigo() == profe.getcodigo())
				{
					agregar = true;
					cout << "Lo sentimos\n";
					cout << " No se permite guardar dos profesores con el mismo código.\n";
				}
			}//comprobación para que no hayan cedulas repetidos

			if (!agregar)
			{
				cin.ignore();
				cout << "Digite el nombre del profesor: ";
				getline(cin, nombre);
				cout << "Digite el telefono del profesor: ";
				cin >> telefono;
				cin.ignore();
				cout << "Digite el correo del profesor: ";
				getline(cin, correo);
				while (true)
				{
					cout << "Digite el codigo del curso: ";
					cin.ignore(); getline(cin, codigoCurso);

					for (int i = 0; i < listaCurso.size(); i++)
					{
						if (listaCurso[i].getCodigo() == codigoCurso)
						{
							encontrarCodCurso = true;
							break;
						}
					}
					if (!encontrarCodCurso)
					{
						cout << "Lo sentimos\n";
						cout << "No existe un curso con ese codigo\n";
						system("pause");
					}

				}
				
				Profesor datos = Profesor(codigo, nombre, telefono, correo, codigoCurso);
				lista.push_back(datos);
				cout << "Profesor agregado correctamente\n";
				system("cls");
				consultarLista();
			}//fin !agregar
			
		}//fin metodo agregar profesor
		void actualizarProfesor() {
			bool actualizar = false;
			bool encontrarCodCurso = false;
			if (lista.empty()) {
				cout << "No hay profesores que actualizar" << endl;
			}
			else {
				int codigo;
				cout << "Digite la cédula del profesor que desea actualizar: ";
				cin >> codigo;
				for (int i = 0; i < lista.size(); i++) {
					if (codigo == lista[i].getcodigo()) {
						actualizar = true;

						string nombre;
						int telefono;
						string correo;
						string codigoCurso;

						cin.ignore();
						cout << "Digite el nombre del profesor: ";
						getline(cin, nombre);
						cout << "Digite el telefono del profesor: ";
						cin >> telefono;
						cin.ignore();
						cout << "Digite el correo del profesor: ";
						getline(cin, correo);

						while (true)
						{
							cout << "Digite el codigo del curso: ";
							cin.ignore(); getline(cin, codigoCurso);

							for (int i = 0; i < listaCurso.size(); i++)
							{
								if (listaCurso[i].getCodigo() == codigoCurso)
								{
									encontrarCodCurso = true;
									break;
								}
							}
							if (!encontrarCodCurso)
							{
								cout << "Lo sentimos\n";
								cout << "No existe un curso con ese codigo\n";
								system("pause");
							}

						}//fin verificar si existe el codigo del curso
						

						lista[i].actualizarDatos(nombre, telefono, correo, codigoCurso);
						cout << "Profesor actualizado con exito" << endl;
						system("pause");
						system("cls");
						consultarLista();
						
					}//fin de la verificaion de si existe o no el codigo del profesor

				}//fin del for que recorre el tamaño del vector
				if (!actualizar) {
					cout << "ERROR:No existe un profesor con esa cédula" << endl;
				}
			}
		}
		void consultarLista() {
			if (lista.empty()) {
				cout << "No hay profesores para mostrar" << endl;
			}
			else {
				cout << "Lista de profesores" << endl;
				for (int i = 0; i < lista.size(); i++) {
					lista[i].mostrarDatos();
				}
			}

		}
		void guardar(const string& carpeta) {
			ofstream archivo(carpeta.c_str());
			if (archivo.is_open())
			{
				for (int i = 0; i < lista.size(); i++)		//guarda informacion en el archivo txt
				{
					archivo << lista[i].getcodigo() << "-" << lista[i].getnombre() << "-" << lista[i].gettelefono() << "-" << lista[i].getcorreo() << "-" << lista[i].getcodigoCurso() << endl;
				}
			}
			else
			{
				cout << "No se encontró un archivo para su lectura... \n";
			}
		}
		void cargar(const string& carpeta) {
			ifstream archivo(carpeta.c_str());
			if (archivo.is_open()) {
				string linea;
				while (getline(archivo, linea)) {
					istringstream ss(linea);
					string nombre, correo, codigoCurso;
					int codigo, telefono;
					//carga la informacion desde el archivo txt
					ss >> codigo;
					ss.ignore();
					getline(ss, nombre, '-');
					ss >> telefono;
					ss.ignore();
					getline(ss, correo, '-');

					getline(ss,codigoCurso);


					Profesor datos(codigo, nombre, telefono, correo, codigoCurso);
					lista.push_back(datos);
				}
				archivo.close();
				cout << "Datos cargados correctamente desde el archivo." << endl;
			}
			else {
				cout << "No se encontró un archivo para su lectura." << endl;
			}
		}
		void Menu_Profesor(const vector<Curso>& _cursos)//recibe por paramtros el vector de cursos para poder acceder a la información
		{
			setlocale(LC_CTYPE, "Spanish");
			listaCurso = _cursos; //se igualan con el vector ya creado anteriormente
			string carpeta = "Profesores.txt";
			int opcion;

			do {
				system("cls");
				cout << "1. Agregar un profesor" << endl;
				cout << "2. Modificar un profesor" << endl;
				cout << "3. Consultar todos los profesores" << endl;
				cout << "4. Guardar profesores en archivo" << endl;
				cout << "5. Recuperar datos del archivo" << endl;
				cout << "6. Para salir al menu principal" << endl;
				cout << endl << "Digite una opcion: ";
				cin >> opcion;

				switch (opcion) {
				case 1:
				{
					system("cls");
					cargar(carpeta);
					agregarProfesor();
					system("pause");
					break;
				}
				case 2:
				{
					system("cls");
					actualizarProfesor();
					system("pause");
					break;
				}
				case 3:
				{
					system("cls");
					consultarLista();
					system("pause");
					break;
				}
				case 4:
				{
					system("cls");
					guardar(carpeta);
					system("pause");
					break;
				}
				case 5:
				{
					system("cls");
					cargar(carpeta);
					system("pause");
					break;
				}
				case 6:
				{
					system("cls");
					cout << "Adios" << endl;
					system("pause");
					break;
				}
				default:
				{
					system("cls");
					cout << "Digite una opcion valida" << endl;
					system("pause");
					break;
				}
				}
			} while (opcion != 6);
		}
		const vector<Profesor>& getVector()const //metodo que retorna el vector de profesores
		{
			return lista;
		}
};

