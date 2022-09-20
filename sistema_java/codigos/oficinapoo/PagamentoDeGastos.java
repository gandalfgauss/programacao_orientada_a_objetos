package oficinapoo;


public class PagamentoDeGastos implements Comparable<PagamentoDeGastos>
{
    public Data dataDePagamento;
    public Data dataDeVencimento;
    private String descricao;
    private double valorPago;
    
    //construtores 
    public PagamentoDeGastos()
    {
	dataDePagamento = new Data();
        dataDeVencimento = new Data();
        descricao = " ";
        valorPago = 0.0;           
    }
    
    public PagamentoDeGastos(String descricao, double valorPago)
    {
	dataDePagamento = new Data();
        dataDeVencimento = new Data();
        this.descricao = descricao;
        this.valorPago = valorPago;           
    }

    public PagamentoDeGastos(Data dataDePagamento, Data dataDeVencimento, String descricao, double valorPago)
    {
	this.dataDePagamento = new Data(dataDePagamento);
        this.dataDeVencimento = new Data(dataDeVencimento);

	if (!setDescricao(descricao))
	{
            this.descricao = " ";
	}

	if (!setValorPago(valorPago))
	{
            this.valorPago = 0.0;
	}

    }

    public PagamentoDeGastos(PagamentoDeGastos pagamentoDeGastos)
    {
	this.dataDePagamento =  new Data(pagamentoDeGastos.dataDePagamento);
        this.dataDeVencimento = new Data(pagamentoDeGastos.dataDeVencimento);
	this.descricao = pagamentoDeGastos.descricao;
	this.valorPago = pagamentoDeGastos.valorPago;
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
        return String.format("Descricao: %s Data de Pagamento: %s  Data de Vencimento: %s Valor: %.2f",
               this.descricao, this.dataDePagamento, this.dataDeVencimento,this.valorPago);
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
        
        final PagamentoDeGastos item = (PagamentoDeGastos) o;
        
        return ((this.valorPago == item.getValorPago()) && (this.descricao.equals(item.getDescricao()))
                && (this.dataDePagamento.compareTo(item.dataDePagamento)) == 0 
                && (this.dataDeVencimento.compareTo(item.dataDeVencimento) == 0)); 
    }
    
    //metodo comparavel, ordenar pela data de Vencimento
    public int compareTo(PagamentoDeGastos item)
    {
        return this.dataDeVencimento.compareTo(item.dataDeVencimento);
    }
    
}