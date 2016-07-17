#ifndef TAREFAS_H_INCLUDED
#define TAREFAS_H_INCLUDED

#include <inttypes.h>
#include "lista_enc.h"

typedef enum{
    OCIOSA,     // Nada a fazer
    EXECUTANDO, // Em execução
    PRONTA,     // Pronta para ser executada
    PARADA      // Tarefa parada por outra com maior prioridade
} ESTADO_TAREFA;

typedef struct tarefas tarefa_t;

tarefa_t* cria_tarefa(uint8_t id, uint64_t duracao, uint64_t periodo);

uint8_t tarefa_get_id(tarefa_t* tarefa);
uint64_t tarefa_get_duracao(tarefa_t* tarefa);
uint64_t tarefa_get_periodo(tarefa_t* tarefa);

void tarefa_set_estado(tarefa_t* tarefa, ESTADO_TAREFA estado);
ESTADO_TAREFA tarefa_get_estado(tarefa_t* tarefa);

void ordena_tarefas(lista_enc_t* lista_tarefas);

#endif // TAREFAS_H_INCLUDED
