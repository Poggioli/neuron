
# Neuron
Este repositório tem como propósito o projeto da disciplina TT304 - Sistemas Operacionais, sendo ele um código em **C** para ordenação de números aleatórios que são encontrados em arquivos de entrada, utilizando o algoritmo de **Mergesort** para ordenar e **multithreads** para que a execução seja mais rápida.
# Integrantes

Joao Vitor Pogiolli - 158049

<s>Rafaella Rodrigues - 243597</s>

<s>Gabriel Coppola - 216146</s>
# Conteúdo do repositório
- **CorrectOutPut.txt**
	- Arquivo que compreende todos os números dos 16 arquivos de entrada fornecidos no repositório já ordenados para comparação com arquivo gerado pelo código.

- **Relatorio.odt**
	- Relatório do trabalho.

- **file1.txt ~ file16.txt**
	- Arquivos de entrada, cada arquivo contém 5.000 (cinco mil) números aleatórios, sendo 1 o menor número possível e 100.000 (cem mil) o maior número possível.

- **makefile**
	- Arquivo make para compilação do algoritmo.

- **mergesortMultiThread.c**
	- Algoritmo em C.

- **scriptToExec.sh**
	- Arquivo que executa o algoritmo de ordenação.

# Instruções

## Maneira 1

 1. Compilar o programa

    ` gcc -g -o mergesortMultiThread mergesortMultiThread.c -lpthread`

 2. Executar o programa
 - Maneira a ser seguida para execução:

    ` ./mergesortMultiThread numero_de_threads arquivos_de_entradas arquivo_saida`

 - Exemplo para execução:

	 `./mergesortMultiThread 2 file1.txt file2.txt file3.txt file4.txt file5.txt output.txt`

3. Será gerado um arquivo de saída com o mesmo nome que você colocou quando compilou o programa.

## Maneira 2

 1. Entrar na pasta do projeto e executar o comando

 ` make `

 2. Executar o comando

 ` chmod 711 scriptToExec.sh `

 este comando dará permissão para que o próximo comando seja executado

 3. Executar o comando

 ` ./scriptToExec.sh `

 este comando irá executar o programa que foi compilado no **passo 1** da seguinte forma: 2, 4, 8 e 16 threads com 1 arquivo até o total de 16 arquivos de entrada
