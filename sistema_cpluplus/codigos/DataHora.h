#pragma once
#ifndef DATAHORA_H
#define DATAHORA_H

#include <iostream>
#include "Data.h"

using namespace std;

class DataHora: public Data
{
	int hora;
	int minuto;

public:
	//construtores e destrutor
	DataHora(int = 1, int = 1, int = 1901, int = 0, int = 0);
	DataHora(DataHora&);
	~DataHora();

	//getters
	int getHora();
	int getMinuto();


	//setters
	bool setHora(int);
	bool setMinuto(int);

	//sobrecarga do operador de atribuicao '=' 
	DataHora& operator=(DataHora&);

	//sobrecarga do operador 'cout'
	friend ostream& operator << (ostream&, DataHora&);

	//sobrecarga do operador ==
	bool operator==(DataHora&);

	//sobrecarga do operador >
	bool operator >(DataHora&);
};

#endif // !DATA_H
