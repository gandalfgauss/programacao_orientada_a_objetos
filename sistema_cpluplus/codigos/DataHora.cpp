#include "DataHora.h"
#include <iostream>//entrada e saida
#include <iomanip>//manipulacao de entrada e saida

using namespace std;

//construtor
DataHora::DataHora(int dia, int mes, int ano, int hora, int minuto) : Data(dia, mes, ano)
{
	if (!setHora(hora))
	{
		this->hora = 0;
	}

	if (!setMinuto(minuto))
	{
		this->minuto = 0;
	}

}

//construtor
DataHora::DataHora(DataHora& data)
{
	setDia(data.getDia());
	setMes(data.getMes());
	setAno(data.getAno());
	this->minuto = data.getMinuto();
	this->hora = data.getHora();
}

//destrutor

DataHora:: ~DataHora() {}

//getters

int DataHora::getHora()
{
	return hora;
}

int DataHora::getMinuto()
{
	return minuto;
}

//setters

bool DataHora::setHora(int hora)
{
	if (hora > 24 || hora < 0)//conferir se hora eh valida
	{
		return false;
	}

	this->hora = hora;

	return true;
}

bool DataHora::setMinuto(int minuto)
{
	if (minuto> 59 || minuto < 0)//conferir se minuto eh valido
	{
		return false;
	}

	this->minuto = minuto;

	return true;
}


//sobrecarga do operador de atribuicao '=' 

DataHora& DataHora:: operator=(DataHora& data)
{
	if (this == &data)
	{
		return *this;
	}

	setDia(data.getDia());
	setMes(data.getMes());
	setAno(data.getAno());
	this->minuto = data.getMinuto();
	this->hora = data.getHora();

	return *this;
}

//sobrecarga do operador 'cout'
ostream& operator << (ostream& out, DataHora& data)
{
	out << setw(2) << setfill('0') << data.getDia() << "/" << setw(2) << setfill('0') << data.getMes() << "/" << data.getAno()
		<< " " << setw(2) << setfill('0') << data.getHora() << ":" << setw(2) << setfill('0') << data.getMinuto();
	return out;
}

//sobrecarga do operador ==
bool DataHora::operator==(DataHora& data)
{
	return(this->getDia() == data.getDia() && this->getMes() == data.getMes() && this->getAno() == data.getAno() && this->hora == data.hora && this->minuto == data.minuto);
}

//sobrecarga do operador >
bool DataHora:: operator >(DataHora& data)
{
	if (this->getAno() > data.getAno())//se o ano for maior a data eh maior
	{
		return true;
	}

	else if (this->getAno() < data.getAno())//se for maior, pode continuar a iterar ate achar o ano
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
				//------
				if (this->getHora() > data.getHora())//se a hora for maior
				{
					return true;
				}

				else if (this->getHora() < data.getHora())//se for maior, pode continuar a iterar ate achar o ano
				{
					return false;
				}

				else//conferir minuto
				{

					//------
					if (this->getMinuto() > data.getMinuto())//se a hora for maior
					{
						return true;
					}

					else if (this->getMinuto() < data.getMinuto())//se for maior, pode continuar a iterar ate achar o ano
					{
						return false;
					}
					else//tudo igual
					{
						return false;
					}
				}
			}
		}
	}

	return false;
}