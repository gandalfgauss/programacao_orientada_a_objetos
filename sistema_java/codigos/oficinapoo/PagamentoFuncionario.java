package oficinapoo;

import java.util.List;
import java.util.LinkedList;
import java.util.Collections;


public class PagamentoFuncionario
{
    public Assistente funcionario;
    public List<ItemPagamentoFuncionario> pagamentosFuncionario;
    
    //construtor
    public PagamentoFuncionario()
    {
        funcionario = new Assistente();
        pagamentosFuncionario = new LinkedList<ItemPagamentoFuncionario>();
    }

    //construtor
    public PagamentoFuncionario(Assistente funcionario)
    {
        this.funcionario = new Assistente(funcionario);
        pagamentosFuncionario = new LinkedList<ItemPagamentoFuncionario>();
    }   

    //construtor
    public PagamentoFuncionario(PagamentoFuncionario pagamento)
    {
        this.funcionario = new Assistente(pagamento.funcionario);

	//inserir novos elementos
        this.pagamentosFuncionario = new LinkedList<ItemPagamentoFuncionario>();
        
        for(ItemPagamentoFuncionario it : pagamento.pagamentosFuncionario)
        {
            this.pagamentosFuncionario.add(new ItemPagamentoFuncionario(it));
        }	
    }
    
     //ordena pela data os itens pagos ao funcionario
    public void ordenaPagamentosFuncionario()
    {
        Collections.sort(pagamentosFuncionario);                                                             
    }

    public void adicionarItemFolhaDePagamento(ItemPagamentoFuncionario item)//adiciona um item pago ao funcionario de maneira ordenada pela data
    {
	//inserir novos elementos
	ItemPagamentoFuncionario copia = new ItemPagamentoFuncionario(item);
       
        //adicionar o pagamento do paciente
	this.pagamentosFuncionario.add(copia);
        
        //ordenar a lista
        ordenaPagamentosFuncionario();     
    }
    

    public boolean removerItemFolhaDePagamento(int posicao)//dada uma posicao remove um item da folha de Pagamento do funcionario
    {
	//verifica se posicao eh valida e se a folha de pagamento nao eh vazia
	if (pagamentosFuncionario.isEmpty() || posicao >  pagamentosFuncionario.size() || posicao < 1)
	{
            return false;
	}
	
        pagamentosFuncionario.remove(posicao-1);
        
	return true;
    }

    public ItemPagamentoFuncionario retornarItemPagamentoFuncionario(int posicao)//retorna um item pago ao funcionario
    {
	//se a posicao for incorreta retorna o ultimmo
        if(posicao > pagamentosFuncionario.size() || posicao < 1)
        {
            return pagamentosFuncionario.get(pagamentosFuncionario.size()-1);
        }
        
	return pagamentosFuncionario.get(posicao-1);
    }

    public String imprimirFolhaDePagamentoDoMes(int mes)//dado um mes, imprime a folha de paagamento do funcionario naquele mes
    {
	int i = 0;
        String leitura = "";
        
        leitura = "Folha de Pagamento - "+funcionario.getNome()
                +" CPF: "+funcionario.getCpf()+ "\n\n";
        
        //se a lista estiver vazia ou mes incorreto retorna falso
	if (pagamentosFuncionario.isEmpty() || mes < 0 || mes > 12)
	{
            leitura +="Sem Folha De Ponto para esse mes";
            return leitura;
	}


	for (ItemPagamentoFuncionario it : pagamentosFuncionario)
	{
            if (it.dataDePagamento.getMes() == mes)
            {
		i++;
		leitura += "Pagamento "+i+": "+it.toString()+"\n";
            }
	}

        return leitura;
	//return i;
    }
    
     //imprime os Pagamentos do Paciente
    public String toString()
    {
        String retorno = "";
        
        retorno = retorno + "Funcionario: " + funcionario.getNome() + " CPF:" + funcionario.getCpf() + "\n\n";
        
        if ( pagamentosFuncionario.isEmpty())//se nao tiver itens de Pagamentos
	{
		retorno = retorno+ "Sem Pagamentos";
	}
        else
        {
            int i = 1;
            for (ItemPagamentoFuncionario it : pagamentosFuncionario)
            {
		retorno = retorno + "Pagamento " + i + ": " + "\n" + it.toString() + "\n";
		i++;
            }
        }
        
        return retorno;
    }  	
}
