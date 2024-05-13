// ------------------------------------ //
// Fila de Hospital                     //
//                                      //
// Autores: Rodrigo Zanetti             //
// Instituição: Fatec Antonio Russo     //
// Professor: Carlos Veríssimo          //
// Paradigma: Programação Modular       //
// Data: 13/05/2024                     //
// ------------------------------------ //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Filas Normal de acordo com especialidade
// Fila Preferencial de acordo com idade
// Fila Urgente -> Chamados Instantaneamente
// Chamar paciente da fila de acordo com a especialidade do médico
// 

//Criação das Structs

int idPaciente = 0;
int idAtendimento = 0;
int Senha = 0;
int historico = 0;
time_t t1;
time_t t2;

typedef struct sPaciente{
  int idPaciente;
  int Senha;
  char nome[50];
  int idade;
  char especialidade[50];
} tPaciente;

typedef struct Node{
  tPaciente paciente;
  struct Node *next;
} tNode;

typedef struct sQueue{
  tNode *inicio;
  tNode *fim;
} tQueue;

// Criar os doutores predefinidos para cada especialidade (otorrino, pediatra, cardiologista, neurologista, geriatra)
// Na hora da chamada, colocar um parametro pedindo a especialidade do doutor predefinido  case "otorrino": doutor1->nome                
typedef struct sMedico{
  int idMedico;
  char nome[50];
  char especialidade[50];
  int sala;
  int onAtendimento;
} tMedico;

// Separar em funções de totem -> adicionar pacientes a fila colocando suas informações
// e funções do sistema -> chamar pacientes, mostrar o painel de chamadas (histórico), mostrar filas, finalizar consulta(difftime(time_t1,time_t2))

tMedico Doutor1 = {1, "João", "Otorrino", 1, 0};
tMedico Doutor2 = {2, "Maria", "Pediatra", 2, 0};
tMedico Doutor3 = {3, "José", "Cardiologista", 3, 0};
tMedico Doutor4 = {4, "Ana", "Neurologista", 4, 0};
tMedico Doutor5 = {5, "Carlos", "Geriatra", 5, 0};

tQueue * Criar(){
  tQueue *fila = (tQueue *) malloc(sizeof(tQueue));
  if(fila != NULL)
  {
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
  }
    else
    {
      printf("Erro ao criar fila");
      return NULL;
    }
}

int Vazia(tQueue *fila)
{
  if(fila->inicio == NULL)
    return 1;
  
  else
    return 0; 
}

void Inserir(tQueue * fila, tPaciente paciente)
{
  tNode *novo = (tNode *) malloc(sizeof(tNode));
  novo->paciente = paciente;
  novo->next = NULL;
  if(fila->fim != NULL)
    fila->fim->next = novo;
  else
    fila->inicio = novo;
  
  fila->fim = novo;
}

void removerHistorico(tQueue *fila){
  tNode *aux = fila->inicio;
  fila->inicio = fila->inicio->next;
  free(aux);
}

int inserirHistorico(tQueue *fila, tPaciente paciente){
  while(historico != 3){
  Inserir(fila, paciente);
  historico++;
  return 0;
  }
  removerHistorico(fila);
  Inserir(fila, paciente);
  return 1;
  
}

void inserirPaciente(char nome[50], int idade, char especialidade[50], tQueue *fila)
{
  tPaciente * paciente = (tPaciente *) malloc(sizeof(tPaciente));
  paciente->idPaciente = idPaciente;
  paciente->Senha = Senha;
  strcpy(paciente->nome, nome);
  paciente->idade = idade;
  strcpy(paciente->especialidade, especialidade);
  Inserir(fila, *paciente);
  Senha += 1;
  
}

int atenderPaciente(tQueue *fila, tQueue *filaHistorico)
{
  if(Vazia(fila))
    return 0;

  tNode *temp = fila->inicio;
  int senha = temp->paciente.Senha;
  printf("Senha: %d\n", senha);
  printf("%s\n", temp->paciente.nome);
  tMedico * Doutor;
    if(strcmp(temp->paciente.especialidade, "Otorrino") == 0)
      Doutor = &Doutor1;
    else if(strcmp(temp->paciente.especialidade, "Pediatra") == 0)
      Doutor = &Doutor2;
    else if(strcmp(temp->paciente.especialidade, "Cardiologista") == 0)
      Doutor = &Doutor3;
    else if(strcmp(temp->paciente.especialidade, "Neurologista") == 0)
      Doutor = &Doutor4;
    else if(strcmp(temp->paciente.especialidade, "Geriatra") == 0)
      Doutor = &Doutor5;
  if(Doutor->onAtendimento == 1){
    printf("O doutor está em atendimento\n");
    return 0;
  }
  if(fila->inicio->next == NULL){
    fila->inicio = NULL;
    fila->fim = NULL;
  } else {
    fila->inicio = fila->inicio->next;
  }
  printf("Doutor(a) %s\n", Doutor->nome);
  printf("Sala: %d\n", Doutor->sala);
  inserirHistorico(filaHistorico, temp->paciente);
  Doutor->onAtendimento = 1;
  t1 = time(NULL);
  free(temp);
  return 1;
}
void mostrarFila(tQueue *fila){
  tNode *temp = fila->inicio;
  printf("[");
  while(temp != NULL)
    {
      printf("(Nome: %s, Senha: %d, Idade: %d, Especialidade: %s) ", temp->paciente.nome, temp->paciente.Senha, temp->paciente.idade, temp->paciente.especialidade);
      temp = temp->next;
    }
  printf("]\n");
}

