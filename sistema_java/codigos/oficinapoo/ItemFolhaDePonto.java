
package oficinapoo;


public class ItemFolhaDePonto implements Comparable<ItemFolhaDePonto>
{
    public Data data;
    private String observacao;
    
    //construtores
    public ItemFolhaDePonto()
    {
        data = new Data();
        observacao = " "; 
    }
    
    public ItemFolhaDePonto(String observacao)
    {
        data = new Data();
        if (!setObservacao(observacao))
	{
            this.observacao = " ";
	}
    }
    
    
    public ItemFolhaDePonto(Data data, String observacao)
    {
        this.data = new Data(data);
         if (!setObservacao(observacao))
	{
            this.observacao = " ";
	}
    }

    public ItemFolhaDePonto(ItemFolhaDePonto item)
    {
       this.data = new Data(item.data);
       this.observacao = item.observacao;  
    }
    
    //getters
    public String getObservacao()
    {
        return observacao;
    }

    //setters
    public boolean setObservacao(String observacao)
    {
        if (observacao.equals("") || observacao.equals(" "))//conferir se nome eh valido, validacao fraca mas ajuda um pouco
	{
            return false;
	}

	this.observacao = observacao;

	return true;
    }
    
    //metodo comparavel
    public int compareTo(ItemFolhaDePonto item)
    {
        return this.data.compareTo(item.data);
    }
   
    //sobrecarga do operador 'printf'
    public String toString()
    {
        return String.format("Data: %s Observacao: %s",this.data,this.observacao);
    }

}
