#ifndef PAGAMENTOS_H
#define PAGAMENTOS_H

#include <iostream>
#include <list>
#include "PagamentoPaciente.h"
#include "PagamentoFuncionario.h"
#include "PagamentoDeGastos.h"

using namespace std;

class Pagamentos
{
public:
	
	list<PagamentoPaciente*> pagamentosPacientes;
	list<PagamentoFuncionario*> pagamentosFuncionarios;
	list<PagamentoDeGastos*> pagamentosDeGastos;


	//construtores e destrutor
	Pagamentos();
	Pagamentos(Pagamentos&);
	~Pagamentos();

	void adicionarPagamentoPaciente(PagamentoPaciente);//adiciona os pagamentos de um paciente
	bool removerPagamentoPaciente(long long cpf);//dado um cpf de um Paciente remove sua lista de pagamentos
	PagamentoPaciente& retornarPagamentoPaciente(long long cpf);//retorna os pagamentos de um paciente dado o cpf
	PagamentoPaciente& retornarPagamentoPaciente(int posicao);//retorna os pagamentos de um paciente dada a posicao

	void adicionarPagamentoFuncionario(PagamentoFuncionario);//adiciona os pagamentos de um funcionario
	bool removerPagamentoFuncionario(long long cpf);//dado um cpf de um Funcionario remove sua lista de pagamentos
	PagamentoFuncionario& retornarPagamentoFuncionario(long long cpf);//retorna os pagamentos de um paciente dada um cpf
	PagamentoFuncionario& retornarPagamentoFuncionario(int posicao);//retorna os pagamentos de um paciente dada a posicao

	void adicionarPagamentoDeGastos(PagamentoDeGastos);//adiciona os pagamentos de contas de maneira ordenada pela data de vencimento
	bool removerPagamentoDeGastos(int posicao);//dado uma posicao remove um item de pagamento de conta
	PagamentoDeGastos& retornarPagamentoDeGastos(int posicao);//dada uma posicao retorna um item de pagamento de conta

	void mostrarPagamentosRealizados();//mostra todos os pagamentos realizados
	bool relatorioDePagamentosPacientes();//mostra todos os pagamentos realizados pelos pacientes
	bool relatorioDePagamentosFuncionarios();//mostra todos os gastos com funcionarios
	bool relatorioDeGastos();//mostra todos osgastos com contas

	void relatorioDePagamentosPacientesNoMes(int mes);//mostra todos os pagamentos realizados pelos pacientes em um mes
	void relatorioDePagamentosFuncionariosNoMes(int mes);//mostra todos os gastos com funcionarios em um mes
	void relatorioDeGastosNoMes(int mes);//mostra todos osgastos com contas em um mes



	//sobrecarga do operador de atribuicao '=' 
	Pagamentos& operator=(Pagamentos&);

};

#endif // !Pagamentos_H
