#include "ItemPagamentoFuncionario.h"
#include <iostream>//entrada e saida

using namespace std;

//construtor
ItemPagamentoFuncionario::ItemPagamentoFuncionario(string descricao, double valorPago)
{
	if (!setDescricao(descricao))
	{
		this->descricao = " ";
	}

	if (!setValorPago(valorPago))
	{
		this->valorPago = 0.0;
	}
}

//construtor
ItemPagamentoFuncionario::ItemPagamentoFuncionario(Data& dataDePagamento, string descricao, double valorPago)
{
	this->dataDePagamento = dataDePagamento;


	if (!setDescricao(descricao))
	{
		this->descricao = " ";
	}

	if (!setValorPago(valorPago))
	{
		this->valorPago = 0.0;
	}

}

//construtor
ItemPagamentoFuncionario::ItemPagamentoFuncionario(ItemPagamentoFuncionario& pagamentoFuncionario)
{

	this->dataDePagamento = pagamentoFuncionario.dataDePagamento;
	this->descricao = pagamentoFuncionario.descricao;
	this->valorPago = pagamentoFuncionario.valorPago;
}

//destrutor

ItemPagamentoFuncionario:: ~ItemPagamentoFuncionario() {}

//getters

string ItemPagamentoFuncionario::getDescricao()
{
	return descricao;
}

double ItemPagamentoFuncionario::getValorPago()
{
	return valorPago;
}


//setters

bool ItemPagamentoFuncionario::setDescricao(string descricao)
{

	if (descricao == "" || descricao == " ")//conferir se nome eh valido, validacao fraca mas ajuda um pouco
	{
		return false;
	}

	this->descricao = descricao;

	return true;
}


bool ItemPagamentoFuncionario::setValorPago(double valorPago)
{
	if (valorPago < 0.0)//conferir se valor eh valido
	{
		return false;
	}

	this->valorPago = valorPago;

	return true;
}


//sobrecarga do operador de atribuicao '=' 

ItemPagamentoFuncionario& ItemPagamentoFuncionario:: operator=(ItemPagamentoFuncionario& pagamentoFuncionario)
{
	if (this == &pagamentoFuncionario)
	{
		return *this;
	}

	this->dataDePagamento = pagamentoFuncionario.dataDePagamento;
	this->descricao = pagamentoFuncionario.descricao;
	this->valorPago = pagamentoFuncionario.valorPago;


	return *this;
}

//sobrecarga do operador 'cout'
ostream& operator << (ostream& out, ItemPagamentoFuncionario& pagamentoFuncionario)
{
	out << "Data:" << pagamentoFuncionario.dataDePagamento
		<< "  " << pagamentoFuncionario.getDescricao() << "  " << "Valor: " << pagamentoFuncionario.getValorPago();
	return out;
}

//sobrecarga do operador ==
bool ItemPagamentoFuncionario::operator==(ItemPagamentoFuncionario& pagamento)
{
	return(this->dataDePagamento == pagamento.dataDePagamento && this->valorPago == pagamento.valorPago 
		&& this->descricao == pagamento.descricao);
}