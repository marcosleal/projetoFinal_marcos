#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 10
#define DEBUG

int main (int argc, char **argv)
{
    char *cvalue = NULL;
    int index, auxC, auxT;
    int c;

    FILE *fp = NULL;
    char close;

    char str[BUFFER_SIZE], strAux[BUFFER_SIZE];
    int numTarefa;

    int *id, *C, *T;

    opterr = 0;

    /* getopt faz formatacao dos dados de entrada:
    c:-> argumento c com uma entrada adicional

    c: -> -c <argumento para c>
    */

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
                id = (int*)malloc(sizeof(int) * numTarefa);
                C = (int*)malloc(sizeof(int) * numTarefa);
                T = (int*)malloc(sizeof(int) * numTarefa);
                #ifdef DEBUG
                printf("Cabecalho adquirido com SUCESSO\n\n");
                #endif
            }else{
                sscanf(str, "T%d;%d;%d", &index, &auxC, &auxT);
                id[index - 1] = index;
                C[index - 1] = auxC;
                T[index - 1] = auxT;
                printf("Armazenado \tT%d\tC: %d\tT: %d\n", id[index - 1], C[index - 1], T[index - 1]);
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

    for (index = optind; index < argc; index++)
        printf ("Non-option argument %s\n", argv[index]);

    free(id);
    free(C);
    free(T);

    return 0;
}
