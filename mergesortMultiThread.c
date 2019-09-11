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

struct ThreadInfo
{
    int threadID;
};

int initialLenght = 10;
int *finalVector;
int threadNumbers, vectorLenght;
char *clockTime, *timeTime, *outputFile;

void ReadFile(char *fileName);
void saveFile();
void saveResultFile();
void Merge(int begin, int middle, int end);
void MergeSort(int begin, int end);
void *ThreadProccess(void *info);
void RealocVector();

int main(int argc, char **argv) {}

void ReadFile(char *fileName) {}
void saveFile() {}
void saveResultFile() {}
void Merge(int begin, int middle, int end) {}
void MergeSort(int begin, int end) {}
void *ThreadProccess(void *info) {}
void RealocVector() {}