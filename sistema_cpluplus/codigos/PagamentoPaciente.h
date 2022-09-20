#ifndef PAGAMENTOPACIENTE_H
#define PAGAMENTOPACIENTE_H

#include <iostream>
#include <list>
#include "Paciente.h"
#include "ItemPagamentoPaciente.h"

using namespace std;

class PagamentoPaciente
{
public:
	Paciente paciente;
	list<ItemPagamentoPaciente*> pagamentosPaciente;


	//construtores e destrutor
	PagamentoPaciente();
	PagamentoPaciente(Paciente&);
	PagamentoPaciente(PagamentoPaciente&);
	~PagamentoPaciente();

	void adicionarItemPagamentoPaciente(ItemPagamentoPaciente);//adiciona um ItemPago pelo paciente
	bool removerItemPagamentoPaciente(int posicao);//dada uma posicao remove um item pago pelo paciente
	ItemPagamentoPaciente& retornarItemPagamentoPaciente(int posicao);//retorna um item pago pelo paciente
	bool imprimirItensPagosNoMes(int mes);

	//sobrecarga do operador de atribuicao '=' 
	PagamentoPaciente& operator=(PagamentoPaciente&);

	//sobrecarga do operador 'cout'
	friend ostream& operator << (ostream&, PagamentoPaciente&);




};

#endif // !PagamentoPaciente_H
