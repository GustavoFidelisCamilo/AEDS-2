#include <stdio.h>
#include <stdlib.h>

typedef struct no_ no;
struct no_ {
  no *prox;
  int valor;
};

no *inicio = NULL;
no *fim = NULL;
no *aux ;
int insere(no *no) {
  if (fim) {
    fim->prox = no;
  } else {
    inicio = no;
  }
  fim = no;
  return 1;
}

int removes(){
  if (inicio){
    inicio = inicio->prox;
    if(!inicio){
      fim = NULL;
    }
  }
}

void imprime(){
  while(inicio){
    printf("%d\n", inicio->valor);
    inicio = inicio->prox;
  }
}

int main(void) {
  no * novo_topo;
  novo_topo = malloc(sizeof(no));
  novo_topo->valor = 12;
  insere(novo_topo);
  novo_topo = malloc(sizeof(no));
  novo_topo->valor = 16;
  insere(novo_topo);
  novo_topo = malloc(sizeof(no));
  novo_topo->valor = 18;
  insere(novo_topo);
  novo_topo = malloc(sizeof(no));
  novo_topo->valor = 22;
  insere(novo_topo);

  removes();


  imprime();

  return 0; 
}
