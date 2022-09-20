#ifndef ASSISTENTE_H
#define ASSISTENTE_H

#include <iostream>
#include <list>
#include "Pessoa.h"
#include "ItemFolhaDePonto.h"

using namespace std;

class Assistente : public Pessoa
{
public:
	list<ItemFolhaDePonto*> folhaDePonto;


	//construtores e destrutor
	Assistente(string = "", string = "", long long = 12345678900, long long = 33988888888);
	Assistente(Assistente&);
	~Assistente();

	//getters e setters herdados

	//metodos
	void adicionarItemFolhaDePonto(ItemFolhaDePonto);//adiciona um item na folha de ponto ordenado pela data
	bool removerItemFolhaDePonto(int posicao);//dada uma posicao remove um item da folha de ponto
	ItemFolhaDePonto& retornarItemFolhaDePonto(int posicao);//retorna um item da folha de ponto
	bool imprimirFolhaDePontoDoMes(int mes);//imprime a folha de ponto de um assistente de um determinado mes
	bool imprimirFolhaDePonto();//imprime toda a folha de ponto de um assistente 


	//sobrecarga do operador de atribuicao '=' 
	Assistente& operator=(Assistente&);

	//sobrecarga do operador 'cout'
	friend ostream& operator << (ostream&, Assistente&);

};

#endif // !Assistente_H
