#ifndef ITEMFOLHADEPONTO_H
#define ITEMFOLHADEPONTO_H

#include <iostream>
#include <string>
#include "Data.h"

using namespace std;

class ItemFolhaDePonto
{
public:
	Data data;

private:
	string observacao;


public:

	//construtores e destrutor
	ItemFolhaDePonto(string = "");
	ItemFolhaDePonto(Data&, string = "");
	ItemFolhaDePonto(ItemFolhaDePonto&);
	~ItemFolhaDePonto();

	//getters
	string getObservacao();

	//setters
	bool setObservacao(string);

	//sobrecarga do operador de atribuicao '=' 
	ItemFolhaDePonto& operator=(ItemFolhaDePonto&);

	//sobrecarga do operador 'cout'
	friend ostream& operator << (ostream&, ItemFolhaDePonto&);

};

#endif // !ItemFolhaDePonto_H
