#include "UsuarioAssistenteAdministrativo.h"

//acesso pela recpciosnista
void usuarioAssistenteAdministrativo(Clinica& clinica)
{
	int opcaoEntraOuSai;

	do
	{
		system("cls");
		cout << "\t\tBEM VINDO AO MENU DA CLINICA " << clinica.getNomeDaClinica() << "\n\n";

		cout << "[0]-Sair\n[1]-Agenda\n[2]-Receber Consulta\n[3]-Fazer Pagamento de Contas\n[4]-Folha de Ponto\n[5]-Pacientes\n"
			<<"\n\nDigite: ";
		lerValorCorretamente(opcaoEntraOuSai);

		switch (opcaoEntraOuSai)
		{
		case 0:
			return;

		case 1:
			//Agenda
			agenda(clinica);

			break;
		case 2:
			//receber Consulta de um paciente
			receberConsulta(clinica);
			break;

		case 3:
			//fazer pagamento de contas
			pagamentoDeContas(clinica);

			break;

		case 4:
			//folha de ponto
			folhaDePonto(clinica);

			break;

		case 5:
			//manipula os pacientes da clinica
			manipularPaciente(clinica);
			break;

		default:
			//opcao incorreta

			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
}