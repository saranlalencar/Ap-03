#include <math.h>

float calcularDistancia(const Ponto *a, const Ponto *b) {
    int dx = b->x - a->x;
    int dy = b->y - a->y;
    return sqrtf(dx * dx + dy * dy);
}