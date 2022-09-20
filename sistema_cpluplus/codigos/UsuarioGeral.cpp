#include "UsuarioGeral.h"

//acesso somente por assistentes e especialistas
void usuarioGeral(Clinica& clinica)
{
	int opcaoEntraOuSai;

	do
	{
		system("cls");
		cout << "\t\tBEM VINDO AO MENU DA CLINICA " << clinica.getNomeDaClinica() << "\n\n";

		cout << "[0]-Sair\n[1]-Agenda\n\nDigite: ";
		lerValorCorretamente(opcaoEntraOuSai);

		switch (opcaoEntraOuSai)
		{
		case 0:
			return;

		case 1:
			//Agenda
			agenda(clinica);

			break;

		default:
			//opcao incorreta

			cout << "\nEscolha Corretamente a opcao !\n\n";
			system("pause");
			break;
		}

	} while (true);
}