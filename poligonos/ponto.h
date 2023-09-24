#ifndef PONTO_H
#define PONTO_H

typedef struct {
    float X;
    float Y;
} Ponto;

Ponto criarPonto(float x, float y);
float calcularDistancia(Ponto p1, Ponto p2);

#endif