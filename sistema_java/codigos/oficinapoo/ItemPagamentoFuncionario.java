package oficinapoo;


public class ItemPagamentoFuncionario implements Comparable<ItemPagamentoFuncionario>
{
    public Data dataDePagamento;

    private String descricao;
    private double valorPago;
    
    //construtores 
    public ItemPagamentoFuncionario()
    {
	dataDePagamento = new Data();
        descricao = " ";
        valorPago = 0.0;           
    }
    
    public ItemPagamentoFuncionario(String descricao, double valorPago)
    {
	dataDePagamento = new Data();
        this.descricao = descricao;
        this.valorPago = valorPago;           
    }

    public ItemPagamentoFuncionario(Data dataDePagamento, String descricao, double valorPago)
    {
	this.dataDePagamento = new Data(dataDePagamento);

	if (!setDescricao(descricao))
	{
            this.descricao = " ";
	}

	if (!setValorPago(valorPago))
	{
            this.valorPago = 0.0;
	}

    }

    public ItemPagamentoFuncionario(ItemPagamentoFuncionario pagamentoFuncionario)
    {
	this.dataDePagamento =  new Data(pagamentoFuncionario.dataDePagamento);
	this.descricao = pagamentoFuncionario.descricao;
	this.valorPago = pagamentoFuncionario.valorPago;
    }

    //getters

    public String getDescricao()
    {
	return descricao;
    }

    public double getValorPago()
    {
	return valorPago;
    }


    //setters
    public boolean setDescricao(String descricao)
    {
	if (descricao.equals("") || descricao.equals(" "))//conferir se nome eh valido, validacao fraca mas ajuda um pouco
	{
            return false;
	}

	this.descricao = descricao;

	return true;
}


    public boolean setValorPago(double valorPago)
    {
	if (valorPago < 0.0)//conferir se valor eh valido
	{
            return false;
	}

	this.valorPago = valorPago;

	return true;
    }

    //sobrecarga do operador 'printf'
    public String toString()
    {
        return String.format("Data: %s %s Valor: %.2f",this.dataDePagamento,this.descricao,this.valorPago);
    }
    
    //sobrecarga do operador ==
    public boolean equals(Object o)
    {
        if(this == o)
        {
            return true;
        }
        
        if(o == null)
        {
            return false;
        }
        
        if(getClass() != o.getClass())
        {
            return false;
        }
        
        final ItemPagamentoFuncionario item = (ItemPagamentoFuncionario) o;
        
        return ((this.valorPago == item.getValorPago()) && (this.descricao.equals(item.getDescricao()))
                && this.dataDePagamento.compareTo(item.dataDePagamento) == 0); 
    }
    
    //metodo comparavel
    public int compareTo(ItemPagamentoFuncionario item)
    {
        return this.dataDePagamento.compareTo(item.dataDePagamento);
    }
    
}