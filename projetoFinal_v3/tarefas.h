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

/** \struct tarefas tarefas.h "tarefas.h"
 *   \brief Estrutura das tarefas
 *
 * Todas as tarefas contém um identificador (id), duração (C), período (T), tempo de início, tempo executado,
 * numero de "jobs" que estão na fila e estado. O tempo no decorrer do programa é medido em "ticks".
 * A duração (C) corresponde quanto tempo a tarefa precisa para ser executada por completo.
 * Quanto menor o período (T) de uma tarefa, maior será sua prioridade na fila de tarefas, sendo que esse
 * número significa de quanto em quanto tempo a tarefa será chamada.
 * O tempo de início é o tempo no qual a tarefa começou a ser executada, sendo importante para manipulação CPU
 */
typedef struct tarefas tarefa_t;

/// \brief Criação de tarefas, indicando C e T
/**
 *  \param id: Identificador para a tarefa
 *  \param duracao: Tempo de duração da tarefa - C
 *  \param período: Tempo para chamada da tarefa - T
 *  \return Um ponteiro alocado do tipo tarefa_t
 *  \sa tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado(), tarefa_get_estado()
 */
tarefa_t* cria_tarefa(uint8_t id, uint64_t duracao, uint64_t periodo);

/// \brief Adquire o id da tarefa
/**
 *  \param tarefa: um ponteiro que representa o endereço da tarefa
 *  \return id da tarefa
 *  \sa cria_tarefa(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado(), tarefa_get_estado()
 */
uint8_t tarefa_get_id(tarefa_t* tarefa);

/// \brief Adquire a duração (C) da tarefa
/**
 *  \param tarefa um ponteiro que representa o endereço da tarefa
 *  \return Duração da tarefa
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_periodo(), tarefa_set_estado(), tarefa_get_estado()
 */
uint64_t tarefa_get_duracao(tarefa_t* tarefa);

/// \brief Adquire o período (T) da tarefa
/**
 *  \param tarefa um ponteiro que representa o endereço da tarefa
 *  \return Período da tarefa
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

/// \brief Adquire o estado da tarefa
/**
 *  \param tarefa um ponteiro que representa o endereço da tarefa
 *  \return estado pondendo ser OCIOSO, EXECUTANDO, PRONTA ou PARADA
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
ESTADO_TAREFA tarefa_get_estado(tarefa_t* tarefa);

/// \brief Ordena as tarefas pelo período (T), sendo do menor para o maior.
/**
 *  \param lista de tarefas: um ponteiro que representa o endereço da lista de tarefas
 *  \return vazio
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
void ordena_tarefas(lista_enc_t* lista_tarefas);

// Função para testes:
/// \brief Função para depuração do código, onde imprime todas as informações de todas tarefas da lista.
/**
 *  \param lista de tarefas: um ponteiro que representa o endereço da lista de tarefas
 *  \return vazio
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
void imprime_tarefas(lista_enc_t* listaTarefas);

/// \brief Estabelece o tempo de início da tarefa.
/**
 *  \param tarefa: um ponteiro que representa o endereço da tarefa
 *  \param tempo: um ponteiro que representa o endereço da tarefa
 *  \return vazio
 */
void tarefa_set_inicio(tarefa_t* tarefa, uint32_t tempo);

/// \brief Adquire o tempo de início da tarefa.
/**
 *  \param tarefa: um ponteiro que representa o endereço da tarefa
 *  \return Tempo de início da tarefa
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
uint32_t tarefa_get_inicio(tarefa_t* tarefa);

/// \brief Adquire a tarefa prioritária.
/**
 *  \param lista de tarefas: um ponteiro que representa o endereço da lista de tarefas
 *  \return Tarefa prioritária
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
tarefa_t* retorna_tarefa_prio(lista_enc_t* listaTarefas);

/// \brief Verifica requisição de tarefa.
/**
 *  \param lista de tarefas: um ponteiro que representa o endereço da lista de tarefas
 *  \param tempo: tempo
 *  \param fp: um ponteiro que representa o endereço da lista de tarefas
 *  \return Vazio
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
void update_tarefas(lista_enc_t* listaTarefas, uint32_t tempo, FILE *fp);

/// \brief Estabelece o tempo de início da tarefa.
/**
 *  \param tarefas: um ponteiro que representa o endereço da tarefa
 *  \param tempo: tempo de início que será estabelecido
 *  \return Vazio
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
void tarefa_set_inicio(tarefa_t* tarefa, uint32_t tempo);


void tarefa_set_pausa(tarefa_t* tarefa, uint32_t tempo);
int tarefa_checa_termino(tarefa_t* tarefa, uint32_t tempo);

uint64_t calcMDC(uint64_t x, uint64_t y);
uint64_t calcMMC(uint64_t x, uint64_t y);
uint64_t tarefas_calcMMC(lista_enc_t* listaTarefas);

void ganntCabecalho(FILE *fp, uint8_t numTarefas);

void ganntFinalizaCabecalho(FILE *fp);

void ganntNomenclatura(FILE *fp, lista_enc_t* lista_tarefas);

void ganntSetaCima(FILE *fp, uint8_t id, uint32_t tempo);

void ganntSetaBaixo(FILE *fp, uint8_t id, uint32_t tempo);

void ganntQuadrado(FILE *fp, uint8_t id, uint32_t inicio, uint32_t fim);

#endif // TAREFAS_H_INCLUDED
