package oficinapoo;

import java.util.List;
import java.util.LinkedList;
import java.util.Collections;

public class Pagamentos
{
    public List<PagamentoPaciente> pagamentosPacientes;
    public List<PagamentoFuncionario> pagamentosFuncionarios;
    public List<PagamentoDeGastos> pagamentosDeGastos;
    
    //construtor
    public Pagamentos()
    {
        pagamentosPacientes = new LinkedList<PagamentoPaciente>();
        pagamentosFuncionarios = new LinkedList<PagamentoFuncionario>();
        pagamentosDeGastos = new LinkedList<PagamentoDeGastos>();     
    }

    //construtor
    public Pagamentos(Pagamentos pagamentos)
    {   
	pagamentosPacientes = new LinkedList<PagamentoPaciente>();
        pagamentosFuncionarios = new LinkedList<PagamentoFuncionario>();
        pagamentosDeGastos = new LinkedList<PagamentoDeGastos>();
        
	//inserir novos  pacientes
        for(PagamentoPaciente it : pagamentos.pagamentosPacientes)
        {
            pagamentosPacientes.add(new PagamentoPaciente(it));
        }

	//inserir novos funcionarios
	 for(PagamentoFuncionario it : pagamentos.pagamentosFuncionarios)
        {
            pagamentosFuncionarios.add(new PagamentoFuncionario(it));
        }
         
	//inserir novos gastos
	 for(PagamentoDeGastos it : pagamentos.pagamentosDeGastos)
        {
            pagamentosDeGastos.add(new PagamentoDeGastos(it));
        }
    }

    //--------------Cliente-------------------------

    public void adicionarPagamentoPaciente(PagamentoPaciente pagamentoPaciente)//adiciona os pagamentos de um paciente
    {
	//inserir novos elementos

	for (PagamentoPaciente it :pagamentosPacientes)
	{
            if (it.paciente.getCpf().equals(pagamentoPaciente.paciente.getCpf()))//se o paciente ja existir
            {
		for(ItemPagamentoPaciente item : pagamentoPaciente.pagamentosPaciente)//adicionar os itens da lista passada como parametro na lista ja existente
		{
                    it.adicionarItemPagamentoPaciente(item);
		}
                    return;
            }
	}

	//caso contrario eh so adicionar o pagamento
	this.pagamentosPacientes.add(new PagamentoPaciente(pagamentoPaciente));
    }

    public boolean removerPagamentoPaciente(String cpf)//dado um cpf de um Paciente remove sua lista de pagamentos
    {
	if (pagamentosPacientes.isEmpty())//se tiver vaio a lista de pacientes
	{
            return false;
	}

	//fazer a busca pelo cpf para remover
        int i = 0;
	for (PagamentoPaciente it : pagamentosPacientes)
	{
            if (it.paciente.getCpf().equals(cpf))//se achei o paciente a ser removido
            {           
		pagamentosPacientes.remove(i);        
		return true;
            }
            
            i++;
	}

	return false;
    }

    public PagamentoPaciente retornarPagamentoPaciente(String cpf)//retorna os pagamentos de um Funcionario dada a sua posicao
    {
	for (PagamentoPaciente it : pagamentosPacientes)
	{
            if (it.paciente.getCpf().equals(cpf))
            {

		return it;
            }
	}

	return pagamentosPacientes.get(pagamentosPacientes.size()-1);///retorna ultimo caso nao encontre
    }

    public PagamentoPaciente retornarPagamentoPaciente(int posicao)//retorna os pagamentos de um paciente dado o sua posicao
    {
	return pagamentosPacientes.get(posicao-1);
    }
    
    //------------------------------ Funcionario------------------------------

