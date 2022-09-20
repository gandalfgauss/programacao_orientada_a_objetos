#include <iostream>
#include <stdlib.h>
#include "Clinica.h"
#include "UsuarioAdministrador.h"
#include "UsuarioAssistenteAdministrativo.h"
#include "UsuarioGeral.h"

using namespace std;

//como compilar tudo em uma linha: 
//g++ main.cpp Agenda.cpp Assistente.cpp Clinica.cpp Data.cpp DataHora.cpp Especialista.cpp ItemAgenda.cpp ItemFolhaDePonto.cpp ItemPagamentoFuncionario.cpp ItemPagamentoPaciente.cpp Paciente.cpp PagamentoDeGastos.cpp PagamentoFuncionario.cpp PagamentoPaciente.cpp Pagamentos.cpp Pessoa.cpp UsuarioAdministrador.cpp UsuarioAssistenteAdministrativo.cpp UsuarioGeral.cpp -Wall -o exec

//outra forma: g++ *.cpp -Wall -o exec

//como compilar:
//g++ main.cpp Agenda.cpp Assistente.cpp Clinica.cpp Data.cpp DataHora.cpp Especialista.cpp ItemAgenda.cpp 
//ItemFolhaDePonto.cpp ItemPagamentoFuncionario.cpp ItemPagamentoPaciente.cpp Paciente.cpp 
//PagamentoDeGastos.cpp PagamentoFuncionario.cpp PagamentoPaciente.cpp Pagamentos.cpp Pessoa.cpp 
//UsuarioAdministrador.cpp UsuarioAssistenteAdministrativo.cpp UsuarioGeral.cpp -Wall -o exec

//para logar : o usuario eh o 'nome'
//			   a senha eh o 'CPF'

int main()
{
	system("cls");

	Clinica clinica;
	string nomeDaClnica, usuario, senha;
	int opcaoSairLogin;
	int opcaoDeLogin;
	
	do
	{
		system("cls");
		cout << "\t\tBEM VINDO AO SISTEMA DE CADASTRO DA CLINICA\n\n";
		
		cout << "[0]-Sair\n[1]-Continuar\n\nDigite: ";
		lerValorCorretamente(opcaoSairLogin);
		

		switch (opcaoSairLogin)
		{
		case 0:
			return 0;
		case 1:
			break;
		default:
			cout << "\n\nDigite corretamente !\n\n";
			system("pause");

		}
	} while (opcaoSairLogin != 1);

	cout << "\nPara comecar digite o nome da sua Clinica: ";
	cin.ignore(500, '\n');
	getline(cin, nomeDaClnica);

	while (!clinica.setNomeDaClinica(nomeDaClnica))
	{
		cout << "\n\nDigite corretamente o nome da sua Clinica: ";
		getline(cin, nomeDaClnica);
	}

	
	do
	{
		do
		{
			system("cls");
			cout << "\t\tBEM VINDO A TELA DE LOGIN DA CLINICA " << clinica.getNomeDaClinica() << "\n\n";

			cout << "[0]-Sair\n[1]-Login\n\nDigite: ";
			lerValorCorretamente(opcaoSairLogin);//le corretamente um dado do tipo int, double e long long
			//eh uma funcao generica que trata a excecao invalid argument

			switch (opcaoSairLogin)
			{
			case 0:
				return 0;
			case 1:
				break;
			default:
				cout << "\n\nDigite corretamente !";
				system("pause");
			}
		} while (opcaoSairLogin != 1);//so sai do loop quando o usuario escolher login, ou seja, digitar '1', termina o programa ao digitar '0'
		
		cout << "\nDigite o nome do usuario: ";
		cin.ignore(500, '\n');
		getline(cin, usuario);

		cout << endl;

		cout << "\nDigite a senha: ";
		getline(cin, senha);

		opcaoDeLogin = clinica.login(usuario, senha);

		//1- Para Usuario Administrador (usuario: admin, senha: admin) - Acesso a todas funcionalidades
		//2- Para Usuario Assistente (Somente Recepcionista tem acesso) - Acesso a 5 funcionalidade 
		//(Agenda, Receber Consulta, Fazer pagamento de contas, Folha de Ponto e Pacientes
		//3- Para Usuario Geral- (Acesso por assistentes de especialistas e especiaista)- So tem acesso a Agenda
		//0 - se nao encontrar

		switch (opcaoDeLogin)
		{
		case 1:
			//Usuario administrador
			usuarioAdministrador(clinica);
			
			break;

		case 2:
			//Usuario Assistente Administrativo
			usuarioAssistenteAdministrativo(clinica);
			break;
		case 3:
			//usuario geral
			usuarioGeral(clinica);
			break;

		case 0:
			//nao existe
			cout << "\nLogin e senha incorretos !\n\n";
			system("pause");

		}

	} while (true);//enquanto nao conseguir logar vai repetir esse loop, 
	//so eh possivel sair do loop digitando '0' dentro do loop mais interno

	return 0;
}