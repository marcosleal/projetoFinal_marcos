/** \file main.c
 * \brief   Objetivo: Implementar funções auxiliares para trabalho com tarefas
 *
 * \author  Sérgio Luiz Martins Jr.
 * \author  Marcos Vinícius Leal da Silva
 * \date    16/07/16
 * \version 2.0
 *
 * A more elaborated file description.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "tarefas.h"
#include "lista_enc.h"
#include "no.h"

#define BUFFER_SIZE 10
#define DEBUG

int main (int argc, char **argv)
{
    tarefa_t* tarefaAtual;
    tarefa_t* tarefaPrio;
    lista_enc_t* listaTarefas;
    no_t* no_aux;
    unsigned long int ticks;
    int hiper_periodo;

    char *cvalue = NULL;
    int indice, auxC, auxT;
    int c;

    FILE *fp = NULL;
    char close;

    char str[BUFFER_SIZE], strAux[BUFFER_SIZE];
    int numTarefa;

    opterr = 0;

    listaTarefas = cria_lista_enc();

    while ((c = getopt(argc, argv, "c:")) != -1)

    switch (c){
        case 'c':
            cvalue = optarg;
            break;
        case '?':
            if (optopt == 'c')
                fprintf (stderr, "Opcao -%c requer um argumento.\n", optopt);
            else if (isprint (optopt))
                fprintf (stderr, "Opcao desconhecida `-%c'.\n", optopt);
            else
                fprintf (stderr, "Caracter desconhecido `\\x%x'.\n", optopt);
                return 1;
        default:
            abort();
    }

    fp = fopen(cvalue, "r");

    if(fp == NULL){                                     // Verificação de erro na abertura
        printf("ERRO na leitura do arquivo de entrada!\n");
        return -1;
    }else
        printf("Arquivo de entrada ABERTO com sucesso.\n\n");

    while(!feof(fp)){                                   // Sairá do laço caso alcance o final do arquivo
        fgets(str, BUFFER_SIZE, fp);                    // Lê uma linha do arquivo até '\n', retorna NULL em str caso falhe

        if((str != NULL)){                              // Caso não tenha falhado a leitura da linha
            // Leitura do cabeçalho
            memset (strAux, '-', BUFFER_SIZE - 1);      // Limpa a string auxiliar - resolve problemas com '\n'
            sscanf(str, "%s", strAux);                  // Armazena a primeira string de str em strAux.
            if(!strncmp(strAux, "N", 1)){
                sscanf(str, "N;%d", &numTarefa);
                #ifdef DEBUG
                printf("Numero de Tarefas = %d\n", numTarefa);
                #endif
            }else if(!strcmp(strAux, "id;C;T")){
                #ifdef DEBUG
                printf("Cabecalho adquirido com SUCESSO\n\n");
                #endif
            }else{
                sscanf(str, "T%d;%d;%d", &indice, &auxC, &auxT);
                tarefaAtual = cria_tarefa(indice, auxC, auxT);
                no_aux = cria_no((void*) tarefaAtual);
                add_cauda(listaTarefas, no_aux);
                printf("Armazenado \tT%d\tC: %d\tT: %d\n", indice, auxC, auxT);
            }
        }
    }

    close = fclose(fp);                                              // Fechando o arquivo de entrada aberto
    if(close == EOF){                                                // Verificando erro no fechamento do arquivo de entrada
        printf("\nERRO ao FECHAR o arquivo de entrada!\n");
        return -1;
    }else{
        printf("\nArquivo de entrada FECHADO com sucesso!\n\n");
    }

    printf ("cvalue = %s\n", cvalue);

    for (indice = optind; indice < argc; indice++)
        printf ("Non-option argument %s\n", argv[indice]);

    ordena_tarefas(listaTarefas);
    hiper_periodo = tarefas_calcMMC(listaTarefas);
    printf("HiperPeriodo = %d\n", hiper_periodo);

    ticks = 0;
    tarefaAtual = NULL;
    while(ticks<=hiper_periodo){
        update_tarefas(listaTarefas, ticks);

        tarefaPrio = retorna_tarefa_prio(listaTarefas);
        if(tarefaPrio){
            if(tarefaAtual != tarefaPrio){
                if(tarefaAtual){
                    if(tarefa_checa_termino(tarefaAtual, ticks)){

                    }else
                        tarefa_set_pausa(tarefaAtual, ticks);
                }
                tarefaAtual = tarefaPrio;
                tarefa_set_inicio(tarefaAtual, ticks);
            }

            if(tarefa_checa_termino(tarefaAtual, ticks)){
                tarefaAtual = retorna_tarefa_prio(listaTarefas);
                if(tarefaAtual){
                    tarefa_set_inicio(tarefaAtual, ticks);
                }
            }
        }

        #ifdef DEBUG
            printf("Tick: %d\n", (int) ticks);
            imprime_tarefas(listaTarefas);
            puts("");
        #endif // DEBUG

        ticks++;
    }




    return 0;
}