int mostrarPainel(tQueue *filaHistorico){
  if(Vazia(filaHistorico) == 1)
    return 0;
  tNode *temp = filaHistorico->inicio;
  printf("Paciente: %s - Senha: %d \n", filaHistorico->fim->paciente.nome, filaHistorico->fim->paciente.Senha);
  if(filaHistorico->inicio != filaHistorico->fim){
  printf("Últimos Chamados: \n");
  while(temp != filaHistorico->fim)
    {
      printf("Paciente: %s - Senha: %d \n", temp->paciente.nome, temp->paciente.Senha);
      temp = temp->next;
    }
  }
  return 1;
}
int finalizarConsulta(int idMedico){
  tMedico * Doutor;
  if(idMedico == 1)
    Doutor = &Doutor1;
  if(idMedico == 2)
    Doutor = &Doutor2;
  if(idMedico == 3)
    Doutor = &Doutor3;
  if(idMedico == 4)
    Doutor = &Doutor4;
  if(idMedico == 5)
    Doutor = &Doutor5;

  if(Doutor->onAtendimento == 0)
  {
    printf("O doutor não está em atendimento\n");
    return 0;
  }

  t2 = time(NULL);
  double tempo = difftime(t2, t1);
  printf("Tempo da consulta em segundos: %.2f\n", tempo);
  Doutor->onAtendimento = 0;
  return 1;
}



int main(void) {
  tQueue filaNormal = *Criar();
  tQueue filaPreferencial = *Criar();
  tQueue filaUrgente = *Criar();
  tQueue filaHistorico = *Criar();
  int interval = 0;
  int input = 1;
  while(input != 0){
  printf("Consultório\n");
  printf("Funcões do Sistema:\n");
  printf("1 - Chamar paciente\n");
  printf("2 - Mostrar painel de chamadas\n");
  printf("3 - Mostrar filas\n");
  printf("4 - Finalizar Consulta");
  printf("\n Funções do totem de atendimento:\n");
  printf("5 - Adicionar paciente\n");
  printf("0 - Sair\n");
  
  scanf("%d", &input);
  switch(input){
    case 1:
      if(Vazia(&filaUrgente) == 0)
        atenderPaciente(&filaUrgente, &filaHistorico);
      else if(Vazia(&filaPreferencial) == 1 && Vazia(&filaNormal) == 1){
        printf("Nenhum paciente na fila\n");
        break;
      }
      else if(Vazia(&filaNormal) == 0)
      {
        if(interval == 3)
        { 
          if(atenderPaciente(&filaPreferencial, &filaHistorico))
            interval = 0;
          break; 
        }
        if(atenderPaciente(&filaNormal, &filaHistorico))
        interval++;
      }
      else if(Vazia(&filaPreferencial) == 0){
        atenderPaciente(&filaPreferencial, &filaHistorico);
      }
      break;
    case 2:
      mostrarPainel(&filaHistorico);
      break;
    case 3:
      printf("Fila Normal:\n");
      mostrarFila(&filaNormal);
      printf("Fila Preferencial:\n");
      mostrarFila(&filaPreferencial);
      printf("Fila Emergencial:\n");
      mostrarFila(&filaUrgente);
      break;
    case 4:
      printf("Digite o número da sala do médico: ");
      int id;
      scanf("%d", &id);
      finalizarConsulta(id);
      break;
    case 5:
    printf("Atendimento Emergencial? (1 - Sim, 0 - Não)");
    int emergencial;
    scanf("%d", &emergencial);
      
    char nome[50];
    printf("Digite o nome do paciente: ");
    scanf(" %49[^\n]", nome); 

    int idade;
    printf("Digite a idade do paciente: ");
    scanf("%d", &idade); 

    char especialidade[50];
    int opt;
    printf("Digite a especialidade do paciente: \n");
    printf("1 - Otorrino\n");
    printf("2 - Pediatra\n");
    printf("3 - Cardiologista\n");
    printf("4 - Neurologista\n");
    printf("5 - Geriatra\n");
    scanf("%d", &opt);
    switch(opt)
      {
        case 1:
          strcpy(especialidade, "Otorrino");
          break;
        case 2:
          strcpy(especialidade, "Pediatra");
          break;
        case 3:
          strcpy(especialidade, "Cardiologista");
          break;
        case 4:
          strcpy(especialidade, "Neurologista");
          break;
        case 5:
          strcpy(especialidade, "Geriatra");
          break;
      }
    if(emergencial == 1){
    inserirPaciente(nome, idade, especialidade, &filaUrgente);
      printf("Paciente adicionado a fila de emergência\n");	
    }
    else if(idade>60){
      inserirPaciente(nome, idade, especialidade, &filaPreferencial);
      printf("Paciente adicionado a fila preferencial\n");
    }
    else{
      inserirPaciente(nome, idade, especialidade, &filaNormal);
      printf("Paciente adicionado a fila normal\n");
    }
    break;
    case 0:
      exit(1);
  }
  }
}

