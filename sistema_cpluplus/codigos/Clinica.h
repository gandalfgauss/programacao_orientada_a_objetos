#ifndef CLINICA_H
#define CLINICA_H

#include <iostream>
#include <list>
#include <string>
#include "Especialista.h"
#include "Assistente.h"
#include "Pagamentos.h"
#include "Paciente.h"


using namespace std;

class Clinica
{
private:
	string nomeDaClinica;

public:

	list<Especialista*> especialistas;
	list<Assistente*> assistentes;
	Assistente recepcionista;
	Pagamentos pagamentos;
	list<Paciente*> pacientes;


	//construtores e destrutor
	Clinica(string = "");
	~Clinica();

	//getters e setter
	string getNomeDaClinica();
	bool setNomeDaClinica(string);

	bool adicionarEspecialista(Especialista);//adiciona um Especialista e retorna false se ele ja existir
	bool removerEspecialista(int posicao);//dada uma posicao remove um especialista
	Especialista& retornarEspecialista(int posicao);//dada uma posicao da lista retorna um especialista

	bool adicionarAssistente(Assistente);//adiciona um Assistente e retorna false se ele ja existir
	bool removerAssistente(int posicao);//dada uma posicao remove um Assistente
	Assistente& retornarAssistente(int posicao);//dada uma posicao da lista retorna um Assistente

	bool adicionarPaciente(Paciente);//adiciona um Paciente e retorna false se ele ja existir
	bool removerPaciente(int posicao);//dada uma posicao remove um Paciente
	Paciente& retornarPaciente(int posicao);//dada uma posicao da lista retorna um Paciente


	bool imprimirNomeDosEspecialistas();//imprime o nome e o cpf dos especialistas cadastrados
	bool imprimirNomeDosFuncionarios();//imprime o nome e o cpf dos funcionarios cadastrados

	bool imprimirPacientes();//imprime todos os dados dos paciente cadastrados
	bool imprimirAssistentes();//imprime todos os dados dos assistentes cadastrados
	bool imprimirEspecialistas();//imprime todos os dados dos especialistas cadastrados

	//retorna:
	//1- Para Usuario Administrador
	//2- Para Usuario Assistente
	//3- Para Usuario Geral
	//4- Erro, nao pode dar acesso
	int login(string usuario, string senha);

	//sobrecarga do operador de atribuicao '=' 
	Clinica& operator=(Clinica&);

};

#endif // !Clinica_H
