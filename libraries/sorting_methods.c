#include <stdio.h>
#include <stdlib.h>
#include "auxiliary_functions.h"
#include "sorting_methods.h"

void buble_sort(int* vet, int tam){
    int i, j;
    for(i = tam ; i > 0 ; i--){
        for(j = 0; j < i - 1; j++){
            if(vet[j] > vet[j + 1]){
                troca(&vet[j], &vet[j + 1]);
            }
        }   
    }
}


void buble_sort_improved(int* vet, int tam){
    int i, j, trc = 0;
    for(i = tam ; i > 0 ; i--){
        for(j = 0; j < i - 1; j++){
            if(vet[j] > vet[j + 1]){
                troca(&vet[j], &vet[j + 1]);
                trc++;
            }
        }
        if(trc == 0 ){
            break;
        }
        else{
            trc = 0;
        }
    }
}


void selection_recursive(int* vet, int tam){
    if(tam > 1){
        int m = maior(vet, tam);
        if(m != tam - 1){
            troca(&vet[tam - 1], &vet[m]);
        }
        selection_recursive(vet, tam - 1);
    }
}


void selection_iterative(int* vet,int tam){
    int i, pos_maior;
    for(i = tam; i > 0; i--){
        pos_maior = maior(vet, i);
        troca(&vet[i - 1], &vet[pos_maior]);
    }
}


void insertion_sort(int* vet, int tam){
    int i, j;
    for(i = 1; i < tam; i++){
        int aux = vet[i];
        for(j = i - 1; j >= 0 && aux < vet[j]; j--){
            vet[j + 1] = vet[j];
        }
        vet[j + 1] = aux;
    }
}


void shell_sort(int* vet, int tam){
    int i, h = 1, j, aux;
    while(h < tam){
        h = h * 3 + 1;
    }
    do{
        h = h / 3;
        for(i = h; i < tam; i++){
            aux = vet[i];
            j = i;
            while(vet[j - h] > aux){
                vet[j] = vet[j - h];
                j =  j - h;
                if(j < h){
                    break;
                }
            }
            vet[j] = aux;
        }
    }while(h != 1);
}


void real_quick_sort(int* vet, int esq, int dir){
    int pivo = vet[(esq + dir) / 2];
    int i = esq;
    int j = dir;
    while(i <= j){
        while(vet[i] < pivo && i < dir){
            i++;
        }
        while(vet[j] > pivo && j > esq){
            j--;
        } 
        if(i <= j){
            troca(&vet[i], &vet[j]);
            i++;
            j--;
        }
    }
    if(esq < j){
        real_quick_sort(vet, esq, j);
    }
    if(dir > i){
        real_quick_sort(vet, i, dir);
    }
}


void quick_sort(int* vet, int tam){
    real_quick_sort(vet, 0, tam);
}


void real_merge_sort(int* v, int tamanho){
    int *novo = (int*) calloc(tamanho, sizeof(int));
    int meio = tamanho / 2;
    int i = 0, j = meio, k = 0;
    while((i < meio) && (j < tamanho)){
        if(v[i] < v[j]){
            novo[k++] = v[i++];
        }
        else{
            novo[k++] = v[j++];
        }
    }
    if(i == meio){
        while(j < tamanho){
            novo[k++] = v[j++];
        }
    }
    else{
        while(i < meio){
            novo[k++] = v[i++];
        }
    }
    for(i = 0; i < tamanho; i++){
        v[i] = novo[i];
    }
    free(novo);
}


void merge_sort(int* v, int tam){
    if(tam >= 2){
        int meio = tam / 2;
        merge_sort(v, meio);
        merge_sort(v + meio, tam - meio);
        real_merge_sort(v, tam);
    }
}


void heap_fy(int* v, int tam, int m){
    int i1 = m * 2;
    int i2 = i1 + 1;
    int maior = m;
    if(i1 < tam && v[i1]  > v[maior]){
        maior = i1;
    }
    if(i2 < tam && v[i2] > v[maior]){
        maior = i2;
    }
    if( m != maior){
        troca(&v[m], &v[maior]);
        heap_fy(v, tam, maior);
    }
}


void buildmax(int* vet,int tam){
    int i;
    for(i = tam / 2; i >= 0; i--){
        heap_fy(vet, tam, i);
    }
}


void heap_sort(int* vet, int tam){
    buildmax(vet,tam);
    int i;
    for(i = tam - 1; i > 0; i--){
        troca(&vet[0], &vet[i]);
        heap_fy(vet, i, 0);
    }
}


void counting_sort(int* vet, int tam){
    int maior = maximo(vet, tam);
    int vetorB[maior + 1];
    int vetorC[tam];
    int i;
    for(i = 0; i < maior + 1; i++){
        vetorB[i] = 0;
    }
    for(i = 0; i < tam; i++){
        vetorB[vet[i]]++;
        vetorC[i] = 0;
    }
    for(i = 1; i < maior + 1; i++){
        vetorB[i] = vetorB[i - 1] + vetorB[i];
    }
    for(i = tam - 1; i >= 0; i--){
        vetorB[vet[i]]--;
        vetorC[vetorB[vet[i]]] = vet[i];
    }
    for(i = 0; i < tam; i++){  
        vet[i] = vetorC[i];
    }
}


void radix_sort(int* vet, int tam){
    int i, k = 1;
    int maior = maximo(vet, tam);
    int* v;
    while(k <= maior){
        int vetorB[maior + 1];
        int vetorC[tam];
        int i;
        for(i = 0; i < maior+1; i++){
            vetorB[i] = 0;
        }
        for(i = 0; i < tam; i++){
            vetorB[z(vet[i], k)]++;
            vetorC[i] = 0;
        }
        for(i = 1; i < maior + 1; i++){
            vetorB[i] = vetorB[i - 1] + vetorB[i];
        }
        for(i = tam - 1; i >= 0; i--){
            vetorB[z(vet[i], k)]--;
                
            vetorC[vetorB[z(vet[i], k)]] = vet[i];
        }
        for(i = 0; i < tam; i++){   
            
            vet[i] = vetorC[i];
        }
        k *= 10;
    }
}

/**
 * method constructor
 *
 * @returns a new Sorting Methods
 */
SortingMethods sortingMethods(){
    SortingMethods new_SM;
    new_SM.buble_sort = &buble_sort;
    new_SM.buble_sort_improved = &buble_sort_improved;
    new_SM.selection_recursive = &selection_recursive;
    new_SM.selection_iterative = &selection_iterative;
    new_SM.insertion_sort = &insertion_sort;
    new_SM.shell_sort = &shell_sort;
    new_SM.quick_sort = &quick_sort;
    new_SM.merge_sort = &merge_sort;
    new_SM.heap_sort = &heap_sort;
    new_SM.counting_sort = &counting_sort;
    new_SM.radix_sort = &radix_sort;
    return new_SM;
}