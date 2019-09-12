
# Neuron
Este repositório tem como destino o projeto da disciplina TT304 - Sistemas Operacionais, sendo ele um código em **C** para ordenação de números aleatórios que são encontrados em arquivos de entrada, utilizando o algoritmo de **Mergesort** para ordenar e **multithreads** para que a execução seja mais rápida.
# Integrantes
Joao Vitor Pogiolli - 158049
Rafella Rodrigues - 243597
Gabriel Coppola - 216146
# Instruções
## Passo 1
`gcc -g -o mergesortMultiThread mergesortMultiThread.c -lpthread`
## Passo 2
### Parâmetros:
`./mergesortMultiThread numero_thread arquivos_entradas arquivo_saida`
### Exemplo de compilação
`./mergesortMultiThread 3 fileOne.txt fileTwo.txt fileThree.txt fileFour.txt output.txt`
## Passo 3
Será gerado um arquivo de saída com o mesmo nome que você colocou quando compilou o programa.