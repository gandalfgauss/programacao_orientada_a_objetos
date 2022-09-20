#include "Pagamentos.h"
#include <iostream>//entrada e saida


using namespace std;

//construtor
Pagamentos::Pagamentos() {}

//construtor
Pagamentos::Pagamentos(Pagamentos& pagamentos)
{
	

	//inserir novos  pacientes
	for (auto it = pagamentos.pagamentosPacientes.begin(); it != pagamentos.pagamentosPacientes.end(); it++)
	{
		this->pagamentosPacientes.push_back(new PagamentoPaciente(**it));
	}

	//inserir novos funcionarios
	for (auto it = pagamentos.pagamentosFuncionarios.begin(); it != pagamentos.pagamentosFuncionarios.end(); it++)
	{
		this->pagamentosFuncionarios.push_back(new PagamentoFuncionario(**it));
	}

	//inserir novos gastos
	for (auto it = pagamentos.pagamentosDeGastos.begin(); it != pagamentos.pagamentosDeGastos.end(); it++)
	{
		this->pagamentosDeGastos.push_back(new PagamentoDeGastos(**it));
	}

}

//destrutor

Pagamentos:: ~Pagamentos()
{
	//destruir Pacientes
	for (auto item : this->pagamentosPacientes)
	{
		if (item != nullptr)
		{
			delete item;
		}
	}

	//destruir Funcionarios
	for (auto item : this->pagamentosFuncionarios)
	{
		if (item != nullptr)
		{
			delete item;
		}
	}

	//destruir Gastos
	for (auto item : this->pagamentosDeGastos)
	{
		if (item != nullptr)
		{
			delete item;
		}
	}
}

//--------------Cliente-------------------------

void Pagamentos::adicionarPagamentoPaciente(PagamentoPaciente pagamentoPaciente)//adiciona os pagamentos de um paciente
{
	//inserir novos elementos

	list < PagamentoPaciente*> ::iterator it = this->pagamentosPacientes.begin();

	for (; it != this->pagamentosPacientes.end(); it++)
	{
		if ((**it).paciente.getCpf() == pagamentoPaciente.paciente.getCpf())//se o paciente ja existir
		{
			for (auto item : pagamentoPaciente.pagamentosPaciente)//adicionar os itens da lista passada como parâmetro na lista sa existente
			{
				(**it).adicionarItemPagamentoPaciente(*item);
			}

			return;
		}
	}

	//caso contrario eh so adicionar o pagamento
	this->pagamentosPacientes.push_back(new PagamentoPaciente(pagamentoPaciente));
}

bool Pagamentos::removerPagamentoPaciente(long long cpf)//dado um cpf de um Paciente remove sua lista de pagamentos
{
	if (pagamentosPacientes.empty())//se tiver vaio a lista de passientes
	{
		return false;
	}

	//fazer a busca pelo cpf para remover

	for (auto it = pagamentosPacientes.begin(); it != pagamentosPacientes.end(); it++)
	{
		if ((**it).paciente.getCpf() == cpf)//se achei o paciente a ser removido
		{
			delete (*it);
			pagamentosPacientes.erase(it);

			return true;
		}
	}

	return false;
}

PagamentoPaciente& Pagamentos::retornarPagamentoPaciente(long long cpf)//retorna os pagamentos de um Funcionario dada a sua posicao
{
	auto it = pagamentosPacientes.begin();
	for (; it != pagamentosPacientes.end(); it++)
	{
		if ((**it).paciente.getCpf() == cpf)
		{

			return **it;
		}

	}

	return **it;///retorna ultimo caso nao encontre
}

PagamentoPaciente& Pagamentos::retornarPagamentoPaciente(int posicao)//retorna os pagamentos de um paciente dado o sua posicao
{
	
	int i = 0;

	auto it = pagamentosPacientes.begin();
	for (; it != pagamentosPacientes.end(); it++)
	{
		if (i == posicao - 1)
		{

			return **it;
		}
		i++;
	}

	return **it;///retorna ultimo caso nao encontre
}
//------------------------------ Funcionario------------------------------

void Pagamentos::adicionarPagamentoFuncionario(PagamentoFuncionario pagamentoFuncionario)//adiciona os pagamentos de um Funcionario
{
	//inserir novos elementos

	list < PagamentoFuncionario*> ::iterator it = this->pagamentosFuncionarios.begin();

	for (; it != this->pagamentosFuncionarios.end(); it++)
	{
		if ((**it).funcionario.getCpf() == pagamentoFuncionario.funcionario.getCpf())//se o Funcionario ja existir
		{
			for (auto item : pagamentoFuncionario.pagamentosFuncionario)//adicionar os itens da lista passada como parâmetro na lista sa existente
			{
				(**it).adicionarItemFolhaDePagamento(*item);
			}

			return;
		}
	}

	//caso contrario eh so adicionar o pagamento
	this->pagamentosFuncionarios.push_back(new PagamentoFuncionario(pagamentoFuncionario));
}

