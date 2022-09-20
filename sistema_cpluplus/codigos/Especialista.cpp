#include "Especialista.h"
#include <iostream>//entrada e saida


using namespace std;

//construtor
Especialista::Especialista(Assistente& assistente, Agenda& agenda,string nome, string endereco, long long cpf, long long telefone) : Pessoa(nome, endereco, cpf, telefone)
{
	this->assistente = assistente;
	this->agenda = agenda;
}

//construtor
Especialista::Especialista(string nome, string endereco, long long cpf, long long telefone) : Pessoa(nome, endereco, cpf, telefone)
{

}

//construtor
Especialista::Especialista(Especialista& especialista)
{
	setNome(especialista.getNome());
	setEndereco(especialista.getEndereco());
	setCpf(especialista.getCpf());
	setTelefone(especialista.getTelefone());

	this->assistente = assistente;
	this->agenda = agenda;

}

//destrutor
Especialista:: ~Especialista(){}


void Especialista::imprimirAgenda()//imprime toda a agenda de um Especialista
{
	cout << "Especialista: " << getNome() << " CPF: " << getCpf() << "\n\n"
		<< agenda;
}

//sobrecarga do operador de atribuicao '=' 

Especialista& Especialista:: operator=(Especialista& especialista)
{
	if (this == &especialista)
	{
		return *this;
	}

	setNome(especialista.getNome());
	setEndereco(especialista.getEndereco());
	setCpf(especialista.getCpf());
	setTelefone(especialista.getTelefone());


	this->assistente = assistente;
	this->agenda = agenda;

	
	return *this;
}


//sobrecarga do operador 'cout'
ostream& operator << (ostream& out, Especialista& especialista)
{
	out << "Nome: " << especialista.getNome() << "\n" << "Endereco: " << especialista.getEndereco() << "\n" << "Cpf: " << especialista.getCpf()
		<< "\n"
		<< "Telefone: " << especialista.getTelefone() << "\n";
	out << "\nAssistente Do Especialista:\n " << "Nome: " << especialista.assistente.getNome() << " CPF: " << especialista.assistente.getCpf();
	
	return out;
}