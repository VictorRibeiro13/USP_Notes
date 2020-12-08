/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2020                           **/
/**   94 - Prof. Luciano Antonio Digiampietri                       **/
/**                                                                 **/
/**   EP3 - Fila de Prioridade (utilizando heap)                    **/
/**                                                                 **/
/**   Victor dos Santos Ribeiro               11917559              **/
/**                                                                 **/
/*********************************************************************/

#include "filaDePrioridade.h"
#include <math.h>

PFILA criarFila(int max) {
  PFILA res = (PFILA) malloc(sizeof(FILADEPRIORIDADE));
  res->maxElementos = max;
  res->arranjo = (PONT*) malloc(sizeof(PONT)*max);
  res->heap = (PONT*) malloc(sizeof(PONT)*max);
  int i;
  for (i=0;i<max;i++) {
    res->arranjo[i] = NULL;
    res->heap[i] = NULL;
  }
  res->elementosNoHeap = 0;
  return res;
}

void exibirLog(PFILA f){
  printf("Log [elementos: %i]\n", f->elementosNoHeap);
  PONT atual;
  int i;
  for (i=0;i<f->elementosNoHeap;i++){
    atual = f->heap[i];
    printf("[%i;%f;%i] ", atual->id, atual->prioridade, atual->posicao);
  }
  printf("\n\n");
}

int tamanho(PFILA f) {
  int size = 0;
  for (int i=0; i < f->maxElementos; i++) {
    if (f->heap[i] != NULL) size++;
  }

  return size;
}

bool buscarElemento(PFILA f, int id) {
  return (id < 0 || id > f->maxElementos || f->arranjo[id] != NULL);
}

bool inserirElemento(PFILA f, int id, float prioridade) {
  if (buscarElemento(f, id)) return false;

  PONT newElement = malloc(sizeof(PONT));
  newElement->id = id;
  newElement->prioridade = prioridade;
  newElement->posicao = 0;

  f->arranjo[id] = newElement;

  if (f->elementosNoHeap == 0) {
    f->elementosNoHeap += 1;
    f->heap[0] = newElement;
    return true;
  }

  int index = f->elementosNoHeap;
  int fatherIndex = (index-1) < 0 ? 0 : (int) floor((index-1)/2);
  f->heap[index] = newElement;

  while (f->heap[fatherIndex]->prioridade < newElement->prioridade) {
    f->heap[index] = f->heap[fatherIndex];
    f->heap[fatherIndex] = newElement;

    f->heap[index]->posicao = index;
    f->heap[fatherIndex]->posicao = fatherIndex; 

    index = fatherIndex;
    fatherIndex = (int) floor((index-1)/2);
  }

  f->heap[index]->posicao = index;
  f->heap[fatherIndex]->posicao = fatherIndex;
   
  f->elementosNoHeap = f->elementosNoHeap + 1;

  return true;
}
  
bool aumentarPrioridade(PFILA f, int id, float novaPrioridade) {
  if (id < 0 || id > f->maxElementos || f->arranjo[id] == NULL) return false;
  PONT element = f->arranjo[id];
  if (element->prioridade >= novaPrioridade) return false;

  element->prioridade = novaPrioridade;

  int index = element->posicao;
  int fatherIndex = (index-1) < 0 ? 0 : (int) floor((index-1)/2);

  while (f->heap[fatherIndex]->prioridade < element->prioridade) {
    f->heap[index] = f->heap[fatherIndex];
    f->heap[fatherIndex] = element;

    f->heap[index]->posicao = index;
    f->heap[fatherIndex]->posicao = fatherIndex; 

    index = fatherIndex;
    fatherIndex = (int) floor((index-1)/2);
  }

  return true;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
  // if (id < 0 || id > f->maxElementos || f->arranjo[id] == NULL) return false;
  //   PONT element = f->arranjo[id];
  //   if (element->prioridade <= novaPrioridade) return false;

  //   element->prioridade = novaPrioridade;

  //   int index = element->posicao;
  //   int fatherIndex = (index-1) < 0 ? 0 : (int) floor((index-1)/2);

  //   while (f->heap[fatherIndex]->prioridade < element->prioridade) {
  //     f->heap[index] = f->heap[fatherIndex];
  //     f->heap[fatherIndex] = element;

  //     f->heap[index]->posicao = index;
  //     f->heap[fatherIndex]->posicao = fatherIndex; 

  //     index = fatherIndex;
  //     fatherIndex = (int) floor((index-1)/2);
  //   }

  return true;
}

PONT removerElemento(PFILA f) {
  if (tamanho(f) == 0) return NULL;

  int index = f->heap[0];

  PONT actualElement = f->heap[1];

  for (int i = 1; i < tamanho(f); i++) {
    /* code */
  }
  

  while (actualElement != NULL && actualElement->posicao != f->maxElementos-1) {

    f->heap[index] = f->heap[fatherIndex];
    f->heap[fatherIndex] = element;

    f->heap[index]->posicao = index;
    f->heap[fatherIndex]->posicao = fatherIndex; 

    index = fatherIndex;
    fatherIndex = (int) floor((index-1)/2);
  }

  return true;



  
  return NULL;
}

bool consultarPrioridade(PFILA f, int id, float* resposta){
  


  return false;
}
