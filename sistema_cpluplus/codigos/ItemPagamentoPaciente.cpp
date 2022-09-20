#include "ItemPagamentoPaciente.h"
#include <iostream>//entrada e saida

using namespace std;

//construtor 
ItemPagamentoPaciente::ItemPagamentoPaciente(string nomeDoPagamento, double valorPago)
{
	if (!setNomeDoPagamento(nomeDoPagamento))
	{
		this->nomeDoPagamento = " ";
	}

	if (!setValorPago(valorPago))
	{
		this->valorPago = 0.0;
	}
}


//construtor

ItemPagamentoPaciente::ItemPagamentoPaciente(Data& dataDePagamento, string nomeDoPagamento, double valorPago)
{
	this->dataDePagamento = dataDePagamento;


	if (!setNomeDoPagamento(nomeDoPagamento))
	{
		this->nomeDoPagamento = " ";
	}

	if (!setValorPago(valorPago))
	{
		this->valorPago = 0.0;
	}

}

//construtor
ItemPagamentoPaciente::ItemPagamentoPaciente(ItemPagamentoPaciente& pagamentoPaciente)
{

	this->dataDePagamento = pagamentoPaciente.dataDePagamento;
	this->nomeDoPagamento = pagamentoPaciente.nomeDoPagamento;
	this->valorPago = pagamentoPaciente.valorPago;

}



//destrutor

ItemPagamentoPaciente:: ~ItemPagamentoPaciente() {}

//getters

string ItemPagamentoPaciente::getNomeDoPagamento()
{
	return nomeDoPagamento;
}

double ItemPagamentoPaciente::getValorPago()
{
	return valorPago;
}


//setters

bool ItemPagamentoPaciente::setNomeDoPagamento(string descricao)
{

	if (descricao == "" || descricao == " ")//conferir se nome eh valido, validacao fraca mas ajuda um pouco
	{
		return false;
	}

	this->nomeDoPagamento = descricao;

	return true;
}


bool ItemPagamentoPaciente::setValorPago(double valorPago)
{
	if (valorPago < 0.0)//conferir se valor eh valido
	{
		return false;
	}

	this->valorPago = valorPago;

	return true;
}


//sobrecarga do operador de atribuicao '=' 

ItemPagamentoPaciente& ItemPagamentoPaciente:: operator=(ItemPagamentoPaciente& pagamentoPaciente)
{
	if (this == &pagamentoPaciente)
	{
		return *this;
	}

	this->dataDePagamento = pagamentoPaciente.dataDePagamento;
	this->nomeDoPagamento = pagamentoPaciente.nomeDoPagamento;
	this->valorPago = pagamentoPaciente.valorPago;


	return *this;
}

//sobrecarga do operador 'cout'
ostream& operator << (ostream& out, ItemPagamentoPaciente& pagamentoPaciente)
{
	out << "Data:" << pagamentoPaciente.dataDePagamento
		<< "  " << pagamentoPaciente.getNomeDoPagamento() << "  " << "Valor: " << pagamentoPaciente.getValorPago();
	return out;
}

//sobrecarga do operador ==
bool ItemPagamentoPaciente::operator==(ItemPagamentoPaciente& pagamento)
{
	return(this->dataDePagamento == pagamento.dataDePagamento && this->valorPago == pagamento.valorPago
		&& this->nomeDoPagamento == pagamento.nomeDoPagamento);
}