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

int initialLength = 10;
int *finalVector;
int threadNumbers, vectorLength = 0;
char clockTime[500], timeTime[500];

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

        finalVector = (int *)malloc(initialLength * sizeof(int));
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
        printf("----- Read finished input files -----\n\n");

        if (vectorLength != 0)
        {

            pthread_t threads[threadNumbers];
            threadInfo infoThread[threadNumbers];
            printf("----- Starting sorting -----\n");
            clock_t time1, time2;
            time_t timeT1, timeT2;

            time1 = clock();
            timeT1 = time(NULL);

            for (register int i = 0; i < threadNumbers; i++)
            {
                infoThread[i].threadID = i;
                pthread_create(&threads[i], NULL, ThreadProccess, (void *)&infoThread[i]);
            }

            for (register int i = 0; i < threadNumbers; i++)
            {
                pthread_join(threads[i], NULL);
            }

            Merge(0, (vectorLength / 2 - 1) / 2, vectorLength / 2 - 1);
            Merge(vectorLength / 2, vectorLength / 2 + (vectorLength - 1 - vectorLength / 2) / 2, vectorLength - 1);
            Merge(0, (vectorLength - 1) / 2, vectorLength - 1);

            time2 = clock();
            timeT2 = time(NULL);
            printf("----- Finished sorting -----\n\n");

            sprintf(timeTime, "%f", difftime(timeT2, timeT1));
            sprintf(clockTime, "%f", ((time2 - time1) / (double)CLOCKS_PER_SEC));

            SaveFile(outputFileName);

            printf("----- Numbers of Threads: %d -----\n----- Number of numbers ordered: %d -----\n----- ClockT: %s -----\n----- TimeT: %s -----\n ", threadNumbers, vectorLength, clockTime, timeTime);
        }
        else
        {
            printf("===== WARNING =====\n");
            printf("There are no values to sort\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        printf("===== ERROR =====\n");
        printf("You need to insert at least 3 parameters, in order:\n<number of thread>\n<input file name> (as many as you want)\n<output file name>\n");
        exit(EXIT_FAILURE);
    }
}

void Merge(int begin, int middle, int end)
{
    register int beginAux1 = begin, beginAux2 = middle + 1, beginAux = 0, tam = end - begin + 1;
    int *vetAux = (int *)malloc(tam * sizeof(int));

    while (beginAux1 <= middle && beginAux2 <= end)
    {
        if (finalVector[beginAux1] < finalVector[beginAux2])
        {
            vetAux[beginAux] = finalVector[beginAux1];
            beginAux1++;
        }
        else
        {
            vetAux[beginAux] = finalVector[beginAux2];
            beginAux2++;
        }
        beginAux++;
    }

    while (beginAux1 <= middle)
    {
        vetAux[beginAux] = finalVector[beginAux1];
        beginAux++;
        beginAux1++;
    }

    while (beginAux2 <= end)
    {
        vetAux[beginAux] = finalVector[beginAux2];
        beginAux++;
        beginAux2++;
    }

    for (beginAux = begin; beginAux <= end; beginAux++)
    {
        finalVector[beginAux] = vetAux[beginAux - begin];
    }
}

void MergeSort(int begin, int end)
{
    if (begin < end)
    {
        register int middle = begin + (end - begin) / 2;
        MergeSort(begin, middle);
        MergeSort(middle + 1, end);
        Merge(begin, middle, end);
    }
}

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
        size_t length = 0;
        ssize_t read;
        while ((read = getline(&line, &length, file)) != -1)
        {
            if (vectorLength == initialLength)
            {
                RealocVector();
            }
            finalVector[vectorLength] = strtol(line, NULL, 10);
            vectorLength++;
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
        for (register int i = 0; i < vectorLength; i++)
        {
            if (i != vectorLength - 1)
            {
                fprintf(file, "%d\n", finalVector[i]);
            }
            else
            {
                fprintf(file, "%d", finalVector[i]);
            }
        }
    }
    fclose(file);
}

void SaveResultFile() {}

void RealocVector()
{
    initialLength *= 2;
    finalVector = (int *)realloc(finalVector, initialLength * sizeof(int));
    if (!finalVector)
    {
        printf("===== ERROR =====");
        printf("Operating system cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }
}

void *ThreadProccess(void *info)
{
    threadInfo *infos = (threadInfo *)info;

    register int begin = infos->threadID * (vectorLength / threadNumbers);
    register int end = (infos->threadID + 1) * (vectorLength / threadNumbers) - 1;
    register int middle = begin + (end - begin) / 2;

    if (begin < end)
    {
        MergeSort(begin, middle);
        MergeSort(middle + 1, end);
        Merge(begin, middle, end);
    }
    pthread_exit(NULL);
}