#include <stdio.h>
#include <string.h>
#include "p1.h"

void print_menu(){
  printf("\n");
    printf("1.Criar tarefa \n2.Deletar tarefa \n3.Listar tarefa \n4.Editar tarefa \n5.Lista de tarefas filtrada por prioridade \n6.Lista de tarefas filtrada pelo estado das tarefas \n7.Lista de tarefas filtrada pela categoria das tarefas \n8.Lista de tarefas filtrada pela categoria e prioridades \n9.Arquivo mostrando as tarefas pela prioridade \n10.Arquivo mostrando as tarefas por categoria \n11.Arquivo mostrando as tarefas por categoria e prioridade \nDigite 0 para sair </3 \n");  
}

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
      qnt += 1;
      Lt -> quantidade = Lt -> quantidade + 1;  
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
    }
  Lt->quantidade--;
    printf("Deletou com sucesso!\n");
    return 0;
}

int listar_tarefas(lista_tarefas Lt){ //quando for a copia do struct usa o ponto
    char estado[30]; //variavel usada apenas para guardar a string da resposta dependendo do estado tarefa
    //printf("quantidade: %d \n", Lt.quantidade);
  if (Lt.quantidade == 0){
  printf("Não tem tarefa para listar\n");
  return 1;
  }
  for (int indice = 0; indice< Lt.quantidade; indice++ ){
      printf("%d.categoria: %s\tdescricao: %s\tprioridade: %2d\t", indice+1,Lt.Tarefas[indice].categoria, Lt.Tarefas[indice].descricao, Lt.Tarefas[indice].prioridade);
    printf("Estado da tarefa: ");
    if(Lt.Tarefas[indice].estado == 0){
      printf("Tarefa não iniciada\n");
  }
    else if(Lt.Tarefas[indice].estado == 1){
      printf("Tarefa em andamento\n");
    }
    else if(Lt.Tarefas[indice].estado == 2){
      printf("Tarefa Concluida :)\n");
    }
  printf("\n");
    }
  return 0;
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
  for (int indice = 0; indice < Lt->quantidade; indice ++ ){
    if (indice == num){
      printf("1.Categoria: %s \n2.Descricao: %s \n3.Prioridade: %d \n4.Estado da tarefa: ",Lt->Tarefas[indice].categoria, Lt->Tarefas[indice].descricao, Lt->Tarefas[indice].prioridade);
      if(Lt->Tarefas[indice].estado == 0){
        printf("Tarefa não iniciada\n");
      }
      else if(Lt->Tarefas[indice].estado == 1){
        printf("Tarefa em andamento\n");
      }
      else if(Lt->Tarefas[indice].estado == 2){
        printf("Tarefa Concluida :)\n");
      }
      printf("Digite o que você deseja editar: ");
      scanf("%d",&decisao);
      if(decisao == 1){
        printf("Digite a nova categoria: ");
        scanf("%s",Lt->Tarefas[indice].categoria);
      }
      else if(decisao == 2){
        printf("Digite a nova descrição: ");
        scanf("%s",Lt->Tarefas[indice].descricao);
      }
      else if(decisao == 3){
        printf("Digite a nova prioridade: ");
        scanf("%d",&Lt->Tarefas[indice].prioridade);
      }
      else if(decisao == 4){
        printf("1.tarefa não iniciada\n2.tarefa esta em andamento\n3.tarefa concluída\n");
        printf("Digite o número do novo estado da tarefa: ");
        scanf("%d",&estado);
        if(estado == 1){
          Lt->Tarefas[indice].estado = 0;
        }
        else if(estado == 2){
          Lt->Tarefas[indice].estado = 1;
        }
        else if(estado == 3){
          Lt->Tarefas[indice].estado = 2;
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
  printf("Tarefa editada com sucesso \n");
  return 0;
}

int filtro_prioridades(lista_tarefas Lt){ //Como colocaria uma mensagem que não existem tarefas com essa prioriade
  int prioridade;//variavel usada para guardar a resposta do usuario
  char resp[30];//variavel usada apenas para guardar a string da resposta dependendo do estado tarefa
  int existe = 0;
  printf("Digite a prioridade das tarefas que queira filtrar: ");
  scanf("%d",&prioridade);
  if (Lt.quantidade == 0){
    printf("Não tem tarefa para listar\n");
    return 1;
    }
  printf("\n");
  for (int indice = 0; indice< Lt.quantidade; indice++ ){
    if(Lt.Tarefas[indice].prioridade == prioridade){
      existe = 1;
      if(Lt.Tarefas[indice].estado == 0){
        strcpy(resp,"tarefa não iniciada");
      }
      else if(Lt.Tarefas[indice].estado == 1){
        strcpy(resp,"tarefa em andamento");
      }
      else if(Lt.Tarefas[indice].estado == 2){
        strcpy(resp,"tarefa concluida");
      }
      printf("Categoria: %s \tDescricao: %s \tEstado da tarefa: %s \tPrioridade: %d \t\n ",Lt.Tarefas[indice].categoria, Lt.Tarefas[indice].descricao,resp, Lt.Tarefas[indice].prioridade);
      printf("\n");
    }
  }
  if (existe == 0){
    printf("Não existe tarefas com essa prioridade");
    return 1;
  }
  return 0;
}

int filtro_estado(lista_tarefas Lt){
  int estado;//variavel usada para guardar a resposta do usuario
  char resp[30]; //variavel usada apenas para guardar a string da resposta dependendo do estado tarefa
  int existe = 0;
  if (Lt.quantidade == 0){
    printf("Não tem tarefa para listar\n");
    return 1;
    }
  printf("1.tarefa não iniciada\n2.tarefa esta em andamento\n3.tarefa concluída\n");
  printf("\n");
  printf("Digite o número do estado das tarefas que queira filtrar: ");
  scanf("%d",&estado);
  printf("\n");
  estado = estado - 1; // pegando o estado da tarefa de acordo com o enum (0, 1, 2)
  if(estado != 0 && estado != 1 && estado != 2){ //Vendo se o número é valido
    printf("Estado de tarefa invalido!");
    return 1;
  }
  if(estado == 0){
    strcpy(resp,"tarefa não iniciada");
  }
  else if(estado == 1){
    strcpy(resp,"tarefa em andamento");
  }
  else if(estado == 2){
    strcpy(resp,"tarefa concluida");
  }
  for (int indice = 0; indice< Lt.quantidade; indice++ ){
    if(Lt.Tarefas[indice].estado == estado){
      existe = 1;
      printf("Categoria: %s \tDescricao: %s \tPrioridade: %d \tEstado da tarefa: %s \t\n ",Lt.Tarefas[indice].categoria, Lt.Tarefas[indice].descricao,Lt.Tarefas[indice].prioridade,resp);
      printf("\n");
    }
  }
  if (existe == 0){
    printf("Não tem tarefas com esse estado");
    return 1;
  }
  return 0;
}

int filtro_categoria(lista_tarefas Lt){
  char categoria[100];//variavel usada para guardar a resposta do usuario
  char resp[30];//variavel usada apenas para guardar a string da resposta dependendo do estado tarefa
  int existe = 0;
  printf("Digite a categoria das tarefas que queira filtrar: ");
  scanf("%s",categoria);
  if (Lt.quantidade == 0){
    printf("Não tem tarefa para listar\n");
    return 1;
    }
  for (int sequencia = 9; sequencia>= 0; sequencia-- ){ //Deixa a prioridade em ordem decrescente
    for (int indice = 0; indice<Lt.quantidade; indice++ ){
      if(strcmp(Lt.Tarefas[indice].categoria,categoria) == 0){
        existe = 1;
        if(Lt.Tarefas[indice].prioridade == sequencia){
          if(Lt.Tarefas[indice].estado == 0){
            strcpy(resp,"tarefa não iniciada");
          }
          else if(Lt.Tarefas[indice].estado == 1){
            strcpy(resp,"tarefa em andamento");
          }
          else if(Lt.Tarefas[indice].estado == 2){
            strcpy(resp,"tarefa concluida");
          }
          printf("Categoria: %s \tDescricao: %s \tPrioridade: %d \tEstado da tarefa: %s \t\n ",Lt.Tarefas[indice].categoria, Lt.Tarefas[indice].descricao,Lt.Tarefas[indice].prioridade,resp);
        }
      }
    }
  }
  if(existe == 0){
    printf("Não tem tarefas com essa categoria");
    return 1;
  }
  return 0;
}

int filtro_categoria_prioridade(lista_tarefas Lt){
  char categoria[100];//variavel usada para guardar a resposta do usuario
  int prioridade;
  char resp[30];//variavel usada apenas para guardar a string da resposta dependendo do estado tarefa
  int existe = 0;
  printf("Digite a categoria das tarefas que queira filtrar: ");
  scanf("%s",categoria);
  printf("Digite a prioridade das categorias que queira filtrar: ");
  scanf("%d",&prioridade);
  if (Lt.quantidade == 0){
    printf("Não tem tarefa para listar\n");
    return 1;
    }
  printf("\n");
  for (int indice = 0; indice<Lt.quantidade; indice++ ){
    if(strcmp(Lt.Tarefas[indice].categoria,categoria) == 0){
      existe = 1;
      if(Lt.Tarefas[indice].prioridade == prioridade){
        existe = 2;
        if(Lt.Tarefas[indice].estado == 0){
          strcpy(resp,"tarefa não iniciada");
        }
        else if(Lt.Tarefas[indice].estado == 1){
          strcpy(resp,"tarefa em andamento");
        }
        else if(Lt.Tarefas[indice].estado == 2){
          strcpy(resp,"tarefa concluida");
        }
        printf("Categoria: %s \tDescricao: %s \tPrioridade: %d \tEstado da tarefa: %s \t\n ",Lt.Tarefas[indice].categoria, Lt.Tarefas[indice].descricao,Lt.Tarefas[indice].prioridade,resp);
        printf("\n");
   }
  }
 }
  if(existe == 0){
    printf("Não tem tarefas com essa categoria\n");
    return 1;
  }
  else if(existe == 1){
    printf("Não tem tarefas com essa prioridade nessa categoria\n");
    return 1;
  }
  return 0;
}

int exportar_prioridades(lista_tarefas Lt, char arquivo_ex[]){
  char arquivo[30] = "prioridade.txt";
  int prioridade;//variavel usada para guardar a resposta do usuario
  char resp[30];//variavel usada apenas para guardar a string da resposta dependendo do estado tarefa
  printf("Digite a prioridade das tarefas que queira filtrar: ");
  scanf("%d",&prioridade);
  if (Lt.quantidade == 0){
    printf("Não tem tarefa \n");
    return 1;
    }
  FILE *f = fopen(arquivo, "w");
  if (f == NULL) { // vê se valor do ponteiro ta apontando pra NULL
    printf("Falha ao abrir o arquivo");
  }
  for (int indice = 0; indice < Lt.quantidade; indice++) {
    if(Lt.Tarefas[indice].prioridade == prioridade){
      if(Lt.Tarefas[indice].estado == 0){
        strcpy(resp,"tarefa não iniciada");
      }
      else if(Lt.Tarefas[indice].estado == 1){
        strcpy(resp,"tarefa em andamento");
      }
      else if(Lt.Tarefas[indice].estado == 2){
        strcpy(resp,"tarefa concluida");
      }
      fprintf(f,"Categoria: %s \tDescricao: %s \tEstado da tarefa: %s \tPrioridade: %d \t\n ",Lt.Tarefas[indice].categoria, Lt.Tarefas[indice].descricao,resp, Lt.Tarefas[indice].prioridade);
  }
 }
  fclose(f);
  return 0;
}

int exportar_categoria(lista_tarefas Lt, char arquivo_ex[]){
  char arquivo[30] = "categoria.txt";
  char categoria[100];
  char resp[30];
  printf("Digite a categoria das tarefas que queira mostrar: ");
  scanf("%s",categoria);
  if (Lt.quantidade == 0){
    printf("Não tem tarefa \n");
    return 1;
    }
  FILE *f = fopen(arquivo, "w");
  if (f == NULL) { // vê se valor do ponteiro ta apontando pra NULL
    printf("Falha ao abrir o arquivo");
  }
  for (int sequencia = 9; sequencia>= 0; sequencia-- ){ //Deixa a prioridade em ordem decrescente
    for (int indice = 0; indice<Lt.quantidade; indice++ ){
      if(strcmp(Lt.Tarefas[indice].categoria,categoria) == 0){
        if(Lt.Tarefas[indice].prioridade == sequencia){
          if(Lt.Tarefas[indice].estado == 0){
            strcpy(resp,"tarefa não iniciada");
          }
          else if(Lt.Tarefas[indice].estado == 1){
            strcpy(resp,"tarefa em andamento");
          }
          else if(Lt.Tarefas[indice].estado == 2){
            strcpy(resp,"tarefa concluida");
          }
          fprintf(f,"Categoria: %s \tDescricao: %s \tPrioridade: %d \tEstado da tarefa: %s \t\n ",Lt.Tarefas[indice].categoria, Lt.Tarefas[indice].descricao,Lt.Tarefas[indice].prioridade,resp);
        }
      }
    }
  }
  fclose(f);
  return 0;
}

int exportar_categoria_prioridade(lista_tarefas Lt, char arquivo_ex[]){
  char categoria[100];//variavel usada para guardar a resposta do usuario
  char arquivo[30] = "categoria_e_prioridade.txt";
  int prioridade;
  char resp[30];//variavel usada apenas para guardar a string da resposta dependendo do estado tarefa
  if (Lt.quantidade == 0){
    printf("Não tem tarefa \n");
    return 1;
    }
  FILE *f = fopen(arquivo, "w");
  if (f == NULL) { // vê se valor do ponteiro ta apontando pra NULL
    printf("Falha ao abrir o arquivo");
  }
  printf("Digite a categoria das tarefas que queira filtrar: ");
  scanf("%s",categoria);
  printf("Digite a prioridade das categorias que queira filtrar: ");
  scanf("%d",&prioridade);
  for (int indice = 0; indice<Lt.quantidade; indice++ ){
      if(strcmp(Lt.Tarefas[indice].categoria,categoria) == 0){
        if(Lt.Tarefas[indice].prioridade == prioridade){
          if(Lt.Tarefas[indice].estado == 0){
            strcpy(resp,"tarefa não iniciada");
          }
          else if(Lt.Tarefas[indice].estado == 1){
            strcpy(resp,"tarefa em andamento");
          }
          else if(Lt.Tarefas[indice].estado == 2){
            strcpy(resp,"tarefa concluida");
          }
          fprintf(f,"Categoria: %s \tDescricao: %s \tPrioridade: %d \tEstado da tarefa: %s \t\n ",Lt.Tarefas[indice].categoria, Lt.Tarefas[indice].descricao,Lt.Tarefas[indice].prioridade,resp);
     }
    }
   }
  fclose(f);
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