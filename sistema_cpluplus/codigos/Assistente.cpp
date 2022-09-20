#include "Assistente.h"
#include <iostream>//entrada e saida


using namespace std;

//construtor
Assistente::Assistente(string nome, string endereco, long long cpf, long long telefone) : Pessoa(nome, endereco, cpf, telefone)
{

}

//construtor
Assistente::Assistente(Assistente& assistente)
{
	setNome(assistente.getNome());
	setEndereco(assistente.getEndereco());
	setCpf(assistente.getCpf());
	setTelefone(assistente.getTelefone());


	//inserir novos elementos
	for (auto it = assistente.folhaDePonto.begin(); it != assistente.folhaDePonto.end(); it++)
	{
		this->folhaDePonto.push_back(new ItemFolhaDePonto(**it));
	}
}

//destrutor
Assistente:: ~Assistente()
{
	for (auto item : this->folhaDePonto)
	{
		if (item != nullptr)
		{
			delete item;
		}
	}
}

void Assistente::adicionarItemFolhaDePonto(ItemFolhaDePonto item)//adiciona um item na folha de ponto ordenado pela data
{
	//inserir novos elementos
	ItemFolhaDePonto* copia = new ItemFolhaDePonto(item);

	list < ItemFolhaDePonto*> ::iterator it = this->folhaDePonto.begin();

	for (; it != this->folhaDePonto.end(); it++)
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

	this->folhaDePonto.insert(it, copia);
}

bool Assistente::removerItemFolhaDePonto(int posicao)//dada uma posicao remove um item da folha de ponto
{
	if (folhaDePonto.empty() || posicao > folhaDePonto.size() || posicao < 1)
	{
		return false;
	}
	int i = 0;
	for (auto it = folhaDePonto.begin(); it != folhaDePonto.end(); it++)
	{
		if (i == posicao - 1)
		{
			delete* it;
			folhaDePonto.erase(it);
			break;
		}
		i++;
	}

	return true;
}

ItemFolhaDePonto& Assistente::retornarItemFolhaDePonto(int posicao)//retorna um item da folha de ponto
{
	int i = 0;

	auto it = folhaDePonto.begin();
	for (; it != folhaDePonto.end(); it++)
	{
		if (i == posicao - 1)
		{

			return **it;
		}
		i++;
	}

	return **it;///retorna ultimo caso nao encontre
}

bool Assistente::imprimirFolhaDePontoDoMes(int mes)//imprime a folha de ponto de um assistente de um determinado mes
{
	int i = 0;

	if (folhaDePonto.empty())
	{
		cout << "\nFolha de Ponto Vazia !";
		return true;
	}

	if (mes < 0 || mes > 12)
	{
		cout << "\nValor de mes incorreto";
		return false;
	}

	cout << "\nFolha de ponto - " << getNome() << "\n";
	for (auto it = folhaDePonto.begin(); it != folhaDePonto.end(); it++)
	{

		if ((**it).data.getMes() == mes)
		{
			i++;
			cout << (**it) << "\n";
		}
	}

	return i;
}

bool Assistente::imprimirFolhaDePonto()//imprime toda a folha de ponto de um assistente
{
	int i = 1;

	if (folhaDePonto.empty())
	{
		cout << "\nFolha de Ponto Vazia";
		return false;
	}

	cout << "\nFolha de ponto - " << getNome() << " CPF: " << getCpf() << "\n";
	for (auto it = folhaDePonto.begin(); it != folhaDePonto.end(); it++)
	{
			cout << "Item " << i <<":\n" << (**it) << "\n";
			i++;
	}

	return true;
}

//sobrecarga do operador de atribuicao '=' 

Assistente& Assistente:: operator=(Assistente& assistente)
{
	if (this == &assistente)
	{
		return *this;
	}

	setNome(assistente.getNome());
	setEndereco(assistente.getEndereco());
	setCpf(assistente.getCpf());
	setTelefone(assistente.getTelefone());


	//desalocar lista
	for (auto desalocar : this->folhaDePonto)
	{
		if (desalocar != nullptr)
		{
			delete desalocar;
		}
	}

	this->folhaDePonto.clear();//limpar a lista 

	//inserir novos elementos
	for (auto it = assistente.folhaDePonto.begin(); it != assistente.folhaDePonto.end(); it++)
	{
		this->folhaDePonto.push_back(new ItemFolhaDePonto(**it));
	}

	return *this;
}


//sobrecarga do operador 'cout'
ostream& operator << (ostream& out, Assistente& assistente)
{
	out << "Nome: " << assistente.getNome() << "\n" << "Endereco: " << assistente.getEndereco() << "\n" << "Cpf: " << assistente.getCpf()
		<< "\n"
		<< "Telefone: " << assistente.getTelefone() << "\n";

	/*if (assistente.folhaDePonto.empty())//se nao tiver  itens
	{
		out << "Folha de Ponto Vazia";
	}
	else//caso contrario imprime os itens
	{
		int i = 1;
		for (auto it = assistente.folhaDePonto.begin(); it != assistente.folhaDePonto.end(); it++)
		{
			out  << **it << "\n";
		}
	}*/

	return out;
}