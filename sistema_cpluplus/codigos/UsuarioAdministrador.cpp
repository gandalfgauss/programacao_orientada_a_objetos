#include "UsuarioAdministrador.h"


//para acessar: usuario-> admin
//				  senha-> admin
void usuarioAdministrador(Clinica& clinica)
{
	int opcaoEntraOuSai;

	do
	{
		system("cls");
		cout << "\t\tBEM VINDO AO MENU DA CLINICA " << clinica.getNomeDaClinica() << "\n\n";
		
		cout << "[0]-Sair\n[1]-Agenda\n[2]-Receber Consulta\n[3]-Fazer Pagamento de Contas\n[4]-Folha de Ponto\n[5]-Pagar Salario\n"
			<<"[6]-Gerar Relatorio\n[7]-Pacientes\n[8]-Funcionarios\n[9]-Especialistas\n"
			<<"[10]-Recepcionista\n[11]-Pagamentos\n\nDigite: ";
		lerValorCorretamente(opcaoEntraOuSai);

		switch (opcaoEntraOuSai)
		{
		case 0:
			return;

		case 1:
			//Agenda
			agenda(clinica);

			break;
		case 2:
			//receber Consulta de um paciente
			receberConsulta(clinica);
			break;

		case 3:
			//fazer pagamento de contas
			pagamentoDeContas(clinica);

			break;

		case 4:
			//folha de ponto
			folhaDePonto(clinica);

			break;
		case 5:
			//pagar salario
			pagarSalario(clinica);

			break;

		case 6:
			//gerar relatorio
			geraRelatorio(clinica);
			break;

		case 7:
			//manipula os pacientes da clinica
			manipularPaciente(clinica);
			break;

		case 8:
			//manipula funcionarios
			manipularFuncionario(clinica);

			break;

		case 9:
			//manipula especialistas
			manipularEspecialista(clinica);

			break;

		case 10:
			//manipula recepcionista
			manipularRecepcionista(clinica);
			break;

		case 11:
			//manipular pagamentos nao maniulados ate entao, remover pagamento especifico de paciente ou todos os pagamentos
			//remover pagamento especifico de funcionario ou todos os pagamentos
			manipularPagamentos(clinica);
			break;
		default:
			//opcao incorreta

			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
}


template<typename T>
void lerValorCorretamente(T& valor)//le um inteiro, double ou long long corretamente, ou seja, trata a excecao invalid argument
{
	//repete o loop ate digitar o tipo de dado corretamente
	while (true)
	{
		try
		{
			if (!(cin >> valor))
			{
				throw invalid_argument("\n\nDigite corretamente: ");
			}
		}
		catch (invalid_argument& e)
		{
			cout << "\nErro: " << e.what();
			cin.clear();
			cin.ignore(500, '\n');
			continue;
		}
		break;

	}
}




//-------------------------------Agenda---------------------
//Menu contendos os nomes dos ortodontistas para o usuario possa escolher
//ver agenda do ortodentista escolhido
//ao escolher pode ter a opcao de editar, remover e adicionar

void agenda(Clinica& clinica)//manipula as agendas dos especilistas
{
	int posicao;
	Especialista* especialista;

	//conferir se tem especialista
	if (clinica.especialistas.empty())
	{
		system("cls");
		cout << "\nNao existe especialistas cadastrados !\n\n";
		system("pause");
		return;
	}

	do
	{

		system("cls");
		cout << "\t\tBEM VINDO A AGENDA DA CLINICA " << clinica.getNomeDaClinica() << "\n\n";
		clinica.imprimirNomeDosEspecialistas();
		cout << "\n[0]-Para Sair\nDigite o numero do Especialista a ser escolhido: ";
		lerValorCorretamente(posicao);
		
		if (posicao == 0)
		{
			return;
		}
		else if (posicao > clinica.especialistas.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		//retorna especialista
		especialista = &clinica.retornarEspecialista(posicao);

		//loop imprimindo agenda do especialista e pedindo pra editar, remover e adicionar item
		agendaEspecialista(clinica, especialista);

	} while (true);
}

void agendaEspecialista(Clinica& clinica, Especialista* especialista)//manipula a agendas de um especilista
{
	int opcaoEntraOuSai;

	do
	{
		system("cls");
		cout << "\t\tBEM VINDO A AGENDA DO(A) ESPECIALISTA " << especialista->getNome() << "\n\n";

		cout << endl << endl;
		especialista->imprimirAgenda();//se estiver vazia imprime agenda vazia
		cout << endl << endl;

		cout << "[0]-Sair\n[1]-Adicionar Item\n[2]-Editar Item\n[3]-Remover Item\n\nDigite: ";
		lerValorCorretamente(opcaoEntraOuSai);

		switch (opcaoEntraOuSai)
		{
		case 0:
			return;
			break;
		case 1:
			//adicionar item da agenda
			adicionarItemAgendaEspecialista(clinica, &especialista->agenda);
			break;

		case 2:
			//editar item agenda
			editarItemAgendaEspecialista(clinica, &especialista->agenda);
			break;

		case 3:
			//remover item agenda
			removerItemAgendaEspecialista(clinica, &especialista->agenda);
			break;


		default:
			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}
		


	} while (true);
}

void adicionarItemAgendaEspecialista(Clinica& clinica, Agenda* agenda)//adiciona um item na agenda de Especialista
{
	system("cls");
	//tem que ter paciente cadastrado para adicionar um item na agenda
	int posicao;
	string descricao;

	ItemAgenda itemAgenda;

	if (clinica.pacientes.empty())
	{
		cout << "\nCadastre um Paciente antes de adicionar um item da agenda ! \n\n";
		system("pause");
		return;
	}

	//caso tenha pacientes deve selecionar um para adicionar na agenda

	do
	{
		system("cls");
		
		clinica.imprimirPacientes();
		
		cout << "\n[0]-Para Sair\nDigite o numero do Paciente a ser escolhido: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}
		else if (posicao > clinica.pacientes.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		itemAgenda.paciente = clinica.retornarPaciente(posicao);
		lerDataHora(&itemAgenda.data);


		cout << "\nDigite a descricao da consulta: ";
		cin.ignore(500, '\n');
		getline(cin, descricao);
		itemAgenda.setDescricao(descricao);

		agenda->adicionarItemAgenda(itemAgenda);//adicionar item agenda
		break;

	} while (true);

}

void lerDataHora(DataHora* data)//ler data hora da agenda
{
	int dia, mes, ano, hora, minuto;
	do
	{
		cout << "\nDigite o dia do proposito: ";
		lerValorCorretamente(dia);

		cout << "\nDigite o mes do proposito: ";
		lerValorCorretamente(mes);

		cout << "\nDigite o ano do proposito: ";
		lerValorCorretamente(ano);

		cout << "\nDigite a hora do proposito: ";
		lerValorCorretamente(hora);

		cout << "\nDigite o minuto do proposito: ";
		lerValorCorretamente(minuto);

		//confere se os valores digitados da data sao validos
		if (((data->setDia(dia)) && (data->setMes(mes)) && (data->setAno(ano)) && (data->setHora(hora)) && (data->setMinuto(minuto))))//se conseguir inserir corretamente a data pode sair do loop
		{
			break;
		}

		cout << "\nDigite corretamente a data\n\n !";
		system("pause");

	} while (true);//enquanto nao conseguir inserir corretamente
}



void lerData(Data* data)//le uma data e a retorna
{
	int dia, mes, ano;
	do
	{
		cout << "\nDigite o dia do proposito: ";
		lerValorCorretamente(dia);

		cout << "\nDigite o mes do proposito: ";
		lerValorCorretamente(mes);

		cout << "\nDigite o ano do proposito: ";
		lerValorCorretamente(ano);

		//confere se os valor digitados da data sao validos
		if (((data->setDia(dia)) && (data->setMes(mes)) && (data->setAno(ano))))//se conseguir inserir corretamente a data pode sair do loop
		{
			break;
		}

		cout << "\nDigite corretamente a data\n\n !";
		system("pause");

			
	} while (true);//enquanto nao conseguir inserir corretamente

}

void removerItemAgendaEspecialista(Clinica& clinica, Agenda* agenda)//remove um item na agenda de Especialista
{
	int posicao;
	do
	{
		system("cls");
		if (agenda->itensDaAgenda.empty())//se agenda estiver vazia nao ha o que remover
		{
			cout << "\nAgenda vazia\n\n !";
			system("pause");
			return;
		}

		cout << *agenda;
		cout << "\n[0]-Para Sair\nDigite o numero do Item a ser removido: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}

		else if (posicao > agenda->itensDaAgenda.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		agenda->removerItemAgenda(posicao);
		break;
	} while (true);
}

void editarItemAgendaEspecialista(Clinica& clinica, Agenda* agenda)//edita um item na agenda de Especialista
{
	system("cls");
	int posicao;
	if (agenda->itensDaAgenda.empty())//Agenda vazia nao ha o que editar 
	{
		cout << "\nAgenda vazia\n\n !";
		system("pause");
		return;
	}

	do
	{
		system("cls");
		cout << *agenda;
		cout << "\n[0]-Para Sair\nDigite o numero do Item a ser Editado: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}
		else if (posicao > agenda->itensDaAgenda.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		//funcao que edita o item
		editarItemAgenda(clinica, &agenda->retornarItemAgenda(posicao));
		break;

	} while (true);
}

void editarItemAgenda(Clinica& clinica, ItemAgenda* itemAgenda)//edita um item da agenda
{

	string descricao;

	int opcao;
	do
	{
		system("cls");
		cout << "Item:\n" << *itemAgenda;//imprime o item a ser editado na tela
		cout << "\n\n[0]-Sair\n[1]-Editar Data\n[2]-Editar Descricao\n[3]-Trocar Paciente\n\nDigite: ";
		lerValorCorretamente(opcao);

		switch (opcao)
		{

		case 0:
			return;
			break;

		case 1:
			//funcao que edita data
			editaDataHora(&itemAgenda->data);
			break;

		case 2:
			//edita descricao
			cout << "\nDigite a nova Descricao: ";
			cin.ignore(500, '\n');
			getline(cin, descricao);
			if (!itemAgenda->setDescricao(descricao))
			{
				cout << "\nDigite corretamente a Descricao\n\n !";
				system("pause");
			}
			break;
		case 3:
			//trocar paciente
			trocarPacienteItemAgenda(clinica, itemAgenda);
			break;
		default:
			//opcao incorreta

			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
	
}

void editaDataHora(DataHora* data)//funcao que edita data hora
{

	int opcao;
	int dia;
	int mes;
	int ano;
	int hora;
	int minuto;

	do
	{
		system("cls");
		cout << *data;
		cout << "\n\n[0]-Sair\n[1]-Editar Dia\n[2]-Editar Mes\n[3]-Editar Ano\n[4]-Editar Hora\n[5]-Editar Minuto\n\nDigite: ";
		lerValorCorretamente(opcao);

		switch (opcao)
		{

		case 0://zero sai do loop
			return;
			break;

		case 1:
			//editar dia
			cout << "\nDigite o novo dia: ";
			lerValorCorretamente(dia);
			if (!data->setDia(dia))
			{
				cout << "\nDigite corretamente o dia\n\n !";
				system("pause");
			}
			break;

		case 2:
			//editar mes
			cout << "\nDigite o novo mes: ";
			lerValorCorretamente(mes);
			if (!data->setMes(mes))
			{
				cout << "\nDigite corretamente o mes\n\n !";
				system("pause");
			}
			break;

		case 3:
			// editar ano
			cout << "\nDigite o novo ano: ";
			lerValorCorretamente(ano);
			if (!data->setAno(ano))
			{
				cout << "\nDigite corretamente o ano\n\n !";
				system("pause");
			}
			break;
		case 4:
			// editar hora
			cout << "\nDigite a nova hora: ";
			lerValorCorretamente(hora);
			if (!data->setHora(hora))
			{
				cout << "\nDigite corretamente a hora\n\n !";
				system("pause");
			}
			break;

		case 5:
			// editar minuto
			cout << "\nDigite o novo minuto: ";
			lerValorCorretamente(minuto);
			if (!data->setMinuto(minuto))
			{
				cout << "\nDigite corretamente o minuto\n\n !";
				system("pause");
			}
			break;

		default:
			//opcao incorreta

			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);

}

void editaData(Data* data)//funcao que edita data
{

	int opcao;
	int dia;
	int mes;
	int ano;

	do
	{
		system("cls");
		cout << *data;
		cout << "\n\n[0]-Sair\n[1]-Editar Dia\n[2]-Editar Mes\n[3]-Editar Ano\n\nDigite: ";
		lerValorCorretamente(opcao);

		switch (opcao)
		{

		case 0://zero sai do loop
			return;
			break;

		case 1:
			//editar dia
			cout << "\nDigite o novo dia: ";
			lerValorCorretamente(dia);
			if (!data->setDia(dia))
			{
				cout << "\nDigite corretamente o dia\n\n !";
				system("pause");
			}
			break;

		case 2:
			//editar mes
			cout << "\nDigite o novo mes: ";
			lerValorCorretamente(mes);
			if (!data->setMes(mes))
			{
				cout << "\nDigite corretamente o mes\n\n !";
				system("pause");
			}
			break;

		case 3:
			// editar ano
			cout << "\nDigite o novo ano: ";
			lerValorCorretamente(ano);
			if (!data->setAno(ano))
			{
				cout << "\nDigite corretamente o ano\n\n !";
				system("pause");
			}
			break;

		default:
			//opcao incorreta

			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);

}

void trocarPacienteItemAgenda(Clinica& clinica, ItemAgenda* itemAgenda)//troca um paciente de um Item da Agenda por outro paciente
{

	system("cls");
	
	int posicao;
	string descricao;

	//tem que ter paciente cadastrado para trocar
	if (clinica.pacientes.empty())
	{
		cout << "\nSem Pacientes Cadastrados ! \n\n";
		system("pause");
		return;
	}

	//caso tenha pacientes deve selecionar um para adicionar na agenda

	do
	{
		system("cls");

		cout << itemAgenda->paciente << endl << endl;

		clinica.imprimirPacientes();//imprime os pacientes

		cout << "\n[0]-Para Sair\nDigite o numero do Paciente a ser escolhido: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}
		else if (posicao > clinica.pacientes.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		//troca o paciente
		itemAgenda->paciente = clinica.retornarPaciente(posicao);

		break;

	} while (true);

}

//----------------------------Fim da Agenda-----------------------------



//------------------Receber Consulta --------------

void receberConsulta(Clinica& clinica)//recebe uma consulta do paciente
{
	int posicao;
	Paciente* paciente;
	PagamentoPaciente pagamentoPaciente;
	PagamentoPaciente impresso;

	//conferir se tem pacientes para receber
	if (clinica.pacientes.empty())
	{
		system("cls");
		cout << "\nNao existe pacientes cadastrados !\n\n";
		system("pause");
		return;
	}

	do
	{
		system("cls");
		cout << "\t\tBEM VINDO AO RECEBIMENTO DE CONSULTA DA CLINICA " << clinica.getNomeDaClinica() << "\n\n";
		clinica.imprimirPacientes();
		cout << "\n[0]-Para Sair\nDigite o numero do Paciente a ser escolhido: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}
		else if (posicao > clinica.pacientes.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		//retorna paciente
		paciente = &clinica.retornarPaciente(posicao);

		//atualizar cadastro
		editaPaciente(paciente);

		pagamentoPaciente.paciente = *paciente;

		pagamentoDoPaciente(clinica, &pagamentoPaciente);//adiciona os detalhes do pagamento do cliente
		
		//adicionar nos pagamentos do paciente da clinica
		clinica.pagamentos.adicionarPagamentoPaciente(pagamentoPaciente);

		system("cls");
		//imprimir pagamentos daquele paciente
		impresso = clinica.pagamentos.retornarPagamentoPaciente(pagamentoPaciente.paciente.getCpf());

		cout << endl << endl;
		cout << impresso << endl << endl;

		system("pause");

		break;

	} while (true);
}

void pagamentoDoPaciente(Clinica& clinica, PagamentoPaciente* pagamentoPaciente)//adiciona os detalhes do pagamento do cliente
{
	
	char opcao;
	double valor;
	string descricao;
	ItemPagamentoPaciente itemPagamentoPaciente;
	
	system("cls");

	lerData(&itemPagamentoPaciente.dataDePagamento);//ler data

	//ler nome do pagamento
	cout << "\n\nDigite o Nome do Pagamento: ";
	cin.ignore(500, '\n');
	getline(cin, descricao);
	itemPagamentoPaciente.setNomeDoPagamento(descricao);


	//ler valor pago
	do
	{
		
		cout << "\n\nDigite o valor pago pelo Paciente: ";
		lerValorCorretamente(valor);

		cout << "\nO valor a ser pago eh " << valor;
		cout << "\nConfirmar [s]-Sim   [n]-Nao, editar: ";
		lerValorCorretamente(opcao);

		if (opcao == 'n')//se for nao ('n') eh so repetir o loop, caso contrario continua o loop normalmente
		{
			system("cls");
			continue;
		}

		if (valor < 0.0)
		{
			cout << "\nErro no Pagamento\n\n";
			system("pause");

			system("cls");
			continue;	
		}

		cout << "\nPagamento Confirmado\n\n!";
		system("pause");

		break;
	} while(true);

	itemPagamentoPaciente.setValorPago(valor);//adiciona valor pago

	pagamentoPaciente->adicionarItemPagamentoPaciente(itemPagamentoPaciente);//adicionar item de pagamento do paciente
	

}

void editaPaciente(Paciente* paciente)//funcao que edita paciente/ atualiza dados
{
	int opcao;
	string nome, endereco;
	long long cpf, telefone;

	do
	{
		system("cls");
		cout << *paciente;
		cout << "\n\n[0]-Sair\n[1]-Editar Nome\n[2]-Editar Endereco\n[3]-Editar CPF\n[4]-Editar Telefone\n\nDigite: ";
		lerValorCorretamente(opcao);

		switch (opcao)
		{

		case 0://sai do loop
			return;
			break;

		case 1:
			//editar nome
			cout << "\nDigite o novo Nome: ";
			cin.ignore(500, '\n');
			getline(cin, nome);
			if (!paciente->setNome(nome))
			{
				cout << "\nDigite corretamente o Nome\n\n !";
				system("pause");
			}
			break;

		case 2:
			//editar endereco
			cout << "\nDigite o novo Endereco: ";
			cin.ignore(500, '\n');
			getline(cin, endereco);
			if (!paciente->setEndereco(endereco))
			{
				cout << "\nDigite corretamente o Endereco\n\n !";
				system("pause");
			}
			break;

		case 3:
			// editar cpf
			cout << "\nDigite o novo CPF: ";
			lerValorCorretamente(cpf);
			if (!paciente->setCpf(cpf))
			{
				cout << "\nDigite corretamente o cpf\n\n !";
				system("pause");
			}
			break;

		case 4:
			// editar telefone
			cout << "\nDigite o novo Telefone: ";
			lerValorCorretamente(telefone);
			if (!paciente->setTelefone(telefone))
			{
				cout << "\nDigite corretamente o Telefone\n\n !";
				system("pause");
			}
			break;

		default:
			//opcao incorreta

			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
}

//------------------Fim do Receber Consulta----------------------------




//------------------Fazer Pagamento de Contas --------------

void pagamentoDeContas(Clinica& clinica)//matem controle dos gastos da clinica
{
	int opcao;

	do
	{
		system("cls");
		cout << "\t\tBEM VINDO AO PAGAMENTO DE CONTAS DA CLINICA " << clinica.getNomeDaClinica() << "\n\n";
		
		cout << "\n\n[0]-Sair\n[1]-Adicionar Conta\n[2]-Remover Conta\n[3]-Editar Conta\n\nDigite: ";
		lerValorCorretamente(opcao);

		switch (opcao)
		{

		case 0://sai do loop
			return;
			break;

		case 1:
			//adicionar conta
			adicionarPagamentoDeContas(clinica);

			break;

		case 2:
			//remover conta
			removerPagamentoDeContas(clinica);

			break;

		case 3:
			// editar conta
			editarPagamentoDeContas(clinica);

			break;

		default:
			//opcao incorreta

			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
}

void adicionarPagamentoDeContas(Clinica& clinica)//adicionar um pagamento de conta
{

	PagamentoDeGastos pagamentoDeGastos;

	Data dataDePagamento;
	Data dataDeVencimento;
	double valorPago;
	string descricao;

	system("cls");

	//ler data de pagamento
	cout << "Data de Pagamento: ";
	lerData(&dataDePagamento);

	pagamentoDeGastos.dataDePagamento = dataDePagamento;

	//ler data de vencimento
	cout << "\n\nData de Vencimento: ";
	lerData(&dataDeVencimento);

	pagamentoDeGastos.dataDeVencimento = dataDeVencimento;

	//ler valor pago
	do
	{
		cout << "\n\nDigite o valor da Conta: ";
		lerValorCorretamente(valorPago);

		if (!pagamentoDeGastos.setValorPago(valorPago))
		{
			cout << "\nDigite corretamente o valor !\n\n";
			system("pause");
			continue;
		}

		break;
	} while (true);

	//ler descricao
	cout << "\nDigite a descricao da conta: ";
	cin.ignore(500, '\n');
	getline(cin, descricao);

	while (!pagamentoDeGastos.setDescricao(descricao))
	{
		cout << "\nDigite a descricao da conta: ";
		getline(cin, descricao);
	}
	

	//agora eh so adicionar o pagamento na lista de pagamentos
	clinica.pagamentos.adicionarPagamentoDeGastos(pagamentoDeGastos);
	
}

void removerPagamentoDeContas(Clinica& clinica)//dada uma posicao remover um pagamento da conta
{
	int posicao;
	do
	{
		system("cls");
		//confere se existe pagamentos a remover
		if (clinica.pagamentos.pagamentosDeGastos.empty())
		{
			cout << "\nSem Pagamentos De Contas\n\n !";
			system("pause");
			return;
		}

		//imprimir pagamentos
		clinica.pagamentos.relatorioDeGastos();

		cout << "\n[0]-Para Sair\nDigite o numero do Item a ser removido: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}

		else if (posicao > clinica.pagamentos.pagamentosDeGastos.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		clinica.pagamentos.removerPagamentoDeGastos(posicao);//remove o pagamento daquela posicao
		break;
	} while (true);
}

void editarPagamentoDeContas(Clinica& clinica)//edita um pagamento de conta
{
	int posicao;

	do
	{
		system("cls");
		//confere se existe pagamentos a editar
		if (clinica.pagamentos.pagamentosDeGastos.empty())
		{
			cout << "\nSem Pagamentos De Contas\n\n !";
			system("pause");
			return;
		}

		//imprimir pagamentos
		clinica.pagamentos.relatorioDeGastos();

		cout << "\n[0]-Para Sair\nDigite o numero do Item a ser editado: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}

		else if (posicao > clinica.pagamentos.pagamentosDeGastos.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		editarItensPagamentosDeContas(clinica, &clinica.pagamentos.retornarPagamentoDeGastos(posicao));//edita um item do pagamento de contas
		break;
	} while (true);
}

void editarItensPagamentosDeContas(Clinica& clinica, PagamentoDeGastos* pagamentoDeGastos)//edita um item do pagamento de conta
{
	double valorPago;
	string descricao;

	int opcao;
	do
	{
		system("cls");
		cout << "Item:\n" << *pagamentoDeGastos;//imprime o item
		cout << "\n\n[0]-Sair\n[1]-Editar Data de Vencimento\n[2]-Editar Data de Pagamento\n[3]-Editar Valor Pago\n[4]-Editar Descricao\n\nDigite: ";
		lerValorCorretamente(opcao);

		switch (opcao)
		{

		case 0://sai do loop
			return;
			break;

		case 1:
			//funcao que edita data de vencimento
			editaData(&pagamentoDeGastos->dataDeVencimento);
			break;

		case 2:
			//funcao que edita a data de pagamento
			editaData(&pagamentoDeGastos->dataDePagamento);
			break;
		case 3:
			//editar valor pago
			cout << "\n\nDigite o valor da Conta: ";
			lerValorCorretamente(valorPago);

			if (!pagamentoDeGastos->setValorPago(valorPago))
			{
				cout << "\nDigite corretamente o valor !\n\n";
				system("pause");
			}

			break;

		case 4:

			//edita descricao
			cout << "\nDigite a nova Descricao: ";
			cin.ignore(500, '\n');
			getline(cin, descricao);
			if (pagamentoDeGastos->setDescricao(descricao))
			{
				cout << "\nDigite corretamente a Descricao\n\n !";
				system("pause");
			}
			break;
		default:
			//opcao incorreta

			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
}
//------------------Fim Fazer Pagamento de Contas --------------



//------------------ Folha de Ponto ----------------

void folhaDePonto(Clinica& clinica)//controla a folha de ponto dos funcionarios(assistentes)
{
	int posicao;
	Assistente* assistente;

	//conferir se tem funcionarios
	if (clinica.assistentes.empty())
	{
		system("cls");
		cout << "\nNao existe Funcionarios cadastrados !\n\n";
		system("pause");
		return;
	}

	//caso tenha funcionarios  eh so impprimir a lista de funcionarios e escolher qual funcionario deseja ver editar ou remover itens da folha de ponto
	do
	{

		system("cls");
		cout << "\t\tBEM VINDO A FOLHA DE PONTO DA CLINICA " << clinica.getNomeDaClinica() << "\n\n";
		clinica.imprimirNomeDosFuncionarios();//imprime a lista de funcionarios

		cout << "\n[0]-Para Sair\nDigite o numero do Funcionario a ser escolhido: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}
		else if (posicao > clinica.assistentes.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		//retorna funcionario
		assistente = &clinica.retornarAssistente(posicao);

		//loop imprimindoa folha de ponto do funcionario e pedindo pra editar, remover e adicionar item
		folhaDePontoAssistente(clinica, assistente);

	} while (true);
}

void folhaDePontoAssistente(Clinica& clinica, Assistente* assistente) //controla a folha de ponto de um funcionario
{
	int opcaoEntraOuSai;

	do
	{
		system("cls");
		cout << "\t\tBEM VINDO A FOLHA DE PONTO DO(A) FUNCIONARIO(A): " << assistente->getNome() << "\n\n";

		//imprimir folha de ponto do funcionario(assistente)
		cout << endl << endl;
		assistente->imprimirFolhaDePonto();//se estiver vazia imprime folha de ponto vazia
		cout << endl << endl;

		cout << "[0]-Sair\n[1]-Adicionar Item\n[2]-Remover Item\n[3]-Editar Item\n\nDigite: ";
		lerValorCorretamente(opcaoEntraOuSai);

		switch (opcaoEntraOuSai)
		{
		case 0://sai do loop
			return;
			break;
		case 1:
			//adicionar item folha de ponto
			adicionarItemFolhaDePonto(clinica, assistente);
			break;

		case 2:
			//remover item folha de ponto
			removerItemFolhaDePonto(clinica, assistente);
			break;

		case 3:
			//editar item folha de ponto
			editarFolhaDePonto(clinica, assistente);

			break;


		default:
			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
}

void adicionarItemFolhaDePonto(Clinica& clinica, Assistente* assistente)//adiciona um item na follha de ponto do funcionario
{
	system("cls");

	string descricao;

	ItemFolhaDePonto itemFolhaDePonto;

	//adicionar
	do
	{
		system("cls");

		//ler a data
		cout << "\nDigite a data: ";
		lerData(&itemFolhaDePonto.data);

		//ler  observacao
		cout << "\nDigite a Observacao da folha de ponto: ";
		cin.ignore(500, '\n');
		getline(cin, descricao);

		while (!itemFolhaDePonto.setObservacao(descricao))
		{
			cout << "\nDigite a Observacao : ";
			getline(cin, descricao);
		}

		assistente->adicionarItemFolhaDePonto(itemFolhaDePonto);
		break;

	} while (true);
}

void removerItemFolhaDePonto(Clinica& clinica, Assistente* assistente)//remove um item na follha de ponto do funcionario
{
	int posicao;
	do
	{
		system("cls");
		if (assistente->folhaDePonto.empty())//verificar se tem itens a ser removidos
		{
			cout << "\nFolha de Ponto vazia\n\n !";
			system("pause");
			return;
		}

		assistente->imprimirFolhaDePonto();//imprime folha de ponto do funcionario
		cout << "\n[0]-Para Sair\nDigite o numero do Item a ser removido: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}

		else if (posicao > assistente->folhaDePonto.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		assistente->removerItemFolhaDePonto(posicao);//remove o item da folha de ponto da posicao escolhida
		break;
	} while (true);
}



void editarFolhaDePonto(Clinica& clinica, Assistente* assistente)//edita um item na follha de ponto do funcionario
{
	system("cls");
	int posicao;
	if (assistente->folhaDePonto.empty())//folha de ponto vazia nao ha o que editar 
	{
		cout << "\nFolha de Ponto vazia\n\n !";
		system("pause");
		return;
	}

	do
	{
		system("cls");
		assistente->imprimirFolhaDePonto();//imprime folha de ponto
		cout << "\n[0]-Para Sair\nDigite o numero do Item a ser Editado: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}
		else if (posicao > assistente->folhaDePonto.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		//funcao que edita o item
		editarItemFolhaDePonto(clinica, &assistente->retornarItemFolhaDePonto(posicao));
		break;

	} while (true);
}



void editarItemFolhaDePonto(Clinica& clinica, ItemFolhaDePonto* itemFolhaDePonto)//edita um item da folha de ponto de um funcionario
{
	string descricao;

	int opcao;
	do
	{
		system("cls");
		cout << "Item:\n" << *itemFolhaDePonto;//imprime o item a ser editado
		cout << "\n\n[0]-Sair\n[1]-Editar Data\n[2]-Editar Descricao\n\nDigite: ";
		lerValorCorretamente(opcao);

		switch (opcao)
		{

		case 0://sai do loop
			return;
			break;

		case 1:
			//funcao que edita data
			editaData(&itemFolhaDePonto->data);
			break;

		case 2:
			//edita descricao
			cout << "\nDigite a nova Descricao: ";
			cin.ignore(500, '\n');
			getline(cin, descricao);
			if (!itemFolhaDePonto->setObservacao(descricao))
			{
				cout << "\nDigite corretamente a Descricao\n\n !";
				system("pause");
			}
			break;
		default:
			//opcao incorreta

			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
}

//------------------Fim de Folha de Ponto --------------



//------------------ Pagar Salario ----------------

void pagarSalario(Clinica& clinica)//realiza um pagamento de funcionario mostrando folha de ponto
{
	int posicao;
	Assistente* assistente;

	//conferir se tem funcionarios
	if (clinica.assistentes.empty())
	{
		system("cls");
		cout << "\nNao existe Funcionarios cadastrados !\n\n";
		system("pause");
		return;
	}

	do
	{

		system("cls");
		cout << "\t\tBEM VINDO AO PAGAMENTO DE SALARIO " << clinica.getNomeDaClinica() << "\n\n";
		clinica.imprimirNomeDosFuncionarios();//imprime funcionarios

		cout << "\n[0]-Para Sair\nDigite o numero do Funcionario a ser escolhido: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}
		else if (posicao > clinica.assistentes.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		//retorna funcionario
		assistente = &clinica.retornarAssistente(posicao);

		//loop que pede para o usuario escolher em entre ver folha de ponto do funcionario ou realizar paagamento
		pagarSalarioParte2(clinica, assistente);

	} while (true);
}

void pagarSalarioParte2(Clinica& clinica, Assistente* assistente)//menu com escolha para ver folha de ponto ou pagar salario
{
	int opcaoEntraOuSai;
	int mes;

	do
	{
		system("cls");
		cout << "\t\tBEM VINDO A AREA DE PAGAMENTO DO(A) FUNCIONARIO(A): " << assistente->getNome() << "\n\n";

		
		cout << "[0]-Sair\n[1]-Folha de Ponto\n[2]-Efetuar Pagamento\n\nDigite: ";
		lerValorCorretamente(opcaoEntraOuSai);

		switch (opcaoEntraOuSai)
		{
		case 0://sai do loop
			return;
			break;
		case 1:
			
			cout << endl << endl;
			cout << "\nDigite o mes: ";
			lerValorCorretamente(mes);
			cout << endl << endl;

			//mostra folha de ponto do mes
			//se estiver vazia imprime folha de ponto vazia, e se mes tiver incorreto imprime mes incorreto
			assistente->imprimirFolhaDePontoDoMes(mes);

			cout << endl << endl;

			system("pause");
			
			break;

		case 2:
			//efetuar pagamento
			efetuarPagamentoFuncionario(clinica, assistente);
			break;

		default:
			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
}

void efetuarPagamentoFuncionario(Clinica& clinica, Assistente* assistente)//efetua o pagamento de um funcionario
{
	
	char opcao;
	double valor;
	string descricao;
	ItemPagamentoFuncionario itemPagamentoFuncionario;
	PagamentoFuncionario pagamentoFuncionario;
	
	system("cls");

	lerData(&itemPagamentoFuncionario.dataDePagamento);//ler data

	//ler descricao do pagamento
	cout << "\n\nDigite a descricao do Pagamento: ";
	cin.ignore(500, '\n');
	getline(cin, descricao);
	itemPagamentoFuncionario.setDescricao(descricao);


	//ler valor pago
	do
	{
		
		cout << "\n\nDigite o valor pago ao Funcionario: ";
		lerValorCorretamente(valor);

		cout << "\nO valor a ser pago eh " << valor;
		cout << "\nConfirmar [s]-Sim   [n]-Nao, editar: ";
		lerValorCorretamente(opcao);

		if (opcao == 'n')//se for nao eh so repetir o loop, caso contrario continua o loop normalmentes
		{
			system("cls");
			continue;
		}

		if (valor < 0.0)
		{
			cout << "\nErro no Pagamento\n\n";
			system("pause");

			system("cls");
			continue;	
		}

		cout << "\nPagamento Confirmado\n\n!";
		system("pause");

		break;
	} while(true);

	itemPagamentoFuncionario.setValorPago(valor);//adiciona valor pago

	//adicionar item de pagamento ao pagamento e funcionario ao pagamento
	pagamentoFuncionario.funcionario = *assistente;
	pagamentoFuncionario.adicionarItemFolhaDePagamento(itemPagamentoFuncionario);

	//adicionar pagamento a clinica
	clinica.pagamentos.adicionarPagamentoFuncionario(pagamentoFuncionario);
	

	//imprimir folha de pagamento do funcionario
	system("cls");
	cout << "\nFolha de Pagamento - " << assistente->getNome() << endl << endl;
	cout << clinica.pagamentos.retornarPagamentoFuncionario(assistente->getCpf());
	

	cout << endl << endl;
	system("pause");
}


//------------------Fim de Pagar Salario --------------




//---------------------Gerar Relatorios------------------------------

void geraRelatorio(Clinica& clinica)//gera 3 tipos de relatorio de pagamentos: Pagamento de Paciente, de gasto da Clinica e Funcionario
{
	int opcaoEntraOuSai;

	do
	{
		system("cls");
		cout << "\t\tBEM VINDO AO GERAR RELATORIO DA CLINICA " << clinica.getNomeDaClinica() << "\n\n";


		cout << "[0]-Sair\n[1]-Relatorio de Pagamentos(Pacientes)\n[2]-Relatorio de Gastos"
			<<"\n[3]-Relatorio de Gastos com Funcionarios\n\nDigite: ";
		lerValorCorretamente(opcaoEntraOuSai);

		switch (opcaoEntraOuSai)
		{
		case 0://sai do looop
			return;
			break;
		case 1:
			//relatorio de pagamentos(pacientes)
			relatorioDePagamentos(clinica);
			break;

		case 2:
			//relatorio de gastos
			relatorioDeGastos(clinica);
			break;

		case 3:
			//relatorio de gastos com funcionarios
			relatorioDeGastosComFuncionarios(clinica);
			break;


		default:
			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);

}
void relatorioDePagamentos(Clinica& clinica)//gera o relatorio de pagamentos de pacientes
{
	int mes;

	system("cls");

	cout << "Digite o mes: ";
	lerValorCorretamente(mes);

	system("cls");
	clinica.pagamentos.relatorioDePagamentosPacientesNoMes(mes);//imprime 'vazio' se estiver vazio e 'mes incorreto' se estiver com mes incorreto

	cout << endl << endl;
	system("pause");
}

void relatorioDeGastos(Clinica& clinica)//gera o relatorio de gastos com a clinica
{
	int mes;

	system("cls");

	cout << "Digite o mes: ";
	lerValorCorretamente(mes);

	system("cls");
	clinica.pagamentos.relatorioDeGastosNoMes(mes);//imprime 'vazio' se estiver vazio e 'mes incorreto' se estiver com mes incorreto

	cout << endl << endl;
	system("pause");
}


void relatorioDeGastosComFuncionarios(Clinica& clincia)//gera o relatorio de pagamentos de funcionarios
{
	int mes;

	system("cls");

	cout << "Digite o mes: ";
	lerValorCorretamente(mes);

	clincia.pagamentos.relatorioDePagamentosFuncionariosNoMes(mes);//imprime 'vazio' se estiver vazio e 'mes incorreto' se estiver com mes incorreto

	cout << endl << endl;
	system("pause");

}




//---------------------Fim do Gerar Relatorios-------------------------




//--------------------- Manipular Pacientes------------------------------



void manipularPaciente(Clinica& clinica)//manipula pacientes, adicionar remove, e edita
{

	int opcaoEntraOuSai;

	do
	{
		system("cls");
		cout << "\t\tBEM VINDO A TELA DOS(AS) PACIENTES DA CLINICA: " << clinica.getNomeDaClinica() << "\n\n";

		cout << "[0]-Sair\n[1]-Adicionar Paciente\n[2]-Remover Paciente\n[3]-Editar Paciente\n[4]-Imprimir Pacientes\n\nDigite: ";
		lerValorCorretamente(opcaoEntraOuSai);

		switch (opcaoEntraOuSai)
		{
		case 0://sai do loop
			return;
			break;
		case 1:
			//adicionar paciente
			adicionarPaciente(clinica);
			break;

		case 2:
			//remover paciente
			removerPaciente(clinica);
			break;

		case 3:
			//editar paciente
			editarPaciente(clinica);

			break;
		case 4:
			//imprime os pacientes
			system("cls");
			clinica.imprimirPacientes();
			cout << endl << endl;
			system("pause");
			break;


		default:
			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);

}

void adicionarPaciente(Clinica& clinica)//funcao que adiciona pacientes
{
	system("cls");

	int posicao;
	Paciente paciente;


	system("cls");

	//ler paciente
	lerPaciente(&paciente);

	//apos ler paciente eh so cadastrar na clinica
	clinica.adicionarPaciente(paciente);

}

void lerPaciente(Paciente* paciente)
{
	int opcao;
	string nome, endereco;
	long long cpf, telefone;

	do
	{
		system("cls");
		
		//ler nome
		cout << "\nDigite o Nome do Paciente: ";
		cin.ignore(500, '\n');
		getline(cin, nome);

		while (!paciente->setNome(nome))
		{
			cout << "\nDigite o nome corretamente: ";
			getline(cin, nome);
		}

		//ler endereco
		cout << "\nDigite o Endereco do Paciente: ";
		getline(cin, endereco);

		while (!paciente->setEndereco(endereco))
		{
			cout << "\nDigite corretamente o Endereco: ";
			getline(cin, endereco);
		}

		//ler cpf
		cout << "\nDigite o CPF do Paciente: ";
		lerValorCorretamente(cpf);
		while (!paciente->setCpf(cpf))
		{
			cout << "\nDigite corretamente o CPF: !";
			lerValorCorretamente(cpf);
		}
			
		//ler telefone
		cout << "\nDigite o Telefone do Paciente: ";
		lerValorCorretamente(telefone);
		while(!paciente->setTelefone(telefone))
		{
			cout << "\nDigite corretamente o Telefone: ";
			lerValorCorretamente(telefone);
		}
		
		break;

	} while (true);

}

void removerPaciente(Clinica& clinica)//funcao que remove um paciente da clinica
{

	int posicao;
	do
	{
		system("cls");
		if (clinica.pacientes.empty())//se estiver sem paciente nao ha o que remover
		{
			cout << "\nSem Pacientes\n\n !";
			system("pause");
			return;
		}

		clinica.imprimirPacientes();
		cout << "\n[0]-Para Sair\nDigite o numero do Paciente a ser removido: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}

		else if (posicao > clinica.pacientes.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		clinica.removerPaciente(posicao);//remove paciente
		break;
	} while (true);
}


void editarPaciente(Clinica& clinica)//funcao que edita pacientes
{
	system("cls");
	int posicao;
	if (clinica.pacientes.empty())//se estiver sem pacientes nao ha o que editar 
	{
		cout << "\nSem Pacientes\n\n !";
		system("pause");
		return;
	}

	do
	{
		system("cls");
		clinica.imprimirPacientes();// imprime os pacientes

		cout << "\n[0]-Para Sair\nDigite o numero do Item a ser Editado: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}
		else if (posicao > clinica.pacientes.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		//funcao que edita dados do paciente
		editaPaciente(&clinica.retornarPaciente(posicao));
		break;

	} while (true);
}


//funcao que edita paciente ja existe "editaPaciente"



//---------------------Fim do Manipular Pacientes-------------------------




//--------------------- Manipular Funcionarios------------------------------



void manipularFuncionario(Clinica& clinica)//manipula funcionarios, adicionar remove, e edita
{
	int opcaoEntraOuSai;

	do
	{
		system("cls");
		cout << "\t\tBEM VINDO A TELA DOS(AS) FUNCIONARIOS DA CLINICA: " << clinica.getNomeDaClinica() << "\n\n";

		cout << "[0]-Sair\n[1]-Adicionar Funcionario\n[2]-Remover Funcionario\n[3]-Editar Funcionario\n[4]-Imprimir Funcionarios\n\nDigite: ";
		lerValorCorretamente(opcaoEntraOuSai);

		switch (opcaoEntraOuSai)
		{
		case 0://sai do loop
			return;
			break;
		case 1:
			//adicionar funcionario
			adicionarFuncionario(clinica);
			break;

		case 2:
			//remover funcionario
			removerFuncionario(clinica);
			break;

		case 3:
			//editar funcionario
			editarFuncionario(clinica);

			break;
		case 4:
			//imprime os funcionario
			system("cls");
			clinica.imprimirAssistentes();
			cout << endl << endl;
			system("pause");
			break;


		default:
			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
}
void adicionarFuncionario(Clinica& clinica)//funcao que adiciona funcionario
{
	system("cls");

	int posicao;
	Assistente funcionario;


	system("cls");

	//ler funcionario
	lerFuncionario(&funcionario);

	//apos ler funcionario eh so cadastrar na clinica
	clinica.adicionarAssistente(funcionario);
}

void lerFuncionario(Assistente* funcionario)//le funcionarios corretamente
{
	int opcao;
	string nome, endereco;
	long long cpf, telefone;

	do
	{
		system("cls");

		//ler nome
		cout << "\nDigite o Nome do Funcionario: ";
		cin.ignore(500, '\n');
		getline(cin, nome);

		while (!funcionario->setNome(nome))
		{
			cout << "\nDigite o nome corretamente: ";
			getline(cin, nome);
		}

		//ler endereco
		cout << "\nDigite o Endereco do Funcionario: ";
		getline(cin, endereco);

		while (!funcionario->setEndereco(endereco))
		{
			cout << "\nDigite corretamente o Endereco: ";
			getline(cin, endereco);
		}

		//ler cpf
		cout << "\nDigite o CPF do Funcionario: ";
		lerValorCorretamente(cpf);
		while (!funcionario->setCpf(cpf))
		{
			cout << "\nDigite corretamente o CPF: ";
			lerValorCorretamente(cpf);
		}

		//ler telefone
		cout << "\nDigite o Telefone do Funcionario: ";
		lerValorCorretamente(telefone);
		while (!funcionario->setTelefone(telefone))
		{
			cout << "\nDigite corretamente o Telefone: ";
			lerValorCorretamente(telefone);
		}
		break;
	} while (true);

}
void removerFuncionario(Clinica& clinica)//funcao que remove funcionarios
{
	int posicao;
	do
	{
		system("cls");
		if (clinica.assistentes.empty())//se nao tiver funcionario nao ha o que remover
		{
			cout << "\nSem Funcionarios \n\n !";
			system("pause");
			return;
		}

		clinica.imprimirAssistentes();
		cout << "\n[0]-Para Sair\nDigite o numero do Funcionario a ser removido: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}

		else if (posicao > clinica.assistentes.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		clinica.removerAssistente(posicao);//remove funcionario na posicao escolhida pela o usuario
		break;
	} while (true);
}
void editarFuncionario(Clinica& clinica)//funcao que edita funcionarios
{
	system("cls");
	int posicao;
	if (clinica.assistentes.empty())//sem funcionarios nao ha o que editar 
	{
		cout << "\nSem Funcionarios\n\n !";
		system("pause");
		return;
	}

	do
	{
		system("cls");
		clinica.imprimirAssistentes();//imprime os funcionarios

		cout << "\n[0]-Para Sair\nDigite o numero do Funcionario a ser Editado: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}
		else if (posicao > clinica.assistentes.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		//funcao que edita dados do funcionario
		editaFuncionario(&clinica.retornarAssistente(posicao));
		break;

	} while (true);
}

void editaFuncionario(Assistente* assistente)//funcao que edita um funcionario /atualiza dados
{
	int opcao;
	string nome, endereco;
	long long cpf, telefone;

	do
	{
		system("cls");
		cout << *assistente;//imprime um funcionario
		cout << "\n\n[0]-Sair\n[1]-Editar Nome\n[2]-Editar Endereco\n[3]-Editar CPF\n[4]-Editar Telefone\n\nDigite: ";
		lerValorCorretamente(opcao);

		switch (opcao)
		{

		case 0://sai do loop
			return;
			break;

		case 1:
			//editar nome
			cout << "\nDigite o novo Nome: ";
			cin.ignore(500, '\n');
			getline(cin, nome);
			if (!assistente->setNome(nome))
			{
				cout << "\nDigite corretamente o Nome\n\n !";
				system("pause");
			}
			break;

		case 2:
			//editar endereco
			cout << "\nDigite o novo Endereco: ";
			cin.ignore(500, '\n');
			getline(cin, endereco);
			if (!assistente->setEndereco(endereco))
			{
				cout << "\nDigite corretamente o Endereco\n\n !";
				system("pause");
			}
			break;

		case 3:
			// editar cpf
			cout << "\nDigite o novo CPF: ";
			lerValorCorretamente(cpf);
			if (!assistente->setCpf(cpf))
			{
				cout << "\nDigite corretamente o cpf\n\n !";
				system("pause");
			}
			break;

		case 4:
			// editar telefone
			cout << "\nDigite o novo Telefone: ";
			lerValorCorretamente(telefone);
			if (!assistente->setTelefone(telefone))
			{
				cout << "\nDigite corretamente o Telefone\n\n !";
				system("pause");
			}
			break;

		default:
			//opcao incorreta

			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
}

//--------------------- Fim do Manipular Funcionarios-------------------------




//--------------------- Manipular Especialista------------------------------



void manipularEspecialista(Clinica& clinica)//manipula especialista, adicionar, remove, e edita
{
	int opcaoEntraOuSai;

	do
	{
		system("cls");
		cout << "\t\tBEM VINDO A TELA DOS(AS) ESPECIALISTA DA CLINICA: " << clinica.getNomeDaClinica() << "\n\n";

		cout << "[0]-Sair\n[1]-Adicionar Especialista\n[2]-Remover Especialista\n[3]-Editar Especialista\n[4]-Imprimir Especialistas\n\nDigite: ";
		lerValorCorretamente(opcaoEntraOuSai);

		switch (opcaoEntraOuSai)
		{
		case 0://sai do loop
			return;
			break;
		case 1:
			//adicionar funcionario
			adicionarEspecialista(clinica);
			break;

		case 2:
			//remover funcionario
			removerEspecialista(clinica);
			break;

		case 3:
			//editar funcionario
			editarEspecialista(clinica);

			break;
		case 4:
			//imprime os especialistas
			system("cls");
			clinica.imprimirEspecialistas();
			cout << endl << endl;
			system("pause");
			break;


		default:
			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);

}

void adicionarEspecialista(Clinica& clinica)//funcao que adiciona especialista
{
	Assistente* assistente;
	Especialista especialista;
	int posicao;
	do
	{
		system("cls");
		if (clinica.assistentes.empty())//sem funcionario nao ha especilistas a serem adicionados
		{
			cout << "\nSem Funcionarios \n\n !";
			system("pause");
			return;
		}

		clinica.imprimirAssistentes();//imprimi os funcionarios
		cout << "\n[0]-Para Sair\nDigite o numero do Funcionario que eh Especialista: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}

		else if (posicao > clinica.assistentes.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		assistente = &clinica.retornarAssistente(posicao);

		especialista.setNome(assistente->getNome());
		especialista.setEndereco(assistente->getEndereco());
		especialista.setCpf(assistente->getCpf());
		especialista.setTelefone(assistente->getTelefone());

		clinica.adicionarEspecialista(especialista);

		break;
	} while (true);
}

void removerEspecialista(Clinica& clinica)//funcao que remove Especialista
{
	int posicao;
	do
	{
		system("cls");
		if (clinica.especialistas.empty())//se nao tiver especialistas nao ha o que remover
		{
			cout << "\nSem Especialistas \n\n !";
			system("pause");
			return;
		}

		clinica.imprimirEspecialistas();//imprime os especialistas da clinica
		cout << "\n[0]-Para Sair\nDigite o numero do Especialista a ser removido: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}

		else if (posicao > clinica.especialistas.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		clinica.removerEspecialista(posicao);//remove especialista na posicao escolhida
		break;
	} while (true);
}

void editarEspecialista(Clinica& clinica)//funcao que edita Especialistas
{
	system("cls");
	int posicao;
	if (clinica.especialistas.empty())//sem especialistas nao ha o que editar 
	{
		cout << "\nSem Especialista\n\n !";
		system("pause");
		return;
	}

	do
	{
		system("cls");
		clinica.imprimirEspecialistas();//imprime especialistas da clinica

		cout << "\n[0]-Para Sair\nDigite o numero do Especialista a ser Editado: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}
		else if (posicao > clinica.especialistas.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		//funcao que edita dados do paciente
		editaEspecialista(clinica, &clinica.retornarEspecialista(posicao));
		break;

	} while (true);
}
void editaEspecialista(Clinica& clinica, Especialista* especialista)//funcao que edita especialista/atualiza dados
{
	int opcao;
	string nome, endereco;
	long long cpf, telefone;

	do
	{
		system("cls");
		cout << *especialista;//imprime um especialista
		cout << "\n\n[0]-Sair\n[1]-Editar Nome\n[2]-Editar Endereco\n[3]-Editar CPF\n[4]-Editar Telefone\n[5]-Editar Assistente\n\nDigite: ";
		lerValorCorretamente(opcao);

		switch (opcao)
		{

		case 0://sai do loop
			return;
			break;

		case 1:
			//editar nome
			cout << "\nDigite o novo Nome: ";
			cin.ignore(500, '\n');
			getline(cin, nome);
			if (!especialista->setNome(nome))
			{
				cout << "\nDigite corretamente o Nome\n\n !";
				system("pause");
			}
			break;

		case 2:
			//editar endereco
			cout << "\nDigite o novo Endereco: ";
			cin.ignore(500, '\n');
			getline(cin, endereco);
			if (!especialista->setEndereco(endereco))
			{
				cout << "\nDigite corretamente o Endereco\n\n !";
				system("pause");
			}
			break;

		case 3:
			// editar cpf
			cout << "\nDigite o novo CPF: ";
			lerValorCorretamente(cpf);
			if (!especialista->setCpf(cpf))
			{
				cout << "\nDigite corretamente o cpf\n\n !";
				system("pause");
			}
			break;

		case 4:
			// editar telefone
			cout << "\nDigite o novo Telefone: ";
			lerValorCorretamente(telefone);
			if (!especialista->setTelefone(telefone))
			{
				cout << "\nDigite corretamente o Telefone\n\n !";
				system("pause");
			}
			break;

		case 5:
			editarAssistenteDoEspecialista(clinica, especialista);//cadastra ou troca a assistente de um especialista 
			break;

		default:
			//opcao incorreta

			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
}


void editarAssistenteDoEspecialista(Clinica& clinica, Especialista* especialista)//cadastra ou troca a assistente de um especialista 
{
	int opcao;
	string nome, endereco;
	long long cpf, telefone;

	do
	{
		system("cls");
		cout << *especialista;
		cout << "\n\n[0]-Sair\n[1]-Trocar Assistente\n[2]-Remover Assistente\n\nDigite: ";
		lerValorCorretamente(opcao);

		switch (opcao)
		{

		case 0:
			return;
			break;

		case 1:
			//troca ou adiciona a assistente do especialista
			trocarAssistenteDoEspecialista(clinica, &especialista->assistente);
			break;

		case 2:
			//zerar assistente
			especialista->assistente.setNome("sem assistente");
			especialista->assistente.setEndereco("sem assistente");
			especialista->assistente.setTelefone(9999999999);
			especialista->assistente.setCpf(12345678900);
			break;

		default:
			//opcao incorreta

			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
}

void trocarAssistenteDoEspecialista(Clinica& clinica, Assistente* assistente)//troca ou adiciona a assistente do especialista
{
	int posicao;
	do
	{
		system("cls");
		if (clinica.assistentes.empty())
		{
			cout << "\nSem Funcionarios \n\n !";
			system("pause");
			return;
		}

		clinica.imprimirAssistentes();
		cout << "\n[0]-Para Sair\nDigite o numero do Funcionario a ser Assistente: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}

		else if (posicao > clinica.assistentes.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		*assistente = clinica.retornarAssistente(posicao);
		break;
	} while (true);
}


//--------------------- Fim do Manipular Especialista-------------------------


//--------------------- Manipular Recepcionista------------------------------



void manipularRecepcionista(Clinica& clinica)//manipula adicionar, remove e imprime recepcionista
{
	int opcaoEntraOuSai;

	do
	{
		system("cls");
		cout << "\t\tBEM VINDO A TELA DO(A) RECEPCIONISTA DA CLINICA: " << clinica.getNomeDaClinica() << "\n\n";

		cout << "[0]-Sair\n[1]-Adicionar Recepcionista\n[2]-Remover Recepcioista\n[3]-Imprimir Recepcionista\n\nDigite: ";
		lerValorCorretamente(opcaoEntraOuSai);

		switch (opcaoEntraOuSai)
		{
		case 0://sai do loop
			return;
			break;
		case 1:
			//adicionar Recepcionista
			adicionarRecepcionista(clinica);
			break;

		case 2:
			//remover recepcionista
			clinica.recepcionista.setNome("sem recepcionista");
			clinica.recepcionista.setEndereco("sem recepcionista");
			clinica.recepcionista.setTelefone(9999999999);
			clinica.recepcionista.setCpf(12345678900);

			break;

		case 3:
			system("cls");
			cout << "\nRecepcionista: \n";
			cout << clinica.recepcionista;
			cout << endl << endl;
			system("pause");

			break;


		default:
			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);

}


void adicionarRecepcionista(Clinica& clinica)//funcao que adiciona recepcionista
{
	Assistente* assistente;

	int posicao;
	do
	{
		system("cls");
		if (clinica.assistentes.empty())//sem funcionario nao ha recepcionista a ser escolhida
		{
			cout << "\nSem Funcionarios \n\n !";
			system("pause");
			return;
		}

		clinica.imprimirAssistentes();//imprime os funcionarios
		cout << "\n[0]-Para Sair\nDigite o numero do Funcionario que sera Recepcionista: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}

		else if (posicao > clinica.assistentes.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		assistente = &clinica.retornarAssistente(posicao);

		clinica.recepcionista.setNome(assistente->getNome());
		clinica.recepcionista.setEndereco(assistente->getEndereco());
		clinica.recepcionista.setCpf(assistente->getCpf());
		clinica.recepcionista.setTelefone(assistente->getTelefone());

		break;
	} while (true);
}


//--------------------- Fim do Manipular Recepcionista-------------------------



//--------------------- Manipular Pagamentos------------------------------
//manipular pagamentos nao maniulados ate entao, remover pagamento especifico de paciente ou todos os pagamentos
//remover pagamento especifico de funcionario ou todos os pagamentos


void manipularPagamentos(Clinica& clinica)//manipula pagamentos
{
	int opcaoEntraOuSai;

	do
	{
		system("cls");
		cout << "\t\tBEM VINDO A TELA DE PAGAMENTOS DA CLINICA: " << clinica.getNomeDaClinica() << "\n\n";

		cout << "[0]-Sair\n[1]-Pagamentos Funcionarios\n[2]-Pagamentos Pacientes\n\nDigite: ";
		lerValorCorretamente(opcaoEntraOuSai);

		switch (opcaoEntraOuSai)
		{
		case 0:///sai do loop
			return;
			break;
		case 1:
			//manipular pagamentos de funcionario
			manipularPagamentosFuncionarios(clinica);
			break;

		case 2:
			//manipular pagamentos de pacientes
			manipularPagamentosPacientes(clinica);

			break;

		default:
			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
}


void manipularPagamentosFuncionarios(Clinica& clinica)//manipula pagamentos de funcionarios
{
	int posicao;
	do
	{
		system("cls");
		if (clinica.pagamentos.pagamentosFuncionarios.empty())//nao ha pagamentos de funcionarios para manipula
		{
			cout << "\nSem Pagamentos de Funcionarios \n\n !";
			system("pause");
			return;
		}

		clinica.pagamentos.relatorioDePagamentosFuncionarios();//imprime os pagamentos existentes
		cout << "\n[0]-Para Sair\nDigite o numero do Pagamento a ser escolhido: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}

		else if (posicao > clinica.pagamentos.pagamentosFuncionarios.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		manipularPagamentosFuncionarios2(clinica, &clinica.pagamentos.retornarPagamentoFuncionario(posicao));
		break;
	} while (true);
}

void manipularPagamentosFuncionarios2(Clinica& clinica, PagamentoFuncionario* pagamentoFuncionario)//manipula pagamentos de um funcionario
{
	int opcaoEntraOuSai;

	do
	{
		system("cls");
		cout << endl << *pagamentoFuncionario;//imprime os pagamentos de um paciente

		cout << "\n[0]-Sair\n[1]-Apagar Pagamento\n[2]-Apagar Item do Pagamento\n\nDigite: ";
		lerValorCorretamente(opcaoEntraOuSai);

		switch (opcaoEntraOuSai)
		{
		case 0:
			return;
			break;
		case 1:
			//apagar pagamento
			clinica.pagamentos.removerPagamentoFuncionario(pagamentoFuncionario->funcionario.getCpf());
			return;
			break;

		case 2:
			//apagar item do pagamento do funcionario
			apagarItemPagamentosFuncionarios(clinica, pagamentoFuncionario);//apaga um item de pagamento do funcionario

			break;

		default:
			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
}


void apagarItemPagamentosFuncionarios(Clinica& clinica, PagamentoFuncionario* pagamentoFuncionario)//apaga um item de pagamento do funcionario
{
	int posicao;
	do
	{
		system("cls");
		if (pagamentoFuncionario->pagamentosFuncionario.empty())//nao ha item de pagamentos de funcionarios para apagar
		{
			cout << "\nSem Itens de Pagamentos de Funcionarios \n\n !";
			system("pause");
			return;
		}

		cout << *pagamentoFuncionario;//imprime os pagamentos de um funcionario
		cout << "\n[0]-Para Sair\nDigite o numero do Item do Pagamento a ser escolhido: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}

		else if (posicao > pagamentoFuncionario->pagamentosFuncionario.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		pagamentoFuncionario->removerItemFolhaDePagamento(posicao);//remove o item do pagamento de um paciente escolhido
		break;
	} while (true);
}


void manipularPagamentosPacientes(Clinica& clinica)//manipula pagamentos de pacientes
{
	int posicao;
	do
	{
		system("cls");
		if (clinica.pagamentos.pagamentosPacientes.empty())//nao ha pagamentos de pacientes para manipula
		{
			cout << "\nSem Pagamentos de Pacientes \n\n !";
			system("pause");
			return;
		}

		clinica.pagamentos.relatorioDePagamentosPacientes();//imprime os pagamentos dos pacientes
		cout << "\n[0]-Para Sair\nDigite o numero do Pagamento a ser escolhido: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}

		else if (posicao > clinica.pagamentos.pagamentosPacientes.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		manipularPagamentosPacientes2(clinica, &clinica.pagamentos.retornarPagamentoPaciente(posicao));//manipula o pagamento e um paciente escolhido
		break;
	} while (true);
}

void manipularPagamentosPacientes2(Clinica& clinica, PagamentoPaciente* pagamentoPaciente)//manipula pagamentos de um paciente
{
	int opcaoEntraOuSai;

	do
	{
		system("cls");
		cout << endl <<*pagamentoPaciente;//imprime os pagamentos de um paciente

		cout << "\n[0]-Sair\n[1]-Apagar Pagamento\n[2]-Apagar Item do Pagamento\n\nDigite: ";
		lerValorCorretamente(opcaoEntraOuSai);

		switch (opcaoEntraOuSai)
		{
		case 0://sai do loop
			return;
			break;
		case 1:
			//apagar pagamento
			clinica.pagamentos.removerPagamentoPaciente(pagamentoPaciente->paciente.getCpf());
			return;
			break;

		case 2:
			//apagar item do pagamento do paciente
			apagarItemPagamentosPacientes(clinica, pagamentoPaciente);//apaga um item de pagamento do paciente

			break;

		default:
			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
}

void apagarItemPagamentosPacientes(Clinica& clinica, PagamentoPaciente* pagamentoPaciente)//apaga um item de pagamento do paciente
{
	int posicao;
	do
	{
		system("cls");
		if (pagamentoPaciente->pagamentosPaciente.empty())//nao ha item de pagamentos de paciente a serem apagados
		{
			cout << "\nSem Itens de Pagamentos de Pacientes \n\n !";
			system("pause");
			return;
		}

		cout << *pagamentoPaciente;//imprime os pagamentos de um paciente
		cout << "\n[0]-Para Sair\nDigite o numero do Item do Pagamento a ser escolhido: ";
		lerValorCorretamente(posicao);

		if (posicao == 0)
		{
			return;
		}

		else if (posicao > pagamentoPaciente->pagamentosPaciente.size() || posicao < 1)//posicao incorreta
		{
			cout << "\nPosicao incorreta !\n\n";
			system("pause");
			continue;
		}

		pagamentoPaciente->removerItemPagamentoPaciente(posicao);//remove o item de pagamento do cliente escolhido
		break;
	} while (true);
}


//--------------------- Fim do Manipular Pagamentos-------------------------
