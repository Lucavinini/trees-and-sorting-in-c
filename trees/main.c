#include <stdio.h>

#include "arvore.h"

int main(void)
{
    Arv *d = arv_cria('d', arv_criavazia(), arv_criavazia());
    Arv *b = arv_cria('b', arv_criavazia(), d);
    Arv *e = arv_cria('e', arv_criavazia(), arv_criavazia());
    Arv *f = arv_cria('f', arv_criavazia(), arv_criavazia());
    Arv *c = arv_cria('c', e, f);
    Arv *a = arv_cria('a', b, c);

    printf("Arvore em pre-ordem: ");
    arv_imprime(a);
    printf("\n");

    printf("'e' esta na arvore? %s\n",
           arv_pertence(a, 'e') ? "Sim" : "Nao");
    printf("'z' esta na arvore? %s\n",
           arv_pertence(a, 'z') ? "Sim" : "Nao");

    a = arv_libera_subarvore(a, 'c');

    printf("Arvore apos liberar a subarvore de raiz 'c': ");
    arv_imprime(a);
    printf("\n");

    a = arv_libera(a);

    return 0;
}
