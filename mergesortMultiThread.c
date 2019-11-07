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
#include <math.h>

typedef struct ThreadInfo
{
    int threadID;
    int vectorBegin;
} threadInfo;

int initialLength = 10;
int *finalVector;
int threadNumbers, vectorLength = 0;
char clockTime[500], timeTime[500];

void Merge(int low, int middle, int high);
void MergeSort(int low, int high);
void ReadFile(char *fileName);
void RealocVector();
void SaveFile(char *fileName);
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

            register int vectorLengthOfThread = vectorLength / threadNumbers;
            
            time1 = clock();
            timeT1 = time(NULL);

            for (register int i = 0; i < threadNumbers; i++)
            {
                infoThread[i].threadID = i;
                infoThread[i].vectorBegin = vectorLengthOfThread * i;
                pthread_create(&threads[i], NULL, ThreadProccess, (void *)&infoThread[i]);
            }

            for (register int i = 0; i < threadNumbers; i++)
            {
                pthread_join(threads[i], NULL);
            }

            register int numOfMerge = threadNumbers / 2, i = 0,
                         low = 0,
                         high = vectorLengthOfThread * 2 - 1,
                         middle = (low + (high - low) / 2);

            while (i < numOfMerge)
            {
                Merge(low, middle, high);
                if (i == numOfMerge - 1)
                {
                    i = 0;
                    numOfMerge /= 2;
                    vectorLengthOfThread *= 2;
                    low = 0;
                    middle = vectorLengthOfThread - 1;
                    high = middle + vectorLengthOfThread;
                    if (numOfMerge == 1)
                    {
                        high = vectorLength - 1;
                    }
                }
                else
                {
                    i++;
                    low = high + 1,
                    middle = low + vectorLengthOfThread - 1,
                    high = middle + vectorLengthOfThread;
                    if (i == numOfMerge - 1)
                    {
                        high = vectorLength - 1;
                    }
                }
            }

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

void Merge(int low, int middle, int high)
{

    int left[middle - low + 1], right[high - middle];
    register int n1 = middle - low + 1;
    register int n2 = high - middle;
    register int i, j;

    for (i = 0; i < n1; i++)
    {
        left[i] = finalVector[i + low];
    }

    for (i = 0; i < n2; i++)
    {
        right[i] = finalVector[i + middle + 1];
    }

    register int k = low;
    i = j = 0;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            finalVector[k++] = left[i++];
        }
        else
        {
            finalVector[k++] = right[j++];
        }
    }

    while (i < n1)
    {
        finalVector[k++] = left[i++];
    }

    while (j < n2)
    {
        finalVector[k++] = right[j++];
    }
}

void MergeSort(int low, int high)
{
    if (low < high)
    {
        register int middle = low + (high - low) / 2;
        MergeSort(low, middle);
        MergeSort(middle + 1, high);
        Merge(low, middle, high);
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
    register int low = infos->vectorBegin;
    register int high = (infos->threadID + 1) * (vectorLength / threadNumbers) - 1;
    if (infos->threadID == threadNumbers - 1)
    {
        high = vectorLength - 1;
    }
    register int middle = low + (high - low) / 2;

    if (low < high)
    {
        MergeSort(low, middle);
        MergeSort(middle + 1, high);
        Merge(low, middle, high);
    }
    pthread_exit(NULL);
}
