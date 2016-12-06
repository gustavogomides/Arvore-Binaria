/*#include <stdio.h>
#include "arvorebinaria.h"
int main() {
    tno *arv=NULL;
    int n, dado;
    char nomeArquivo[30];

    arv=insere(arv, 7);
    arv=insere(arv, 2);
    arv=insere(arv, 0);
    arv=insere(arv, 1);
    arv=insere(arv, 20);
    arv=insere(arv, 100);
    arv=insere(arv, 8);
    arv=insere(arv, 9);
    arv=insere(arv, 5);
    arv=insere(arv, 6);
    arv=insere(arv, 27);
    //printf("Digite o nome do arquivo de entrada: \n");
    //scanf("%s", &nomeArquivo);
    FILE *arq;

    arq = fopen("teste.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo %s", nomeArquivo);
        return 0;
    }

    while(!feof(arq))
    {
        fscanf(arq, "%d", &dado);
        if (ferror(arq))
        {
            printf("Erro ao ler arquivo de dados");
            return 0;
        }
        insere(arv, dado);
    }


    printf ("==> Percursos:\n");
    printf("Arvore no percurso Pre-Ordem: ");
    preordem(arv);
    printf("\n\n");

    /*printf("Arvore no percurso Em-Ordem: ");
    emordem(arv);
    printf("\n\n");

    printf("Arvore no percurso Pos-Ordem: ");
    posordem(arv);
    printf("\n\n");

    printf ("\n==> Altura da arvore: %d\n", altura(arv));

    printf ("\n\n==> Menor elemento: %d -- Maior elemento: %d\n", menor(arv),maior(arv));

    printf("\n\n==> Digite um numero para ser removido da arvore: ");
    scanf("%d", &n);
    removeArvore(arv, n);

    printf ("\n\n==> Arvore depois da remocao:\n\n");
    printf("Arvore no percurso Pre-Ordem: ");
    preordem(arv);
    printf("\n\n");

    printf("Arvore no percurso Em-Ordem: ");
    emordem(arv);
    printf("\n\n");

    printf("Arvore no percurso Pos-Ordem: ");
    posordem(arv);
    printf("\n\n");
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.h"
#include "avl.h"
#include <string.h>
int main()
{
    FILE *arq;
    char nomeArquivo[30];
    int dado;

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", &nomeArquivo);
    strcat(nomeArquivo, ".txt");
    arvore *A = criaArvore();
    arq = fopen(nomeArquivo, "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo %s", nomeArquivo);
        return 0;
    }

    while(!feof(arq))
    {
        fscanf(arq, "%d", &dado);
        if (ferror(arq))
        {
            printf("Erro ao ler arquivo de dados");
            return 0;
        }
        insereNo(A, dado);
    }

    percorreOrdem(A->dir);
    printf("\n");

    return 0;
}

