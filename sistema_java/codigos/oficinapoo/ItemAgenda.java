package oficinapoo;

public class ItemAgenda implements Comparable<ItemAgenda>
{
    public DataHora data;
    public Paciente paciente;

    private String descricao;

    //construtores
    public ItemAgenda()
    {
        descricao = " ";
        data = new DataHora();
        paciente = new Paciente();
    }
    
     public ItemAgenda(String descricao)
    {
       if (!setDescricao(descricao))
	{
            this.descricao = " ";
	}
        data = new DataHora();
        paciente = new Paciente();
    }
     
    public ItemAgenda(DataHora data, Paciente paciente, String descricao)
    {
        this.data = new DataHora(data);
        this.paciente = new Paciente(paciente);
        
        if (!setDescricao(descricao))
	{
            this.descricao = " ";
	}
    }
    
    public ItemAgenda(ItemAgenda itemAgenda)
    {
        this.data = new DataHora(itemAgenda.data);
        this.paciente = new Paciente(itemAgenda.paciente);
        this.descricao = itemAgenda.descricao;
    }
	
    //getters
    public String getDescricao()
    {
        return descricao;
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

    //sobrecarga do operador 'printf'
    public String toString()
    {
        return String.format("Data: %s Paciente: %s CPF: %s %s",this.data,
                              this.paciente.getNome(), this.paciente.getCpf(), this.descricao);
    }
    
    //metodo comparavel
    public int compareTo(ItemAgenda item)
    {
        return this.data.compareTo(item.data);
    }
	
}
