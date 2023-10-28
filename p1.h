typedef struct{
    int prioridade;
    char categoria[100];//struct em categoria pra ter mais opcoes
    char descricao[300];
    int estado;
}tarefa;

typedef struct{ //fwrite desse struct
    tarefa Tarefas[100];
    int quantidade; //fazer for (ultima tarefa que adicionei (comeca com 0 e vai add)
}lista_tarefas;

typedef enum{N_INICIADA,FAZENDO,COMPLETA} estado;
//não iniciado = 0, em andamento = 1, completa = 2.
//int pq retorna numero (1 ou 0)
int cria_tarefa(lista_tarefas *Lt);
int deleta_tarefa(lista_tarefas *Lt);
int listar_tarefas(lista_tarefas Lt);
void print_menu();
int ler_arquivo(lista_tarefas *Lt, char nome[]);
int salva_tarefa(lista_tarefas Lt, char nome[]);
//p2
int editar_tarefa(lista_tarefas *Lt);
int filtro_prioridades(lista_tarefas Lt);
int filtro_estado(lista_tarefas Lt);
int filtro_categoria(lista_tarefas Lt);


/*

Filtrar tarefas por categoria: idem, mas com o filtro por categoria e com a prioridade ordenada da maior para a menor;

Filtrar tarefas por prioridade e categoria: junção das duas funções anteriores em que o usuário escolhe a categoria e a prioridade e o seu programa deve exibir as tarefas que passarem pelos dois filtros;

Exportar tarefas por prioridade: seu programa deve gerar um arquivo texto listando apenas as tarefas da prioridade escolhida pelo usuário. Cada tarefa deve estar em uma linha do arquivo na sequência: prioridade, categoria, estado e descrição;

Exportar tarefas por categoria: idem ao anterior, inclusive no formato do arquivo exportado, sendo que as tarefas devem estar ordenadas por prioridade;

Exportar tarefas por prioridade e categoria: junção dos filtros anteriores, mantendo o formato do arquivo que deve ser exportado.*/