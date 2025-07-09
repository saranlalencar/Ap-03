Ponto encontrarMaiorSoma(Ponto *vetor, int quantidade) {
    Ponto maior = *vetor;
    int maxSoma = vetor->x + vetor->y;

    for (int i = 1; i < quantidade; i++) {
        int soma = (vetor + i)->x + (vetor + i)->y;
        if (soma > maxSoma) {
            maior = *(vetor + i);
            maxSoma = soma;
        }
    }
    return maior;
}