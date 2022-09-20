package oficinapoo;
import static oficinapoo.LerValorCorretamente.*;

public class UsuarioAssistenteAdministrativo
{  
    public void usuarioAssistenteAdministrativo(Clinica clinica)
    {
        int opcaoEntraOuSai;
        String leitura;
        UsuarioAdministrador usuarioAdministrador = new UsuarioAdministrador();
        do
        {
            leitura =  "\t\tBEM VINDO AO MENU DA CLINICA " 
                    + clinica.getNomeDaClinica() + "\n\n"
                    + "[0]-Sair\n[1]-Agenda\n[2]-Receber Consulta\n[3]-Fazer Pagamento de Contas\n[4]-Folha de Ponto\n[5]-Pacientes\n"
                    + "\n\nDigite: ";
            
            opcaoEntraOuSai = lerInteiroCorretamente(leitura);

            switch (opcaoEntraOuSai)
            {
		case 0:
                    return;

		case 1:
                    //Agenda
                    usuarioAdministrador.agenda(clinica);

                    break;
                    
                case 2:
                    //receber Consulta de um paciente
                    usuarioAdministrador.receberConsulta(clinica);
                    break;

		case 3:
                    //fazer pagamento de contas
                    usuarioAdministrador.pagamentoDeContas(clinica);

                    break;

		case 4:
                    //folha de ponto
                    usuarioAdministrador.folhaDePonto(clinica);

                    break;

		case 5:
                    //manipula os pacientes da clinica
                    usuarioAdministrador.manipularPaciente(clinica);
                    break;

		default:
                    //opcao incorreta

                    mensagemErro("\nEscolha Corretamente a opcao !\n\n");
                    break;
            }
	} while (true);
    }
    
}


