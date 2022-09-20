#include "Clinica.h"
#include <iostream>//entrada e saida


using namespace std;

//construtor
Clinica::Clinica(string nomeDaClinica)
{
	this->nomeDaClinica = nomeDaClinica;
}

//destrutor
Clinica:: ~Clinica()
{
	//destruir especialistas
	for (auto item : this->especialistas)
	{
		if (item != nullptr)
		{
			delete item;
		}
	}

	//destruir Funcionarios
	for (auto item : this->assistentes)
	{
		if (item != nullptr)
		{
			delete item;
		}
	}

	//destruir pacientes
	for (auto item : this->pacientes)
	{
		if (item != nullptr)
		{
			delete item;
		}
	}
}

//getter
string Clinica::getNomeDaClinica()
{
	return nomeDaClinica;
}

//setter
bool Clinica:: setNomeDaClinica(string nomeDaClinica)
{
	if (nomeDaClinica == "" || nomeDaClinica == " ")//conferir se nome eh valido, validacao fraca mas ajuda um pouco
	{
		return false;
	}

	this->nomeDaClinica = nomeDaClinica;

	return true;
}

//--------------Especialista-------------------------

bool Clinica:: adicionarEspecialista(Especialista especialista)//adiciona um Especialista e retorna false se ja existir
{
	//inserir novos elementos
	Especialista* copia = new Especialista(especialista);

	list < Especialista*> ::iterator it = this->especialistas.begin();

	for (; it != this->especialistas.end(); it++)
	{
		if ((**it).getCpf() ==  (*copia).getCpf())//se o especialista ja existir
		{
			return false;
		}


	}

	this->especialistas.push_back(copia);

	return true;
}

bool Clinica:: removerEspecialista(int posicao)//dada uma posicao remove um especialista
{
	if (especialistas.empty() || posicao > especialistas.size() || posicao < 1)//se tiver vazia a lista ou posicao invalida
	{
		return false;
	}

	//fazer a busca pelo item para remover

	int i = 0;
	for (auto it = especialistas.begin(); it != especialistas.end(); it++)
	{
		if (i == posicao - 1)
		{
			delete *it;
			especialistas.erase(it);
			break;
		}
		i++;
	}

	return true;
}

Especialista& Clinica:: retornarEspecialista(int posicao)//dada uma posicao da lista retorna um especialista
{
	int i = 0;

	auto it = especialistas.begin();
	for (; it != especialistas.end(); it++)
	{
		if (i == posicao - 1)
		{

			return **it;
		}
		i++;
	}

	return **it;///retorna ultimo caso nao encontre
}
//------------------------------Assistente------------------------------

bool Clinica::adicionarAssistente(Assistente assistente)//adiciona um Assistente e retorna false se ja existir
{
	//inserir novos elementos
	Assistente* copia = new Assistente(assistente);

	list < Assistente*> ::iterator it = this->assistentes.begin();

	for (; it != this->assistentes.end(); it++)
	{
		if ((**it).getCpf() == (*copia).getCpf())//se o Assistente ja existir
		{
			return false;
		}
	}

	this->assistentes.push_back(copia);

	return true;
}

bool Clinica::removerAssistente(int posicao)//dada uma posicao remove um Assistente
{
	if (assistentes.empty() || posicao > assistentes.size() || posicao < 1)//se tiver vazia a lista ou posicao invalida
	{
		return false;
	}

	//fazer a busca pelo item para remover

	int i = 0;
	for (auto it = assistentes.begin(); it != assistentes.end(); it++)
	{
		if (i == posicao - 1)
		{
			delete* it;
			assistentes.erase(it);
			break;
		}
		i++;
	}

	return true;
}

Assistente& Clinica::retornarAssistente(int posicao)//dada uma posicao da lista retorna um Assistente
{
	int i = 0;

	auto it = assistentes.begin();
	for (; it != assistentes.end(); it++)
	{
		if (i == posicao - 1)
		{

			return **it;
		}
		i++;
	}

	return **it;///retorna ultimo caso nao encontre
}

//---------------------------Pacientes -----------------

bool Clinica::adicionarPaciente(Paciente paciente)//adiciona um Paciente e retorna false se ja existir
{
	//inserir novos elementos
	Paciente* copia = new Paciente(paciente);

	list < Paciente*> ::iterator it = this->pacientes.begin();

	for (; it != this->pacientes.end(); it++)
	{
		if ((**it).getCpf() == (*copia).getCpf())//se o Paciente ja existir
		{
			return false;
		}


	}

	this->pacientes.push_back(copia);

	return true;
}

