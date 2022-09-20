#ifndef USUARIOADMINISTRADOR_H
#define USUARIOADMINISTRADOR_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdexcept>
#include "Clinica.h"



using namespace std;


void usuarioAdministrador(Clinica&);

template<typename T>
void lerValorCorretamente(T& valor);//le um inteiro, double ou long long corretamente, ou seja, trata a excecao invalid argument


//-----------------Agenda-----------------------
void agenda(Clinica&);//manipula as agendas dos especilistas
void agendaEspecialista(Clinica&, Especialista*);//manipula a agendas de um especilista
void adicionarItemAgendaEspecialista(Clinica&,Agenda*);//adiciona um item na agenda de Especialista
void lerDataHora(DataHora*);//ler data hora da agenda
void lerData(Data*);//le uma data e a retorna
void removerItemAgendaEspecialista(Clinica&, Agenda*);//remove um item na agenda de Especialista
void editarItemAgendaEspecialista(Clinica&, Agenda*);//edita um item na agenda de Especialista
void editarItemAgenda(Clinica&, ItemAgenda*);//edita um item da agenda
void editaData(Data* data);//funcao que edita data
void editaDataHora(DataHora* data);//funcao que edita data hora
void trocarPacienteItemAgenda(Clinica&, ItemAgenda*);//troca um paciente de um Item da Agenda por outro paciente
//---------------------------FIM DA AGENDA-----------



//------------------Receber Consulta --------------
void receberConsulta(Clinica&);//recebe uma consulta do paciente e adicionar a lista de pagamentos
void pagamentoDoPaciente(Clinica&, PagamentoPaciente*);//adiciona os detalhes do pagamento do cliente
void editaPaciente(Paciente* paciente);//funcao que edita paciente/atualiza dados
//------------------Fim do Receber Consulta -----------------------------------



//------------------Fazer Pagamento de Contas --------------
void pagamentoDeContas(Clinica&);//matem controle dos gastos da clinica
void adicionarPagamentoDeContas(Clinica&);//adicionar um pagamento de conta
void removerPagamentoDeContas(Clinica&);//dada uma posicao remover um pagamento da conta
void editarPagamentoDeContas(Clinica&);//edita um item pagamento de conta
void editarItensPagamentosDeContas(Clinica&, PagamentoDeGastos*);//edita um pagamento de conta
//------------------Fim Fazer Pagamento de Contas --------------



//------------------ Folha de Ponto ----------------
void folhaDePonto(Clinica&);//controla a folha de ponto dos funcionarios(assistentes)
void folhaDePontoAssistente(Clinica&, Assistente*);//controla a folha de ponto de um funcionario
void adicionarItemFolhaDePonto(Clinica&, Assistente*);//adiciona um item na follha de ponto do funcionario
void removerItemFolhaDePonto(Clinica&, Assistente*);//remove um item na follha de ponto do funcionario
void editarFolhaDePonto(Clinica&, Assistente*);//edita um item na follha de ponto do funcionario
void editarItemFolhaDePonto(Clinica&, ItemFolhaDePonto*);//edita um item da folha de ponto de um funcionario
//------------------Fim de Folha de Ponto --------------



//------------------ Pagar Salario ----------------
void pagarSalario(Clinica&);//realiza um pagamento de funcionarios mostrando folha de ponto, primeiro retorna o funcionario escolhido
void pagarSalarioParte2(Clinica&, Assistente*);//menu com escolha para ver folha de ponto ou pagar salario 
void efetuarPagamentoFuncionario(Clinica&, Assistente*);//efetua o pagamento de um funcionario
//------------------Fim de Pagar Salario --------------




//---------------------Gerar Relatorios------------------------------
void geraRelatorio(Clinica&);//gera 3 tipos de relatorio de pagamentos: Pagamento de Paciente, de gasto da Clinica eFuncionario
void relatorioDePagamentos(Clinica&);//gera o relatorio de pagamentos de pacientes
void relatorioDeGastos(Clinica&);//gera o relatorio de gastos com a clinica
void relatorioDeGastosComFuncionarios(Clinica&);//gera o relatorio de pagamentos de funcionarios
//---------------------Fim do Gerar Relatorios-------------------------



//--------------------- Manipular Pacientes------------------------------
void manipularPaciente(Clinica&);//manipula pacientes, adicionar remove, e edita
void adicionarPaciente(Clinica&);//funcao que adiciona pacientes
void lerPaciente(Paciente*);//le um paciente corretamente
void removerPaciente(Clinica&);//funcao que remove um paciente da clinica
void editarPaciente(Clinica&);//funcao que edita pacientes
//funcao que edita paciente ja existe "editaPaciente"
//---------------------Fim do Manipular Pacientes-------------------------




//--------------------- Manipular Funcionarios------------------------------
void manipularFuncionario(Clinica&);//manipula funcionarios, adicionar remove, e edita
void adicionarFuncionario(Clinica&);//funcao que adiciona funcionario
void lerFuncionario(Assistente*);//le funcionarios corretamente
void removerFuncionario(Clinica&);//funcao que remove funcionarios
void editarFuncionario(Clinica&);//funcao que edita funcionarios
void editaFuncionario(Assistente*);//funcao que edita funcionario/atualiza dados
//--------------------- Fim doManipular Funcionarios-------------------------




//--------------------- Manipular Especialista------------------------------
void manipularEspecialista(Clinica&);//manipula especialista, adicionar, remove, e edita
void adicionarEspecialista(Clinica&);//funcao que adiciona especialista
void removerEspecialista(Clinica&);//funcao que remove Especialista
void editarEspecialista(Clinica&);//funcao que edita Especialistas
void editaEspecialista(Clinica&, Especialista*);//funcao que edita especialista/atualiza dados
void editarAssistenteDoEspecialista(Clinica&, Especialista*);//cadastra ou troca a assistente de um especialista 
void trocarAssistenteDoEspecialista(Clinica&,Assistente*);//troca ou adiciona a assistente do especialista
//--------------------- Fim do Manipular Especialista-------------------------





//--------------------- Manipular Recepcionista------------------------------
void manipularRecepcionista(Clinica&);//manipula adicionar, remove e imprime recepcionista
void adicionarRecepcionista(Clinica&);//funcao que adiciona recepcionista
//--------------------- Fim do Manipular Recepcionista-------------------------



//--------------------- Manipular Pagamentos------------------------------
//manipular pagamentos nao maniulados ate entao, remover pagamento especifico de paciente ou todos os pagamentos
//remover pagamento especifico de funcionario ou todos os pagamentos

void manipularPagamentos(Clinica&);//manipula pagamentos de funcionario e pacientes
void manipularPagamentosFuncionarios(Clinica&);//manipula pagamentos de funcionarios
void manipularPagamentosFuncionarios2(Clinica&, PagamentoFuncionario*);//manipula pagamentos de um funcionario
void apagarItemPagamentosFuncionarios(Clinica&, PagamentoFuncionario*);//apaga um item de pagamento do funcionario
void manipularPagamentosPacientes(Clinica&);//manipula pagamentos de pacientes
void manipularPagamentosPacientes2(Clinica&, PagamentoPaciente*);//manipula pagamentos de  um paciente
void apagarItemPagamentosPacientes(Clinica&, PagamentoPaciente*);//apaga um item de pagamento do paciente
//--------------------- Fim do Manipular Pagamentos-------------------------



#endif // !USUARIOADMINISTRADOR_H




