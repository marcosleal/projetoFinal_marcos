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
