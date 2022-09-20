#include "Paciente.h"
#include <iostream>//entrada e saida


using namespace std;

//construtor
Paciente::Paciente(string nome, string endereco, long long cpf, long long telefone) : Pessoa(nome, endereco, cpf, telefone)
{
	
}

//construtor
Paciente::Paciente(Paciente& paciente)
{
	setNome(paciente.getNome());
	setEndereco(paciente.getEndereco());
	setCpf(paciente.getCpf());
	setTelefone(paciente.getTelefone());
	
}

//destrutor

Paciente:: ~Paciente() {}


//sobrecarga do operador de atribuicao '=' 

Paciente& Paciente:: operator=(Paciente& paciente)
{
	if (this == &paciente)
	{
		return *this;
	}

	setNome(paciente.getNome());
	setEndereco(paciente.getEndereco());
	setCpf(paciente.getCpf());
	setTelefone(paciente.getTelefone());

	return *this;
}

//sobrecarga do operador 'cout'
ostream& operator << (ostream& out, Paciente& paciente)
{
	out << "Nome: " << paciente.getNome() << "\n" << "Endereco: " << paciente.getEndereco() << "\n" << "Cpf: " << paciente.getCpf()
		<< "\n"
		<<"Telefone: " << paciente.getTelefone();
	return out;
}

//sobrecarga do operador ==
bool Paciente::operator==(Paciente& paciente)
{
	return(this->getNome() == paciente.getNome() && this->getEndereco() == paciente.getEndereco() 
		&& this->getCpf() == paciente.getCpf() && this->getTelefone() == paciente.getTelefone());
}