#include <stdio.h>
#include <stdlib.h>

typedef struct no_ no;
struct no_{
  no * prox;
  int valor;
};
no * topo =NULL;
no * novo_topo ;

void imprime(){
  no * aux = topo;
  while(aux){
    printf("valor = %d\n", aux->valor);
    aux =aux->prox;
  }
}

int insere(no * no){
  
  no->prox = topo;
  topo = no;
  return 1;
}

int removes(){
  if (topo){
  topo = topo->prox;
  return 1;
  }
  return -1;
}



int main(void) {
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
  novo_topo = malloc(sizeof(no));
  novo_topo->valor = 92;
  insere(novo_topo);
  //imprime();

  removes();
  removes();

  imprime();
  return 0;
}