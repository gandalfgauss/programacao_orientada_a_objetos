#include "PagamentoDeGastos.h"
#include <iostream>//entrada e saida

using namespace std;

//construtor
PagamentoDeGastos:: PagamentoDeGastos(string descricao, double valorPago)
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
PagamentoDeGastos::PagamentoDeGastos(Data& dataDePagamento, Data& dataDeVencimento, string descricao, double valorPago)
{
	this->dataDePagamento = dataDePagamento;
	this->dataDeVencimento = dataDeVencimento;


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
PagamentoDeGastos::PagamentoDeGastos(PagamentoDeGastos& PagamentoDeGastos)
{
	
	this->dataDePagamento = PagamentoDeGastos.dataDePagamento;
	this->dataDeVencimento = PagamentoDeGastos.dataDeVencimento;
	this->descricao = PagamentoDeGastos.descricao;
	this->valorPago = PagamentoDeGastos.valorPago;
}

//destrutor

PagamentoDeGastos:: ~PagamentoDeGastos() {}

//getters

string PagamentoDeGastos::getDescricao()
{
	return descricao;
}

double PagamentoDeGastos::getValorPago()
{
	return valorPago;
}

//setters

bool PagamentoDeGastos::setDescricao(string descricao)
{

	if (descricao == "" || descricao == " ")//conferir se nome eh valido, validacao fraca mas ajuda um pouco
	{
		return false;
	}

	this->descricao = descricao;

	return true;
}

bool PagamentoDeGastos::setValorPago(double valorPago)
{
	if (valorPago < 0.0)//conferir se valor eh valido
	{
		return false;
	}

	this->valorPago = valorPago;

	return true;
}


//sobrecarga do operador de atribuicao '=' 

PagamentoDeGastos& PagamentoDeGastos:: operator=(PagamentoDeGastos& PagamentoDeGastos)
{
	if (this == &PagamentoDeGastos)
	{
		return *this;
	}

	this->dataDePagamento = PagamentoDeGastos.dataDePagamento;
	this->dataDeVencimento = PagamentoDeGastos.dataDeVencimento;
	this->descricao = PagamentoDeGastos.descricao;
	this->valorPago = PagamentoDeGastos.valorPago;

	return *this;
}

//sobrecarga do operador 'cout'
ostream& operator << (ostream& out, PagamentoDeGastos& PagamentoDeGastos)
{
	out << "Descricao: " << PagamentoDeGastos.getDescricao()
		<< "  Data de Pagamento:" << PagamentoDeGastos.dataDePagamento << "  Data de Vencimento:" << PagamentoDeGastos.dataDeVencimento
		<<" Valor: " << PagamentoDeGastos.getValorPago();
	return out;
}

//sobrecarga do operador ==
bool PagamentoDeGastos::operator==(PagamentoDeGastos& pagamento)
{
	return(this->dataDePagamento == pagamento.dataDePagamento && this->dataDeVencimento == pagamento.dataDeVencimento
		&& this->valorPago == pagamento.valorPago && this->descricao == pagamento.descricao);
}