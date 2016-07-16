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
    uint8_t id;            // Identificador da tarefa
    uint64_t duracao;      // Quanto tempo a tarefa será totalmente executada - C
    uint64_t periodo;      // Quanto tempo até a tarefa ser executada novamente - T
    ESTADO_TAREFA estado;  // Qual estado da tarefa
};

// Função cria tarefa - Precisamos decidir se ela já vai ser criada e definida ou vamos ter funções de setar
tarefa_t* cria_tarefa()
{
    tarefa_t* p_tarefa;

    p_tarefa = (tarefa_t*) malloc(sizeof(tarefa_t));
    if(p_tarefa == NULL){
        perror("Erro ao alocar tarefa:");
        exit(EXIT_FAILURE);
    }

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