bool Pagamentos::removerPagamentoFuncionario(long long cpf)//dado um cpf de um Funcionario remove sua lista de pagamentos
{
	if (pagamentosFuncionarios.empty())//se tiver vaio a lista de Funcionarios
	{
		return false;
	}

	//fazer a busca pelo cpf para remover

	for (auto it = pagamentosFuncionarios.begin(); it != pagamentosFuncionarios.end(); it++)
	{
		if ((**it).funcionario.getCpf() == cpf)//se achei o Funcionario a ser removido
		{
			delete (*it);
			pagamentosFuncionarios.erase(it);

			return true;
		}
	}

	return false;
}

PagamentoFuncionario& Pagamentos::retornarPagamentoFuncionario(long long cpf)//retorna os pagamentos de um Funcionario dada a sua posicao
{
	auto it = pagamentosFuncionarios.begin();
	for (; it != pagamentosFuncionarios.end(); it++)
	{
		if ((**it).funcionario.getCpf() == cpf)
		{

			return **it;
		}

	}

	return **it;///retorna ultimo caso nao encontre
}

PagamentoFuncionario& Pagamentos::retornarPagamentoFuncionario(int posicao)//retorna os pagamentos de um Funcionario dada a sua posicao
{
	int i = 0;

	auto it = pagamentosFuncionarios.begin();
	for (; it != pagamentosFuncionarios.end(); it++)
	{
		if (i == posicao - 1)
		{

			return **it;
		}
		i++;
	}

	return **it;///retorna ultimo caso nao encontre
}

//---------------------------Gastos Conta -----------------

void Pagamentos::adicionarPagamentoDeGastos(PagamentoDeGastos item)//adiciona os pagamentos de contas de maneira ordenada pela data de vencimento
{
	//inserir novos elementos
	PagamentoDeGastos* copia = new PagamentoDeGastos(item);

	list < PagamentoDeGastos*> ::iterator it = this->pagamentosDeGastos.begin();

	for (; it != this->pagamentosDeGastos.end(); it++)
	{
		if ((**it).dataDeVencimento > (*copia).dataDeVencimento)//se o ano a inserir for menor ja pode inserir
		{
			break;
		}

		else if ((*copia).dataDeVencimento > (**it).dataDeVencimento)//se for maior, pode continuar a iterar ate achar o ano
		{
			continue;
		}

		else//eh igual
		{
			break;
		}

	}

	this->pagamentosDeGastos.insert(it, copia);
}

bool Pagamentos::removerPagamentoDeGastos(int posicao)//dado uma posicao remove um item de pagamento de conta
{
	if (pagamentosDeGastos.empty() || posicao > pagamentosDeGastos.size() || posicao < 1)//se tiver vaio a lista de Funcionarios
	{
		return false;
	}

	//fazer a busca pelo item para remover

	int i = 0;
	for (auto it = pagamentosDeGastos.begin(); it != pagamentosDeGastos.end(); it++)
	{
		if (i == posicao - 1)
		{
			delete (*it);
			pagamentosDeGastos.erase(it);
			break;
		}
		i++;
	}

	return true;
}

