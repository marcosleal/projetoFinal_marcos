/** \file tarefas.h
 * \brief   Cabeçalho de Funções para manipulação das tarefas.
 *
 * \author  Sérgio Luiz Martins Jr.
 * \author  Marcos Vinícius Leal da Silva
 * \date    16/07/16
 * \version 1.0
 *
 * A more elaborated file description.
 */

#ifndef TAREFAS_H_INCLUDED
#define TAREFAS_H_INCLUDED

#include <inttypes.h>
#include "lista_enc.h"

/** \enum ESTADO_TAREFA
 * Indica qual é o estado da tarefa, sendo:
 */
typedef enum{
    OCIOSA,     ///< Nada a fazer
    EXECUTANDO, ///< Em execução
    PRONTA,     ///< Pronta para ser executada
    PARADA      ///< Tarefa parada por outra com maior prioridade
} ESTADO_TAREFA;

/** \typedef tarefas tarefas.h "tarefas.h"
 *   \brief Estrutura das tarefas
 * Todas as tarefas contém um identificador (id), duração (C), período (T) e estado.
 */
typedef struct tarefas tarefa_t;

/// \brief Criação de tarefas, indicando C e T
/**
 *  \param id Identificador para a tarefa
 *  \param duracao Tempo de duração da tarefa - C
 *  \param período Tempo para chamada da tarefa - T
 *  \return Um ponteiro do tipo tarefa_t
 *  \sa tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado(), tarefa_get_estado()
 */
tarefa_t* cria_tarefa(uint8_t id, uint64_t duracao, uint64_t periodo);

/// \brief Requisição do id da tarefa
/**
 *  \param tarefa um ponteiro que representa o endereço da tarefa
 *  \return Inteiro de 8 bits não sinalizado
 *  \sa cria_tarefa(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado(), tarefa_get_estado()
 */
uint8_t tarefa_get_id(tarefa_t* tarefa);

/// \brief Requisição da duração (C) da tarefa
/**
 *  \param tarefa um ponteiro que representa o endereço da tarefa
 *  \return Inteiro de 64 bits não sinalizado
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_periodo(), tarefa_set_estado(), tarefa_get_estado()
 */
uint64_t tarefa_get_duracao(tarefa_t* tarefa);

/// \brief Requisição do período (T) da tarefa
/**
 *  \param tarefa um ponteiro que representa o endereço da tarefa
 *  \return Inteiro de 64 bits não sinalizado
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_set_estado(), tarefa_get_estado()
 */
uint64_t tarefa_get_periodo(tarefa_t* tarefa);

/// \brief Estabelece o estado da tarefa
/**
 *  \param tarefa um ponteiro que representa o endereço da tarefa
 *  \param estado pondendo ser OCIOSO, EXECUTANDO, PRONTA ou PARADA
 *  \return vazio
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_get_estado()
 */
void tarefa_set_estado(tarefa_t* tarefa, ESTADO_TAREFA estado);

/// \brief Requisição do estado da tarefa
/**
 *  \param tarefa um ponteiro que representa o endereço da tarefa
 *  \return estado pondendo ser OCIOSO, EXECUTANDO, PRONTA ou PARADA
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
ESTADO_TAREFA tarefa_get_estado(tarefa_t* tarefa);

void ordena_tarefas(lista_enc_t* lista_tarefas);

#endif // TAREFAS_H_INCLUDED
