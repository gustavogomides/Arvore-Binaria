#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.h"
#include "avl.h"
/*
tno* cria() {
   return NULL;
}
int vazia(tno *r) {
    return r==NULL;
}
tno* iniciadado(int va) {
    tno *aux;
    aux=(tno*)malloc(sizeof(tno));
    if (!aux) exit(1);
    aux->dado=va;
    aux->esq=NULL;
    aux->dir=NULL;
    return aux;
}
tno* insere(tno *r, int va) {
    if(!r) return iniciadado(va);
    if (va < r->dado) r->esq=insere(r->esq, va);
    else r->dir=insere(r->dir, va);
    return r;
}
tno* removeArvore(tno *r, int dado) {
    if(vazia(r)) return NULL;
    else if(dado < r->dado) r->esq = removeArvore(r->esq, dado);
    else if(dado > r->dado) r->dir = removeArvore(r->dir, dado);
    else {
        if(r->esq == NULL && r->dir == NULL) {
            free(r);
            r = NULL;
        }
        else if(r->esq == NULL) {
            tno *sai;

            sai = r;
            r = r->dir;
            free(sai);
        }
        else if(r->dir == NULL) {
            tno *sai;

            sai = r;
            r = r->esq;
            free(sai);
        }
        else {
            tno *aux;

            aux = r->esq;
            while(aux->dir != NULL) {
                aux = aux->dir;
            }
            r->dado = aux->dado;
            aux->dado = dado;
            r->esq = removeArvore(r->esq, dado);
         }
    }
    return r;
}
int altura(tno *a) {
    if(a) {
        if(altura(a->esq) > altura(a->dir)) return 1 + altura(a->esq);
        else return 1 + altura(a->dir);
    }
    else return 0;
}
void preordem(tno *r) {
    if (!vazia(r)) {
            printf ("%d   ", r->dado);
            preordem(r->esq);
            preordem(r->dir);
    }
}
void emordem(tno *r) {
    if (!vazia(r)) {
            emordem(r->esq);
            printf ("%d   ", r->dado);
            emordem(r->dir);
    }
}
void posordem(tno *r) {
    if (!vazia(r)) {
            posordem(r->esq);
            posordem(r->dir);
            printf ("%d   ", r->dado);
    }
}
int maior(tno *inicio) {
	if((inicio->dir) && (inicio->dir->dado > inicio->dado)) return maior(inicio->dir);
	else return inicio->dado;
}
int menor(tno *inicio) {
    if((inicio->esq) && (inicio->esq->dado < inicio->dado)) return menor(inicio->esq);
    else return inicio->dado;
}
*/

arvore * criaArvore()
{
    arvore *sentinela;
    sentinela = (arvore*)calloc (1,sizeof(arvore));
    sentinela->raiz = -1000;
    sentinela->esq = NULL;
    sentinela->dir = NULL;
    sentinela->pai = NULL;

    return sentinela;
}

void insereNo(arvore *A, int num)
{

    arvore *novoNo, *aux, *auxPai;
    novoNo = (arvore*)calloc(1,sizeof(arvore));
    novoNo->raiz = num;
    novoNo->bal = 0;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->pai = NULL;

    if (A->dir == NULL)
    {
        A->dir = novoNo;
        novoNo->pai = A;
        return;
    }

    aux = A->dir;
    while (aux != NULL)
    {
        auxPai = aux;
        if (num < aux->raiz)
            aux = aux->esq;
        else
            aux = aux->dir;
    }

    if (num < auxPai->raiz)
        auxPai->esq = novoNo;
    else
        auxPai->dir = novoNo;
    novoNo->pai = auxPai;

    atualizaBal(novoNo->pai, num);
}

void percorreOrdem (arvore *A)
{
    if (A == NULL)
        return;
    percorreOrdem(A->esq);
    printf(" %d ", A->raiz);
    percorreOrdem(A->dir);
}
