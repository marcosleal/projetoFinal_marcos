/** \file tarefas.h
 * \brief   Cabeçalho de Funções para manipulação das tarefas.
 *
 * \author  Sérgio Luiz Martins Jr.
 * \author  Marcos Vinícius Leal da Silva
 * \date    20/07/16
 * \version 1.0
 *
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
 * O tempo de início é o tempo no qual a tarefa começou a ser executada.
 * O tempo de execução representa quantos ciclos a tarefa executou.
 * O número de execução representa quantos "jobs" estão na fila.
 * E o estado indica qual o estado da tarefa.
 */
typedef struct tarefas tarefa_t;

/// \brief Criação de tarefas, indicando C e T
/**
 *  \param id: Identificador para a tarefa
 *  \param duracao: Tempo de duração da tarefa - C
 *  \param periodo: Tempo para chamada da tarefa - T
 *  \return Um ponteiro alocado do tipo tarefa_t
 *  \sa tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado(), tarefa_get_estado()
 */
tarefa_t* cria_tarefa(uint8_t id, uint64_t duracao, uint64_t periodo);

/// \brief Adquire o id da tarefa
/**
 *  \param tarefa: um ponteiro que representa o endereço da tarefa
 *  \return id: identificador da tarefa
 *  \sa cria_tarefa(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado(), tarefa_get_estado()
 */
uint8_t tarefa_get_id(tarefa_t* tarefa);

/// \brief Adquire a duração (C) da tarefa
/**
 *  \param tarefa: um ponteiro que representa o endereço da tarefa
 *  \return Duração da tarefa
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_periodo(), tarefa_set_estado(), tarefa_get_estado()
 */
uint64_t tarefa_get_duracao(tarefa_t* tarefa);

/// \brief Adquire o período (T) da tarefa
/**
 *  \param tarefa: um ponteiro que representa o endereço da tarefa
 *  \return Período da tarefa
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_set_estado(), tarefa_get_estado()
 */
uint64_t tarefa_get_periodo(tarefa_t* tarefa);

/// \brief Estabelece o estado da tarefa
/**
 *  \param tarefa: um ponteiro que representa o endereço da tarefa
 *  \param estado: pondendo ser OCIOSO, EXECUTANDO, PRONTA ou PARADA
 *  \return vazio
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_get_estado()
 */
void tarefa_set_estado(tarefa_t* tarefa, ESTADO_TAREFA estado);

/// \brief Adquire o estado da tarefa
/**
 *  \param tarefa: um ponteiro que representa o endereço da tarefa
 *  \return estado: pondendo ser OCIOSO, EXECUTANDO, PRONTA ou PARADA
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
ESTADO_TAREFA tarefa_get_estado(tarefa_t* tarefa);

/// \brief Ordena as tarefas pelo período (T), sendo do menor para o maior.
/**
 *  \param lista_tarefas: um ponteiro que representa o endereço da lista de tarefas
 *  \return vazio
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
void ordena_tarefas(lista_enc_t* lista_tarefas);

// Função para testes:
/// \brief Função para depuração do código, onde imprime todas as informações de todas tarefas da lista.
/**
 *  \param listaTarefas: um ponteiro que representa o endereço da lista de tarefas
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
 *  \param listaTarefas: um ponteiro que representa o endereço da lista de tarefas
 *  \return Tarefa prioritária
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
tarefa_t* retorna_tarefa_prio(lista_enc_t* listaTarefas);

/// \brief Verifica requisição de tarefa.
/**
 *  \param listaTarefas: um ponteiro que representa o endereço da lista de tarefas
 *  \param tempo: tempo
 *  \param fp: um ponteiro que representa o endereço da lista de tarefas
 *  \return Vazio
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
void update_tarefas(lista_enc_t* listaTarefas, uint32_t tempo, FILE *fp);

/// \brief Estabelece o tempo de início da tarefa.
/**
 *  \param tarefa: um ponteiro que representa o endereço da tarefa
 *  \param tempo: tempo de início que será estabelecido
 *  \return Vazio
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
void tarefa_set_inicio(tarefa_t* tarefa, uint32_t tempo);

/// \brief Estabelece o tempo de pausa da tarefa.
/**
 *  \param tarefa: um ponteiro que representa o endereço da tarefa
 *  \param tempo: tempo de pausa que será estabelecido
 *  \return Vazio
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
void tarefa_set_pausa(tarefa_t* tarefa, uint32_t tempo);

/// \brief Verifica se a tarefa está terminada.
/**
 *  \param tarefa: um ponteiro que representa o endereço da tarefa
 *  \param tempo: tempo que será verificado.
 *  \return 0: tarefa não terminada; 1: tarefa terminada
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
int tarefa_checa_termino(tarefa_t* tarefa, uint32_t tempo);

/// \brief Calcula o máximo divisor comum (MDC) entre dois números.
/**
 *  \param x: número inteiro não sinalizado
 *  \param y: número inteiro não sinalizado
 *  \return máximo divisor comum
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
uint64_t calcMDC(uint64_t x, uint64_t y);

/// \brief Calcula o mínimo múltiplo comum (MMC) entre dois números.
/**
 *  \param x: número inteiro não sinalizado
 *  \param y: número inteiro não sinalizado
 *  \return mínimo múltiplo comum
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
uint64_t calcMMC(uint64_t x, uint64_t y);

/// \brief Calcula o mínimo múltiplo comum (MMC) do período (T) de uma lista de tarefas.
/**
 *  \param listaTarefas: ponteiro que representa o endereço de uma lista de tarefas
 *  \return mínimo múltiplo comum dos períodos (T) da lista de tarefas
 *  \sa cria_tarefa(), tarefa_get_id(), tarefa_get_duracao(), tarefa_get_periodo(), tarefa_set_estado()
 */
