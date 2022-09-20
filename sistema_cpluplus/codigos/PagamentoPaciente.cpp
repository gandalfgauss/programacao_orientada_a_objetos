#include "PagamentoPaciente.h"
#include <iostream>//entrada e saida


using namespace std;

//construtor
PagamentoPaciente :: PagamentoPaciente() {}


//construtor
PagamentoPaciente::PagamentoPaciente(Paciente& paciente)
{
	this->paciente = paciente;
}

//construtor
PagamentoPaciente::PagamentoPaciente(PagamentoPaciente& pagamento)
{
	this->paciente = pagamento.paciente;

	//inserir novos elementos
	for (auto it = pagamento.pagamentosPaciente.begin(); it != pagamento.pagamentosPaciente.end(); it++)
	{
		this->pagamentosPaciente.push_back(new ItemPagamentoPaciente(**it));
	}
	
}

//destrutor

PagamentoPaciente:: ~PagamentoPaciente() 
{
	for (auto item : this->pagamentosPaciente)
	{
		if (item != nullptr)
		{
			delete item;
		}
	}
}

void PagamentoPaciente:: adicionarItemPagamentoPaciente(ItemPagamentoPaciente item)//adiciona um ItemPago pelo paciente de maneira ordenada pela data
{
	//inserir novos elementos
	ItemPagamentoPaciente* copia = new ItemPagamentoPaciente(item);

	list < ItemPagamentoPaciente*> ::iterator it = this->pagamentosPaciente.begin();

	for (; it != this->pagamentosPaciente.end(); it++)
	{
		if ((**it).dataDePagamento > (*copia).dataDePagamento)//se o ano a inserir for menor ja pode inserir
		{
			break;
		}
			
		else if ((*copia).dataDePagamento > (**it).dataDePagamento)//se for maior, pode continuar a iterar ate achar o ano
		{
			continue;
		}

		else//eh igual
		{
			break;
		}

	}

	this->pagamentosPaciente.insert(it, copia);
}

bool PagamentoPaciente:: removerItemPagamentoPaciente(int posicao)//dada uma posicao remove um item pago pelo paciente
{
	if (pagamentosPaciente.empty() || posicao > pagamentosPaciente.size() || posicao < 1)
	{
		return false;
	}
	int i = 0;
	for (auto it = pagamentosPaciente.begin(); it != pagamentosPaciente.end(); it++)
	{
		if (i == posicao - 1)
		{
			delete *it;
			pagamentosPaciente.erase(it);
			break;
		}
		i++;
	}

	return true;
}

ItemPagamentoPaciente& PagamentoPaciente :: retornarItemPagamentoPaciente(int posicao)//retorna um item pago pelo paciente
{
	int i = 0;

	auto it = pagamentosPaciente.begin();
	for (; it != pagamentosPaciente.end(); it++)
	{
		if (i == posicao - 1)
		{
			
			return **it;
		}
		i++;
	}

	return **it;///retorna ultimo caso nao encontre
}

bool PagamentoPaciente::imprimirItensPagosNoMes(int mes)
{
	int i = 0;

	if (pagamentosPaciente.empty() || mes < 0 || mes > 12)
	{
		return false;
	}

	for (auto it = pagamentosPaciente.begin(); it != pagamentosPaciente.end(); it++)
	{
		
		if ((**it).dataDePagamento.getMes() == mes)
		{
			i++;
			cout << "Pagamento " << i << ": " << (**it) << "\n";

		}
	}

	return i;
}

//sobrecarga do operador de atribuicao '=' 

PagamentoPaciente& PagamentoPaciente:: operator=(PagamentoPaciente& pagamento)
{
	if (this == &pagamento)
	{
		return *this;
	}

	this->paciente = pagamento.paciente;
	
	//desalocar lista
	for (auto desalocar : this->pagamentosPaciente)
	{
		if (desalocar != nullptr)
		{
			delete desalocar;
		}
	}

	this->pagamentosPaciente.clear();//limpar a lista 

	//inserir novos elementos
	for (auto it = pagamento.pagamentosPaciente.begin(); it != pagamento.pagamentosPaciente.end(); it++)
	{
		this->pagamentosPaciente.push_back(new ItemPagamentoPaciente(**it));
	}

	return *this;
}


//sobrecarga do operador 'cout'
ostream& operator << (ostream& out, PagamentoPaciente& pagamento)
{
	out << "Paciente: " << pagamento.paciente.getNome() << " CPF:" << pagamento.paciente.getCpf() << "\n\n";

	if (pagamento.pagamentosPaciente.empty())//se nao tiver pagamentos
	{
		out << "Sem pagamentos";
	}
	else//caso contrario imprime os pagamentos
	{
		int i = 1;
		for (auto it = pagamento.pagamentosPaciente.begin(); it != pagamento.pagamentosPaciente.end(); it++)
		{
			out << "Pagamento " << i << ": " << "\n" << **it <<"\n";
			i++;
		}
	}

	return out;
}