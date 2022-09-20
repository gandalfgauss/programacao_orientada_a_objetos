#include "ItemAgenda.h"
#include <iostream>//entrada e saida

using namespace std;

//construtor
ItemAgenda::ItemAgenda(string descricao)
{
	if (!setDescricao(descricao))
	{
		this->descricao = " ";
	}
}

//construtor

ItemAgenda::ItemAgenda(DataHora& data, Paciente& paciente, string descricao)
{
	this->data = data;
	this->paciente = paciente;

	if (!setDescricao(descricao))
	{
		this->descricao = " ";
	}
}

//construtor
ItemAgenda::ItemAgenda(ItemAgenda& pagamentoPaciente)
{

	this->data = pagamentoPaciente.data;
	this->paciente = pagamentoPaciente.paciente;
	this->descricao = pagamentoPaciente.descricao;
}

//destrutor

ItemAgenda:: ~ItemAgenda() {}

//getters

string ItemAgenda::getDescricao()
{
	return descricao;
}

//setters

bool ItemAgenda::setDescricao(string descricao)
{

	if (descricao == "" || descricao == " ")//conferir se nome eh valido, validacao fraca mas ajuda um pouco
	{
		return false;
	}

	this->descricao = descricao;

	return true;
}


//sobrecarga do operador de atribuicao '=' 

ItemAgenda& ItemAgenda:: operator=(ItemAgenda& item)
{
	if (this == &item)
	{
		return *this;
	}

	this->data = item.data;
	this->paciente = item.paciente;
	this->descricao = item.descricao;

	return *this;
}

//sobrecarga do operador 'cout'
ostream& operator << (ostream& out, ItemAgenda& item)
{
	out << "Data: " << item.data
		<< "  Paciente: " << item.paciente.getNome() << " CPF:" << item.paciente.getCpf() << "  " << item.descricao;
	return out;
}
