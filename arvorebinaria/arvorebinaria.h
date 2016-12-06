/*struct no {
    int dado;
    struct no *esq;
    struct no *dir;
};typedef struct no tno;

tno* cria();
int vazia(tno *r);
tno* iniciadado(int va);
tno* insere(tno *r, int va);
tno* removetno(tno *r, int dado);
int altura(tno *a);
void preordem(tno *r);
void emordem(tno *r);
void posordem(tno *r);
int maior(tno *inicio);
int menor(tno *inicio);

void rotacaoEsq (tno *x);
void rotacaoDir(tno *x);
void balanceamento(tno *no); //verifica a necessidade de rota��es e atualiza o FB caso haja rota��o dupla
void atualizaBal(tno *no, int num); //atualiza o FB at� chegar na raiz ou at� realizar rota��es
*/

typedef struct arvore
{
    int raiz;
    int bal;
    struct arvore *esq;
    struct arvore *dir;
    struct arvore *pai;
}arvore;

arvore * criaArvore();
void insereNo(arvore *A, int num);
void percorreOrdem (arvore *A);
