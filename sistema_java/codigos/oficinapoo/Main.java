package oficinapoo;

import static oficinapoo.LerValorCorretamente.*;

public class Main 
{
    
    public static void main(String[] args) 
    {
      
        String leitura;
        Clinica clinica = new Clinica();       
        UsuarioAdministrador admin = new UsuarioAdministrador();
        UsuarioGeral usuarioGeral = new UsuarioGeral();
        UsuarioAssistenteAdministrativo usuarioAssistenteAdministrativo = new UsuarioAssistenteAdministrativo();
        
        
	String nomeDaClinica, usuario, senha;
	int opcaoSairLogin;
	int opcaoDeLogin; 	              
            
        nomeDaClinica = lerStringCorretamente("\t\tBEM VINDO AO SISTEMA DE CADASTRO DA CLINICA\n\n\nPara comecar digite o nome da sua Clinica: ");
        	 
	while (nomeDaClinica == null || !clinica.setNomeDaClinica(nomeDaClinica))
	{
            nomeDaClinica = lerStringCorretamente("\t\tBEM VINDO AO SISTEMA DE CADASTRO DA CLINICA\n\n\nPara comecar digite o nome da sua Clinica: ");
	}
        
	do
	{
            do
            {
		leitura = "\t\tBEM VINDO A TELA DE LOGIN DA CLINICA " + 
                        clinica.getNomeDaClinica() + "\n\n" + "[0]-Sair\n[1]-Login\n\nDigite: ";
                                           
		opcaoSairLogin = lerInteiroCorretamente(leitura);//le corretamente um dado do tipo int ou double
		
		switch (opcaoSairLogin)
		{
                    case 0:
			return;
                    case 1:
			break;
		}
            } while (opcaoSairLogin != 1);//so sai do loop quando o usuario escolher login, ou seja, digitar '1', termina o programa ao digitar '0'
		
            usuario = lerStringCorretamente("\nDigite o nome do usuario: ");

            senha = lerStringCorretamente("\nDigite a senha: ");
          
            opcaoDeLogin = clinica.login(usuario, senha);

            //1- Para Usuario Administrador (usuario: admin, senha: admin) - Acesso a todas funcionalidades
            //2- Para Usuario Assistente (Somente Recepcionista tem acesso) - Acesso a 5 funcionalidade 
            //(Agenda, Receber Consulta, Fazer pagamento de contas, Folha de Ponto e Pacientes
            //3- Para Usuario Geral- (Acesso por assistentes de especialistas e especiaista)- So tem acesso a Agenda
            //0 - se nao encontrar

            switch (opcaoDeLogin)
            {
                case 1:
                    //Usuario administrador
                    admin.usuarioAdministrador(clinica);
			
                    break;

		case 2:
                    //Usuario Assistente Administrativo
                    usuarioAssistenteAdministrativo.usuarioAssistenteAdministrativo(clinica);
                    break;
		case 3:
                    //usuario geral
                    usuarioGeral.usuarioGeral(clinica);
                    break;

		case 0:
                    //nao existe
                    mensagemErro("\nLogin e senha incorretos !\n\n");

            }

	} while (true);//enquanto nao conseguir logar vai repetir esse loop, 
	//so eh possivel sair do loop digitando '0' dentro do loop mais interno
    }
}
