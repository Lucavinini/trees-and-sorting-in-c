#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

struct arv {
    char info;
    Arv *sae;
    Arv *sad;
};

Arv *arv_criavazia()
{
    return NULL;
}

Arv *arv_cria(char c, Arv *sae, Arv *sad)
{
    Arv *a = malloc(sizeof(Arv));

    if (a == NULL) {
        return NULL;
    }

    a->info = c;
    a->sae = sae;
    a->sad = sad;

    return a;
}

int arv_vazia(Arv *a)
{
    return a == NULL;
}

int arv_pertence(Arv *a, char c)
{
    if (arv_vazia(a)) {
        return 0;
    }

    return a->info == c || arv_pertence(a->sae, c) || arv_pertence(a->sad, c);
}

Arv *arv_libera(Arv *a)
{
    if (!arv_vazia(a)) {
        arv_libera(a->sae);
        arv_libera(a->sad);
        free(a);
    }

    return NULL;
}

static Arv *arv_libera_subarvore_rec(Arv *a, char raiz, int *encontrou)
{
    if (arv_vazia(a) || *encontrou) {
        return a;
    }

    if (a->info == raiz) {
        *encontrou = 1;
        return arv_libera(a);
    }

    a->sae = arv_libera_subarvore_rec(a->sae, raiz, encontrou);
    a->sad = arv_libera_subarvore_rec(a->sad, raiz, encontrou);

    return a;
}

Arv *arv_libera_subarvore(Arv *a, char raiz)
{
    int encontrou = 0;

    return arv_libera_subarvore_rec(a, raiz, &encontrou);
}

void arv_imprime(Arv *a)
{
    if (!arv_vazia(a)) {
        printf("<%c", a->info);
        arv_imprime(a->sae);
        arv_imprime(a->sad);
        printf(">");
    }
}
