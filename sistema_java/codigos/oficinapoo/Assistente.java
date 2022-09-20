package oficinapoo;

import java.util.List;
import java.util.LinkedList;
import java.util.Collections;

public class Assistente extends Pessoa
{
    public List<ItemFolhaDePonto> folhaDePonto;
    
    //construtores
    
    //construtores
    public Assistente()
    {
        super("", "", "12345678900", "33988888888");
        folhaDePonto = new LinkedList<ItemFolhaDePonto>();
    }
    
    public Assistente(String nome, String endereco, String cpf, String telefone)
    {
        super(nome, endereco, cpf, telefone);
        folhaDePonto = new LinkedList<ItemFolhaDePonto>();
    }
    
    public Assistente(Assistente assistente)
    {
        super(assistente.getNome(), assistente.getEndereco(), assistente.getCpf(), assistente.getTelefone());
        
        folhaDePonto = new LinkedList<ItemFolhaDePonto>();
        
        for(ItemFolhaDePonto it : assistente.folhaDePonto)
        {
            folhaDePonto.add(new ItemFolhaDePonto(it));
        }
    }
    
    //ordena a a folha de ponto pela data
    public void ordenaFolhaDePonto()
    {
        Collections.sort(folhaDePonto);                                                             
    }

    public void adicionarItemFolhaDePonto(ItemFolhaDePonto item)//adiciona um item na folha de ponto ordenado pela data
    {
	//inserir novo elemento
	ItemFolhaDePonto copia = new ItemFolhaDePonto(item);
        folhaDePonto.add(copia);
        ordenaFolhaDePonto();
    }

    public boolean removerItemFolhaDePonto(int posicao)//dada uma posicao remove um item da folha de ponto
    {
	//verifica se posicao eh valida
	if (folhaDePonto.isEmpty() || posicao >  folhaDePonto.size() || posicao < 1)
	{
            return false;
	}
	
        folhaDePonto.remove(posicao-1);
        
	return true;
    }

    public ItemFolhaDePonto retornarItemFolhaDePonto(int posicao)//retorna um item da folha de ponto
    {
	//se a posicao for incorreta retorna o ultimmo
        if(posicao > folhaDePonto.size() || posicao < 1)
        {
            return folhaDePonto.get(folhaDePonto.size()-1);
        }
        
	return folhaDePonto.get(posicao-1);
    }

    public String imprimirFolhaDePontoDoMes(int mes)//imprime a folha de ponto de um assistente de um determinado mes
    {
	int i = 0;
        String leitura = "";
        
	if (folhaDePonto.isEmpty())
	{
            leitura = "\nFolha de Ponto Vazia !";
            return leitura;
	}

	if (mes < 0 || mes > 12)
	{
            leitura = "\nValor de mes incorreto";
            return leitura;
	}

	leitura = "\nFolha de ponto - "+getNome()+ "\n";
        
	for (ItemFolhaDePonto item :folhaDePonto)
	{
            if (item.data.getMes() == mes)
            {
                i++;
               leitura += item.toString()+"\n";
            }
	}

	//return i;
        //mudei para
        return leitura;
    }

    public String imprimirFolhaDePonto()//imprime toda a folha de ponto de um assistente
    {
	int i = 1;
        String leitura = "";
        
	if (folhaDePonto.isEmpty())
	{
            leitura = "\nFolha de Ponto Vazia";
            return leitura;
	}

	leitura = "\nFolha de ponto - "+getNome()+" CPF: "+getCpf()+"\n";
        
	for (ItemFolhaDePonto item :folhaDePonto)
	{          
            leitura += "Item "+i+":\n"+item.toString()+"\n";
            i++;
	}
			
	return leitura;
    }

    //imprime Os dados do assistente
    public String toString()
    {
        return super.toString();
    } 
}