uint64_t tarefas_calcMMC(lista_enc_t* listaTarefas);

/// \brief Escreve em um arquivo de saída o cabeçalho do Diagrama de Gannt.
/**
 *  \param fp: ponteiro do arquivo de saída
 *  \param numTarefas: numero de tarefas do Diagrama de Gannt
 *  \param escalaTempo: escala de tempo do Diagrama de Gannt
 *  \return vazio
 *  \sa gannt_finaliza_cabecalho(), gannt_nomenclatura(), gannt_seta_cima(), gannt_seta_baixo(), gannt_quadrado()
 */
void gannt_cabecalho(FILE *fp, uint8_t numTarefas, uint32_t escalaTempo);

/// \brief Escreve em um arquivo de saída a finalização do cabeçalho do Diagrama de Gannt.
/**
 *  \param fp: ponteiro do arquivo de saída
 *  \return vazio
 *  \sa gannt_cabecalho(), gannt_nomenclatura(), gannt_seta_cima(), gannt_seta_baixo(), gannt_quadrado()
 */
void gannt_finaliza_cabecalho(FILE *fp);

/// \brief Escreve em um arquivo de saída a legenda das tarefas no Diagrama de Gannt.
/**
 *  \param fp: ponteiro do arquivo de saída
 *  \param lista_tarefas: ponteiro que representa o endereço de uma lista de tarefas
 *  \return vazio
 *  \sa gannt_cabecalho(), gannt_finaliza_cabecalho(), gannt_seta_cima(), gannt_seta_baixo(), gannt_quadrado()
 */
void gannt_nomenclatura(FILE *fp, lista_enc_t* lista_tarefas);

/// \brief Escreve em um arquivo de saída a chegada de uma tarefa no Diagrama de Gannt.
/**
 *  \param fp: ponteiro do arquivo de saída
 *  \param id: identificador da tarefa
 *  \param tempo: tempo de chegada da tarefa
 *  \return vazio
 *  \sa gannt_cabecalho(), gannt_finaliza_cabecalho(), gannt_nomenclatura(), gannt_seta_baixo(), gannt_quadrado()
 */
void gannt_seta_cima(FILE *fp, uint8_t id, uint32_t tempo);

/// \brief Escreve em um arquivo de saída o término de uma tarefa no Diagrama de Gannt.
/**
 *  \param fp: ponteiro do arquivo de saída
 *  \param id: identificador da tarefa
 *  \param tempo: tempo de término da tarefa
 *  \return vazio
 *  \sa gannt_cabecalho(), gannt_finaliza_cabecalho(), gannt_nomenclatura(), gannt_seta_cima(), gannt_quadrado()
 */
void gannt_seta_baixo(FILE *fp, uint8_t id, uint32_t tempo);

/// \brief Escreve em um arquivo de saída a execução de uma tarefa no Diagrama de Gannt.
/**
 *  \param fp: ponteiro do arquivo de saída
 *  \param id: identificador da tarefa
 *  \param inicio: tempo de início da execução
 *  \param fim: tempo de fim da execução
 *  \return vazio
 *  \sa gannt_cabecalho(), gannt_finaliza_cabecalho(), gannt_nomenclatura(), gannt_seta_cima(), gannt_seta_baixo()
 */
void gannt_quadrado(FILE *fp, uint8_t id, uint32_t inicio, uint32_t fim);

/// \brief Desaloca o espaço de memória utilizado pela lista de tarefas.
/**
 *  \param lista_tarefas: ponteiro da lista de tarefas
 *  \return vazio
 *  \sa cria_no(), cria_lista_enc(), cria_tarefa()
 *
 * Função recebe toda a lista e desaloca nós, tarefas e a lista.
 */
void desaloca_lista_tarefas(lista_enc_t* lista_tarefas);

#endif // TAREFAS_H_INCLUDED

