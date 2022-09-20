package oficinapoo;
import static oficinapoo.LerValorCorretamente.*;

public class UsuarioGeral
{  
    public void usuarioGeral(Clinica clinica)
    {
        int opcaoEntraOuSai;
        String leitura;
        UsuarioAdministrador usuarioAdministrador = new UsuarioAdministrador();
        do
        {
            leitura =  "\t\tBEM VINDO AO MENU DA CLINICA " 
                    + clinica.getNomeDaClinica() + "\n\n"
                    + "[0]-Sair\n[1]-Agenda\n\nDigite: ";
            
            opcaoEntraOuSai = lerInteiroCorretamente(leitura);

            switch (opcaoEntraOuSai)
            {
		case 0:
                    return;

		case 1:
                    //Agenda
                    usuarioAdministrador.agenda(clinica);

                    break;

		default:
                    //opcao incorreta

                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
            }
	} while (true);
    }
    
}
