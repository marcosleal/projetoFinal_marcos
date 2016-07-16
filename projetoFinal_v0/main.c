/** \file main.c
 * \brief   Objetivo: Criar o TaD que ira ser utilizado para conter as informações das tarefas
 *
 * \author  Sérgio Luiz Martins Jr.
 * \author  Marcos Vinícius Leal da Silva
 * \date    16/07/16
 * \version 1.0
 *
 * A more elaborated file description.
 */

// Data: 16/07/2016
//
// Objetivo: Criar o TaD que ira ser utilizado para conter as informações das tarefas
//

#include <stdio.h>
#include <stdlib.h>

#include "tarefas.h"

int main()
{
    tarefa_t* tarefaTeste;

    tarefaTeste = cria_tarefa();

    tarefa_set_estado(tarefaTeste, OCIOSA);

    return 0;
}
