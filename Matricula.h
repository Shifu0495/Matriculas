#pragma once
#include "Librerias.h"



class Matricula
	{
	private:
		static int n;
		int codigo;
		long long id_est;
		int id_prof;
		bool estado = false;
		string fechaM;
		string fechaC;
	public:
		Matricula(long long Id_est, int Id_prof,string _fecha, bool _estado,string _fechac)
		{
			Matricula::n++;
			this->codigo = Matricula::n;
			this->id_est = Id_est;
			this->id_prof = Id_prof;
			this->fechaM = _fecha;
			this->estado = _estado;
			this->fechaC = _fechac;
		}
		void getMatricula()
		{
			cout << "\n***************************************\n";
			cout << "Codigo de Matricula: " << this->codigo << endl;
			cout << "Identificación del estudiante: " << this->id_est << endl;
			cout << "Identificación del docente matriculado: " << this->id_prof << endl;
			cout << "Fecha de matricula: " << this->fechaM << endl;
			cout << "Estado de la matricula: " << (this->estado ? "Matriculada":"Pendiente") << endl;
			cout << "Fecha de cancelación de matricula: " << this->fechaC << endl;
			cout << "****************************************\n";
		}
		const int getCodigo()const
		{
			return this->codigo;
		}
		const long long getId_est()const
		{
			return this->id_est;
		}
		const int getId_Prof()const
		{
			return this->id_prof;
		}
		const bool getEstado() const
		{
			return this->estado;
		}
		const string getFecha()const
		{
			return this->fechaM;
		}
		const string getFechaC()const
		{
			return this->fechaC;
		}
		void setEstado()
		{
			this->estado = false;
		}
		void setFechaC(string _fecha)
		{
			this->fechaC = _fecha;
		}
		



};
int Matricula::n = 0;

