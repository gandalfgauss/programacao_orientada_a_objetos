#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
using namespace std;

class Pessoa
{
	string nome;
	string endereco;
	long long cpf;
	long long telefone;

public:
	//construtores e destrutor
	Pessoa(string="", string="", long long = 12345678900, long long = 33988888888);
	Pessoa(Pessoa&);
	~Pessoa();

	//getters
	string getNome();
	string getEndereco();
	long long getCpf();
	long long getTelefone();

	//setters
	bool setNome(string);
	bool setEndereco(string);
	bool setCpf(long long);
	bool setTelefone(long long);

	//sobrecarga do operador de atribuicao '=' 
	Pessoa& operator=(Pessoa&);

	//sobrecarga do operador 'cout'
	friend ostream& operator << (ostream&, Pessoa&);
};

#endif // !Pessoa_H