PagamentoDeGastos& Pagamentos::retornarPagamentoDeGastos(int posicao)//dada uma posicao retorna um item de pagamento de conta
{
	int i = 0;

	auto it = pagamentosDeGastos.begin();
	for (; it != pagamentosDeGastos.end(); it++)
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

void Pagamentos:: mostrarPagamentosRealizados()//mostra todos os pagamentos realizados
{

	cout << "\t\tPagamentos dos Pacientes: " << "\n\n";

	if (pagamentosPacientes.empty())
	{
		cout << "Sem pagamentos de Pacientes" << endl << endl;
	}

	for (auto it = pagamentosPacientes.begin(); it != pagamentosPacientes.end(); it++)
	{
		cout << **it << endl << endl;
	}

	cout << "\t\tPagamentos dos Funcionarios: " << "\n\n";

	if (pagamentosFuncionarios.empty())
	{
		cout << "Sem pagamentos de Funcionarios" << endl << endl;
	}

	for (auto it = pagamentosFuncionarios.begin(); it != pagamentosFuncionarios.end(); it++)
	{
		cout << **it << endl << endl;
	}

	cout << "\t\tPagamentos de Contas: " << "\n\n";

	if (pagamentosDeGastos.empty())
	{
		cout << "Sem Pagamentos de Contas" << endl;
	}

	for (auto it = pagamentosDeGastos.begin(); it != pagamentosDeGastos.end(); it++)
	{
		cout << **it << endl << endl;
	}
}

bool Pagamentos::relatorioDePagamentosPacientes() //mostra todos os pagamentos realizados pelos pacientes
{
	int i = 1;

	if (pagamentosPacientes.empty())
	{
		cout << "Sem pagamentos de Pacientes" << endl << endl;

		return false;
	}

	cout << "\t\t\tPagamentos dos Pacientes: " << "\n\n";

	for (auto it = pagamentosPacientes.begin(); it != pagamentosPacientes.end(); it++)
	{
		cout << i << "-";
		cout << **it << endl << endl;
	}

	return true;
}

bool Pagamentos::relatorioDePagamentosFuncionarios()//mostra todos os gastos com funcionarios
{
	int i = 1;

	if (pagamentosFuncionarios.empty())
	{
		cout << "Sem pagamentos de Funcionarios" << endl << endl;
		return false;
	}

	cout << "\t\tPagamentos dos Funcionarios: " << "\n\n";

	for (auto it = pagamentosFuncionarios.begin(); it != pagamentosFuncionarios.end(); it++)
	{
		cout << i << "-";
		cout << **it << endl << endl;
		i++;
	}

	return true;
}

bool Pagamentos::relatorioDeGastos()//mostra todos osgastos com contas
{
	int i = 1;
	cout << "\t\tPagamentos de Contas: " << "\n\n";

	if (pagamentosDeGastos.empty())
	{
		cout << "Sem Pagamentos de Contas" << endl;

		return false;
	}

	for (auto it = pagamentosDeGastos.begin(); it != pagamentosDeGastos.end(); it++)
	{
		cout << "Item " << i << ":\n";
		cout << **it << endl << endl;

		i++;
	}

	return true;
}
//--------------------------------------------------------

void Pagamentos:: relatorioDePagamentosPacientesNoMes(int mes)//mostra todos os pagamentos realizados pelos pacientes em um mes
{
	if (pagamentosPacientes.empty())
	{
		cout << "Sem pagamentos de Pacientes";
		return;
	}

	if ( mes < 0 || mes > 12)
	{
		cout << "Mes incorreto" << endl << endl;
		return;
	}

	cout << "\t\tPagamentos dos Pacientes: " << "\n\n";

	for (auto it = pagamentosPacientes.begin(); it != pagamentosPacientes.end(); it++)
	{

		cout << "Paciente: " << (**it).paciente.getNome() << " CPF: " << (**it).paciente.getCpf() << "\n";
		(**it).imprimirItensPagosNoMes(mes);

		cout << endl;
	}
}

void Pagamentos::relatorioDePagamentosFuncionariosNoMes(int mes)//mostra todos os gastos com funcionarios em um mes
{
	if (pagamentosFuncionarios.empty())
	{
		cout << "Sem pagamentos dos Funcionarios !" << endl << endl;
		return;
	}

	if (mes < 0 || mes > 12)
	{
		cout << "Mes incorreto" << endl << endl;
		return;
	}

	cout << "\t\tPagamentos dos Funcionarios: " << "\n\n";

	for (auto it = pagamentosFuncionarios.begin(); it != pagamentosFuncionarios.end(); it++)
	{
		(**it).imprimirFolhaDePagamentoDoMes(mes);
	}
}

void Pagamentos::relatorioDeGastosNoMes(int mes)//dado um mes, imprime a folha de paagamento do funcionario naquele mes
{
	int i = 0;
	if (pagamentosDeGastos.empty())
	{
		cout << "Folha de Pagamento vazia !";
		return;
	}

	if ( mes < 0 || mes > 12)
	{
		cout << " Mes incorreto";
		return;
	}

	cout << "\t\tPagamentos de Contas: " << "\n\n";

	for (auto it = pagamentosDeGastos.begin(); it != pagamentosDeGastos.end(); it++)
	{

		if ((**it).dataDeVencimento.getMes() == mes)
		{
			i++;
			cout << "Pagamento " << i << ": " << (**it) << "\n";

		}
	}

}

//----------------------------------------------------

//sobrecarga do operador de atribuicao '=' 

Pagamentos& Pagamentos:: operator=(Pagamentos& pagamento)
{
	if (this == &pagamento)
	{
		return *this;
	}


	///destruir Pacientes
	for (auto item : this->pagamentosPacientes)
	{
		if (item != nullptr)
		{
			delete item;
		}
	}

	//destruir Funcionarios
	for (auto item : this->pagamentosFuncionarios)
	{
		if (item != nullptr)
		{
			delete item;
		}
	}

	//destruir Gastos
	for (auto item : this->pagamentosDeGastos)
	{
		if (item != nullptr)
		{
			delete item;
		}
	}

	//limpar a lista 
	this->pagamentosPacientes.clear();
	this->pagamentosFuncionarios.clear();
	this->pagamentosDeGastos.clear();

	//inserir novos elementos em cada lista

	for (auto it = pagamento.pagamentosPacientes.begin(); it != pagamento.pagamentosPacientes.end(); it++)
	{
		this->pagamentosPacientes.push_back(new PagamentoPaciente(**it));
	}

	for (auto it = pagamento.pagamentosFuncionarios.begin(); it != pagamento.pagamentosFuncionarios.end(); it++)
	{
		this->pagamentosFuncionarios.push_back(new PagamentoFuncionario(**it));
	}

	for (auto it = pagamento.pagamentosDeGastos.begin(); it != pagamento.pagamentosDeGastos.end(); it++)
	{
		this->pagamentosDeGastos.push_back(new PagamentoDeGastos(**it));
	}

	return *this;
}
