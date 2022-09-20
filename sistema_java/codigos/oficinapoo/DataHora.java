package oficinapoo;


public class DataHora extends Data implements Comparable<Data>
{
    private int hora;
    private int minuto;
    
    //construtores
    public DataHora()
    {
        super(1,1,1901);
        
        hora = 0;
        minuto =0;
    }
    
    public DataHora(int dia, int mes, int ano, int hora, int minuto)
    {
        super(dia, mes, ano);
        
        if (!setHora(hora))
	{
            this.hora = 0;
	}

	if (!setMinuto(minuto))
	{
            this.minuto = 0;
	}
    }
  
    public DataHora(DataHora data)
    {
        super(data.getDia(), data.getMes(), data.getAno());
	this.minuto = data.getMinuto();
	this.hora = data.getHora();
    }
	
    //getters
    public int getHora()
    {
        return hora;
    }
    
    public int getMinuto()
    {
        return minuto;
    }

    //setters
    public boolean setHora(int hora)
    {
        if (hora > 24 || hora < 0)//conferir se hora eh valida
	{
            return false;
	}

	this.hora = hora;

	return true;
    }
    
    public boolean setMinuto(int minuto)
    {
        if (minuto> 59 || minuto < 0)//conferir se minuto eh valido
	{
            return false;
	}

	this.minuto = minuto;

	return true;
    }
    
    //sobrecarga do operador 'printf'
    public String toString()
    {
        return String.format("%02d/%02d/%d %02d:%02d", this.getDia(),
                this.getMes(), this.getAno(), this.getHora(), this.getMinuto());
    }

    
   //compara se eh maior, menor, ou igual
    public int compareTo(Data dataAux)
    {
        DataHora data = (DataHora) dataAux;
        
        int resultado = super.compareTo(data);
        
        if(resultado != 0)
        {
            return resultado;
        }
        
        else//dia, mes e ano iguais
        {
            //------
            if (this.getHora() > data.getHora())//se a hora for maior
            {
                return 1;
            }

            else if (this.getHora() < data.getHora())//se for maior, pode parar
            {
                return -1;
            }

            else//conferir minuto
            {
                //------
                if (this.getMinuto() > data.getMinuto())//se a hora for maior
                {
                    return 1;
                }

                else if (this.getMinuto() < data.getMinuto())//se for maior, pode continuar a iterar ate achar o ano
                {
                    return -1;
                }
                else//tudo igual
                {
                    return 0;
                }
            }
        }
    }
}