    public void adicionarPagamentoFuncionario(PagamentoFuncionario pagamentoFuncionario)//adiciona os pagamentos de um Funcionario
    {
        
        for (PagamentoFuncionario it :pagamentosFuncionarios)
	{
            if (it.funcionario.getCpf().equals(pagamentoFuncionario.funcionario.getCpf()))//se o Funcionario ja existir
            {
		for (ItemPagamentoFuncionario item : pagamentoFuncionario.pagamentosFuncionario)//adicionar os itens da lista passada como parametro na lista ja existente
		{
                    it.adicionarItemFolhaDePagamento(item);
		}
                    return;
            }
	}

	//caso contrario eh so adicionar o pagamento
	this.pagamentosFuncionarios.add(new PagamentoFuncionario(pagamentoFuncionario));
        
    }

    public boolean removerPagamentoFuncionario(String cpf)//dado um cpf de um Funcionario remove sua lista de pagamentos
    {
	if (pagamentosFuncionarios.isEmpty())//se tiver vazio a lista de Funcionarios
	{
            return false;
	}

	//fazer a busca pelo cpf para remover

	 int i = 0;
	for (PagamentoFuncionario it : pagamentosFuncionarios)
	{
            if (it.funcionario.getCpf().equals(cpf))//se achei o funcionario a ser removido
            {           
		pagamentosFuncionarios.remove(i);        
		return true;
            }
            
            i++;
	}

	return false;
    }

    public PagamentoFuncionario retornarPagamentoFuncionario(String cpf)//retorna os pagamentos de um Funcionario dada seu cpf
    {
	for (PagamentoFuncionario it : pagamentosFuncionarios)
	{
            if (it.funcionario.getCpf().equals(cpf))
            {
		return it;
            }
	}

	return pagamentosFuncionarios.get(pagamentosFuncionarios.size()-1);///retorna ultimo caso nao encontre
    }

    public PagamentoFuncionario retornarPagamentoFuncionario(int posicao)//retorna os pagamentos de um Funcionario dada a sua posicao
    {
	return pagamentosFuncionarios.get(posicao-1);
    }
    
    

    //---------------------------Gastos Conta -----------------
    
    
    //ordena pela data os itens de gastos (contas) pagos
    public void ordenaPagamentosDeGastos()
    {
        Collections.sort(pagamentosDeGastos);                                                             
    }

    public void adicionarPagamentoDeGastos(PagamentoDeGastos item)//adiciona os pagamentos de contas de maneira ordenada pela data de vencimento
    {
	//inserir novos elementos
	PagamentoDeGastos copia = new PagamentoDeGastos(item);

	this.pagamentosDeGastos.add(copia);
        
        //ordena lista pela data de vencimento
        ordenaPagamentosDeGastos();      
      }

    public boolean removerPagamentoDeGastos(int posicao)//dado uma posicao remove um item de pagamento de conta
    {
	if (pagamentosDeGastos.isEmpty() || posicao > pagamentosDeGastos.size() || posicao < 1)//se tiver vaio a lista de Funcionarios
	{
            return false;
	}

	//remove o item
	pagamentosDeGastos.remove(posicao-1);

	return true;
    }

    public PagamentoDeGastos retornarPagamentoDeGastos(int posicao)//dada uma posicao retorna um item de pagamento de conta
    {
	return pagamentosDeGastos.get(posicao-1);
    }

    //---------------------------------------------------------

    public void mostrarPagamentosRealizados()//mostra todos os pagamentos realizados
    {

	System.out.println("\t\tPagamentos dos Pacientes:\n");

	if (pagamentosPacientes.isEmpty())
	{
            System.out.println("Sem pagamentos de Pacientes\n");
	}

	for (PagamentoPaciente it : pagamentosPacientes)
	{
            System.out.printf("%s\n\n", it.toString());
	}

	System.out.println("\t\tPagamentos dos Funcionarios:\n");

	if (pagamentosFuncionarios.isEmpty())
	{
            System.out.println("Sem pagamentos de Funcionarios\n");
	}

	for (PagamentoFuncionario it : pagamentosFuncionarios)
        {
            System.out.printf("%s\n\n", it.toString());
	}

	System.out.println("\t\tPagamentos de Contas:\n");

	if (pagamentosDeGastos.isEmpty())
	{
            System.out.println("Sem Pagamentos de Contas" );
	}

	for (PagamentoDeGastos it : pagamentosDeGastos)
	{
            System.out.printf("%s\n\n", it.toString());
	}
    }

