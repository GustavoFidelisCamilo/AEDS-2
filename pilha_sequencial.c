#include <stdio.h>
#include <stdlib.h>

#define MAX 6

typedef struct no_{
  int chave; // indentificador
  int valor; // valor da chave
}no;

no P[MAX];
int topo = -1;

int insere(no pilha){
  if (topo !=  MAX){
    topo = topo+1;
    P[topo] = pilha;
    return topo;
  }else 
  return -1; 
}

int removes(){
  if (topo != MAX){
    topo = topo-1;
    return topo;
  }else
  return -1;
}

int busca_ord(int x){
  P[topo+1].chave = x;
  int i =0;
  while(P[i].chave < x)
    i++;
  if (i == topo +1 || P[i].chave !=x)
    return 0;
  else 
    return i;
}

void imprime(){
  for(int i = 0; i <=topo;i++){
    printf("chave: %d\n valor: %d \n", P[i].chave, P[i].valor );
  }
}

int main(void) {
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
  removes();
  removes();
  novo.chave = 3;
  novo.valor = 30;
  insere(novo);
  printf("\n%d\n", busca_ord(6));
  printf("\n%d\n", busca_ord(3));
  imprime(P);
  
  return 0;
}