package oficinapoo;


public class Paciente extends Pessoa
{
    
    //construtores
    public Paciente()
    {
        super("", "", "12345678900", "33988888888");
    }
    
    public Paciente(String nome, String endereco, String cpf, String telefone)
    {
        super(nome, endereco, cpf, telefone);
    }
    
    public Paciente(Paciente paciente)
    {
        super(paciente.getNome(), paciente.getEndereco(), paciente.getCpf(), paciente.getTelefone());
    }
   

    //getters e setters herdados
	
   //sobrecarga do operador 'printf'
    public String toString()
    {
        return super.toString();
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
        
        final Paciente paciente = (Paciente) o;
        
        return (this.getNome().equals(paciente.getNome()) && this.getEndereco().equals(paciente.getEndereco()) 
		&& this.getCpf().equals(paciente.getCpf()) && this.getTelefone().equals(paciente.getTelefone())); 
    }
}
