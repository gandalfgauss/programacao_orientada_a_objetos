#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <list>
#include "ItemAgenda.h"

using namespace std;

class Agenda
{
public:
	list<ItemAgenda*> itensDaAgenda;

	//construtores e destrutor
	Agenda();
	Agenda(Agenda&);
	~Agenda();

	void adicionarItemAgenda(ItemAgenda);//adiciona um Item na agenda
	bool removerItemAgenda(int posicao);//dada uma posicao remove um item da agenda
	ItemAgenda& retornarItemAgenda(int posicao);//retorna um item da agenda

	//sobrecarga do operador de atribuicao '=' 
	Agenda& operator=(Agenda&);

	//sobrecarga do operador 'cout'
	friend ostream& operator << (ostream&, Agenda&);

};

#endif // !Agenda_H
