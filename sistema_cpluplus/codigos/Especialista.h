#ifndef ESPECIALISTA_H
#define ESPECIALISTA_H

#include <iostream>
#include <list>
#include "Pessoa.h"
#include "Agenda.h"
#include "Assistente.h"

using namespace std;

class Especialista : public Pessoa
{
public:
	Assistente assistente;
	Agenda agenda;


	//construtores e destrutor
	Especialista(Assistente&, Agenda& , string = "", string = "", long long = 12345678900, long long = 33988888888);
	Especialista(string = "", string = "", long long = 12345678900, long long = 33988888888);
	Especialista(Especialista&);
	~Especialista();

	//getters e setters herdados

	//metodos
	void imprimirAgenda();

	//sobrecarga do operador de atribuicao '=' 
	Especialista& operator=(Especialista&);

	//sobrecarga do operador 'cout'
	friend ostream& operator << (ostream&, Especialista&);

};

#endif // !Especialista_H
