#ifndef ITEMPAGAMENTOPACIENTE_H
#define ITEMPAGAMENTOPACIENTE_H

#include <iostream>
#include <string>
#include "Data.h"

using namespace std;

class ItemPagamentoPaciente
{
public:
	Data dataDePagamento;

private:
	string nomeDoPagamento;
	double valorPago;

public:

	//construtores e destrutor
	ItemPagamentoPaciente(string = "", double = 0.0);
	ItemPagamentoPaciente(Data&, string = "", double = 0.0);
	ItemPagamentoPaciente(ItemPagamentoPaciente&);
	~ItemPagamentoPaciente();

	//getters
	string getNomeDoPagamento();
	double getValorPago();


	//setters
	bool setNomeDoPagamento(string);
	bool setValorPago(double);

	//sobrecarga do operador de atribuicao '=' 
	ItemPagamentoPaciente& operator=(ItemPagamentoPaciente&);

	//sobrecarga do operador 'cout'
	friend ostream& operator << (ostream&, ItemPagamentoPaciente&);

	//sobrecarga do operador ==
	bool operator==(ItemPagamentoPaciente&);
};

#endif // !ItemPagamentoPaciente_H
