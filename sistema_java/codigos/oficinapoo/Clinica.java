package oficinapoo;

import java.util.List;
import java.util.LinkedList;

public class Clinica
{
    private String nomeDaClinica;
    public List<Especialista> especialistas;
    public List<Assistente> assistentes;
    public Assistente recepcionista;
    public Pagamentos pagamentos;
    public List<Paciente> pacientes;
    
    //construtor
    public Clinica()
    {
	nomeDaClinica = " ";
        especialistas = new LinkedList<Especialista>();
        assistentes = new LinkedList<Assistente>();
        recepcionista = new Assistente();
        pagamentos = new Pagamentos();
        pacientes = new LinkedList<Paciente>();       
    }
    
    //construtor
    public Clinica(String nomeDaClinica)
    {
	this.nomeDaClinica = nomeDaClinica;
        especialistas = new LinkedList<Especialista>();
        assistentes = new LinkedList<Assistente>();
        recepcionista = new Assistente();
        pagamentos = new Pagamentos();
        pacientes = new LinkedList<Paciente>();
    }
 
    //getter
    public String getNomeDaClinica()
    {
	return nomeDaClinica;
    }

    //setter
    public boolean setNomeDaClinica(String nomeDaClinica)
    {
	if (nomeDaClinica.equals("") || nomeDaClinica.equals(" "))//conferir se nome eh valido, validacao fraca mas ajuda um pouco
	{
            return false;
	}

	this.nomeDaClinica = nomeDaClinica;

	return true;
    }

    //--------------Especialista-------------------------

    public boolean adicionarEspecialista(Especialista especialista)//adiciona um Especialista e retorna false se ja existir
    {
	//inserir novos elementos
	Especialista copia = new Especialista(especialista);

	for (Especialista it : especialistas)
	{
            if (it.getCpf().equals(copia.getCpf()))//se o especialista ja existir
            {
		return false;
            }
	}

	this.especialistas.add(copia);

	return true;
    }

    public boolean removerEspecialista(int posicao)//dada uma posicao remove um especialista
    {
	if (especialistas.isEmpty() || posicao > especialistas.size() || posicao < 1)//se tiver vazia a lista ou posicao invalida
	{
		return false;
	}

	//remove o item na posicao passada como parametro
	especialistas.remove(posicao-1);

	return true;
    }
    
    

    public Especialista retornarEspecialista(int posicao)//dada uma posicao da lista retorna um especialista
    {
	return especialistas.get(posicao-1);
    }
    
    //------------------------------Assistente------------------------------

    public boolean adicionarAssistente(Assistente assistente)//adiciona um Assistente e retorna false se ja existir
    {
	//inserir novos elementos
	Assistente copia = new Assistente(assistente);

	for (Assistente it : assistentes)
	{
            if (it.getCpf().equals(copia.getCpf()))//se o Assistente ja existir
            {
		return false;
            }
	}

	this.assistentes.add(copia);

	return true;
    }

    public boolean removerAssistente(int posicao)//dada uma posicao remove um Assistente
    {
	if (assistentes.isEmpty() || posicao > assistentes.size() || posicao < 1)//se tiver vazia a lista ou posicao invalida
	{
		return false;
	}

	//remover assistente na posicao passada como parâmetro
	assistentes.remove(posicao-1);

	return true;
    }

    public Assistente retornarAssistente(int posicao)//dada uma posicao da lista retorna um Assistente
    {
	return assistentes.get(posicao-1);
    }

    
    //---------------------------Pacientes -----------------

    public boolean adicionarPaciente(Paciente paciente)//adiciona um Paciente e retorna false se ja existir
    {
	//inserir novos elementos
	Paciente copia = new Paciente(paciente);

	for (Paciente it : pacientes)
	{
            if (it.getCpf().equals(copia.getCpf()))//se o Paciente ja existir
            {
		return false;
            }
	}

	this.pacientes.add(copia);  

	return true;
    }

