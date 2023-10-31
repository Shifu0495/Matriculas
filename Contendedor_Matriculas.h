#pragma once
#include "Matricula.h"
#include"Curso.h"
#include "Estudiantes.h"
#include "Profesor.h"


class Contenedor_Matrícula
{
private:
	vector< Matricula> matriculas;
	vector<Curso> cursos;
	vector<Estudiantes> estudiantes;
	vector<Profesor> profesores;
public:

	void AgregarMatricula()
	{
		bool find1 = false, find2 = false;
		long long id_est;
		int id_prof;
		string fecha;
		while (true)
		{
			cout << "Ingrese la cedula de Estudiante que realiza la matricula: ";
			cin >> id_est;
			for (int i = 0; i < estudiantes.size(); i++)
			{
				if (estudiantes[i].getCedula() == id_est)
				{
					find1 = true;
					
				}
				else
				{
					cout << "Lo sentimos\n";
					cout << "No hay un estudiante registrado con esa cedula\n";
					break;
				}
			}
		}
		while (true)
		{
			cout << "Ingrese la cedula del docente con el que se va a matricular: ";
			cin>>id_prof;
			for(int i=0; i< profesores.size(); i++)
			{
				if(profesores[i].getcodigo() == id_prof)
				{
					find2 = true;
					break;
				}
				else
				{
					cout << "Lo sentimos\n";
					cout << "No hay un docente registrado con esa cedula\n";
				}
			 }
			
		}
		// Obtener la hora actual
		auto currentTime = std::chrono::system_clock::now();

		// Convertir la hora actual a un formato de tiempo desde el epoch (1 de enero de 1970)
		std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);

		// Crear una estructura tm para almacenar la fecha y hora local
		std::tm timeInfo;

		// Obtener fecha y hora local de forma segura
		localtime_s(&timeInfo, &currentTimeT);

		// Crear un flujo de salida de string
		std::ostringstream oss;

		// Formatear y mostrar la fecha y hora actual
		oss << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S");

		// Convertir el flujo de salida a un string
		fecha = oss.str();
		Matricula _matriculas = Matricula(id_est, id_prof, fecha , true,"");
		matriculas.push_back(_matriculas);
		
	}
	void consultarMatricula()
	{
		if (matriculas.empty())
		{
			cout << "No se han registrado matriculas\n";
		}
		else
		{
			long long id;
			bool find = false;

			cout << "Ingrese la cedula del estudiante: ";
			cin >> id;
			for (int i = 0; i < matriculas.size(); i++)
			{
				if (matriculas[i].getId_est() == id)
				{
					matriculas[i].getMatricula();
				}
			
			}
			if (!find)
			{
				cout << "Lo sentimos\n";
				cout << "No existe un estudiante registrado en el sistema con esa cédula\n";
			}
		}
	}
	void MostrarMatricula()
	{
		if (matriculas.empty())
		{
			cout << "No se han registrado matriculas\n";
		}
		else
		{
			cout << "____LISTA__DE__MATRICULAS_____\n";
			for (int i = 0; i < matriculas.size(); i++)
			{
				matriculas[i].getMatricula();
			}
			cout << "_____FIN_DE_LA_LISTA_____\n";
		}
	}
	void CancelarMatricula()
	{
		if (matriculas.empty())
		{
			cout << "No se han registrado matriculas\n";
		}
		else
		{
			int code;
			bool find = false;
			string fechaCancelacion;

			cout << "Ingrese el codigo de la matricula que desea cancelar: ";
			cin >> code;

			for (int i=0; i<matriculas.size(); i++)
			{
				if (matriculas[i].getCodigo() == code && matriculas[i].getEstado() == true)
				{
					string confirmación;
					find = true;
					system("cls");
					cout << "Está seguro de cancelar la matricula ?\n";
					cout << "Si es asi confirme con si\n";
					cout << "Sino presione cualquier letra\n";
					cin >> confirmación;
					if (confirmación == "Si" || confirmación == "si")
					{
						// Obtener la hora actual
						auto currentTime = std::chrono::system_clock::now();

						// Convertir la hora actual a un formato de tiempo desde el epoch (1 de enero de 1970)
						std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);

						// Crear una estructura tm para almacenar la fecha y hora local
						std::tm timeInfo;

						// Obtener fecha y hora local de forma segura
						localtime_s(&timeInfo, &currentTimeT);

						// Crear un flujo de salida de string
						std::ostringstream oss;

						// Formatear y mostrar la fecha y hora actual
						oss << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S");

						// Convertir el flujo de salida a un string
						fechaCancelacion = oss.str();

						matriculas[i].setEstado(); //cambia el estado de activo a inactivo
						cursos[i].setAumentarCupo();//libera el cupo
						matriculas[i].setFechaC(fechaCancelacion); //manda la fecha para cambiarla 

						cout << "Matricula cancelada correctamente\n";
					}
					else
					{
						break;
					}
				}
				
			}
			if (!find)
			{
				cout << "Lo sentimos\n";
				cout << "No se encontró una matricula con ese codigo\n";
				cout << "O No hay matriculas disponibles para cancelar\n";
			}
		}
	}

	void menuMatricula(const vector<Curso>& _cursos, const vector<Estudiantes>&_estudiantes, const vector<Profesor>& _profesores)
	{
		cursos = _cursos;
		estudiantes = _estudiantes;
		profesores = _profesores;
		setlocale(LC_CTYPE, "Spanish");
		int opc;
		do
		{
			system("cls");
			cout << "_BIENVENIDO AL SISTEMA DE MATRÍCULA_\n";
			cout << "*************************************\n";
			cout << "\n1. Matricular Curso            \n";
			cout << "2. Cancelar Matrícula            \n";
			cout << "3. Consultar Matrículas          \n";
			cout << "4. Ver Todas las Matrículas      \n";
			cout << "5. Regresar al Menú Principal    \n";
			cout << "\n***********************************\n";
			cout << "Seleccione una opción: ";
			cin >> opc;

			switch (opc)
			{
			case 1:
			{
				AgregarMatricula();
				system("pause");
				break;
			}
			case 2:
			{
				CancelarMatricula();
				system("pause");
				break;
			}
			case 3:
			{
				consultarMatricula();
				system("pause");
				break;
			}
			case 4:
			{
				MostrarMatricula();
				system("pause");
				break;
			}
			case 5:
			{
				cout << "\n\nUsted esta siendo redirigido al menú principal.....\n";
				system("pause");
				break;
			}
			default:
			{
				cout << "Inrgese una opción valida.....\n";
				system("pause");
				break;
			}

			}

		} while (opc != 5);


	}

};

