#ifndef PagamentoDeGastos_H
#define PagamentoDeGastos_H

#include <iostream>
#include <string>
#include "Data.h"

using namespace std;

class PagamentoDeGastos
{
public:
	Data dataDePagamento;
	Data dataDeVencimento;

private:
	string descricao;
	double valorPago;

public:

	//construtores e destrutor
	PagamentoDeGastos(string = "", double = 0.0);
	PagamentoDeGastos(Data&, Data&, string = "", double = 0.0);
	PagamentoDeGastos(PagamentoDeGastos&);
	~PagamentoDeGastos();

	//getters
	string getDescricao();
	double getValorPago();

	//setters
	bool setDescricao(string);
	bool setValorPago(double);

	//sobrecarga do operador de atribuicao '=' 
	PagamentoDeGastos& operator=(PagamentoDeGastos&);

	//sobrecarga do operador 'cout'
	friend ostream& operator << (ostream&, PagamentoDeGastos&);

	//sobrecarga do operador ==
	bool operator==(PagamentoDeGastos&);
};

#endif // !PagamentoDeGastos_H
