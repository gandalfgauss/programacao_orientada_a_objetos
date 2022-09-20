#ifndef ITEMAGENDA_H
#define ITEMAGENDA_H

#include <iostream>
#include <string>
#include "DataHora.h"
#include "Paciente.h"

using namespace std;

class ItemAgenda
{
public:
	DataHora data;
	Paciente paciente;

private:
	string descricao;

public:

	//construtores e destrutor
	ItemAgenda(string = "");
	ItemAgenda(DataHora&, Paciente&, string = "");
	ItemAgenda(ItemAgenda&);
	~ItemAgenda();

	//getters
	string getDescricao();

	//setters
	bool setDescricao(string);


	//sobrecarga do operador de atribuicao '=' 
	ItemAgenda& operator=(ItemAgenda&);

	//sobrecarga do operador 'cout'
	friend ostream& operator << (ostream&, ItemAgenda&);

	
};

#endif // !ItemAgenda_H
