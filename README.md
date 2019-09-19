
# Neuron
Este repositório tem como destino o projeto da disciplina TT304 - Sistemas Operacionais, sendo ele um código em **C** para ordenação de números aleatórios que são encontrados em arquivos de entrada, utilizando o algoritmo de **Mergesort** para ordenar e **multithreads** para que a execução seja mais rápida.
# Integrantes

Joao Vitor Pogiolli - 158049

Rafaella Rodrigues - 243597

<s>Gabriel Coppola - 216146</s> 
# Instruções

 1. Compilar o programa

    ` gcc -g -o mergesortMultiThread mergesortMultiThread.c -lpthread`

 2. Executar o programa
 - Maneira a ser seguida para execução:

    ` ./mergesortMultiThread numero_thread arquivos_entradas arquivo_saida`

 - Exemplo para execução:

	 `./mergesortMultiThread 2 file1.txt file2.txt file3.txt file4.txt file5.txt output.txt`

3. Será gerado um arquivo de saída com o mesmo nome que você colocou quando compilou o programa.
