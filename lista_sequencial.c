#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef struct no_ {
  int chave; // identificador;
  int valor; // valor armazenado;
} no;

int tam = -1; // tam é o indice do slide;
no L[MAX];

/*typedef struct lista{
  no p[MAX]; // criando um vetor de nos dentro da lista
  int atual; // quantidade de nos
}lista;*/

int busca(int x) {
  L[tam + 1].chave = x; // em uma posicao que nao tem nada é alocado uma chave
                        // para ter criterio de parada
  int i = 0;
  while (L[i].chave != x)
    i = i + 1;
  // se foi achado então o i nao chegou a ser tam +1 dai existe
  if (i != tam + 1)
    return i;
  else
    return 0; // caso seja igual então cheguou na ultima posicao e nao achou
}

int busca1(int x) { // busca o indice do vetor
  int i = 0;        // existe um elemento
  while (i <= tam) {
    if (L[i].chave == x) {
      return ++i;
    } else
      i++;
  }
  return 0;
}

int busca_ord(int x) {
  L[tam + 1].chave = x;
  int i = 0;
  while (L[i].chave < x)
    i = i + 1;
  // se nao for encontrado entao ou percorreu todo o vetoor ou
  // elemento existe ou o elemento é maior
  if (i == tam + 1 || L[i].chave != x)
    return 0;
  else
    return i;
}

int busca_bin(int x) { // contando o zero
  int inf = 1, sup = tam;
  while (inf <= sup) {
    int meio = (inf + sup) / 2;
    if (L[meio].chave == x) {
      return meio;
      inf = sup + 1;
    } else if (L[meio].chave < x)
      inf = meio + 1;
    else
      sup = meio - 1;
  }
  return 0;
}

int insere(no no) {
  if (tam < MAX) {
    if (busca(no.chave) == 0) {
      L[tam + 1] = no;
      tam = tam + 1;
      return tam;
    } else
      return 0;
  } else
    return -1;
}

int removes(int x) {
  if (tam != 0) {
    int indice = busca(x);
    if (indice != -1) {
      printf("chave removida: %d \n valor removido: %d \n", L[indice].chave,
             L[indice].valor);
      // free(L[indice]);
      tam = tam - 1;
      for (int i = indice; i < tam; i++) {
        L[i] = L[i + 1];
      }

      return tam;
    }
  }
  return tam;
}

void imprime() {
  for (int i = 0; i <= tam; i++) {
    printf("chave: %d\n valor: %d \n", L[i].chave, L[i].valor);
  }
}

int main() {
  int retorno;
  no novo;
  novo.chave = 1;
  novo.valor = 10;
  insere(novo);
  novo.chave = 2;
  novo.valor = 20;
  insere(novo);
  novo.chave = 3;
  novo.valor = 30;
  insere(novo);
  novo.chave = 4;
  novo.valor = 40;
  insere(novo);
  novo.chave = 5;
  novo.valor = 50;
  insere(novo);
  novo.chave = 6;
  novo.valor = 60;
  insere(novo);
  imprime();
  printf("\n%d\n", busca_bin(1));
  printf("\n%d\n", busca1(1));
  printf("\n%d\n", busca_ord(4));
  printf("\n%d\n", busca(6));
  removes(6);
  removes(1);
  removes(5);
  removes(4);
  novo.chave = 6;
  novo.valor = 60;
  insere(novo);
  imprime();
  return 0;
}