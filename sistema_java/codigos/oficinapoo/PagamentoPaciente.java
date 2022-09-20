package oficinapoo;

import java.util.List;
import java.util.LinkedList;
import java.util.Collections;


public class PagamentoPaciente
{
    public Paciente paciente;
    public List<ItemPagamentoPaciente> pagamentosPaciente;
    
    //construtor
    public PagamentoPaciente()
    {
        paciente = new Paciente();
        pagamentosPaciente = new LinkedList<ItemPagamentoPaciente>();
    }


    //construtor
    public PagamentoPaciente(Paciente paciente)
    {
        this.paciente = new Paciente(paciente);
        pagamentosPaciente = new LinkedList<ItemPagamentoPaciente>();
    }   

    //construtor
    public PagamentoPaciente(PagamentoPaciente pagamento)
    {
        this.paciente = new Paciente(pagamento.paciente);

	//inserir novos elementos
        this.pagamentosPaciente = new LinkedList<ItemPagamentoPaciente>();
        
        for(ItemPagamentoPaciente it : pagamento.pagamentosPaciente)
        {
            this.pagamentosPaciente.add(new ItemPagamentoPaciente(it));
        }	
    }
    
     //ordena a os item pagos pelo paciente pela data
    public void ordenaPagamentosPaciente()
    {
        Collections.sort(pagamentosPaciente);                                                             
    }

    public void adicionarItemPagamentoPaciente(ItemPagamentoPaciente item)//adiciona um ItemPago pelo paciente de maneira ordenada pela data
    {
	//inserir novos elementos
	ItemPagamentoPaciente copia = new ItemPagamentoPaciente(item);
       
        //adicionar o pagamento do paciente
	this.pagamentosPaciente.add(copia);
        
        //ordenar a lista
        ordenaPagamentosPaciente();     
    }
    

    public boolean removerItemPagamentoPaciente(int posicao)//dada uma posicao remove um item pago pelo paciente
    {
	//verifica se posicao eh valida e se lista de pagamentos de pacientes nao eh vazia
	if (pagamentosPaciente.isEmpty() || posicao >  pagamentosPaciente.size() || posicao < 1)
	{
            return false;
	}
	
        pagamentosPaciente.remove(posicao-1);
        
	return true;
    }

    public ItemPagamentoPaciente retornarItemPagamentoPaciente(int posicao)//retorna um item pago pelo paciente
    {
	//se a posicao for incorreta retorna o ultimmo
        if(posicao > pagamentosPaciente.size() || posicao < 1)
        {
            return pagamentosPaciente.get(pagamentosPaciente.size()-1);
        }
        
	return pagamentosPaciente.get(posicao-1);
    }

    public String imprimirItensPagosNoMes(int mes)//imprime os itens pagos no mes pelo funcionario
    {
        String leitura = "";
	int i = 0;

        //se a lista estiver vazia ou mes incorreto retorna falso
	if (pagamentosPaciente.isEmpty() || mes < 0 || mes > 12)
	{
		return "Sem Itens";
	}

	for (ItemPagamentoPaciente it : pagamentosPaciente)
	{
            if (it.dataDePagamento.getMes() == mes)
            {
		i++;
		leitura += "Pagamento "+i+": "+it+"\n";
            }
	}

        return leitura;
	//return i;
    }
    
     //imprime os Pagamentos do Paciente
    public String toString()
    {
        String retorno = "";
        
        retorno = retorno + "Paciente: " + paciente.getNome() + " CPF:" + paciente.getCpf() + "\n\n";
        
        if ( pagamentosPaciente.isEmpty())//se nao tiver itens de Pagamentos
	{
		retorno = retorno+ "Sem Pagamentos";
	}
        else
        {
            int i = 1;
            for (ItemPagamentoPaciente it : pagamentosPaciente)
            {
		retorno = retorno + "Pagamento " + i + ": " + "\n" + it.toString() + "\n";
		i++;
            }
        }
        
        return retorno;
    }  
	
}
