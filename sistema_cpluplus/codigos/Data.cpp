#include "Data.h"
#include <iostream>//entrada e saida
#include <iomanip>//manipulacao de entrada e saida

using namespace std;

//construtor
Data::Data(int dia, int mes, int ano)
{
	if (!setDia(dia))
	{
		this->dia = 1;
	}

	if (!setMes(mes))
	{
		this->mes = 1;
	}

	if (!setAno(ano))
	{
		this->ano = 1901;
	}
	
}

//construtor
Data::Data(Data& data)
{
	this->dia = data.dia;
	this->mes = data.mes;
	this->ano = data.ano;
}

//destrutor

Data:: ~Data(){}

//getters

int Data::getDia()
{
	return dia;
}

int Data::getMes()
{
	return mes;
}

int Data::getAno()
{
	return ano;
}

//setters

bool Data::setDia(int dia)
{
	if (dia > 31 || dia <= 0)//conferir se dia eh valido
	{
		return false;
	}

	this->dia = dia;

	return true;
}

bool Data::setMes(int mes)
{
	if (mes > 12 || mes <= 0)//conferir se mes eh valido
	{
		return false;
	}

	this->mes = mes;

	return true;
}

bool Data::setAno(int ano)
{
	if (ano > 2100 || ano <= 1900)//conferir se ano eh valido
	{
		return false;
	}

	this->ano = ano;

	return true;
}

//sobrecarga do operador de atribuicao '=' 

Data& Data:: operator=(Data& data)
{
	if (this == &data)
	{
		return *this;
	}

	this->dia = data.dia;
	this->mes = data.mes;
	this->ano = data.ano;

	return *this;
}

//sobrecarga do operador 'cout'
ostream& operator << (ostream& out, Data& data)
{
	out << setw(2) << setfill('0') << data.getDia() << "/" << setw(2) << setfill('0')<< data.getMes() << "/" << data.getAno();
	return out;
}

//sobrecarga do operador ==
bool Data::operator==(Data& data)
{
	return(this->dia == data.dia && this->mes == data.mes && this->ano == data.ano);

	
}

//sobrecarga do operador >
bool Data:: operator >(Data& data)
{
	if (this->getAno() > data.getAno())//se o ano for maior a data eh maior
	{
		return true;
	}

	else if (this->getAno() <  data.getAno())//se for maior, pode continuar a iterar ate achar o ano
	{
		return false;
	}

	else//ano eh igual
	{
		if (this->getMes() > data.getMes())//confere se mes eh maior
		{
			return true;
		}

		else if (this->getMes() < data.getMes())//se for maior, pode continuar a iterar ate achar o ano
		{
			false;
		}

		else//ano e mes sao iguais
		{
			if (this->getDia() > data.getDia())//se o dia a inserir for menor ja pode inserir
			{
				return true;
			}

			else if (this->getDia() < data.getDia())//se for maior, pode continuar a iterar ate achar o ano
			{
				return false;
			}

			else//dia, mes e ano iguais
			{
				return false;
			}
		}
	}
}