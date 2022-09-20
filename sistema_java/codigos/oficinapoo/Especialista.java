package oficinapoo;

public class Especialista extends Pessoa
{
    public Assistente assistente;
    public Agenda agenda;
    
    //construtores
    public Especialista()
    {
        super("", "", "12345678900", "33988888888");
        assistente = new Assistente();
        agenda = new Agenda();   
    }
    
    public Especialista(String nome, String endereco, String cpf, String telefone)
    {
        super(nome, endereco, cpf, telefone);
        assistente = new Assistente();
        agenda = new Agenda();
    }
    
    public Especialista(Assistente assistente, Agenda agenda,String nome, String endereco, String cpf, String telefone)
    {
        super(nome, endereco, cpf, telefone);
	this.assistente = new Assistente(assistente);
        this.agenda = new Agenda(agenda);
    }
    
     public Especialista(Especialista especialista)
    {
        super(especialista.getNome(), especialista.getEndereco(), especialista.getCpf(), especialista.getTelefone());
	this.assistente = new Assistente(especialista.assistente);
        this.agenda = new Agenda(especialista.agenda);
    }

    public String imprimirAgenda()//imprime toda a agenda de um Especialista
    {
        String leitura = "";
	leitura = "Especialista:" + getNome()+ " CPF:"+ getCpf() + "\n\n" + agenda.toString();
        return leitura;
    }
    
    //sobrecarga do operador print
    public String toString()
    {
        String retorno = "";
        retorno = retorno + super.toString() +"\n";
        retorno = retorno + "\nAssistente Do Especialista:\nNome: " + assistente.getNome() 
                + " CPF: " + assistente.getCpf();
        
        return retorno;
    }

}
