#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int x;
    struct Node *prox;
} Node;

Node *criarNo() {
    Node *novo = malloc(sizeof(Node));
    if (!novo) {
        fprintf(stderr, "Falha na alocação de nó.\n");
        exit(EXIT_FAILURE);
    }
    novo->x = rand() % 100; 
    novo->prox = NULL;
    return novo;
}

Node *criarLista(int n) {
    if (n <= 0) return NULL;

    Node *head = criarNo();
    Node *atual = head;
    for (int i = 1; i < n; i++) {
        atual->prox = criarNo();
        atual = atual->prox;
    }
    return head;
}

void imprimirLista(const Node *head) {
    const Node *p = head;
    int idx = 1;
    printf("Lista encadeada:\n");
    while (p) {
        printf("  Nó %d: x = %d\n", idx++, p->x);
        p = p->prox;
    }
}

void liberarLista(Node *head) {
    Node *p = head;
    while (p) {
        Node *tmp = p->prox;
        free(p);
        p = tmp;
    }
}

int main() {
    srand((unsigned)time(NULL));

    int n = 4;  
    Node *lista = criarLista(n);

    imprimirLista(lista);
    liberarLista(lista);

    return 0;
}