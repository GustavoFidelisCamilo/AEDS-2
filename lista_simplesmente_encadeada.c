#include <stdio.h>
#include <stdlib.h>

typedef struct no_ no;
struct no_{
  int valor;
  no *prox;
};



no * inicia_lista(no * ptlista){
  ptlista = malloc(sizeof(no));
  ptlista->prox = NULL;
  return ptlista;
}

void remove_lista(no * ptlista){
  while(ptlista){
    no * n = ptlista;
    ptlista = ptlista->prox;
    free(n);
  }
}
void busca_enc(int x, no * lista,no **ant, no **pont){
  *ant = lista;
  *pont = NULL;
  no * ptr = lista->prox;
  while (ptr){
    if(ptr->valor < x){
      *ant = ptr;
      ptr = ptr->prox;
    }else{
      if(ptr->valor==x){
        *pont = ptr;
      }
      ptr = NULL;
    }
  }
}

int insere_enc(no * lista, int valor){
  no * ant = NULL;
  no * pont = lista->prox;
  busca_enc(valor, lista, &ant, &pont);
  while(pont == NULL){
    no * n = malloc(sizeof(no));
    n->valor = valor;
    n->prox = ant->prox;
    ant->prox = n;
    return 0;
  }
  return -1;
}

no *remove_enc(no * lista, int valor){
  no* ant  = NULL;
  no* pont = lista->prox;
  busca_enc(valor,lista,&ant,&pont);
  if(pont){
    ant->prox = pont->prox;
    return pont;
  }
  return NULL;
}

void imprime(no * lista){
  no *pont = lista->prox;
  while(pont){
    printf("valor: %d\n", pont->valor);
    pont= pont->prox;
  }
}

int main(void) {
  no * ptlista = inicia_lista(ptlista);;
  insere_enc(ptlista, 1);
  insere_enc(ptlista, 2);
  insere_enc(ptlista, 3);
  insere_enc(ptlista, 4);
  insere_enc(ptlista, 5);
  imprime(ptlista);
  remove_enc(ptlista, 1);
  remove_enc(ptlista, 2);
  remove_enc(ptlista, 3);
  imprime(ptlista);
  
  return 0;
}