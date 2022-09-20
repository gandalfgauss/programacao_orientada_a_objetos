package oficinapoo;

import javax.swing.JOptionPane;

public class LerValorCorretamente
{   //le um inteiro corretamente com interface grafica, ou seja, trata a excecao 
    public static final int lerInteiroCorretamente(String leitura)
    {
        int valor;
        String resultado;
        
	//repete o loop ate digitar o tipo de dado corretamente
	while (true)
	{
            try
            {         
		resultado = JOptionPane.showInputDialog(leitura);
                
                if(resultado == null)//saiu sem digitar
                {
                    continue;
                }
                
                valor = Integer.parseInt(resultado);
            }
            catch (NumberFormatException e)
            {
		continue;
            }
            break;
	}
        
        return valor;
    }
    
    //le um double corretamente com interface grafica, ou seja, trata a excecao 
    public static final double lerDoubleCorretamente(String leitura)
    {
        double valor;
        String resultado;
        
	//repete o loop ate digitar o tipo de dado corretamente
	while (true)
	{
            try
            {         
		resultado = JOptionPane.showInputDialog(leitura);
                
                if(resultado == null)//saiu sem digitar
                {
                    continue;
                }
                
                valor = Double.parseDouble(resultado);
            }
            catch (NumberFormatException e)
            {
		continue;
            }
            break;
	}
        
        return valor;
    }
    
    //le um string corretamente com interface grafica, e trata insercao vazia 
     public static final String lerStringCorretamente(String leitura)
    {
        String resultado;
        
	//repete o loop ate digitar o tipo de dado corretamente
	while (true)
	{
          resultado = JOptionPane.showInputDialog(leitura);
                
           if(resultado == null || resultado.equals("") || resultado.equals(" "))//saiu sem digitar ou digitou nada
           {
               continue;
           }
                                  
            break;
	}
        
        return resultado;
    }
     
    public static final void mensagemErro(String leitura)//imprime uma mensagem de erro 
    {
        JOptionPane.showMessageDialog(null, leitura , "ERRO",JOptionPane.ERROR_MESSAGE);
    }
    
    public static final void mensagemInformacao(String leitura)//imprime uma informacao
    {
         JOptionPane.showMessageDialog(null, leitura , "INFO",JOptionPane.INFORMATION_MESSAGE);
    }
    
    public static final int mensagemCerteza(String leitura)//interface grafica de confirmar
    {   
        //se fechar retorna -1, se 'Yes' retorna 0 e se 'No' retorna 1
        int resultado = -1;
        
        //repete enquanto nao responder sim ou nao
        while((resultado = JOptionPane.showConfirmDialog(null, leitura , "CONFIRMAR",JOptionPane.YES_NO_OPTION,
                 JOptionPane.WARNING_MESSAGE)) == -1);
         
        return resultado;
                        
    }
          
}
