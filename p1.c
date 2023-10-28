#include <stdio.h>
#include <string.h>
#include "p1.h"

int cria_tarefa(lista_tarefas *Lt){ // usa ponteiro pra funcao -> usa seta
    int estado;
    char priority;
    int qnt = 0; //só pra funcao
    if (Lt->quantidade < 100){
      printf("Digite a categoria da tarefa: ");
      scanf("%s", Lt->Tarefas[Lt->quantidade].categoria);
      printf("Digite a descricao da tarefa: ");
      scanf("%s", Lt->Tarefas[Lt->quantidade].descricao);
      printf("Digite a prioridade da tarefa (0-9): ");
      scanf("%d", &Lt->Tarefas[Lt->quantidade].prioridade);
      printf("1.tarefa não iniciada\n2.tarefa esta em andamento\n3.tarefa concluída\n");
      printf("Digite o número que indica o estado da tarefa\n: ");
      scanf("%d",&estado);
      if(estado == 1){
        Lt->Tarefas[Lt->quantidade].estado = 0;
      }
      else if(estado == 2){
        Lt->Tarefas[Lt->quantidade].estado = 1;
      }
      else if(estado == 3){
        Lt->Tarefas[Lt->quantidade].estado = 2;
      }
      else{
        printf("Estado inválido");
        return 1;
      }
      
       //prioridade de 0 a 9 pois para perguntar novamente a prioridade se o usuario nao digitar um numero precisa usar a tabela ascii e ela vai de 0 a 9
      qnt += 1;
      Lt -> quantidade = Lt -> quantidade + 1;  //funciona dentro e fora da funcao  
    }
    if(qnt == 1){                            
        printf("Tarefa criada com sucesso!\n");      
        return 0;                                  
    }                                              
    if(qnt != 1){                            
        printf("Erro ao criar tarefa\n");                
        return 1;                                                        
    }                
}

int deleta_tarefa(lista_tarefas *Lt){
    int num = 0;
    printf("Digite o número da categoria da tarefa que deseja deletar: ");
    scanf("%d",&num);
    if (Lt->quantidade == 0 || Lt->quantidade < num){  
        printf("Falha ao deletar a tarefa :( \n ");
        return 1;
    }
    for (int search = num - 1; search < Lt->quantidade; search ++ ){
        strcpy(Lt->Tarefas[search].categoria, Lt->Tarefas[search +1].categoria);
        strcpy(Lt->Tarefas[search].descricao, Lt->Tarefas[search +1].descricao);  
        Lt->Tarefas[search].prioridade = Lt->Tarefas[search +1].prioridade;
        Lt->Tarefas[search].estado = Lt->Tarefas[search +1].estado;
        Lt->quantidade--;
    }
    printf("Deletou com sucesso!\n");
    return 0;
}

int listar_tarefas(lista_tarefas Lt){ //quando for a copia do struct usa o ponto
    char estado[30];
    printf("\n");
    //printf("quantidade: %d \n", Lt.quantidade);
  if (Lt.quantidade == 0){
  printf("Não tem tarefa para listar\n");
  return 1;
  }
  for (int ToDo = 0; ToDo< Lt.quantidade; ToDo++ ){
      printf("%d.categoria: %s\tdescricao: %s\tprioridade: %2d\t", ToDo+1,Lt.Tarefas[ToDo].categoria, Lt.Tarefas[ToDo].descricao, Lt.Tarefas[ToDo].prioridade);
    printf("Estado da tarefa: ");
    if(Lt.Tarefas[ToDo].estado == 0){
      printf("Tarefa não iniciada\n");
  }
    else if(Lt.Tarefas[ToDo].estado == 1){
      printf("Tarefa em andamento\n");
    }
    else if(Lt.Tarefas[ToDo].estado == 2){
      printf("Tarefa Concluida :)\n");
    }
  printf("\n");
    }
  return 0;
}

void print_menu(){
    printf("1.Criar tarefa \n2.Deletar tarefa \n3.Listar tarefa \n4.Editar tarefa \nDigite 0 para sair </3 \n");  
}

int editar_tarefa(lista_tarefas *Lt){
  int num = 0;
  int decisao;
  int estado;
  printf("Digite o número da categoria da tarefa que deseja mudar: ");
  scanf("%d",&num);
  num = num -1;
  if (Lt->quantidade == 0 || Lt->quantidade < num){  
      printf("Falha ao encontrar a tarefa :( \n ");
      return 1;
  }
  for (int pesquisa = 0; pesquisa < Lt->quantidade; pesquisa ++ ){
    if (pesquisa == num){
      printf("1.Categoria: %s \n2.Descricao: %s \n3.Prioridade: %d \n4.Estado da tarefa: ",Lt->Tarefas[pesquisa].categoria, Lt->Tarefas[pesquisa].descricao, Lt->Tarefas[pesquisa].prioridade);
      if(Lt->Tarefas[pesquisa].estado == 0){
        printf("Tarefa não iniciada\n");
      }
      else if(Lt->Tarefas[pesquisa].estado == 1){
        printf("Tarefa em andamento\n");
      }
      else if(Lt->Tarefas[pesquisa].estado == 2){
        printf("Tarefa Concluida :)\n");
      }
      printf("Digite o que você deseja editar: ");
      scanf("%d",&decisao);
      if(decisao == 1){
        printf("Digite a nova categoria: ");
        scanf("%s",Lt->Tarefas[pesquisa].categoria);
      }
      else if(decisao == 2){
        printf("Digite a nova descrição: ");
        scanf("%s",Lt->Tarefas[pesquisa].descricao);
      }
      else if(decisao == 3){
        printf("Digite a nova prioridade: ");
        scanf("%d",&Lt->Tarefas[pesquisa].prioridade);
      }
      else if(decisao == 4){
        printf("1.tarefa não iniciada\n2.tarefa esta em andamento\n3.tarefa concluída\n");
        printf("Digite o número do novo estado da tarefa: ");
        scanf("%d",&estado);
        if(estado == 1){
          Lt->Tarefas[pesquisa].estado = 0;
        }
        else if(estado == 2){
          Lt->Tarefas[pesquisa].estado = 1;
        }
        else if(estado == 3){
          Lt->Tarefas[pesquisa].estado = 2;
        }
        else{
          printf("Estado inválido");
          return 1;
        }
      }
      else{
        printf("Opção inválida");
        return 1;
        }
    }
  }
  return 0;
}

int salva_tarefa(lista_tarefas Lt, char nome[]){
    FILE *f = fopen(nome,"wb");
    if (f == NULL){ //vê se valor do ponteiro ta apontando pra NULL
        printf("Falha ao abrir o arquivo");
        return 1;
    }
    fwrite(&Lt, sizeof(lista_tarefas), 1, f);
    fclose(f);
    return 0;
}

int ler_arquivo(lista_tarefas *Lt, char nome[]){  
    FILE *f = fopen(nome, "rb");
    if (f == NULL){
        printf("Falha ao abrir o arquivo\n");
        return 1;
    } //  var, tamanho, quantidade, arquivo
    fread(Lt, sizeof(lista_tarefas), 1, f); //1 pq é 1 struct (se fosse o tarefa seria 100 em quantidade)
    fclose(f);
    return 0;
}