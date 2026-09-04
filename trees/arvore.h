#ifndef ARVORE_H
#define ARVORE_H

typedef struct arv Arv;

Arv *arv_criavazia();

Arv *arv_cria(char c, Arv *sae, Arv *sad);

int arv_vazia(Arv *a);

int arv_pertence(Arv *a, char c);

Arv *arv_libera(Arv *a);

Arv *arv_libera_subarvore(Arv *a, char raiz);

void arv_imprime(Arv *a);

#endif
