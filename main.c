#include <stdio.h>
#include "p1.h"
#include <string.h>

int main(){
    char arquivo[]= "tarefa";
    char arquivo_pri[] = "-";
    char arquivo_cat[] = "-";
    char arquivo_cat_pri[] = "-";
    int codigo; //armazena codigo de retorno das funcoes
    lista_tarefas Lt;
    codigo = ler_arquivo(&Lt, arquivo); //chama a funcao de ler arquivo
    if( codigo == 1){
        Lt.quantidade = 0; //limpa memoria
    }
    int opcao;
    do{
      print_menu();
      printf("Digite o numero da opcao desejada: ");
      scanf("%d", &opcao);
      printf("\n");
      if (opcao == 0){
      }else if(opcao == 1){
          cria_tarefa(&Lt);
      }else if(opcao == 2){
          deleta_tarefa(&Lt);
      }else if(opcao == 3){
          listar_tarefas(Lt);
      }else if(opcao == 4){
          editar_tarefa(&Lt);
      }else if(opcao == 5){
          filtro_prioridades(Lt);
      }else if(opcao == 6){
          filtro_estado(Lt);
      }else if(opcao == 7){
          filtro_categoria(Lt);
      }else if(opcao == 8){
          filtro_categoria_prioridade(Lt);
      }else if(opcao == 9){
          exportar_prioridades(Lt,arquivo_pri);
      }else if(opcao == 10){
          exportar_categoria(Lt,arquivo_cat);
      }else if(opcao == 11){
          exportar_categoria_prioridade(Lt,arquivo_cat_pri);
      }else{
          printf("Opcao escolhida nao existe\n");
      }
      codigo = salva_tarefa(Lt, arquivo);
      if(codigo != 0){
          printf("Erro ao salvar as tarefas\n");
      }
    }while(opcao != 0); //loop
}