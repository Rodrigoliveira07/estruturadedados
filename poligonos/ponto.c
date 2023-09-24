#include "ponto.h"
#include <math.h>

Ponto criarPonto(float x, float y) {
    Ponto ponto;
    ponto.X = x;
    ponto.Y = y;
    return ponto;
}

float calcularDistancia(Ponto p1, Ponto p2) {
    float dx = p2.X - p1.X;
    float dy = p2.Y - p1.Y;
    return sqrt(dx * dx + dy * dy);
}