    public boolean removerPaciente(int posicao)//dada uma posicao remove um Paciente
    {
	if (pacientes.isEmpty() || posicao > pacientes.size() || posicao < 1)//se tiver vazia a lista ou posicao invalida
	{
            return false;
	}

	//remover item na posicao passada como parametro
        pacientes.remove(posicao-1);

	return true;
    }

    public Paciente retornarPaciente(int posicao)//dada uma posicao da lista retorna um Paciente
    {
	return pacientes.get(posicao-1);
    }
    
    //---------------------------------------------------------
    
    public String imprimirNomeDosEspecialistas()//imprime o nome dos especialistas cadastrados
    {
        String leitura = "";
        
	if (especialistas.isEmpty())
	{
            leitura += "\nLista de Especialistas vazia.";
            return leitura;
	}

	int i = 1;

	for (Especialista it : especialistas)
	{
            leitura += "Especialista" + i+":"+ it.getNome() + "CPF:" + it.getCpf() +"\n\n";        
            i++;
	}
        
        return leitura;
    }
    
    

    public String imprimirNomeDosFuncionarios()//imprime o nome dos funcionarios cadastrados
    {
        String leitura = "";
        
	if (assistentes.isEmpty())
	{
            leitura = "\nLista de Funcionarios vazia.";
            return leitura;
	}

	int i = 1;

	for (Assistente it : assistentes)
	{
            leitura += "Funcionario "+i+": "+it.getNome()+" CPF: "+it.getCpf()+"\n\n";
            i++;
	}
        
        return leitura;
    }

    public String imprimirPacientes()//imprime todos os dados dos paciente cadastrados
    {
        String leitura = "";
        
        if (pacientes.isEmpty())
	{
            leitura = "\nLista de Pacientes vazia.";
            return leitura;
	}

	int i = 1;

	for (Paciente it :pacientes)
	{
            leitura += "Paciente " + i+":\n" + it.toString() +"\n\n";
            i++;
	}
        
        return leitura;
    }
    
    

    public String imprimirAssistentes()//imprime todos os dados dos assistentes cadastrados
    {
        String leitura = "";
        
	if (assistentes.isEmpty())
	{
            leitura = "\nLista de Funcionarios vazia.";
            return leitura;
	}

	int i = 1;

	for (Assistente it : assistentes)
	{
            leitura += "Funcionario "+i+":\n"+it.toString()+"\n\n";
            i++;
	}
        
        return leitura;
    }

    public String imprimirEspecialistas()//imprime todos os dados dos especialistas cadastrados
    {
        String leitura = "";
        
	if (especialistas.isEmpty())
	{
            leitura = "\nLista de Especialistas vazia.";
            return leitura;
	}

	int i = 1;

	for (Especialista it : especialistas)
	{
            leitura += "Especialista "+i+":\n"+it.toString()+"\n\n";
            i++;
	}
        
        return leitura;
    }

    //-------------------------------------------------------

    //retorna:
	//1- Para Usuario Administrador (usuario: admin, senha: admin)
	//2- Para Usuario Assistente 
	//3- Para Usuario Geral
	//0- Erro, nao pode dar acesso
	//Para as opcoes 2 e 3 serem retornados o Usuario dever se o nome da Pessoa e a Senha � o Cpf
    int login(String usuario, String senha)
    {
	if (usuario.equals("admin") && senha.equals("admin"))
	{
            return 1;
	}
	else if(recepcionista.getNome().equals(usuario) && recepcionista.getCpf().equals(senha))//conferir se eh recepcionista
	{
            return 2;
	}
	else //conferir se eh assistente ou especialista para dar acesso de Usuario Geral
	{
            for (Assistente item : assistentes)//conferir se eh assistente
            {
                if (item.getNome().equals(usuario) && item.getCpf().equals(senha))
                {
                    return 3;
		}
            }

            for (Especialista item : especialistas)//conferir se eh especialista
            {
		if (item.getNome().equals(usuario) && item.getCpf().equals(senha))
		{
                    return 3;
		}
            }
	}

	return 0;
    }

}
