#include "Contendedor_Matriculas.h"
#include "Contenedor_Cursos.h"
#include "Contenedor_Estudiantes.h"
#include "Contenedor_Profesor.h"

int main()
{
	setlocale(LC_CTYPE, "Spanish");
	Contenedor_Matrícula matricula;
	Contenedor_Cursos curso;
	Contenedor_Estudiantes estudiante;
	Contenedor_Profesor profesores;

	int opcmain;
	do
	{
		system("cls");
		cout << "________BIENVENIDO_______\n";
		cout << "-----------------------------\n";
		cout << "\n1)Para gestionar cursos\n";
		cout << "2)Para gestionar estudiantes\n";
		cout << "3)Para gestionar docentes\n";
		cout << "4)Para gestionar matriculas\n";
		cout << "5)Para salir\n";
		cout << "\n-----------------------------\n";
		cout << "Ingrese una opción: ";
		cin >> opcmain;

		switch (opcmain)
		{
			case 1:
			{
				curso.menu();
				system("pause");
				break;
			}
			case 2:
			{
				estudiante.MenuEstudiante();
				system("pause");
				break;
			}
			case 3:
			{
				profesores.Menu_Profesor(curso.getVector());
				system("pause");
				break;
			}
			case 4:
			{
				matricula.menuMatricula(curso.getVector(),estudiante.getvector(),profesores.getVector());
				system("pause");
				break;
			}
			case 5:
			{
				char confirmacion;
				cout << "Estas seguro de salir? " << endl;
				cout << "Ingrese s para confirmar o ingrese cualquier otra letra para permanecer. " << endl;
				cin >> confirmacion;

				if (confirmacion == 's' || confirmacion == 'S')
				{
					system("cls");
					cout << "Saliendo del programa.... " << endl;
					system("pause");
					return true;
				}
				cout << "volviendo...\n";
				system("pause");
				break;
			}
			default:
				cout << "Ingrese una opción valida\n";
				system("pause");
				break;
		}

	} while (true); //sentencia de bucle

}