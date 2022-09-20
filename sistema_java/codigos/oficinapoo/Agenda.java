package oficinapoo;

import java.util.List;
import java.util.LinkedList;
import java.util.Collections;

public class Agenda 
{
    public List<ItemAgenda> itensDaAgenda;

    //construtores
    public Agenda()
    {
        itensDaAgenda = new LinkedList<ItemAgenda>();
    }
    
    public Agenda(Agenda agenda)
    {
        itensDaAgenda = new LinkedList<ItemAgenda>();
        
        for(ItemAgenda it : agenda.itensDaAgenda)
        {
            itensDaAgenda.add(new ItemAgenda(it));
        }     
    }
    
    
    //ordena a agenda pela data
    public void ordenaAgenda()
    {
        Collections.sort(itensDaAgenda);                                                             
    }
     
    
    public void adicionarItemAgenda(ItemAgenda item)//adiciona um Item e ordena a Agenda
    {
	//inserir novo elemento
	ItemAgenda copia = new ItemAgenda(item);
        itensDaAgenda.add(copia);
        ordenaAgenda();
    }

    public boolean removerItemAgenda(int posicao)//dada uma posicao remove um item da agenda
    {
        //verifica se posicao eh valida
	if (itensDaAgenda.isEmpty() || posicao >  itensDaAgenda.size() || posicao < 1)
	{
            return false;
	}
	
        itensDaAgenda.remove(posicao-1);
        
	return true;
    }

    public ItemAgenda retornarItemAgenda(int posicao)//retorna um item da agenda
    {
        //se a posicao for incorreta retorna o ultimmo
        if(posicao > itensDaAgenda.size() || posicao < 1)
        {
            return itensDaAgenda.get(itensDaAgenda.size()-1);
        }
        
	return itensDaAgenda.get(posicao-1);
    }

    //imprime a agenda
    public String toString()
    {
        String retorno = "";
        if (itensDaAgenda.isEmpty())//se nao tiver itens na agenda
	{
		retorno = "Agenda vazia";
	}
        else
        {
            retorno = retorno+"Agenda\n";
            int i = 1;
            for(ItemAgenda item: itensDaAgenda)
            {
                retorno = retorno+"Item " + i +":\n" +item.toString() + "\n";
                i++;
            }
        }
        
        return retorno;
    }  
}
