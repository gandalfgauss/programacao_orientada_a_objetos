
package oficinapoo;

public class Pessoa
{
    private String nome;
    private String endereco;
    private String cpf;
    private String telefone;

    //construtores
    public Pessoa()
    {
        this.nome = " ";
        this.endereco = " ";
        this.cpf = "12345678900";
        this.telefone = "33988888888";
    }
    
    public Pessoa(String nome, String endereco, String cpf, String telefone)
    {
        if (!setNome(nome))
	{
            this.nome = " ";
	}

	if (!setEndereco(endereco))
	{
            this.endereco = " ";
	}

	if (!setCpf(cpf))
	{
            this.cpf = "12345678900";
	}

	if (!setTelefone(telefone))
	{
            this.telefone = "33988888888";
	}
    }
    
    public Pessoa(Pessoa pessoa)
    {
        this.nome = pessoa.nome;
	this.endereco = pessoa.endereco;
	this.cpf = pessoa.cpf;
	this.telefone = pessoa.telefone;
    }

    //getters
    public String getNome()
    {
        return nome;
    }
    public String getEndereco()
    {
        return endereco;
    }
    
    public String getCpf()
    {
        return cpf;
    }
    public String getTelefone()
    {
        return telefone;
    }

    //setters
    public boolean setNome(String nome)
    {
        if (nome.equals("") || nome.equals(" "))//conferir se nome eh valido, validacao fraca mas ajuda um pouco
        {
            return false;
	}

	this.nome = nome;

	return true;
    }
    
    public boolean setEndereco(String endereco)
    {
        if (endereco.equals("") || endereco.equals(" "))//conferir se endereco eh valido
	{
            return false;
	}

	this.endereco = endereco;

	return true;
    }
    
    public boolean setCpf(String cpf)
    {
        if (cpf.length() != 11)//conferir se cpf mais ou menos que 11 digitos
	{
            return false;
	}

	this.cpf = cpf;

	return true;
    }
    
    
    public boolean setTelefone(String telefone)
    {
        if (telefone.length() < 8)//conferir se telefone tem menos de 8 digitos
	{
            return false;
	}

	this.telefone = telefone;

	return true;
    }

    

   //sobrecarga do operador 'printf'
    public String toString()
    {
        return String.format("Nome: %s\nEndereco: %s\nCpf: %s\nTelefone: %s",
                              this.getNome(), this.getEndereco(), this.getCpf(), this.getTelefone());
    }
}
