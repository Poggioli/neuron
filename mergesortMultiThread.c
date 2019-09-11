/*
*
*   Projeto de "Merge and sort"
*   Disciplina TT304 - Sistemas Operacionais
*   
*   Integrantes
*       Joao Vitor Pogiolli - 158049
*       Rafella Rodrigues   - 243597
*       Gabriel Coppola     - 216146
*
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ThreadInfo
{
    int threadID;
} threadInfo;

int initialLenght = 10;
int *finalVector;
int threadNumbers, vectorLenght;
char *clockTime, *timeTime;

void Merge(int begin, int middle, int end);
void MergeSort(int begin, int end);
void ReadFile(char *fileName);
void RealocVector();
void SaveFile(char *fileName);
void SaveResultFile();
void *ThreadProccess(void *info);

int main(int argc, char **argv)
{
    if (argc >= 4)
    {
        register int lastPositionArgc = argc - 1;
        char *outputFileName = argv[lastPositionArgc];
        threadNumbers = strtol(argv[1], NULL, 10);
        pthread_t threads[threadNumbers];
        threadInfo infoThread[threadNumbers];

        finalVector = (int *)malloc(initialLenght * sizeof(int));
        if (!finalVector)
        {
            printf("===== ERROR =====\n");
            printf("Operating system cannot allocate memory\n");
            exit(EXIT_FAILURE);
        }

        printf("----- Opening and reading input files -----\n");
        for (register int i = 2; i < lastPositionArgc; i++)
        {
            ReadFile(argv[i]);
        }
        printf("----- Read finished input files -----\n");
    }
    else
    {
        printf("===== ERROR =====\n");
        printf("You need to insert at least 3 parameters, in order:\n<number of thread>\n<input file name> (as many as you want)\n<output file name>\n");
        exit(EXIT_FAILURE);
    }
}

void Merge(int begin, int middle, int end) {}
void MergeSort(int begin, int end) {}
void ReadFile(char *fileName)
{
    FILE *file;
    file = fopen(fileName, "r");

    if (!file)
    {
        printf("===== ERROR =====\n");
        printf("Error to open input file: %s\n", fileName);
    }
    else
    {
        char *line = NULL;
        size_t lenght = 0;
        while (!feof(file))
        {
            fgets(line, lenght, file);
            if (vectorLenght == initialLenght)
            {
                RealocVector();
            }
            finalVector[vectorLenght] = atoi(line);
            vectorLenght++;
        }
    }
    fclose(file);
}
void SaveFile(char *fileName)
{
    FILE *file;
    file = fopen(fileName, "w");
    if (!file)
    {
        printf("===== ERROR =====\n");
        printf("Error to open file output file: %s\n", fileName);
    }
    else
    {
        printf("----- Writing output file: %s -----\n", fileName);
        for (register int i = 0; i < vectorLenght; i++)
        {
            fprintf(file, "%d\n", finalVector[i]);
        }
    }
    fclose(file);
}
void SaveResultFile() {}
void RealocVector()
{
    initialLenght *= 2;
    finalVector = (int *)realloc(finalVector, initialLenght * sizeof(int));
    if (!finalVector)
    {
        printf("===== ERROR =====");
        printf("Operating system cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }
}
void *ThreadProccess(void *info)
{
    return NULL;
}