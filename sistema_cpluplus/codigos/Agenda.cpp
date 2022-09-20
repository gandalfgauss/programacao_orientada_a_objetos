#include "Agenda.h"
#include <iostream>//entrada e saida


using namespace std;

//construtor
Agenda::Agenda() {}


//construtor
Agenda::Agenda(Agenda& agenda)
{
	//inserir novos elementos
	for (auto it = agenda.itensDaAgenda.begin(); it != agenda.itensDaAgenda.end(); it++)
	{
		this->itensDaAgenda.push_back(new ItemAgenda(**it));
	}

}

//destrutor

Agenda:: ~Agenda()
{
	for (auto item : this->itensDaAgenda)
	{
		if (item != nullptr)
		{
			delete item;
		}
	}
}

void Agenda::adicionarItemAgenda(ItemAgenda item)//adiciona um Item na agenda de maneira ordenada pela data
{
	//inserir novos elementos
	ItemAgenda* copia = new ItemAgenda(item);

	list < ItemAgenda*> ::iterator it = this->itensDaAgenda.begin();

	for (; it != this->itensDaAgenda.end(); it++)
	{
		if ((**it).data > (*copia).data)//se o ano a inserir for menor ja pode inserir
		{
			break;
		}

		else if ((*copia).data > (**it).data)//se for maior, pode continuar a iterar ate achar o ano
		{
			continue;
		}

		else//eh igual
		{
			break;
		}

	}

	this->itensDaAgenda.insert(it, copia);
}

bool Agenda::removerItemAgenda(int posicao)//dada uma posicao remove um item da agenda
{
	if (itensDaAgenda.empty() || posicao >  itensDaAgenda.size() || posicao < 1)
	{
		return false;
	}
	int i = 0;
	for (auto it =itensDaAgenda.begin(); it != itensDaAgenda.end(); it++)
	{
		if (i == posicao - 1)
		{
			delete* it;
			itensDaAgenda.erase(it);
			break;
		}
		i++;
	}

	return true;
}

ItemAgenda& Agenda::retornarItemAgenda(int posicao)//retorna um item da agenda
{
	int i = 0;

	auto it = itensDaAgenda.begin();
	for (; it != itensDaAgenda.end(); it++)
	{
		if (i == posicao - 1)
		{

			return **it;
		}
		i++;
	}

	return **it;///retorna ultimo caso nao encontre
}

//sobrecarga do operador de atribuicao '=' 

Agenda& Agenda:: operator=(Agenda& agenda)
{
	if (this == &agenda)
	{
		return *this;
	}


	//desalocar lista
	for (auto desalocar : this->itensDaAgenda)
	{
		if (desalocar != nullptr)
		{
			delete desalocar;
		}
	}

	this->itensDaAgenda.clear();//limpar a lista 

	//inserir novos elementos
	for (auto it = agenda.itensDaAgenda.begin(); it != agenda.itensDaAgenda.end(); it++)
	{
		this->itensDaAgenda.push_back(new ItemAgenda(**it));
	}

	return *this;
}


//sobrecarga do operador 'cout'
ostream& operator << (ostream& out, Agenda& agenda)
{
	if (agenda.itensDaAgenda.empty())//se nao tiver itens na agenda
	{
		out << "Agenda vazia";
	}
	else//caso contrario imprime os itens
	{
		out << "Agenda:\n ";
		int i = 1;
		for (auto it = agenda.itensDaAgenda.begin(); it != agenda.itensDaAgenda.end(); it++)
		{
			out << "Item " << i << ": " << "\n" << **it << "\n";
			i++;
		}
	}

	return out;
}