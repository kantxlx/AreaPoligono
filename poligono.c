#include <stdio.h>
#include <stdlib.h>

// Estrutura Ponto definida na pergunta
typedef struct {
    float X;
    float Y;
} Ponto;

// Função para calcular a área do triângulo
float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    float deltaX1 = B.X - A.X;
    float deltaY1 = B.Y - A.Y;
    float deltaX2 = C.X - A.X;
    float deltaY2 = C.Y - A.Y;

    return 0.5 * fabs(deltaX1 * deltaY2 - deltaX2 * deltaY1);
}

// Função para calcular a área do polígono
float PoligonoArea(Ponto *vertices, int numVertices) {
    int i;
    float totalArea = 0;
    Ponto A = vertices[0];

    for (i = 1; i < numVertices; i++) {
        Ponto B = vertices[i];
        Ponto C = (i == numVertices - 1) ? vertices[1] : vertices[i + 1];
        totalArea += (A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y)) / 2.0;
        A = B;
    }

    return fabs(totalArea);
}

// Função principal
int main() {
    int numVertices;
    Ponto *vertices;
    int i;

    // Lê o número de vértices
    scanf("%d", &numVertices);

    // Aloca memória para as vértices
    vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));

    // Lê as coordenadas das vértices
    for (i = 0; i < numVertices; i++) {
        scanf("%f %f", &vertices[i].X, &vertices[i].Y);
    }

    // imprimir a área do polígono
    printf("A area do poligono e: %.2f\n", PoligonoArea(vertices, numVertices));

    // Libera a memória alocada
    free(vertices);

    return 0;
}