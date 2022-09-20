package oficinapoo;


public class ItemPagamentoPaciente implements Comparable<ItemPagamentoPaciente>
{
    public Data dataDePagamento;

    private String nomeDoPagamento;
    private double valorPago;
    
    //construtores 
    public ItemPagamentoPaciente()
    {
	dataDePagamento = new Data();
        nomeDoPagamento = " ";
        valorPago = 0.0;           
    }
    
    public ItemPagamentoPaciente(String nomeDoPagamento, double valorPago)
    {
	dataDePagamento = new Data();
        this.nomeDoPagamento = nomeDoPagamento;
        this.valorPago = valorPago;           
    }

    public ItemPagamentoPaciente(Data dataDePagamento, String nomeDoPagamento, double valorPago)
    {
	this.dataDePagamento = new Data(dataDePagamento);

	if (!setNomeDoPagamento(nomeDoPagamento))
	{
            this.nomeDoPagamento = " ";
	}

	if (!setValorPago(valorPago))
	{
            this.valorPago = 0.0;
	}

    }

    public ItemPagamentoPaciente(ItemPagamentoPaciente pagamentoPaciente)
    {
	this.dataDePagamento =  new Data(pagamentoPaciente.dataDePagamento);
	this.nomeDoPagamento = pagamentoPaciente.nomeDoPagamento;
	this.valorPago = pagamentoPaciente.valorPago;
    }

    //getters

    public String getNomeDoPagamento()
    {
	return nomeDoPagamento;
    }

    public double getValorPago()
    {
	return valorPago;
    }


    //setters
    public boolean setNomeDoPagamento(String descricao)
    {
	if (descricao.equals("") || descricao.equals(" "))//conferir se nome eh valido, validacao fraca mas ajuda um pouco
	{
		return false;
	}

	this.nomeDoPagamento = descricao;

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
        return String.format("Data: %s %s Valor: %.2f",this.dataDePagamento,this.nomeDoPagamento,this.valorPago);
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
        
        final ItemPagamentoPaciente item = (ItemPagamentoPaciente) o;
        
        return ((this.valorPago == item.getValorPago()) && (this.nomeDoPagamento.equals(item.getNomeDoPagamento()))
                && this.dataDePagamento.compareTo(item.dataDePagamento) == 0); 
    }
    
    //metodo comparavel
    public int compareTo(ItemPagamentoPaciente item)
    {
        return this.dataDePagamento.compareTo(item.dataDePagamento);
    }
    
}