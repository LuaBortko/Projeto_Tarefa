#include <stdio.h>
#include "p1.h"
#include <string.h>

int main(){
    char arquivo[]= "tarefa";
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
    if (opcao == 0){
    }else if(opcao == 1){
        cria_tarefa(&Lt);
    }else if(opcao == 2){
        deleta_tarefa(&Lt);
    }else if(opcao == 3){
        listar_tarefas(Lt);
    }else{
        printf("Opcao escolhida nao existe\n");
    }
    }while(opcao != 0); //loop

    codigo = salva_tarefa(Lt, arquivo);    //chama a funcao ->salva tarefa
    if(codigo != 0){
        printf("Erro ao salvar as tarefas\n");
    }
}