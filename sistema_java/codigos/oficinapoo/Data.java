package oficinapoo;


public class Data implements Comparable<Data>
{
    private int dia;
    private int mes;
    private int ano;
    
    //construtores
    public Data()
    {
        dia = 1;
        mes = 1;
        ano = 1901;            
    }
    
    public Data(int dia, int mes, int ano)
    {
        if (!setDia(dia))
	{
            this.dia = 1;
	}

	if (!setMes(mes))
	{
            this.mes = 1;
	}

	if (!setAno(ano))
	{
            this.ano = 1901;
	}
    }
    
    public Data(Data data)
    {
        this.dia = data.dia;
	this.mes = data.mes;
	this.ano = data.ano;
    }

    //getters
    public int getDia()
    {
        return dia;
    }
    public int getMes()
    {
        return mes;
    }
    public int getAno()
    {
        return ano;
    }

    //setters
    public boolean setDia(int dia)
    {
        if (dia > 31 || dia <= 0)//conferir se dia eh valido
	{
            return false;
	}

	this.dia = dia;

	return true;
    }
    
    public boolean setMes(int mes)
    {
        if (mes > 12 || mes <= 0)//conferir se mes eh valido
	{
            return false;
	}

	this.mes = mes;

	return true;
    }
    
    public boolean setAno(int ano)
    {
        if (ano > 2100 || ano <= 1900)//conferir se ano eh valido
	{
            return false;
	}

	this.ano = ano;

	return true;
    }

    //sobrecarga do operador 'print'
    public String toString()
    {
        return String.format("%02d/%02d/%d", this.getDia(),
                this.getMes(), this.getAno());
    }

    //compara se eh maior, menor, ou igual
    public int compareTo(Data data)
    {
        if (this.getAno() > data.getAno())//se o ano for maior a data eh maior
	{
            return 1;
	}

	else if (this.getAno() <  data.getAno())//se for maior, pode parar
        {  
            return -1;
	}

	else//ano eh igual
	{
            if (this.getMes() > data.getMes())//confere se mes eh maior
            {
                return 1;
            }

            else if (this.getMes() < data.getMes())//se for maior, pode para
            {
                return -1;
            }

            else//ano e mes sao iguais
            {
		if (this.getDia() > data.getDia())//se o dia a inserir for menor ja pode inserir
		{
                    return 1;
		}

		else if (this.getDia() < data.getDia())//se for maior, pode continuar a iterar ate achar o ano
		{
                    return -1;
		}

		else//dia, mes e ano iguais
		{
                    return 0;
		}
            }
	} 
    }

}
