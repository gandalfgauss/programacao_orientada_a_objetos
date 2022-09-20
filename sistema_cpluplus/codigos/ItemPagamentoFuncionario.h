#ifndef ITEMPAGAMENTOFUNCIONARIO_H
#define ITEMPAGAMENTOFUNCIONARIO_H

#include <iostream>
#include <string>
#include "Data.h"

using namespace std;

class ItemPagamentoFuncionario
{
public:
	Data dataDePagamento;

private:
	string descricao;
	double valorPago;

public:

	//construtores e destrutor
	ItemPagamentoFuncionario(string = "", double = 0.0);
	ItemPagamentoFuncionario(Data&, string = "", double = 0.0);
	ItemPagamentoFuncionario(ItemPagamentoFuncionario&);
	~ItemPagamentoFuncionario();

	//getters
	string getDescricao();
	double getValorPago();


	//setters
	bool setDescricao(string);
	bool setValorPago(double);

	//sobrecarga do operador de atribuicao '=' 
	ItemPagamentoFuncionario& operator=(ItemPagamentoFuncionario&);

	//sobrecarga do operador 'cout'
	friend ostream& operator << (ostream&, ItemPagamentoFuncionario&);

	//sobrecarga do operador ==
	bool operator==(ItemPagamentoFuncionario&);
};

#endif // !ItemPagamentoFuncionario_H
