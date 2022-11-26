#include <stdio.h>
#include <stdlib.h>
#define MAX 7
// BY Fidelis
typedef struct no_{
  int chave;
  int valor;
}no;


no F[MAX];
int f = 0; //inicio
int r = 0; //retaguarda

int insere(no fila){
  int prov = r % MAX+1;
  if(prov != f -1){
    r = prov;
    F[r] = fila;
    if (f == 0){
      f = 1;
    }
    return r;
  }
  return -1;
}

int removes(){
  if (f != 0){
    if(f == r){
      f = r = 0;
    }else 
      f = f % MAX +1;
    return f; 
  }
  return -1;
}

void imprime(){
  int i = f,j = r;
  if(i == f){
    printf("chave: %d \n valor %d\n", F[i].chave, F[i].valor);
    for(i =i+1; i != r % MAX+1 ; i++){
    printf("chave: %d \n valor %d\n", F[i].chave, F[i].valor);
    i = i % MAX;
    }
  }
  for(; i != r % MAX+1 ; i++){
  printf("chave: %d \n valor %d\n", F[i].chave, F[i].valor);
  i = i % MAX;
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
  novo.chave = 5;
  novo.valor = 50;
  insere(novo);
  novo.chave = 6;
  novo.valor = 60;
  insere(novo);
  novo.chave = 7;
  novo.valor = 70;
  insere(novo);
  imprime();
  printf("\n\n\n");

  removes();
  removes();
  removes();
  imprime();
  printf("\n\n\n");
  
  novo.chave = 9;
  novo.valor = 0;
  insere(novo);
  novo.chave = 9;
  novo.valor = 0;
  insere(novo); 
  insere(novo);
  /* deve travar a posição para se o r der a volta ficar sempre uma posição vaga*/
  removes();
  insere(novo);
  imprime();
  
  return 0;
}