bool Clinica::removerPaciente(int posicao)//dada uma posicao remove um Paciente
{
	if (pacientes.empty() || posicao > pacientes.size() || posicao < 1)//se tiver vazia a lista ou posicao invalida
	{
		return false;
	}

	//fazer a busca pelo item para remover

	int i = 0;
	for (auto it = pacientes.begin(); it != pacientes.end(); it++)
	{
		if (i == posicao - 1)
		{
			delete* it;
			pacientes.erase(it);
			break;
		}
		i++;
	}

	return true;
}

Paciente& Clinica::retornarPaciente(int posicao)//dada uma posicao da lista retorna um Paciente
{
	int i = 0;

	auto it = pacientes.begin();
	for (; it != pacientes.end(); it++)
	{
		if (i == posicao - 1)
		{

			return **it;
		}
		i++;
	}

	return **it;///retorna ultimo caso nao encontre
}
//---------------------------------------------------------
bool Clinica::imprimirNomeDosEspecialistas()//imprime o nome dos especialistas cadastrados
{
	if (especialistas.empty())
	{
		cout << "\nLista de Especialistas vazia.";
		return false;
	}

	int i = 1;

	for (auto it : especialistas)
	{
		cout << "Especialista " << i << ": " << (*it).getNome() << " CPF: " << (*it).getCpf() << endl << endl;
		i++;
	}
}

bool Clinica::imprimirNomeDosFuncionarios()//imprime o nome dos funcionarios cadastrados
{
	if (assistentes.empty())
	{
		cout << "\nLista de Funcionarios vazia.";
		return false;
	}

	int i = 1;

	for (auto it : assistentes)
	{
		cout << "Funcionario " << i << ": " << (*it).getNome() << " CPF: " << (*it).getCpf() << endl << endl;
		i++;
	}
}

bool Clinica:: imprimirPacientes()//imprime todos os dados dos paciente cadastrados
{
	if (pacientes.empty())
	{
		cout << "\nLista de Pacientes vazia.";
		return false;
	}

	int i = 1;

	for (auto it :pacientes)
	{
		cout << "Paciente " << i << ": " << "\n" << (*it) << endl << endl;
		i++;
	}
}

bool Clinica:: imprimirAssistentes()//imprime todos os dados dos assistentes cadastrados
{
	if (assistentes.empty())
	{
		cout << "\nLista de Funcionarios vazia.";
		return false;
	}

	int i = 1;

	for (auto it : assistentes)
	{
		cout << "Funcionario " << i << ": " << "\n" << (*it) << endl << endl;
		i++;
	}
}

bool Clinica:: imprimirEspecialistas()//imprime todos os dados dos especialistas cadastrados
{
	if (especialistas.empty())
	{
		cout << "\nLista de Especialistas vazia.";
		return false;
	}

	int i = 1;

	for (auto it : especialistas)
	{
		cout << "Especialista " << i << ": " << "\n" << (*it) << endl << endl;
		i++;
	}
}

//-------------------------------------------------------

//retorna:
	//1- Para Usuario Administrador (usuario: admin, senha: admin)
	//2- Para Usuario Assistente 
	//3- Para Usuario Geral
	//0- Erro, nao pode dar acesso
	//Para as opcoes 2 e 3 serem retornados o Usuario dever se o nome da Pessoa e a Senha é o Cpf
int Clinica::login(string usuario, string senha)
{
	if (usuario == "admin" && senha == "admin")
	{
		return 1;
	}
	else if(recepcionista.getNome() == usuario && to_string(recepcionista.getCpf()) == senha)//conferir se é recepcionista
	{
		return 2;
	}
	else //conferir se eh assistente ou especialista para dar acesso de Usuario Geral
	{
		for (auto item : assistentes)//conferir se eh assistente
		{
			if (item->getNome() == usuario && to_string(item->getCpf()) == senha)
			{
				return 3;
			}
		}

		for (auto item : especialistas)//conferir se eh especialista
		{
			if (item->getNome() == usuario && to_string(item->getCpf()) == senha)
			{
				return 3;
			}
		}
	}

	return 0;
}

