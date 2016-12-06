#include <stdio.h>
#include "arvorebinaria.h"
#include "avl.h"

void rotacaoEsq (arvore *x){
    arvore *y, *z;
    z = y->esq;
    y = x->dir;
    x->dir = y->esq;
    y->esq = x;

    y->pai = x->pai;
    x->pai = y;

    if (z != NULL) {
        x->dir = z;
        z->pai = x;
    }

    if (y-> pai <= y->raiz) y->pai->dir = y;
    else y->pai->esq = y;

    x->bal=0;
    y->bal=0;
}
void rotacaoDir (arvore *x){
    arvore *y, *z;
    z = y->dir;
    y = x->esq;
    x->esq = y->dir;
    y->dir = x;

    y->pai = x->pai;
    x->pai = y;

    if (z != NULL) {
        x->esq = z;
        z->pai = x;
    }

    if (y-> pai <= y->raiz) y->pai->dir = y;
    else y->pai->esq = y;

    x->bal=0;
    y->bal=0;
}

void balanceamento(arvore *no) {
    arvore *filho;
    if (no->bal == 2) {
        filho = no->dir;
        if (filho->bal < 0) {
                rotacaoDir(filho);
                rotacaoEsq(no);
        }
        else rotacaoEsq(no);
    }
    if (no->bal == -2) {
        filho = no->esq;
        if (filho->bal > 0) {
            rotacaoEsq(filho);
            rotacaoDir(no);
        }
        else rotacaoDir(no);
    }
}

///ajustar o FB na rotação dupla
verifica se ta na raiz
senao atualiza FB, direita (+1) e esquerda (-1)
se achar -2 ou +2 chama balanceamento
e dps ir percorrendo ate chegar na sentinela->raiz
