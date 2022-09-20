#include "ItemFolhaDePonto.h"
#include <iostream>//entrada e saida

using namespace std;

//construtor

ItemFolhaDePonto::ItemFolhaDePonto(string observacao)
{

	if (!setObservacao(observacao))
	{
		this->observacao = " ";
	}
}

//construtor

ItemFolhaDePonto::ItemFolhaDePonto(Data& data, string observacao)
{
	this->data = data;


	if (!setObservacao(observacao))
	{
		this->observacao = " ";
	}
}

//construtor
ItemFolhaDePonto::ItemFolhaDePonto(ItemFolhaDePonto& item)
{
	this->data = item.data;
	this->observacao = item.observacao;

}



//destrutor

ItemFolhaDePonto:: ~ItemFolhaDePonto() {}

//getters

string ItemFolhaDePonto::getObservacao()
{
	return observacao;
}

//setters

bool ItemFolhaDePonto::setObservacao(string observacao)
{

	if (observacao == "" || observacao == " ")//conferir se nome eh valido, validacao fraca mas ajuda um pouco
	{
		return false;
	}

	this->observacao = observacao;

	return true;
}

//sobrecarga do operador de atribuicao '=' 

ItemFolhaDePonto& ItemFolhaDePonto:: operator=(ItemFolhaDePonto& item)
{
	if (this == &item)
	{
		return *this;
	}

	this->data = item.data;
	this->observacao = item.observacao;

	return *this;
}

//sobrecarga do operador 'cout'
ostream& operator << (ostream& out, ItemFolhaDePonto& item)
{
	out << "Data: " << item.data << "  Observacao: " << item.observacao;
	return out;
}
