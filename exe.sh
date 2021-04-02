#!/bin/sh
#cria o Object file (arquivos.o)
gcc -c libraries/auxiliary_functions.c -lrt
gcc -c libraries/sorting_methods.c -lrt
gcc -c libraries/test_database.c -lrt
gcc -c main.c -lrt

aux='auxiliary_functions.o'
sorting='sorting_methods.o'
database='test_database.o'
main='main.o'

#cria o linker juntando todos os object file criados anteriorimente.
gcc -o binary $aux $sorting $database $main -lrt

#executa o linker (executavel)
./binary

rm *.o