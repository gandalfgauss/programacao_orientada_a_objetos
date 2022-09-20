package oficinapoo;
import static oficinapoo.LerValorCorretamente.*;


public class UsuarioAdministrador
{
    //para acessar: usuario-> admin
    //senha-> admin
    public void usuarioAdministrador(Clinica clinica)
    {
        String leitura = "";
	int opcaoEntraOuSai;

	do
	{
            leitura = "\t\tBEM VINDO AO MENU DA CLINICA " + clinica.getNomeDaClinica() + "\n\n"
                        + "[0]-Sair\n[1]-Agenda\n[2]-Receber Consulta\n[3]-Fazer Pagamento de Contas\n[4]-Folha de Ponto\n[5]-Pagar Salario\n"
			+"[6]-Gerar Relatorio\n[7]-Pacientes\n[8]-Funcionarios\n[9]-Especialistas\n"
			+"[10]-Recepcionista\n[11]-Pagamentos\n\nDigite: ";
            opcaoEntraOuSai = lerInteiroCorretamente(leitura);

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
                        mensagemErro("\nOpcao incorreta !\n\n");
			break;
            }
	} while (true);
    }


    //-------------------------------Agenda---------------------
    //Menu contendos os nomes dos ortodontistas para o usuario possa escolher
    //ver agenda do ortodentista escolhido
    //ao escolher pode ter a opcao de editar, remover e adicionar

    public void agenda(Clinica clinica)//manipula as agendas dos especilistas
    {
        String leitura = "";
	int posicao;
	Especialista especialista = new Especialista();

	//conferir se tem especialista
	if (clinica.especialistas.isEmpty())
	{
            mensagemErro("\nNao existe especialistas cadastrados !\n\n");
            return;
	}

	do
	{

            leitura = "\t\tBEM VINDO A AGENDA DA CLINICA " + clinica.getNomeDaClinica() + "\n\n"
                        + clinica.imprimirNomeDosEspecialistas()
                        + "\n[0]-Para Sair\nDigite o numero do Especialista a ser escolhido: ";
                
            posicao = lerInteiroCorretamente(leitura);
		
            if (posicao == 0)
            {
                return;
            }
            else if (posicao > clinica.especialistas.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            //retorna especialista
            especialista = clinica.retornarEspecialista(posicao);

            //loop imprimindo agenda do especialista e pedindo pra editar, remover e adicionar item
            agendaEspecialista(clinica, especialista);

	} while (true);
    }

    public void agendaEspecialista(Clinica clinica, Especialista especialista)//manipula a agendas de um especilista
    {
	int opcaoEntraOuSai;
        String leitura = "";

	do
	{   //se estiver vazia imprime agenda vazia
            leitura = "\t\tBEM VINDO A AGENDA DO(A) ESPECIALISTA " + especialista.getNome()
                        +"\n\n\n\n" + especialista.imprimirAgenda() + "\n\n"
                        +  "[0]-Sair\n[1]-Adicionar Item\n[2]-Editar Item\n[3]-Remover Item\n\nDigite: ";
            opcaoEntraOuSai = lerInteiroCorretamente(leitura);

            switch (opcaoEntraOuSai)
            {
		case 0:
			return;
		case 1:
			//adicionar item da agenda
			adicionarItemAgendaEspecialista(clinica, especialista.agenda);
			break;

		case 2:
			//editar item agenda
			editarItemAgendaEspecialista(clinica, especialista.agenda);
			break;

		case 3:
			//remover item agenda
			removerItemAgendaEspecialista(clinica, especialista.agenda);
			break;


		default:
			mensagemErro("\nEscolha Corretamente a opcao !\n\n");
			break;
            }
		
	} while (true);
    }

    public void adicionarItemAgendaEspecialista(Clinica clinica, Agenda agenda)//adiciona um item na agenda de Especialista
    {
	//tem que ter paciente cadastrado para adicionar um item na agenda
	int posicao;
	String descricao;
        String leitura = "";

	ItemAgenda itemAgenda = new ItemAgenda();

	if (clinica.pacientes.isEmpty())
	{
            mensagemErro("\nCadastre um Paciente antes de adicionar um item da agenda ! \n\n");
            return;
	}

	//caso tenha pacientes deve selecionar um para adicionar na agenda
	do
	{        
		
            leitura = clinica.imprimirPacientes()+ "\n[0]-Para Sair\nDigite o numero do Paciente a ser escolhido: ";
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }
            else if (posicao > clinica.pacientes.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro( "\nPosicao incorreta !\n\n");
		continue;
            }

            itemAgenda.paciente = new Paciente(clinica.retornarPaciente(posicao));
            lerDataHora(itemAgenda.data);


            leitura = "\nDigite a descricao da consulta: ";
            descricao = lerStringCorretamente(leitura);
            itemAgenda.setDescricao(descricao);

            agenda.adicionarItemAgenda(itemAgenda);//adicionar item agenda
            break;

	} while (true);

    }

    public void lerDataHora(DataHora data)//ler data hora da agenda
    {
	int dia, mes, ano, hora, minuto;
        String leitura = "";
	do
	{
		leitura = "\nDigite o dia do proposito: ";
		dia = lerInteiroCorretamente(leitura);

		leitura = "\nDigite o mes do proposito: ";
		mes = lerInteiroCorretamente(leitura);

		leitura= "\nDigite o ano do proposito: ";
		ano = lerInteiroCorretamente(leitura);

		leitura= "\nDigite a hora do proposito: ";
		hora = lerInteiroCorretamente(leitura);
                
		leitura = "\nDigite o minuto do proposito: ";
		minuto = lerInteiroCorretamente(leitura);

		//confere se os valores digitados da data sao validos
		if (((data.setDia(dia)) && (data.setMes(mes)) && (data.setAno(ano)) && (data.setHora(hora)) && (data.setMinuto(minuto))))//se conseguir inserir corretamente a data pode sair do loop
		{
                    break;
		}

		mensagemErro("\nDigite corretamente a data\n\n !");
	} while (true);//enquanto nao conseguir inserir corretamente
    }


    public void lerData(Data data)//le uma data e a retorna
    {
	int dia, mes, ano;
        String leitura = "";
	do
	{
            leitura = "\nDigite o dia do proposito: ";
            dia = lerInteiroCorretamente(leitura);

            leitura = "\nDigite o mes do proposito: ";
            mes = lerInteiroCorretamente(leitura);

            leitura = "\nDigite o ano do proposito: ";
            ano = lerInteiroCorretamente(leitura);

            //confere se os valor digitados da data sao validos
            if (((data.setDia(dia)) && (data.setMes(mes)) && (data.setAno(ano))))//se conseguir inserir corretamente a data pode sair do loop
            {
               break;
            }

            mensagemErro("\nDigite corretamente a data\n\n !");		
	} while (true);//enquanto nao conseguir inserir corretamente
    }

    public void removerItemAgendaEspecialista(Clinica clinica, Agenda agenda)//remove um item na agenda de Especialista
    {
        String leitura = "";
	int posicao;
        
	do
	{
            if (agenda.itensDaAgenda.isEmpty())//se agenda estiver vazia nao ha o que remover
            {
		mensagemErro("\nAgenda vazia\n\n !");		
                return;
            }

            leitura = agenda.toString() + 
                "\n[0]-Para Sair\nDigite o numero do Item a ser removido: ";
            
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
                return;
            }

            else if (posicao > agenda.itensDaAgenda.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            agenda.removerItemAgenda(posicao);
            
            break;
	} while (true);
    }

    public void editarItemAgendaEspecialista(Clinica clinica, Agenda agenda)//edita um item na agenda de Especialista
    {
        String leitura = "";
	int posicao;
	if (agenda.itensDaAgenda.isEmpty())//Agenda vazia nao ha o que editar 
	{
            mensagemErro("\nAgenda vazia\n\n !");
            return;
	}

	do
	{	
            leitura = agenda.toString()
                + "\n[0]-Para Sair\nDigite o numero do Item a ser Editado: ";
		
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }
            else if (posicao > agenda.itensDaAgenda.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            //funcao que edita o item
            editarItemAgenda(clinica, agenda.retornarItemAgenda(posicao));
            break;

	} while (true);
    }

    public void editarItemAgenda(Clinica clinica, ItemAgenda itemAgenda)//edita um item da agenda
    {
        String leitura = "";
	String descricao;

	int opcao;
	do
	{
            leitura = "Item:\n" + itemAgenda.toString()//imprime o item a ser editado na tela
                + "\n\n[0]-Sair\n[1]-Editar Data\n[2]-Editar Descricao\n[3]-Trocar Paciente\n\nDigite: ";
            
            opcao = lerInteiroCorretamente(leitura);

            switch (opcao)
            {

            case 0:
                return;

            case 1:
                //funcao que edita data
                editaDataHora(itemAgenda.data);
		break;

            case 2:
		//edita descricao
		leitura = "\nDigite a nova Descricao: ";
		descricao = lerStringCorretamente(leitura);
                
		if (!itemAgenda.setDescricao(descricao))
                {
                    mensagemErro("\nDigite corretamente a Descricao\n\n !");
		}
                
		break;
                
            case 3:
		//trocar paciente
                trocarPacienteItemAgenda(clinica, itemAgenda);
		break;
                
            default:
		//opcao incorreta
		mensagemErro("\nEscolha Corretamente a opcao !\n\n");
		break;
            }
	} while (true);	
    }

    public void editaDataHora(DataHora data)//funcao que edita data hora
    {
        String leitura = "";
	int opcao;
	int dia;
	int mes;
	int ano;
	int hora;
	int minuto;

	do
	{
            leitura = data.toString()
                    + "\n\n[0]-Sair\n[1]-Editar Dia\n[2]-Editar Mes\n[3]-Editar Ano\n[4]-Editar Hora\n[5]-Editar Minuto"
                    + "\n\nDigite: ";
            opcao = lerInteiroCorretamente(leitura);

            switch (opcao)
            {

                case 0://zero sai do loop
                    return;

		case 1:
                    //editar dia
                    leitura = "\nDigite o novo dia: ";
                    dia = lerInteiroCorretamente(leitura);
                    if (!data.setDia(dia))
                    {
			mensagemErro("\nDigite corretamente o dia\n\n !");
                    }
                    break;

		case 2:
                    //editar mes
                    leitura = "\nDigite o novo mes: ";
                    mes = lerInteiroCorretamente(leitura);
                    if (!data.setMes(mes))
                    {
			mensagemErro("\nDigite corretamente o mes\n\n !");		
                    }
                    break;

		case 3:
                    // editar ano
                    leitura = "\nDigite o novo ano: ";
                    ano = lerInteiroCorretamente(leitura);
                    if (!data.setAno(ano))
                    {
			mensagemErro("\nDigite corretamente o ano\n\n !");
                    }
                    break;
		case 4:
                    // editar hora
                    leitura = "\nDigite a nova hora: ";
                    hora = lerInteiroCorretamente(leitura);
                    if (!data.setHora(hora))
                    {
			mensagemErro("\nDigite corretamente a hora\n\n !");
                    }
                    break;

		case 5:
                    // editar minuto
                    leitura = "\nDigite o novo minuto: ";
                    minuto = lerInteiroCorretamente(leitura);
                    if (!data.setMinuto(minuto))
                    {
			mensagemErro("\nDigite corretamente o minuto\n\n !");
                    }
                    break;

		default:
                    //opcao incorreta
                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
            }

	} while (true);

    }

    public void editaData(Data data)//funcao que edita data
    {
        String leitura = "";
	int opcao;
	int dia;
	int mes;
	int ano;

	do
	{
            leitura = data.toString()
                + "\n\n[0]-Sair\n[1]-Editar Dia\n[2]-Editar Mes\n[3]-Editar Ano\n\nDigite: ";
            opcao = lerInteiroCorretamente(leitura);

            switch (opcao)
            {

                case 0://zero sai do loop
                    return;

                case 1:
                    //editar dia
                    leitura = "\nDigite o novo dia: ";
                    dia = lerInteiroCorretamente(leitura);
                    if (!data.setDia(dia))
                    {
			mensagemErro("\nDigite corretamente o dia\n\n !");
                    }
                    break;

		case 2:
                    //editar mes
                    leitura = "\nDigite o novo mes: ";
                    mes = lerInteiroCorretamente(leitura);
                    if (!data.setMes(mes))
                    {
                        mensagemErro("\nDigite corretamente o mes\n\n !");
                    }
			break;

		case 3:
                    // editar ano
                    leitura = "\nDigite o novo ano: ";
                    ano = lerInteiroCorretamente(leitura);
                    if (!data.setAno(ano))
                    {
			mensagemErro("\nDigite corretamente o ano\n\n !");
                    }
                    break;

		default:
                    //opcao incorreta
                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
            }

	} while (true);
    }

    public void trocarPacienteItemAgenda(Clinica clinica, ItemAgenda itemAgenda)//troca um paciente de um Item da Agenda por outro paciente
    {

	String leitura = "";
	int posicao;
	String descricao;

	//tem que ter paciente cadastrado para trocar
	if (clinica.pacientes.isEmpty())
	{
		mensagemErro("\nSem Pacientes Cadastrados ! \n\n");
		return;
	}

	//caso tenha pacientes deve selecionar um para adicionar na agenda
	do
	{
            leitura = itemAgenda.paciente.toString()
                    + clinica.imprimirPacientes()//imprime os pacientes
                    + "\n[0]-Para Sair\nDigite o numero do Paciente a ser escolhido: ";
	
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }
            else if (posicao > clinica.pacientes.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            //troca o paciente
            itemAgenda.paciente = new Paciente(clinica.retornarPaciente(posicao));

            break;

	} while (true);

    }

    //----------------------------Fim da Agenda-----------------------------



    //------------------Receber Consulta --------------

    public void receberConsulta(Clinica clinica)//recebe uma consulta do paciente
    {
        String leitura = "";
	int posicao;
	Paciente paciente = new Paciente();
	PagamentoPaciente pagamentoPaciente= new PagamentoPaciente();
	PagamentoPaciente impresso = new PagamentoPaciente();

	//conferir se tem pacientes para receber
	if (clinica.pacientes.isEmpty())
	{
            mensagemErro("\nNao existe pacientes cadastrados !\n\n");
            return;
	}

	do
	{
            leitura = "\t\tBEM VINDO AO RECEBIMENTO DE CONSULTA DA CLINICA " 
                    + clinica.getNomeDaClinica() + "\n\n"
                    + clinica.imprimirPacientes() 
                    + "\n[0]-Para Sair\nDigite o numero do Paciente a ser escolhido: ";
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }
            else if (posicao > clinica.pacientes.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }
            
            //retorna paciente
            paciente = clinica.retornarPaciente(posicao);

            //atualizar cadastro
            editaPaciente(paciente);

            pagamentoPaciente.paciente = new Paciente(paciente);

            pagamentoDoPaciente(clinica, pagamentoPaciente);//adiciona os detalhes do pagamento do cliente
		
            //adicionar nos pagamentos do paciente da clinica
            clinica.pagamentos.adicionarPagamentoPaciente(pagamentoPaciente);

            //imprimir pagamentos daquele paciente
            impresso = clinica.pagamentos.retornarPagamentoPaciente(pagamentoPaciente.paciente.getCpf());

            mensagemInformacao("\n\n" +  impresso.toString()+"\n\n");

            break;

	} while (true);
    }

    public void pagamentoDoPaciente(Clinica clinica, PagamentoPaciente pagamentoPaciente)//adiciona os detalhes do pagamento do cliente
    {
	String leitura = "";
	int opcao;
	double valor;
	String descricao;
	ItemPagamentoPaciente itemPagamentoPaciente = new ItemPagamentoPaciente();
	
	lerData(itemPagamentoPaciente.dataDePagamento);//ler data

	//ler nome do pagamento
	leitura = "\n\nDigite o Nome do Pagamento: ";
	descricao = lerStringCorretamente(leitura);
	itemPagamentoPaciente.setNomeDoPagamento(descricao);
        
	//ler valor pago
	do
	{	
            leitura = "\n\nDigite o valor pago pelo Paciente: ";
            valor = lerDoubleCorretamente(leitura);

            leitura =  "\nO valor a ser pago eh " + valor
                    + "\nConfirmar:" ;
            opcao = mensagemCerteza(leitura);

            if (opcao == 1)//se for 'No' retorna '1' eh so repetir o loop, caso contrario continua o loop normalmente
            {
		continue;
            }

            if (valor < 0.0)
            {
                mensagemErro("\nErro no Pagamento\n\n");
		continue;	
            }

            mensagemInformacao("\nPagamento Confirmado\n\n!");
            break;
	} while(true);

	itemPagamentoPaciente.setValorPago(valor);//adiciona valor pago

	pagamentoPaciente.adicionarItemPagamentoPaciente(itemPagamentoPaciente);//adicionar item de pagamento do paciente	
    }

    public void editaPaciente(Paciente paciente)//funcao que edita paciente/ atualiza dados
    {
	int opcao;
	String nome, endereco;
	String cpf, telefone;
        String leitura = "";

	do
	{
            leitura = paciente.toString() 
                    + "\n\n[0]-Sair\n[1]-Editar Nome\n[2]-Editar Endereco\n[3]-Editar CPF\n[4]-Editar Telefone"
                    + "\n\nDigite: ";
            opcao = lerInteiroCorretamente(leitura);

            switch (opcao)
            {

                case 0://sai do loop
                    return;

		case 1:
                    //editar nome
                    leitura = "\nDigite o novo Nome: ";
                    
                    nome = lerStringCorretamente(leitura);
                    if (!paciente.setNome(nome))
                    {
			mensagemErro("\nDigite corretamente o Nome\n\n !");
                    }
                    break;

		case 2:
                    //editar endereco
                    leitura = "\nDigite o novo Endereco: ";
                    endereco = lerStringCorretamente(leitura);
                    if (!paciente.setEndereco(endereco))
                    {
                        mensagemErro("\nDigite corretamente o Endereco\n\n !");
                    }
                    break;

		case 3:
                    // editar cpf
                    leitura = "\nDigite o novo CPF: ";
                    cpf  = lerStringCorretamente(leitura);
                    if (!paciente.setCpf(cpf))
                    {
			mensagemErro("\nDigite corretamente o cpf\n\n !");
                    }
                    break;

		case 4:
                    // editar telefone
                    leitura = "\nDigite o novo Telefone: ";
                    telefone = lerStringCorretamente(leitura);
                    if (!paciente.setTelefone(telefone))
                    {
			mensagemErro("\nDigite corretamente o Telefone\n\n !");
                    }
                    break;

		default:
                    //opcao incorreta
                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
            }

	} while (true);
    }

    //------------------Fim do Receber Consulta----------------------------




    //------------------Fazer Pagamento de Contas --------------

    public void pagamentoDeContas(Clinica clinica)//matem controle dos gastos da clinica
    {
	int opcao;
        String leitura = "";
	do
	{
            leitura = "\t\tBEM VINDO AO PAGAMENTO DE CONTAS DA CLINICA " 
                    + clinica.getNomeDaClinica() + "\n\n"
                    + "\n\n[0]-Sair\n[1]-Adicionar Conta\n[2]-Remover Conta\n[3]-Editar Conta\n\nDigite: ";
            
            opcao = lerInteiroCorretamente(leitura);

            switch (opcao)
            {

		case 0://sai do loop
                    return;

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
                    
                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");

                    break;
            }

	} while (true);
    }

    public void adicionarPagamentoDeContas(Clinica clinica)//adicionar um pagamento de conta
    {

	PagamentoDeGastos pagamentoDeGastos = new PagamentoDeGastos();

	Data dataDePagamento = new Data();
	Data dataDeVencimento = new Data();
	double valorPago;
	String descricao;
        String leitura = "";

	//ler data de pagamento
	leitura = "Cadastrar Data de Pagamento: ";
        mensagemInformacao(leitura);
	lerData(dataDePagamento);

	pagamentoDeGastos.dataDePagamento = new Data(dataDePagamento);

	//ler data de vencimento
	leitura = "\n\nCadastrar Data de Vencimento: ";
        mensagemInformacao(leitura);
	lerData(dataDeVencimento);

	pagamentoDeGastos.dataDeVencimento = new Data(dataDeVencimento);

	//ler valor pago
	do
	{
            leitura = "\n\nDigite o valor da Conta: ";
            valorPago = lerDoubleCorretamente(leitura);

            if (!pagamentoDeGastos.setValorPago(valorPago))
            {
                mensagemErro("\nDigite corretamente o valor !\n\n");
		continue;
            }

            break;
	} while (true);

	//ler descricao
	leitura = "\nDigite a descricao da conta: ";
	descricao = lerStringCorretamente(leitura);

	while (!pagamentoDeGastos.setDescricao(descricao))
	{
            leitura = "\nDigite a descricao da conta: ";
            descricao = lerStringCorretamente(leitura);
	}
	
	//agora eh so adicionar o pagamento na lista de pagamentos
	clinica.pagamentos.adicionarPagamentoDeGastos(pagamentoDeGastos);	
    }

    public void removerPagamentoDeContas(Clinica clinica)//dada uma posicao remover um pagamento da conta
    {
	int posicao;
        String leitura = "";
	do
	{
            //confere se existe pagamentos a remover
            if (clinica.pagamentos.pagamentosDeGastos.isEmpty())
            {
		mensagemErro("\nSem Pagamentos De Contas\n\n !");
		return;
            }

            //imprimir pagamentos
            leitura = clinica.pagamentos.relatorioDeGastos()
                    + "\n[0]-Para Sair\nDigite o numero do Item a ser removido: ";
            
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }

            else if (posicao > clinica.pagamentos.pagamentosDeGastos.size() || posicao < 1)//posicao incorreta
            {
                mensagemErro("\nPosicao incorreta !\n\n");
                continue;
            }

            clinica.pagamentos.removerPagamentoDeGastos(posicao);//remove o pagamento daquela posicao
            break;
	} while (true);
    }

    public void editarPagamentoDeContas(Clinica clinica)//edita um pagamento de conta
    {
	int posicao;
        String leitura = "";
        
	do
	{
            //confere se existe pagamentos a editar
            if (clinica.pagamentos.pagamentosDeGastos.isEmpty())
            {
		mensagemErro("\nSem Pagamentos De Contas\n\n !");
                return;
            }

            //imprimir pagamentos
            leitura = clinica.pagamentos.relatorioDeGastos()
                    + "\n[0]-Para Sair\nDigite o numero do Item a ser editado: ";
	
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }

            else if (posicao > clinica.pagamentos.pagamentosDeGastos.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            editarItensPagamentosDeContas(clinica, clinica.pagamentos.retornarPagamentoDeGastos(posicao));//edita um item do pagamento de contas
            break;
	} while (true);
    }

    public void editarItensPagamentosDeContas(Clinica clinica, PagamentoDeGastos pagamentoDeGastos)//edita um item do pagamento de conta
    {
	double valorPago;
	String descricao;
        String leitura = "";

	int opcao;
	do
	{
            leitura =  "Item:\n" + pagamentoDeGastos.toString()//imprime o item
                    +"\n\n[0]-Sair\n[1]-Editar Data de Vencimento\n[2]-Editar Data de Pagamento\n[3]-Editar Valor Pago\n[4]-Editar Descricao\n\nDigite: ";
            
            opcao = lerInteiroCorretamente(leitura);

            switch (opcao)
            {

                case 0://sai do loop
                    return;

		case 1:
                    //funcao que edita data de vencimento
                    editaData(pagamentoDeGastos.dataDeVencimento);
                    break;

		case 2:
                    //funcao que edita a data de pagamento
                    editaData(pagamentoDeGastos.dataDePagamento);
                    break;
		case 3:
                    //editar valor pago
                    leitura =  "\n\nDigite o valor da Conta: ";
                    valorPago = lerDoubleCorretamente(leitura);

                    if (!pagamentoDeGastos.setValorPago(valorPago))
                    {
			mensagemErro("\nDigite corretamente o valor !\n\n");
                    }

                    break;

		case 4:
                    //edita descricao
                    leitura = "\nDigite a nova Descricao: ";                  
                    descricao = lerStringCorretamente(leitura);
                    
                    if (!pagamentoDeGastos.setDescricao(descricao))
                    {
			mensagemErro("\nDigite corretamente a Descricao\n\n !");
                    }
                    break;
		default:
                    //opcao incorreta
                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
		}

	} while (true);
    }
    //------------------Fim Fazer Pagamento de Contas --------------



    //------------------ Folha de Ponto ----------------

    public void folhaDePonto(Clinica clinica)//controla a folha de ponto dos funcionarios(assistentes)
    {
	int posicao;
	Assistente assistente = new Assistente();
        String leitura = "";

	//conferir se tem funcionarios
	if (clinica.assistentes.isEmpty())
	{
            mensagemErro("\nNao existe Funcionarios cadastrados !\n\n");
            return;
	}

	//caso tenha funcionarios  eh so impprimir a lista de funcionarios e escolher qual funcionario deseja ver editar ou remover itens da folha de ponto
	do
	{
            leitura = "\t\tBEM VINDO A FOLHA DE PONTO DA CLINICA "
                    + clinica.getNomeDaClinica() + "\n\n"
                    + clinica.imprimirNomeDosFuncionarios()//imprime a lista de funcionarios
                    +"\n[0]-Para Sair\nDigite o numero do Funcionario a ser escolhido: ";
            
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }
            else if (posicao > clinica.assistentes.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            //retorna funcionario
            assistente = clinica.retornarAssistente(posicao);

            //loop imprimindoa folha de ponto do funcionario e pedindo pra editar, remover e adicionar item
            folhaDePontoAssistente(clinica, assistente);

	} while (true);
    }

    public void folhaDePontoAssistente(Clinica clinica, Assistente assistente) //controla a folha de ponto de um funcionario
    {
	int opcaoEntraOuSai;
        String leitura = "";
        
	do
	{
            leitura = "\t\tBEM VINDO A FOLHA DE PONTO DO(A) FUNCIONARIO(A): " 
                    + assistente.getNome() + "\n\n\n\n"
                    //imprimir folha de ponto do funcionario(assistente)
                    +assistente.imprimirFolhaDePonto()//se estiver vazia imprime folha de ponto vazia
                    + "\n\n"
                    + "[0]-Sair\n[1]-Adicionar Item\n[2]-Remover Item\n[3]-Editar Item\n\nDigite: ";
                    
            opcaoEntraOuSai = lerInteiroCorretamente(leitura);

            switch (opcaoEntraOuSai)
            {
		case 0://sai do loop
			return;
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
                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
            }

	} while (true);
    }

    public void adicionarItemFolhaDePonto(Clinica clinica, Assistente assistente)//adiciona um item na follha de ponto do funcionario
    {
	String descricao;
        String leitura = "";

	ItemFolhaDePonto itemFolhaDePonto = new ItemFolhaDePonto();

	//adicionar
	do
	{
            //ler a data
            mensagemInformacao("\nDigite a data: ");
            lerData(itemFolhaDePonto.data);

            //ler  observacao
            leitura = "\nDigite a Observacao da folha de ponto: ";
            descricao = lerStringCorretamente(leitura);

            while (!itemFolhaDePonto.setObservacao(descricao))
            {
		leitura = "\nDigite a Observacao : ";
                descricao = lerStringCorretamente(leitura);
            }

            assistente.adicionarItemFolhaDePonto(itemFolhaDePonto);
            break;

	} while (true);
    }

    public void removerItemFolhaDePonto(Clinica clinica, Assistente assistente)//remove um item na follha de ponto do funcionario
    {
	int posicao;
        String leitura = "";
	do
	{
            if (assistente.folhaDePonto.isEmpty())//verificar se tem itens a ser removidos
            {
		mensagemErro("\nFolha de Ponto vazia\n\n !");
		return;
            }

            leitura = assistente.imprimirFolhaDePonto()//imprime folha de ponto do funcionario
                    +"\n[0]-Para Sair\nDigite o numero do Item a ser removido: ";
            
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }

            else if (posicao > assistente.folhaDePonto.size() || posicao < 1)//posicao incorreta
            {
                mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            assistente.removerItemFolhaDePonto(posicao);//remove o item da folha de ponto da posicao escolhida
            break;
	} while (true);
    }


    public void editarFolhaDePonto(Clinica clinica, Assistente assistente)//edita um item na follha de ponto do funcionario
    {
	int posicao;
        String leitura = "";
        
	if (assistente.folhaDePonto.isEmpty())//folha de ponto vazia nao ha o que editar 
	{
            mensagemErro("\nFolha de Ponto vazia\n\n !");
            return;
	}

	do
	{
            leitura = assistente.imprimirFolhaDePonto()//imprime folha de ponto
                    + "\n[0]-Para Sair\nDigite o numero do Item a ser Editado: ";
	
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }
            else if (posicao > assistente.folhaDePonto.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            //funcao que edita o item
            editarItemFolhaDePonto(clinica, assistente.retornarItemFolhaDePonto(posicao));
            break;
	} while (true);
    }



    public void editarItemFolhaDePonto(Clinica clinica, ItemFolhaDePonto itemFolhaDePonto)//edita um item da folha de ponto de um funcionario
    {
	String descricao;
        String leitura;
        
	int opcao;
	do
	{
            leitura = "Item:\n" + itemFolhaDePonto.toString()//imprime o item a ser editado
                    + "\n\n[0]-Sair\n[1]-Editar Data\n[2]-Editar Descricao\n\nDigite: ";
            
            opcao = lerInteiroCorretamente(leitura);

            switch (opcao)
            {

		case 0://sai do loop
                    return;

		case 1:
                    //funcao que edita data
                    editaData(itemFolhaDePonto.data);
                    break;

		case 2:
                    //edita descricao
                    leitura = "\nDigite a nova Descricao: ";
                    descricao = lerStringCorretamente(leitura);
                    if (!itemFolhaDePonto.setObservacao(descricao))
                    {
			mensagemErro("\nDigite corretamente a Descricao\n\n !");
                    }
                    break;
                    
		default:
                    //opcao incorreta

                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
            }

	} while (true);
    }

    //------------------Fim de Folha de Ponto --------------



    //------------------ Pagar Salario ----------------

    public void pagarSalario(Clinica clinica)//realiza um pagamento de funcionario mostrando folha de ponto
    {
	int posicao;
	Assistente assistente = new Assistente();
        String leitura = "";

	//conferir se tem funcionarios
	if (clinica.assistentes.isEmpty())
	{
            mensagemErro("\nNao existe Funcionarios cadastrados !\n\n");
            return;
	}

	do
	{
            leitura = "\t\tBEM VINDO AO PAGAMENTO DE SALARIO " 
                    + clinica.getNomeDaClinica() + "\n\n"
                    + clinica.imprimirNomeDosFuncionarios()//imprime funcionarios
                    +  "\n[0]-Para Sair\nDigite o numero do Funcionario a ser escolhido: ";
            
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }
            else if (posicao > clinica.assistentes.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");;
		continue;
            }

            //retorna funcionario
            assistente = clinica.retornarAssistente(posicao);

            //loop que pede para o usuario escolher em entre ver folha de ponto do funcionario ou realizar paagamento
            pagarSalarioParte2(clinica, assistente);

	} while (true);
    }

    void pagarSalarioParte2(Clinica clinica, Assistente assistente)//menu com escolha para ver folha de ponto ou pagar salario
    {
	int opcaoEntraOuSai;
	int mes;
        
        String leitura = "";

	do
	{
            leitura = "\t\tBEM VINDO A AREA DE PAGAMENTO DO(A) FUNCIONARIO(A): " 
                    + assistente.getNome() + "\n\n"
                    +  "[0]-Sair\n[1]-Folha de Ponto\n[2]-Efetuar Pagamento\n\nDigite: ";
               
            opcaoEntraOuSai = lerInteiroCorretamente(leitura);

            switch (opcaoEntraOuSai)
            {
		case 0://sai do loop
                    return;
			
		case 1:
                    
                    leitura = "\n\n"
                            +"\nDigite o mes: ";
                    
                    mes = lerInteiroCorretamente(leitura);
			
                    //mostra folha de ponto do mes
                    //se estiver vazia imprime folha de ponto vazia, e se mes tiver incorreto imprime mes incorreto
                    leitura = assistente.imprimirFolhaDePontoDoMes(mes) + "\n\n";
                    mensagemInformacao(leitura);
			
                    break;

		case 2:
                    //efetuar pagamento
                    efetuarPagamentoFuncionario(clinica, assistente);
                    break;

		default:
                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
            }

	} while (true);
    }

    public void efetuarPagamentoFuncionario(Clinica clinica, Assistente assistente)//efetua o pagamento de um funcionario
    {	
	int opcao;
	double valor;
	String descricao;
        String leitura = "";
	ItemPagamentoFuncionario itemPagamentoFuncionario = new ItemPagamentoFuncionario();
	PagamentoFuncionario pagamentoFuncionario = new PagamentoFuncionario();
	
	lerData(itemPagamentoFuncionario.dataDePagamento);//ler data

	//ler descricao do pagamento
	leitura = "\n\nDigite a descricao do Pagamento: ";
	descricao = lerStringCorretamente(leitura); 
	itemPagamentoFuncionario.setDescricao(descricao);

	//ler valor pago
	do
	{	
            leitura = "\n\nDigite o valor pago ao Funcionario: ";
            valor = lerDoubleCorretamente(leitura);

            leitura = "\nO valor a ser pago eh " + valor
                    + "\nConfirmar: ";
            
            opcao = mensagemCerteza(leitura);

            if (opcao == 1)//se for nao eh so repetir o loop, caso contrario continua o loop normalmentes
            {
		continue;
            }

            if (valor < 0.0)
            {
		mensagemErro("\nErro no Pagamento\n\n");
		continue;	
            }

            mensagemInformacao("\nPagamento Confirmado\n\n!");

            break;
	} while(true);

	itemPagamentoFuncionario.setValorPago(valor);//adiciona valor pago

	//adicionar item de pagamento ao pagamento e funcionario ao pagamento
	pagamentoFuncionario.funcionario = new Assistente(assistente);
	pagamentoFuncionario.adicionarItemFolhaDePagamento(itemPagamentoFuncionario);

	//adicionar pagamento a clinica
	clinica.pagamentos.adicionarPagamentoFuncionario(pagamentoFuncionario);

	//imprimir folha de pagamento do funcionario
	leitura = "\nFolha de Pagamento - " + assistente.getNome() +"\n\n"
                + clinica.pagamentos.retornarPagamentoFuncionario(assistente.getCpf()).toString();
    }


    //------------------Fim de Pagar Salario --------------




    //---------------------Gerar Relatorios------------------------------

    public void geraRelatorio(Clinica clinica)//gera 3 tipos de relatorio de pagamentos: Pagamento de Paciente, de gasto da Clinica e Funcionario
    {
	int opcaoEntraOuSai;
        String leitura = "";
        
	do
	{
            leitura = "\t\tBEM VINDO AO GERAR RELATORIO DA CLINICA "
                    + clinica.getNomeDaClinica() + "\n\n"
                    + "[0]-Sair\n[1]-Relatorio de Pagamentos(Pacientes)\n[2]-Relatorio de Gastos"
                    + "\n[3]-Relatorio de Gastos com Funcionarios\n\nDigite: ";
           
            opcaoEntraOuSai = lerInteiroCorretamente(leitura);

            switch (opcaoEntraOuSai)
            {
		case 0://sai do looop
                    return;
                    
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
                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
            }

	} while (true);
    }
    
    public void relatorioDePagamentos(Clinica clinica)//gera o relatorio de pagamentos de pacientes
    {
	int mes;
        String leitura = "";

	leitura = "Digite o mes: ";
	mes = lerInteiroCorretamente(leitura);

	leitura = clinica.pagamentos.relatorioDePagamentosPacientesNoMes(mes);//imprime 'vazio' se estiver vazio e 'mes incorreto' se estiver com mes incorreto
        
        mensagemInformacao(leitura);
    }

    public void relatorioDeGastos(Clinica clinica)//gera o relatorio de gastos com a clinica
    {
        String leitura = "";
	int mes;


	leitura = "Digite o mes: ";
	mes = lerInteiroCorretamente(leitura);

	leitura = clinica.pagamentos.relatorioDeGastosNoMes(mes);//imprime 'vazio' se estiver vazio e 'mes incorreto' se estiver com mes incorreto

	mensagemInformacao(leitura);
    }


    public void relatorioDeGastosComFuncionarios(Clinica clincia)//gera o relatorio de pagamentos de funcionarios
    {
	int mes;
        String leitura = "";
        
	leitura = "Digite o mes: ";
	mes = lerInteiroCorretamente(leitura);

        leitura = clincia.pagamentos.relatorioDePagamentosFuncionariosNoMes(mes);//imprime 'vazio' se estiver vazio e 'mes incorreto' se estiver com mes incorreto
        mensagemInformacao(leitura);

    }

    //---------------------Fim do Gerar Relatorios-------------------------




    //--------------------- Manipular Pacientes------------------------------



    public void manipularPaciente(Clinica clinica)//manipula pacientes, adicionar remove, e edita
    {
        String leitura = "";
	int opcaoEntraOuSai;

	do
	{
            leitura = "\t\tBEM VINDO A TELA DOS(AS) PACIENTES DA CLINICA: "
                    + clinica.getNomeDaClinica() + "\n\n"
                    +  "[0]-Sair\n[1]-Adicionar Paciente\n[2]-Remover Paciente\n[3]-Editar Paciente\n[4]-Imprimir Pacientes\n\nDigite: ";
            
            opcaoEntraOuSai = lerInteiroCorretamente(leitura);

            switch (opcaoEntraOuSai)
            {
		case 0://sai do loop
                    return;
                    
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
                    
                    leitura = clinica.imprimirPacientes();
                    mensagemInformacao(leitura);
                  
                    break;

		default:
                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
            }
	} while (true);
    }

    public void adicionarPaciente(Clinica clinica)//funcao que adiciona pacientes
    {
	int posicao;
	Paciente paciente = new Paciente();

	//ler paciente
	lerPaciente(paciente);

	//apos ler paciente eh so cadastrar na clinica
	clinica.adicionarPaciente(paciente);

    }

    public void lerPaciente(Paciente paciente)
    {
        String leitura = "";
	int opcao;
	String nome, endereco;
	String cpf, telefone;

	do
	{
            //ler nome
            leitura ="\nDigite o Nome do Paciente: ";
            nome = lerStringCorretamente(leitura);

            while (!paciente.setNome(nome))
            {
                 leitura ="\nDigite o Nome do Corretamente: ";
                nome = lerStringCorretamente(leitura);
            }

            //ler endereco
            leitura = "\nDigite o Endereco do Paciente: ";
            endereco = lerStringCorretamente(leitura);

            while (!paciente.setEndereco(endereco))
            {
               leitura = "\nDigite corretamente o Endereco: ";
               endereco = lerStringCorretamente(leitura);
            }

            //ler cpf
            leitura = "\nDigite o CPF do Paciente: ";
            cpf = lerStringCorretamente(leitura);
            while (!paciente.setCpf(cpf))
            {
		leitura = "\nDigite corretamente o CPF: !";
		cpf = lerStringCorretamente(leitura);
            }
			
            //ler telefone
            leitura = "\nDigite o Telefone do Paciente: ";
            telefone = lerStringCorretamente(leitura);
            
            while(!paciente.setTelefone(telefone))
            {
		leitura = "\nDigite corretamente o Telefone: ";
		telefone = lerStringCorretamente(leitura);
            }
		
            break;

	} while (true);
    }

    public void removerPaciente(Clinica clinica)//funcao que remove um paciente da clinica
    {
        String leitura = "";
	int posicao;
	do
	{
            if (clinica.pacientes.isEmpty())//se estiver sem paciente nao ha o que remover
            {
                mensagemErro("\nSem Pacientes\n\n !");
                return;
            }

            leitura = clinica.imprimirPacientes()
                    + "\n[0]-Para Sair\nDigite o numero do Paciente a ser removido: ";
            
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }

            else if (posicao > clinica.pacientes.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
                continue;
            }

            clinica.removerPaciente(posicao);//remove paciente
            break;
            
	} while (true);
    }


    public void editarPaciente(Clinica clinica)//funcao que edita pacientes
    {
	int posicao;
        String leitura = "";
        
	if (clinica.pacientes.isEmpty())//se estiver sem pacientes nao ha o que editar 
	{
            mensagemErro("\nSem Pacientes\n\n !");
            return;
	}

	do
	{
            leitura = clinica.imprimirPacientes()// imprime os pacientes
                    + "\n[0]-Para Sair\nDigite o numero do Item a ser Editado: ";
	
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }
            else if (posicao > clinica.pacientes.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            //funcao que edita dados do paciente
            editaPaciente(clinica.retornarPaciente(posicao));
            break;

	} while (true);
    }


    //funcao que edita paciente ja existe "editaPaciente"



    //---------------------Fim do Manipular Pacientes-------------------------




    //--------------------- Manipular Funcionarios------------------------------



    public void manipularFuncionario(Clinica clinica)//manipula funcionarios, adicionar remove, e edita
    {
	int opcaoEntraOuSai;
        String leitura = "";

	do
	{
            leitura = "\t\tBEM VINDO A TELA DOS(AS) FUNCIONARIOS DA CLINICA: "
                    + clinica.getNomeDaClinica() + "\n\n"
                    +"[0]-Sair\n[1]-Adicionar Funcionario\n[2]-Remover Funcionario\n[3]-Editar Funcionario\n[4]-Imprimir Funcionarios"
                    + "\n\nDigite: ";
            
            opcaoEntraOuSai = lerInteiroCorretamente(leitura);

            switch (opcaoEntraOuSai)
            {
		case 0://sai do loop
                    return;
                    
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
                    leitura = clinica.imprimirAssistentes();
                    mensagemInformacao(leitura);
                   
                    break;


		default:
                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");             
                    break;
            }

        } while (true);
    }
    
    public void adicionarFuncionario(Clinica clinica)//funcao que adiciona funcionario
    {
        String leitura = "";
	int posicao;
	Assistente funcionario = new Assistente();

	//ler funcionario
	lerFuncionario(funcionario);

	//apos ler funcionario eh so cadastrar na clinica
	clinica.adicionarAssistente(funcionario);
    }

    public void lerFuncionario(Assistente funcionario)//le funcionarios corretamente
    {
	int opcao;
        String nome, endereco;
	String cpf, telefone;
        String leitura = "";

	do
	{
            //ler nome
            leitura = "\nDigite o Nome do Funcionario: ";
            nome = lerStringCorretamente(leitura);

            while (!funcionario.setNome(nome))
            {
		leitura = "\nDigite o nome corretamente: ";
		nome = lerStringCorretamente(leitura);
            }

            //ler endereco
            leitura = "\nDigite o Endereco do Funcionario: ";
            endereco = lerStringCorretamente(leitura);

            while (!funcionario.setEndereco(endereco))
            {
		leitura = "\nDigite corretamente o Endereco: ";
		endereco = lerStringCorretamente(leitura);
            }

            //ler cpf
            leitura = "\nDigite o CPF do Funcionario: ";
            cpf = lerStringCorretamente(leitura);
            
            while (!funcionario.setCpf(cpf))
            {
		leitura = "\nDigite corretamente o CPF: ";
		cpf = lerStringCorretamente(leitura);
            }

            //ler telefone
            leitura = "\nDigite o Telefone do Funcionario: ";
            telefone = lerStringCorretamente(leitura);
            
            while (!funcionario.setTelefone(telefone))
            {
		leitura = "\nDigite corretamente o Telefone: ";
            	telefone = lerStringCorretamente(leitura);
            }
            break;
        } while (true);

    }
    
    public void removerFuncionario(Clinica clinica)//funcao que remove funcionarios
    {
        String leitura = "";
	int posicao;
        
	do
	{
            if (clinica.assistentes.isEmpty())//se nao tiver funcionario nao ha o que remover
            {
                mensagemErro("\nSem Funcionarios \n\n !");
                return;
            }

            leitura = clinica.imprimirAssistentes()
                    +"\n[0]-Para Sair\nDigite o numero do Funcionario a ser removido: ";
	
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }

            else if (posicao > clinica.assistentes.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            clinica.removerAssistente(posicao);//remove funcionario na posicao escolhida pela o usuario
            
            break;
	} while (true);
    }
    
    public void editarFuncionario(Clinica clinica)//funcao que edita funcionarios
    {
	String leitura = "";
	int posicao;
        
	if (clinica.assistentes.isEmpty())//sem funcionarios nao ha o que editar 
	{
            mensagemErro("\nSem Funcionarios\n\n !");
            return;
	}

	do
	{
            leitura = clinica.imprimirAssistentes()//imprime os funcionarios
                    +"\n[0]-Para Sair\nDigite o numero do Funcionario a ser Editado: ";
            
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
                return;
            }
            else if (posicao > clinica.assistentes.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            //funcao que edita dados do funcionario
            editaFuncionario(clinica.retornarAssistente(posicao));
            break;

	} while (true);
    }

    public void editaFuncionario(Assistente assistente)//funcao que edita um funcionario /atualiza dados
    {
	int opcao;
	String nome, endereco;
	String cpf, telefone;
        String leitura = "";

	do
	{
            leitura = assistente.toString()//imprime um funcionario
                    + "\n\n[0]-Sair\n[1]-Editar Nome\n[2]-Editar Endereco\n[3]-Editar CPF\n[4]-Editar Telefone"
                    + "\n\nDigite: ";
            
            opcao = lerInteiroCorretamente(leitura);

            switch (opcao)
            {

                case 0://sai do loop
                    return;

		case 1:
                    //editar nome
                    leitura = "\nDigite o novo Nome: ";
                    nome = lerStringCorretamente(leitura);
                            
                    if (!assistente.setNome(nome))
                    {
			mensagemErro("\nDigite corretamente o Nome\n\n !");
                    }
                    break;

		case 2:
                    //editar endereco
                    leitura = "\nDigite o novo Endereco: ";
                    endereco = lerStringCorretamente(leitura);
                    
                    if (!assistente.setEndereco(endereco))
                    {
			mensagemErro("\nDigite corretamente o Endereco\n\n !");
                    }
                    break;

		case 3:
                    // editar cpf
                    leitura = "\nDigite o novo CPF: ";
                    cpf = lerStringCorretamente(leitura);
                    if (!assistente.setCpf(cpf))
                    {
			mensagemErro("\nDigite corretamente o cpf\n\n !");
                    }
                    break;

		case 4:
                    // editar telefone
                    leitura = "\nDigite o novo Telefone: ";
                    telefone = lerStringCorretamente(leitura);
                    
                    if (!assistente.setTelefone(telefone))
                    {
                        mensagemErro("\nDigite corretamente o Telefone\n\n !");
                    }
                    break;

		default:
                    //opcao incorreta
                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
            }

	} while (true);
    }

    //--------------------- Fim do Manipular Funcionarios-------------------------




    //--------------------- Manipular Especialista------------------------------



    public void manipularEspecialista(Clinica clinica)//manipula especialista, adicionar, remove, e edita
    {
	int opcaoEntraOuSai;
        String leitura = "";
        
	do
	{
            leitura = "\t\tBEM VINDO A TELA DOS(AS) ESPECIALISTA DA CLINICA: " 
                    + clinica.getNomeDaClinica() + "\n\n"
                    + "[0]-Sair\n[1]-Adicionar Especialista\n[2]-Remover Especialista\n[3]-Editar Especialista\n[4]-Imprimir Especialistas"
                    + "\n\nDigite: ";
            
            opcaoEntraOuSai = lerInteiroCorretamente(leitura);

            switch (opcaoEntraOuSai)
            {
                case 0://sai do loop
                    return;
			
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
                    
                    leitura = clinica.imprimirEspecialistas();
                    mensagemInformacao(leitura);
                    break;


		default:
                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
            }

	} while (true);
    }

    public void adicionarEspecialista(Clinica clinica)//funcao que adiciona especialista
    {
	Assistente assistente = new Assistente();
	Especialista especialista = new Especialista();
	int posicao;
        String leitura = "";
        
	do
	{
            if (clinica.assistentes.isEmpty())//sem funcionario nao ha especilistas a serem adicionados
            {
                mensagemErro("\nSem Funcionarios \n\n !");
		return;
            }

            leitura = clinica.imprimirAssistentes()//imprimi os funcionarios
                    + "\n[0]-Para Sair\nDigite o numero do Funcionario que eh Especialista: ";
            
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }

            else if (posicao > clinica.assistentes.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            assistente = clinica.retornarAssistente(posicao);

            especialista.setNome(assistente.getNome());
            especialista.setEndereco(assistente.getEndereco());
            especialista.setCpf(assistente.getCpf());
            especialista.setTelefone(assistente.getTelefone());

            clinica.adicionarEspecialista(especialista);

            break;
        } while (true);
    }

    public void removerEspecialista(Clinica clinica)//funcao que remove Especialista
    {
        String leitura = "";
	int posicao;
        
	do
	{
            if (clinica.especialistas.isEmpty())//se nao tiver especialistas nao ha o que remover
            {
		mensagemErro("\nSem Especialistas \n\n !");
		return;
            }

            leitura = clinica.imprimirEspecialistas()//imprime os especialistas da clinica
                    + "\n[0]-Para Sair\nDigite o numero do Especialista a ser removido: ";
            
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
                return;
            }

            else if (posicao > clinica.especialistas.size() || posicao < 1)//posicao incorreta
            {
                mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            clinica.removerEspecialista(posicao);//remove especialista na posicao escolhida
            break;
            
	} while (true);
    }

    public void editarEspecialista(Clinica clinica)//funcao que edita Especialistas
    {
	String leitura = "";
	int posicao;
        
	if (clinica.especialistas.isEmpty())//sem especialistas nao ha o que editar 
	{
            mensagemErro("\nSem Especialista\n\n !");
            return;
	}

	do
	{
            leitura = clinica.imprimirEspecialistas()//imprime especialistas da clinica
                    + "\n[0]-Para Sair\nDigite o numero do Especialista a ser Editado: ";
	
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }
            else if (posicao > clinica.especialistas.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            //funcao que edita dados do paciente
            editaEspecialista(clinica, clinica.retornarEspecialista(posicao));
            break;

	} while (true);
    }
    
    public void editaEspecialista(Clinica clinica, Especialista especialista)//funcao que edita especialista/atualiza dados
    {
        String leitura = "";
	int opcao;
	String nome, endereco;
	String cpf, telefone;

	do
	{
            leitura = especialista.toString()//imprime um especialista
                    +"\n\n[0]-Sair\n[1]-Editar Nome\n[2]-Editar Endereco\n[3]-Editar CPF\n[4]-Editar Telefone\n[5]-Editar Assistente"
                    + "\n\nDigite: ";
            
            opcao = lerInteiroCorretamente(leitura);

            switch (opcao)
            {

		case 0://sai do loop
                    return;		

		case 1:
                    //editar nome
                    leitura = "\nDigite o novo Nome: ";
                    nome = lerStringCorretamente(leitura);
                    
                    if (!especialista.setNome(nome))
                    {
			mensagemErro("\nDigite corretamente o Nome\n\n !");
                    }
                    break;

		case 2:
                    //editar endereco
                    leitura = "\nDigite o novo Endereco: ";
                    endereco = lerStringCorretamente(leitura);
                    
                    if (!especialista.setEndereco(endereco))
                    {
			mensagemErro("\nDigite corretamente o Endereco\n\n !");
                    }
                    break;

		case 3:
                    // editar cpf
                    leitura = "\nDigite o novo CPF: ";
                    cpf = lerStringCorretamente(leitura);
                    if (!especialista.setCpf(cpf))
                    {
                        mensagemErro("\nDigite corretamente o cpf\n\n !");
                    }
                    break;

		case 4:
                    // editar telefone
                    leitura = "\nDigite o novo Telefone: ";
                    telefone = lerStringCorretamente(leitura);
                    
                    if (!especialista.setTelefone(telefone))
                    {
			mensagemErro("\nDigite corretamente o Telefone\n\n !");
                    }
                    break;

		case 5:
                    editarAssistenteDoEspecialista(clinica, especialista);//cadastra ou troca a assistente de um especialista 
                    break;

		default:
                    //opcao incorreta

                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
            }

	} while (true);
    }


    public void editarAssistenteDoEspecialista(Clinica clinica, Especialista especialista)//cadastra ou troca a assistente de um especialista 
    {
	int opcao;
	String nome, endereco;
	String cpf, telefone;
        String leitura = "";

	do
	{
            leitura = especialista.toString()
                    + "\n\n[0]-Sair\n[1]-Trocar Assistente\n[2]-Remover Assistente"
                    + "\n\nDigite: ";
            
            opcao = lerInteiroCorretamente(leitura);

            switch (opcao)
            {

		case 0:
                    return;

		case 1:
                    //troca ou adiciona a assistente do especialista
                    trocarAssistenteDoEspecialista(clinica, especialista);
                    break;

		case 2:
			//zerar assistente
			especialista.assistente.setNome("sem assistente");
			especialista.assistente.setEndereco("sem assistente");
			especialista.assistente.setTelefone("9999999999");
			especialista.assistente.setCpf("12345678900");
			break;

		default:
                    //opcao incorreta

                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
	}

	} while (true);
    }

    public void trocarAssistenteDoEspecialista(Clinica clinica, Especialista especialista)//troca ou adiciona a assistente do especialista
    {
	int posicao;
        String leitura = "";
        
	do
	{
            if (clinica.assistentes.isEmpty())
            {
                mensagemErro("\nSem Funcionarios \n\n !");
                return;
            }

            leitura = clinica.imprimirAssistentes()
                    +"\n[0]-Para Sair\nDigite o numero do Funcionario a ser Assistente: ";
                
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }

            else if (posicao > clinica.assistentes.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            especialista.assistente = new Assistente(clinica.retornarAssistente(posicao));
            break;
            
	} while (true);
    }


    //--------------------- Fim do Manipular Especialista-------------------------


    //--------------------- Manipular Recepcionista------------------------------



    public void manipularRecepcionista(Clinica clinica)//manipula adicionar, remove e imprime recepcionista
    {
	int opcaoEntraOuSai;
        String leitura = "";

	do
	{
            leitura = "\t\tBEM VINDO A TELA DO(A) RECEPCIONISTA DA CLINICA: " 
                    + clinica.getNomeDaClinica() + "\n\n"
                    + "[0]-Sair\n[1]-Adicionar Recepcionista\n[2]-Remover Recepcioista\n[3]-Imprimir Recepcionista"
                    + "\n\nDigite: ";
            
            opcaoEntraOuSai = lerInteiroCorretamente(leitura);

            switch (opcaoEntraOuSai)
            {
		case 0://sai do loop
                    return;
		case 1:
                    //adicionar Recepcionista
                    adicionarRecepcionista(clinica);
                    break;

		case 2:
                    //remover recepcionista
                    clinica.recepcionista.setNome("sem recepcionista");
                    clinica.recepcionista.setEndereco("sem recepcionista");
                    clinica.recepcionista.setTelefone("9999999999");
                    clinica.recepcionista.setCpf("12345678900");

                    break;

		case 3:
                    leitura = "\nRecepcionista: \n" 
                            + clinica.recepcionista.toString();
                    mensagemInformacao(leitura);

                    break;

		default:
                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
            }

	} while (true);
    }


    public void adicionarRecepcionista(Clinica clinica)//funcao que adiciona recepcionista
    {
	Assistente assistente = new Assistente();
        String leitura = "";
        
	int posicao;
	do
	{
            if (clinica.assistentes.isEmpty())//sem funcionario nao ha recepcionista a ser escolhida
            {
                mensagemErro("\nSem Funcionarios \n\n !");
		return;
            }

            leitura = clinica.imprimirAssistentes()//imprime os funcionarios
                    + "\n[0]-Para Sair\nDigite o numero do Funcionario que sera Recepcionista: ";
            
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }

            else if (posicao > clinica.assistentes.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            assistente = clinica.retornarAssistente(posicao);

            clinica.recepcionista.setNome(assistente.getNome());
            clinica.recepcionista.setEndereco(assistente.getEndereco());
            clinica.recepcionista.setCpf(assistente.getCpf());
            clinica.recepcionista.setTelefone(assistente.getTelefone());

            break;
	} while (true);
    }


    //--------------------- Fim do Manipular Recepcionista-------------------------



    //--------------------- Manipular Pagamentos------------------------------
    //manipular pagamentos nao maniulados ate entao, remover pagamento especifico de paciente ou todos os pagamentos
    //remover pagamento especifico de funcionario ou todos os pagamentos


    public void manipularPagamentos(Clinica clinica)//manipula pagamentos
    {
	int opcaoEntraOuSai;
        String leitura = "";

	do
	{
            leitura = "\t\tBEM VINDO A TELA DE PAGAMENTOS DA CLINICA: "
                    + clinica.getNomeDaClinica() + "\n\n"
                    +  "[0]-Sair\n[1]-Pagamentos Funcionarios\n[2]-Pagamentos Pacientes\n\nDigite: ";
            
            opcaoEntraOuSai = lerInteiroCorretamente(leitura);

            switch (opcaoEntraOuSai)
            {
		case 0:///sai do loop
                    return;

		case 1:
                    //manipular pagamentos de funcionario
                    manipularPagamentosFuncionarios(clinica);
                    break;

		case 2:
                    //manipular pagamentos de pacientes
                    manipularPagamentosPacientes(clinica);

                    break;

		default:
                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
            }

	} while (true);
    }


    public void manipularPagamentosFuncionarios(Clinica clinica)//manipula pagamentos de funcionarios
    {
	int posicao;
        String leitura = "";
        
	do
	{
            if (clinica.pagamentos.pagamentosFuncionarios.isEmpty())//nao ha pagamentos de funcionarios para manipula
            {
		mensagemErro("\nSem Pagamentos de Funcionarios \n\n !");
		return;
            }

            leitura = clinica.pagamentos.relatorioDePagamentosFuncionarios()//imprime os pagamentos existentes
                    +"\n[0]-Para Sair\nDigite o numero do Pagamento a ser escolhido: ";
            
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }

            else if (posicao > clinica.pagamentos.pagamentosFuncionarios.size() || posicao < 1)//posicao incorreta
            {
                mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            manipularPagamentosFuncionarios2(clinica, clinica.pagamentos.retornarPagamentoFuncionario(posicao));
            break;
	} while (true);
    }

    public void manipularPagamentosFuncionarios2(Clinica clinica, PagamentoFuncionario pagamentoFuncionario)//manipula pagamentos de um funcionario
    {
	int opcaoEntraOuSai;
        String leitura = "";

	do
	{
            leitura = pagamentoFuncionario.toString()//imprime os pagamentos de um paciente
                    + "\n[0]-Sair\n[1]-Apagar Pagamento\n[2]-Apagar Item do Pagamento\n\nDigite: ";
            
            opcaoEntraOuSai = lerInteiroCorretamente(leitura);

            switch (opcaoEntraOuSai)
            {
		case 0:
                    return;
                    
		case 1:
                    //apagar pagamento
                    clinica.pagamentos.removerPagamentoFuncionario(pagamentoFuncionario.funcionario.getCpf());
                    return;

		case 2:
                    //apagar item do pagamento do funcionario
                    apagarItemPagamentosFuncionarios(clinica, pagamentoFuncionario);//apaga um item de pagamento do funcionario

                    break;

		default:
                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
            }

	} while (true);
    }


    public void apagarItemPagamentosFuncionarios(Clinica clinica, PagamentoFuncionario pagamentoFuncionario)//apaga um item de pagamento do funcionario
    {
        String leitura = "";
        
	int posicao;
	do
	{
            if (pagamentoFuncionario.pagamentosFuncionario.isEmpty())//nao ha item de pagamentos de funcionarios para apagar
            {
                mensagemErro("\nSem Itens de Pagamentos de Funcionarios \n\n !");
		return;
            }

            leitura = pagamentoFuncionario.toString()//imprime os pagamentos de um funcionario
                    +"\n[0]-Para Sair\nDigite o numero do Item do Pagamento a ser escolhido: ";
            
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }

            else if (posicao > pagamentoFuncionario.pagamentosFuncionario.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            pagamentoFuncionario.removerItemFolhaDePagamento(posicao);//remove o item do pagamento de um funcionario escolhido
            
            break;
	} while (true);
    }


    public void manipularPagamentosPacientes(Clinica clinica)//manipula pagamentos de pacientes
    {
	int posicao;
        String leitura = "";
        
	do
	{
            if (clinica.pagamentos.pagamentosPacientes.isEmpty())//nao ha pagamentos de pacientes para manipula
            {
		mensagemErro("\nSem Pagamentos de Pacientes \n\n !");
		return;
            }

            leitura = clinica.pagamentos.relatorioDePagamentosPacientes()//imprime os pagamentos dos pacientes
                    + "\n[0]-Para Sair\nDigite o numero do Pagamento a ser escolhido: ";
	
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }

            else if (posicao > clinica.pagamentos.pagamentosPacientes.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            manipularPagamentosPacientes2(clinica, clinica.pagamentos.retornarPagamentoPaciente(posicao));//manipula o pagamento e um paciente escolhido
            break;
            
	} while (true);
    }

    public void manipularPagamentosPacientes2(Clinica clinica, PagamentoPaciente pagamentoPaciente)//manipula pagamentos de um paciente
    {
	int opcaoEntraOuSai;
        String leitura = "";
        
	do
	{
            leitura = pagamentoPaciente.toString()//imprime os pagamentos de um paciente
                    + "\n[0]-Sair\n[1]-Apagar Pagamento\n[2]-Apagar Item do Pagamento\n\nDigite: ";
            
            opcaoEntraOuSai = lerInteiroCorretamente(leitura);

            switch (opcaoEntraOuSai)
            {
		case 0://sai do loop
                    return;
		
		case 1:
                    //apagar pagamento
                    clinica.pagamentos.removerPagamentoPaciente(pagamentoPaciente.paciente.getCpf());
                    return;

		case 2:
                    //apagar item do pagamento do paciente
                    apagarItemPagamentosPacientes(clinica, pagamentoPaciente);//apaga um item de pagamento do paciente

                    break;

		default:
                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
            }

	} while (true);
    }

    public void apagarItemPagamentosPacientes(Clinica clinica, PagamentoPaciente pagamentoPaciente)//apaga um item de pagamento do paciente
    {
	int posicao;
        String leitura = "";
        
	do
	{
            if (pagamentoPaciente.pagamentosPaciente.isEmpty())//nao ha item de pagamentos de paciente a serem apagados
            {
		mensagemErro("\nSem Itens de Pagamentos de Pacientes \n\n !");
		return;
            }

            leitura = pagamentoPaciente.toString()//imprime os pagamentos de um paciente
                    + "\n[0]-Para Sair\nDigite o numero do Item do Pagamento a ser escolhido: ";
            
            posicao = lerInteiroCorretamente(leitura);

            if (posicao == 0)
            {
		return;
            }

            else if (posicao > pagamentoPaciente.pagamentosPaciente.size() || posicao < 1)//posicao incorreta
            {
		mensagemErro("\nPosicao incorreta !\n\n");
		continue;
            }

            pagamentoPaciente.removerItemPagamentoPaciente(posicao);//remove o item de pagamento do cliente escolhido
            break;
	} while (true);
    }
    //--------------------- Fim do Manipular Pagamentos-------------------------
}
