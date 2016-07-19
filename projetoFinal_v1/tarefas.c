/** \file tarefas.c
 * \brief   Funções para manipulação das tarefas.
 *
 * \author  Sérgio Luiz Martins Jr.
 * \author  Marcos Vinícius Leal da Silva
 * \date    16/07/16
 * \version 1.0
 *
 * A more elaborated file description.
 */

// Changelog
//
//  16/07/2016 - Criação do dado
//

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "tarefas.h"

struct tarefas{
    uint8_t id;            /// Identificador da tarefa
    uint64_t duracao;      /// Quanto tempo a tarefa será totalmente executada - C
    uint64_t periodo;      /// Quanto tempo até a tarefa ser executada novamente - T
    ESTADO_TAREFA estado;  /// Qual estado da tarefa
};

// Função cria tarefa
tarefa_t* cria_tarefa(uint8_t id, uint64_t duracao, uint64_t periodo)
{
    tarefa_t* p_tarefa;

    p_tarefa = (tarefa_t*) malloc(sizeof(tarefa_t));
    if(p_tarefa == NULL){
        perror("Erro ao alocar tarefa:");
        exit(EXIT_FAILURE);
    }

    p_tarefa->id = id;
    p_tarefa->duracao = duracao;
    p_tarefa->periodo = periodo;
    p_tarefa->estado = PRONTA;

    return p_tarefa;
}

uint8_t tarefa_get_id(tarefa_t* tarefa)
{
    uint8_t id;

    // Verifica se o ponteiro de tarefa é válido



    id = tarefa->id;

    return id;
}

uint64_t tarefa_get_duracao(tarefa_t* tarefa)
{
    uint64_t duracao;

    // Verifica se o ponteiro de tarefa é válido


    duracao = tarefa->duracao;

    return duracao;
}

uint64_t tarefa_get_periodo(tarefa_t* tarefa)
{
    uint64_t periodo;

    periodo = tarefa->periodo;

    return periodo;
}

void tarefa_set_estado(tarefa_t* tarefa, ESTADO_TAREFA estado)
{
    // Verifica se o ponteiro de tarefa é válido

    tarefa->estado = estado;
}

ESTADO_TAREFA tarefa_get_estado(tarefa_t* tarefa)
{
    ESTADO_TAREFA estado;

    estado = tarefa->estado;

    return estado;
}

void ordena_tarefas(lista_enc_t* lista_tarefas)
{
    tarefa_t* p_tarefa;
    tarefa_t* p_tarefa_next;
    no_t* p_no;
    int tamanho, i;

    for(tamanho = tamanho_lista(lista_tarefas); tamanho>1; tamanho--){
        p_no = obter_cabeca(lista_tarefas);
        for(i=0; i<(tamanho-1); i++){
            p_tarefa = (tarefa_t*) obter_dado(p_no);
            p_no = obtem_proximo(p_no);
            p_tarefa_next = (tarefa_t*) obter_dado(p_no);
            if(tarefa_get_periodo(p_tarefa) > tarefa_get_periodo(p_tarefa_next)){
                swap_nos(lista_tarefas, obtem_anterior(p_no));
            }
        }
    }
}

void imprimeCabecalho(FILE *fp, uint8_t numTarefas)
{
    fprintf(fp, "\\documentclass[legalpaper,10pt]{article}\n");
    fprintf(fp, "\\usepackage[landscape]{geometry}\n");
    fprintf(fp, "\\usepackage[utf8]{inputenc}\n");
    fprintf(fp, "\\usepackage[brazil]{babel}\n\n");

    fprintf(fp, "\\usepackage{listings}\n");
    fprintf(fp, "\\usepackage{listingsutf8}\n\n");

    fprintf(fp, "\\usepackage{rtsched}\n\n");

    fprintf(fp, "\\begin{document}\n\n");

    fprintf(fp, "\\begin{figure}[h]\n");
    fprintf(fp, "\\centering\n\n");

    fprintf(fp, "\t%% Cria ambiente, %d tarefas, escala de tempo até 90\n", numTarefas+1);
    fprintf(fp, "\t\\begin{RTGrid}[nosymbols=1,width=25cm]{%d}{90}\n", numTarefas+1);
}

void finalizaCabecalho(FILE *fp)
{
    fprintf(fp, "\t\\end{RTGrid}\n\n");

    fprintf(fp, "\\caption{Exemplo de escalonamento para tarefas.}\n");
    fprintf(fp, "\\label{fig:ex1}\n");
    fprintf(fp, "\\end{figure}\n");
    fprintf(fp, "\\end{document}");
}

//void imprimeNomenclatura(FILE *fp, lista_enc_t* lista_tarefas)
//{
//    tarefa_t* p_tarefa;
//    no_t* p_no;
//    int tamanho, i;
//
//    fprintf(fp, "\t%% Nomenclatura das tarefas\n");
//
//    tamanho = tamanho_lista(lista_tarefas);
//
//    fprintf(fp, "\\RowLabel{%d}{CPU}\n", tamanho+1);
//
//    p_no = obter_cabeca(lista_tarefas);
//
//    for(i = 0; i < tamanho; i++){
//        p_tarefa = (tarefa_t*) obter_dado(p_no);
//        fprintf(fp, "\\RowLabel{%d}{$\\tau_%d}\n", i+1, tarefa_get_id(p_tarefa));
//        p_no = obtem_proximo(p_no);
//    }
//}
