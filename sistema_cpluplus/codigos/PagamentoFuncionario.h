#ifndef PAGAMENTOFUNCIONARIO_H
#define PAGAMENTOFUNCIONARIO_H

#include <iostream>
#include <list>
#include "Assistente.h"
#include "ItemPagamentoFuncionario.h"

using namespace std;

class PagamentoFuncionario
{
public:
	Assistente funcionario;
	list<ItemPagamentoFuncionario*> pagamentosFuncionario;


	//construtores e destrutor
	PagamentoFuncionario();
	PagamentoFuncionario(Assistente&);
	PagamentoFuncionario(PagamentoFuncionario&);
	~PagamentoFuncionario();

	void adicionarItemFolhaDePagamento(ItemPagamentoFuncionario);//adiciona um Item na folha de Pagamento do funcionario
	bool removerItemFolhaDePagamento(int posicao);//dada uma posicao remove um item da folha de Pagamento do funcionario
	ItemPagamentoFuncionario& retornarItemPagamentoFuncionario(int posicao);//retorna um item de Pagamento do funcionario
	bool imprimirFolhaDePagamentoDoMes(int mes);//dado um mes, imprime a folha de paagamento do funcionario naquele mes

	//sobrecarga do operador de atribuicao '=' 
	PagamentoFuncionario& operator=(PagamentoFuncionario&);

	//sobrecarga do operador 'cout'
	friend ostream& operator << (ostream&, PagamentoFuncionario&);
};

#endif // !PagamentoFuncionario_H
