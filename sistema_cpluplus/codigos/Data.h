#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;

class Data
{
	int dia;
	int mes;
	int ano;

public:
	//construtores e destrutor
	Data(int = 1, int = 1, int = 1901);
	Data(Data&);
	~Data();

	//getters
	int getDia();
	int getMes();
	int getAno();

	//setters
	bool setDia(int);
	bool setMes(int);
	bool setAno(int);

	//sobrecarga do operador de atribuicao '=' 
	Data& operator=(Data&);

	//sobrecarga do operador 'cout'
	friend ostream& operator << (ostream&, Data&);

	//sobrecarga do operador ==
	bool operator==(Data&);

	//sobrecarga do operador >
	bool operator >(Data&);
};

#endif // !DATA_H