    public String relatorioDePagamentosPacientes() //mostra todos os pagamentos realizados pelos pacientes
    {
	int i = 1;
        String leitura = "";

	if (pagamentosPacientes.isEmpty())
	{
            leitura = "Sem pagamentos de Pacientes\n";

            return leitura;
	}

	leitura = "\t\t\tPagamentos dos Pacientes:\n";

	for (PagamentoPaciente it : pagamentosPacientes)
	{
            leitura += i+" - "+it.toString()+"\n\n";
            i++;
	}

	return leitura;
    }

    public String relatorioDePagamentosFuncionarios()//mostra todos os gastos com funcionarios
    {
	int i = 1;
        
        String leitura = "";

	if (pagamentosFuncionarios.isEmpty())
	{
            leitura = "Sem pagamentos de Funcionarios\n";
            return leitura;
	}

	leitura = "\t\tPagamentos dos Funcionarios:\n";

	for (PagamentoFuncionario it : pagamentosFuncionarios)
	{
            leitura += i +" - "+it.toString()+"\n\n";
            i++;
	}

	return leitura;
    }

    public String relatorioDeGastos()//mostra todos osgastos com contas
    {
	int i = 1;
        String leitura = "";
	leitura = "\t\tPagamentos de Contas:\n";

	if (pagamentosDeGastos.isEmpty())
	{
            leitura += "Sem Pagamentos de Contas";
            return leitura;
	}

	for (PagamentoDeGastos it : pagamentosDeGastos)
	{
            leitura += "Item "+i+":\n"+ it.toString()+"\n\n";
            i++;
	}

	return leitura;
    }
//--------------------------------------------------------

    public String relatorioDePagamentosPacientesNoMes(int mes)//mostra todos os pagamentos realizados pelos pacientes em um mes
    {
        String leitura = "";
        
	if (pagamentosPacientes.isEmpty())
	{
            leitura = "Sem pagamentos de Pacientes";
            return leitura;
	}

	if ( mes < 0 || mes > 12)
	{
            leitura = "Mes incorreto\n";
            return leitura;
	}

	leitura = "\t\tPagamentos dos Pacientes:\n";

	for (PagamentoPaciente it : pagamentosPacientes)
	{
            leitura += "Paciente: "+it.paciente.getNome()+" CPF: "+it.paciente.getCpf()+"\n"
                    +it.imprimirItensPagosNoMes(mes) +"\n";
	}
        
        return leitura;
    }

    public String relatorioDePagamentosFuncionariosNoMes(int mes)//mostra todos os gastos com funcionarios em um mes
    {
        String leitura = "";
	if (pagamentosFuncionarios.isEmpty())
	{
            leitura = "Sem pagamentos dos Funcionarios !\n";
            return leitura;
	}

	if (mes < 0 || mes > 12)
	{
            leitura = "Mes incorreto\n";
            return leitura;
	}

	leitura = "\t\tPagamentos dos Funcionarios:\n";

	for (PagamentoFuncionario it : pagamentosFuncionarios)
	{
            leitura += it.imprimirFolhaDePagamentoDoMes(mes);
	}
        
        return leitura;
    }

    public String relatorioDeGastosNoMes(int mes)//dado um mes, imprime a folha de paagamento do funcionario naquele mes
    {
        String leitura = "";
	int i = 0;
	if (pagamentosDeGastos.isEmpty())
	{
            leitura = "Folha de Pagamento vazia !";
            return leitura;
	}

	if ( mes < 0 || mes > 12)
	{
           leitura = "Mes incorreto";
           return leitura;
	}

        leitura = "\t\tPagamentos de Contas:\n";

	for (PagamentoDeGastos it : pagamentosDeGastos)
	{
            if (it.dataDeVencimento.getMes() == mes)
            {
		i++;
		leitura += "Pagamento "+i+": "+it.toString()+"\n";
            }
	}
        
        return leitura;
    }

    //----------------------------------------------------
}
