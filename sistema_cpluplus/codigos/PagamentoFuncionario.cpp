#include "PagamentoFuncionario.h"
#include <iostream>//entrada e saida


using namespace std;

//construtor
PagamentoFuncionario::PagamentoFuncionario()
{
}

//construtor
PagamentoFuncionario::PagamentoFuncionario(Assistente& assistente)
{
	this->funcionario = assistente;
}

//construtor
PagamentoFuncionario::PagamentoFuncionario(PagamentoFuncionario& pagamento)
{
	this->funcionario = pagamento.funcionario;

	//inserir novos elementos
	for (auto it = pagamento.pagamentosFuncionario.begin(); it != pagamento.pagamentosFuncionario.end(); it++)
	{
		this->pagamentosFuncionario.push_back(new ItemPagamentoFuncionario(**it));
	}

}

//destrutor

PagamentoFuncionario:: ~PagamentoFuncionario()
{
	for (auto item : this->pagamentosFuncionario)
	{
		if (item != nullptr)
		{
			delete item;
		}
	}
}

void PagamentoFuncionario::adicionarItemFolhaDePagamento(ItemPagamentoFuncionario item)//adiciona um Item na folha de Pagamento do funcionario de maneira ordenada pela data
{
	//inserir novos elementos
	ItemPagamentoFuncionario* copia = new ItemPagamentoFuncionario(item);

	list < ItemPagamentoFuncionario*> ::iterator it = this->pagamentosFuncionario.begin();

	for (; it != this->pagamentosFuncionario.end(); it++)
	{
		if ((**it).dataDePagamento > (*copia).dataDePagamento)//se o data a inserir for menor ja pode inserir
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

	this->pagamentosFuncionario.insert(it, copia);
}

bool PagamentoFuncionario::removerItemFolhaDePagamento(int posicao)//dada uma posicao remove um item da folha de Pagamento do funcionario
{
	if (pagamentosFuncionario.empty() || posicao > pagamentosFuncionario.size() || posicao < 1)
	{
		return false;
	}
	int i = 0;
	for (auto it = pagamentosFuncionario.begin(); it != pagamentosFuncionario.end(); it++)
	{
		if (i == posicao - 1)
		{
			delete* it;
			pagamentosFuncionario.erase(it);
			break;
		}
		i++;
	}

	return true;
}

ItemPagamentoFuncionario& PagamentoFuncionario::retornarItemPagamentoFuncionario(int posicao)//retorna um item de Pagamento do funcionario
{
	int i = 0;

	auto it = pagamentosFuncionario.begin();
	for (; it != pagamentosFuncionario.end(); it++)
	{
		if (i == posicao - 1)
		{

			return **it;
		}
		i++;
	}

	return **it;///retorna ultimo caso nao encontre
}

bool PagamentoFuncionario::imprimirFolhaDePagamentoDoMes(int mes)//dado um mes, imprime a folha de paagamento do funcionario naquele mes
{
	int i = 0;
	cout << "Folha de Pagamento - " << funcionario.getNome() << " CPF: " << funcionario.getCpf() << "\n\n";
	if (pagamentosFuncionario.empty() || mes < 0 || mes > 12)
	{
		cout << "Folha de Pagamento vazia ou mes incorreto";
		return false;
	}

	for (auto it = pagamentosFuncionario.begin(); it != pagamentosFuncionario.end(); it++)
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

PagamentoFuncionario& PagamentoFuncionario:: operator=(PagamentoFuncionario& pagamento)
{
	if (this == &pagamento)
	{
		return *this;
	}

	this->funcionario = pagamento.funcionario;

	//desalocar lista
	for (auto desalocar : this->pagamentosFuncionario)
	{
		if (desalocar != nullptr)
		{
			delete desalocar;
		}
	}

	this->pagamentosFuncionario.clear();//limpar a lista 

	//inserir novos elementos
	for (auto it = pagamento.pagamentosFuncionario.begin(); it != pagamento.pagamentosFuncionario.end(); it++)
	{
		this->pagamentosFuncionario.push_back(new ItemPagamentoFuncionario(**it));
	}

	return *this;
}


//sobrecarga do operador 'cout'
ostream& operator << (ostream& out, PagamentoFuncionario& pagamento)
{
	out << "Funcionario: " << pagamento.funcionario.getNome() << " CPF:" << pagamento.funcionario.getCpf() << "\n\n";

	if (pagamento.pagamentosFuncionario.empty())//se nao tiver pagamentos
	{
		out << "Sem pagamentos";
	}
	else//caso contrario imprime os pagamentos
	{
		int i = 1;
		for (auto it = pagamento.pagamentosFuncionario.begin(); it != pagamento.pagamentosFuncionario.end(); it++)
		{
			out << "Pagamento " << i << ": " << "\n" << **it << "\n";
			i++;
		}
	}

	return out;
}