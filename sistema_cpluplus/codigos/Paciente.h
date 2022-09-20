#ifndef PACIENTE_H
#define PACIENTE_H

#include "Pessoa.h"
#include <iostream>
#include <string>
using namespace std;

class Paciente: public Pessoa
{
	
public:
	//construtores e destrutor
	Paciente(string = "", string = "", long long = 12345678900, long long = 33988888888);
	Paciente(Paciente&);
	~Paciente();

	//getters e setters herdados
	
	//sobrecarga do operador de atribuicao '=' 
	Paciente& operator=(Paciente&);

	//sobrecarga do operador 'cout'
	friend ostream& operator << (ostream&, Paciente&);

	//sobrecarga do operador ==
	bool operator==(Paciente&);
};

#endif // !Paciente_H
