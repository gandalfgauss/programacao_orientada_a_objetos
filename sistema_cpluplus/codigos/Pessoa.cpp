#include "Pessoa.h"
#include <iostream>//entrada e saida

using namespace std;

//construtor
Pessoa::Pessoa(string nome, string endereco, long long cpf, long long telefone)
{
	if (!setNome(nome))
	{
		this->nome = " ";
	}

	if (!setEndereco(endereco))
	{
		this->endereco = " ";
	}

	if (!setCpf(cpf))
	{
		this->cpf = 12345678900;
	}

	if (!setTelefone(telefone))
	{
		this->telefone = 33988888888;
	}

}

//construtor
Pessoa::Pessoa(Pessoa& Pessoa)
{
	this->nome = Pessoa.nome;
	this->endereco = Pessoa.endereco;
	this->cpf = Pessoa.cpf;
	this->telefone = telefone;
}

//destrutor

Pessoa:: ~Pessoa() {}

//getters

string Pessoa::getNome()
{
	return nome;
}

string Pessoa::getEndereco()
{
	return endereco;
}

long long Pessoa::getCpf()
{
	return cpf;
}

long long Pessoa::getTelefone()
{
	return telefone;
}

//setters

bool Pessoa::setNome(string nome)
{
	
	if (nome == "" || nome == " ")//conferir se nome eh valido, validacao fraca mas ajuda um pouco
	{
		return false;
	}

	this->nome = nome;

	return true;
}

bool Pessoa::setEndereco(string endereco)
{
	if (endereco == "" || endereco == " ")//conferir se endereco eh valido
	{
		return false;
	}

	this->endereco = endereco;

	return true;
}

bool Pessoa::setCpf(long long cpf)
{
	if (to_string(cpf).size() < 10 || to_string(cpf).size() > 11)//conferir se cpf tem 10 ou 11 digitos
	{
		return false;
	}

	this->cpf = cpf;

	return true;
}

bool Pessoa::setTelefone(long long telefone)
{
	if (to_string(telefone).size() < 8)//conferir se telefone tem menos de 8 digitos
	{
		return false;
	}

	this->telefone = telefone;

	return true;
}

//sobrecarga do operador de atribuicao '=' 

Pessoa& Pessoa:: operator=(Pessoa& Pessoa)
{
	if (this == &Pessoa)
	{
		return *this;
	}

	this->nome = Pessoa.nome;
	this->endereco = Pessoa.endereco;
	this->cpf = Pessoa.cpf;
	this->telefone = Pessoa.telefone;

	return *this;
}

//sobrecarga do operador 'cout'
ostream& operator << (ostream& out, Pessoa& Pessoa)
{
	out << "Nome: " << Pessoa.getNome() << "\n" << "Endereco: " << Pessoa.getEndereco() << "\n" << "Cpf: " << Pessoa.getCpf() << "\n"
		"Telefone: " << Pessoa.getTelefone();
	return out;
}