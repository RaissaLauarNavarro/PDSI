#include <stdio.h>
#include <stdlib.h>

char **criaTabuleiro(int t);
void lerTabuleiro(char **tabuleiro, int t);
// void imprimirTabuleiro(char **tabuleiro, int t);
void percorrerTabuleiro(char **tabuleiro, int t);
int contarCapturas1(char **tabuleiro, int t, int x, int y);
int contarCapturas2(char **tabuleiro, int t, int x, int y);
int contarCapturas3(char **tabuleiro, int t, int x, int y);
int contarCapturas4(char **tabuleiro, int t, int x, int y);
void liberarTabuleiro(char **tabuleiro, int t);

typedef struct{
    int x, y, n1, n2, n3, n4;
}jogadas_t;

// “o” (casa preta vazia)
// “p” (casa preta com peça preta)
// “b” (casa preta com peça branca)
// “ ” (casa branca)


int main(){
    int tamanhoTabuleiro;
    scanf("%d", &tamanhoTabuleiro);
    char **tabuleiro = criaTabuleiro(tamanhoTabuleiro);
    lerTabuleiro(tabuleiro, tamanhoTabuleiro);
    // imprimirTabuleiro(tabuleiro, tamanhoTabuleiro);
    percorrerTabuleiro(tabuleiro, tamanhoTabuleiro);
    liberarTabuleiro(tabuleiro, tamanhoTabuleiro);

    return EXIT_SUCCESS;
}


char **criaTabuleiro(int t){
    char **tabuleiro = (char**)malloc(t * sizeof(char*));

    for (int i = 0; i < t; i++){
        tabuleiro[i] = (char*) malloc(t * sizeof(char));
    }
    return tabuleiro;
}


void lerTabuleiro(char **tabuleiro, int t){
    getchar();
    for (int i = 0; i < t; i++){
        for(int j = 0; j < t; j++){
            scanf("%c", &tabuleiro[i][j]);
        }
        getchar();
    }
}


// void imprimirTabuleiro(char **tabuleiro, int t){
//     for (int i = 0; i < t; i++){
//         for(int j = 0; j < t; j++){
//             printf("%d.%d: %c\n",i+1, j+1, tabuleiro[i][j]);
//         }
//     }
// }


void percorrerTabuleiro(char **tabuleiro, int t) {
    jogadas_t jogadas[30];

    // realiza a verificação de jogadas
    int q = 0;
    int contador=0;
    for (int i = 0; i < t; i++) {
        if(i%2==0){
            for (int j = 0; j < t; j++) {
                if (tabuleiro[i][j] == 'b') {
                    // cria uma cópia temporária do tabuleiro para alteraçã
                    char **tempTabuleiro1 = criaTabuleiro(t);
                    char **tempTabuleiro2 = criaTabuleiro(t);
                    char **tempTabuleiro3 = criaTabuleiro(t);
                    char **tempTabuleiro4 = criaTabuleiro(t);
                    for (int k = 0; k < t; k++) {
                        for (int l = 0; l < t; l++) {
                            tempTabuleiro1[k][l] = tabuleiro[k][l];
                        }
                    }
                    for (int k = 0; k < t; k++) {
                        for (int l = 0; l < t; l++) {
                            tempTabuleiro2[k][l] = tabuleiro[k][l];
                        }
                    }
                    for (int k = 0; k < t; k++) {
                        for (int l = 0; l < t; l++) {
                            tempTabuleiro3[k][l] = tabuleiro[k][l];
                        }
                    }
                    for (int k = 0; k < t; k++) {
                        for (int l = 0; l < t; l++) {
                            tempTabuleiro4[k][l] = tabuleiro[k][l];
                        }
                    }

                    // salva a struct a contagem de jogadas levando em conta duas prioridades diferentes
                    jogadas[q].n1 = contarCapturas1(tempTabuleiro1, t, i, j);
                    jogadas[q].n2 = contarCapturas2(tempTabuleiro2, t, i, j);
                    jogadas[q].n3 = contarCapturas3(tempTabuleiro3, t, i, j);
                    jogadas[q].n4 = contarCapturas4(tempTabuleiro4, t, i, j);
                    jogadas[q].x = i;
                    jogadas[q].y = j;
                    q++;

                    // verifica qual prioridade representa a melhor jogada
                    if(jogadas[q].n2 > jogadas[q].n1){
                        jogadas[q].n1 = jogadas[q].n2;
                    }
                    if(jogadas[q].n3 > jogadas[q].n1){
                        jogadas[q].n1 = jogadas[q].n3;
                    }
                    if(jogadas[q].n4 > jogadas[q].n1){
                        jogadas[q].n1 = jogadas[q].n4;
                    }

                    // Libera a memória da cópia do tabuleiro
                    liberarTabuleiro(tempTabuleiro1, t);
                    liberarTabuleiro(tempTabuleiro2, t);
                    liberarTabuleiro(tempTabuleiro3, t);
                    liberarTabuleiro(tempTabuleiro4, t);
                }
            }
        }
        if(i%2!=0){
            for (int j = t-1; j >= 0; j--) {
                if (tabuleiro[i][j] == 'b') {
                    // cria uma cópia temporária do tabuleiro para alteração
                    char **tempTabuleiro1 = criaTabuleiro(t);
                    char **tempTabuleiro2 = criaTabuleiro(t);
                    char **tempTabuleiro3 = criaTabuleiro(t);
                    char **tempTabuleiro4 = criaTabuleiro(t);
                    for (int k = 0; k < t; k++) {
                        for (int l = 0; l < t; l++) {
                            tempTabuleiro1[k][l] = tabuleiro[k][l];
                        }
                    }
                    for (int k = 0; k < t; k++) {
                        for (int l = 0; l < t; l++) {
                            tempTabuleiro2[k][l] = tabuleiro[k][l];
                        }
                    }
                    for (int k = 0; k < t; k++) {
                        for (int l = 0; l < t; l++) {
                            tempTabuleiro3[k][l] = tabuleiro[k][l];
                        }
                    }
                    for (int k = 0; k < t; k++) {
                        for (int l = 0; l < t; l++) {
                            tempTabuleiro4[k][l] = tabuleiro[k][l];
                        }
                    }


                    // salva a struct a contagem de jogadas levando em conta duas prioridades diferentes
                    jogadas[q].n1 = contarCapturas1(tempTabuleiro1, t, i, j);
                    jogadas[q].n2 = contarCapturas2(tempTabuleiro2, t, i, j);
                    jogadas[q].n3 = contarCapturas3(tempTabuleiro3, t, i, j);
                    jogadas[q].n4 = contarCapturas4(tempTabuleiro4, t, i, j);
                    jogadas[q].x = i;
                    jogadas[q].y = j;
                    q++;

                    // verifica qual prioridade representa a melhor jogada
                    if(jogadas[q].n2 > jogadas[q].n1){
                        jogadas[q].n1 = jogadas[q].n2;
                    }
                    if(jogadas[q].n3 > jogadas[q].n1){
                        jogadas[q].n1 = jogadas[q].n3;
                    }
                    if(jogadas[q].n4 > jogadas[q].n1){
                        jogadas[q].n1 = jogadas[q].n4;
                    }

                    // Libera a memória da cópia do tabuleiro
                    liberarTabuleiro(tempTabuleiro1, t);
                    liberarTabuleiro(tempTabuleiro2, t);
                    liberarTabuleiro(tempTabuleiro3, t);
                    liberarTabuleiro(tempTabuleiro4, t);
                }
            }
        }
    }

    // Verifica e imprime qual é a melhor jogada
    int melhorJogada = jogadas[0].n1;
    int xMelhor = jogadas[0].x;
    int yMelhor = jogadas[0].y;
    for (int i = 1; i < q; i++) {
        if (jogadas[i].n1 > melhorJogada) {
            melhorJogada = jogadas[i].n1;
            xMelhor = jogadas[i].x;
            yMelhor = jogadas[i].y;
        }
    }
    printf("%d %d %d\n", xMelhor, yMelhor, melhorJogada);

    // Imprime todas as outras jogadas
    for (int i = 0; i < q; i++) {
        if (jogadas[i].n1 != 0)
            printf("%d %d %d\n", jogadas[i].x, jogadas[i].y, jogadas[i].n1);
    }

   
}


int contarCapturas1(char **tabuleiro, int t, int x, int y) {
    int contador = 0;
    if (x >= 2 && y >= 2 && tabuleiro[x - 1][y - 1] == 'p' && tabuleiro[x - 2][y - 2] == 'o') {    // verifica a diagonal superior esquerda
        contador++;
        tabuleiro[x - 1][y - 1] = 'o';
        tabuleiro[x][y] = 'o';
        contador += contarCapturas1(tabuleiro, t, x - 2, y - 2);
    }else if (x <= t - 3 && y >= 2 && tabuleiro[x + 1][y - 1] == 'p' && tabuleiro[x + 2][y - 2] == 'o') { // verifica a diagonal superior direita
        contador++;
        tabuleiro[x + 1][y - 1] = 'o';
        tabuleiro[x][y] = 'o';
        contador += contarCapturas1(tabuleiro, t, x + 2, y - 2);
    }else if (x >= 2 && y <= t - 3 && tabuleiro[x - 1][y + 1] == 'p' && tabuleiro[x - 2][y + 2] == 'o') { // verifica a diagonal inferior esquerda
        contador++;
        tabuleiro[x - 1][y + 1] = 'o'; 
        tabuleiro[x][y] = 'o';
        contador += contarCapturas1(tabuleiro, t, x - 2, y + 2);
    }else if (x <= t - 3 && y <= t - 3 && tabuleiro[x + 1][y + 1] == 'p' && tabuleiro[x + 2][y + 2] == 'o') { // verifica a diagonal inferior direita
        contador++;
        tabuleiro[x + 1][y + 1] = 'o';
        tabuleiro[x][y] = 'o';
        contador += contarCapturas1(tabuleiro, t, x + 2, y + 2);
    }
    return contador;
}


int contarCapturas2(char **tabuleiro, int t, int x, int y) {
    int contador = 0;
    if (x <= t - 3 && y <= t - 3 && tabuleiro[x + 1][y + 1] == 'p' && tabuleiro[x + 2][y + 2] == 'o') { // verifica a diagonal inferior direita
        contador++;
        tabuleiro[x + 1][y + 1] = 'o';
        tabuleiro[x][y] = 'o';
        contador += contarCapturas2(tabuleiro, t, x + 2, y + 2);
    }else if (x >= 2 && y <= t - 3 && tabuleiro[x - 1][y + 1] == 'p' && tabuleiro[x - 2][y + 2] == 'o') { // verifica a diagonal inferior esquerda
        contador++;
        tabuleiro[x - 1][y + 1] = 'o'; 
        tabuleiro[x][y] = 'o';
        contador += contarCapturas2(tabuleiro, t, x - 2, y + 2);
    }else if (x <= t - 3 && y >= 2 && tabuleiro[x + 1][y - 1] == 'p' && tabuleiro[x + 2][y - 2] == 'o') { // verifica a diagonal superior direita
        contador++;
        tabuleiro[x + 1][y - 1] = 'o';
        tabuleiro[x][y] = 'o';
        contador += contarCapturas2(tabuleiro, t, x + 2, y - 2);
    }else if (x >= 2 && y >= 2 && tabuleiro[x - 1][y - 1] == 'p' && tabuleiro[x - 2][y - 2] == 'o') { // verifica a diagonal superior esquerda
        contador++;
        tabuleiro[x - 1][y - 1] = 'o';
        tabuleiro[x][y] = 'o';
        contador += contarCapturas2(tabuleiro, t, x - 2, y - 2); 
    }
    return contador;
}


int contarCapturas3(char **tabuleiro, int t, int x, int y) {
    int contador = 0;
    if (x <= t - 3 && y >= 2 && tabuleiro[x + 1][y - 1] == 'p' && tabuleiro[x + 2][y - 2] == 'o') { // verifica a diagonal superior direita
        contador++;
        tabuleiro[x + 1][y - 1] = 'o';
        tabuleiro[x][y] = 'o';
        contador += contarCapturas3(tabuleiro, t, x + 2, y - 2);
    }else if (x >= 2 && y >= 2 && tabuleiro[x - 1][y - 1] == 'p' && tabuleiro[x - 2][y - 2] == 'o') { // verifica a diagonal superior esquerda
        contador++;
        tabuleiro[x - 1][y - 1] = 'o';
        tabuleiro[x][y] = 'o';
        contador += contarCapturas3(tabuleiro, t, x - 2, y - 2); 
    }else if (x <= t - 3 && y <= t - 3 && tabuleiro[x + 1][y + 1] == 'p' && tabuleiro[x + 2][y + 2] == 'o') { // verifica a diagonal inferior direita
        contador++;
        tabuleiro[x + 1][y + 1] = 'o';
        tabuleiro[x][y] = 'o';
        contador += contarCapturas3(tabuleiro, t, x + 2, y + 2);
    }else if (x >= 2 && y <= t - 3 && tabuleiro[x - 1][y + 1] == 'p' && tabuleiro[x - 2][y + 2] == 'o') { // verifica a diagonal inferior esquerda
        contador++;
        tabuleiro[x - 1][y + 1] = 'o'; 
        tabuleiro[x][y] = 'o';
        contador += contarCapturas3(tabuleiro, t, x - 2, y + 2);
    }
    return contador;
}


int contarCapturas4(char **tabuleiro, int t, int x, int y) {
    int contador = 0;
    if (x >= 2 && y <= t - 3 && tabuleiro[x - 1][y + 1] == 'p' && tabuleiro[x - 2][y + 2] == 'o') { // verifica a diagonal inferior esquerda
        contador++;
        tabuleiro[x - 1][y + 1] = 'o'; 
        tabuleiro[x][y] = 'o';
        contador += contarCapturas4(tabuleiro, t, x - 2, y + 2);
    }else if (x <= t - 3 && y <= t - 3 && tabuleiro[x + 1][y + 1] == 'p' && tabuleiro[x + 2][y + 2] == 'o') { // verifica a diagonal inferior direita
        contador++;
        tabuleiro[x + 1][y + 1] = 'o';
        tabuleiro[x][y] = 'o';
        contador += contarCapturas4(tabuleiro, t, x + 2, y + 2);
    }else if (x >= 2 && y >= 2 && tabuleiro[x - 1][y - 1] == 'p' && tabuleiro[x - 2][y - 2] == 'o') {// verifica a diagonal superior esquerda
        contador++;
        tabuleiro[x - 1][y - 1] = 'o';
        tabuleiro[x][y] = 'o';
        contador += contarCapturas4(tabuleiro, t, x - 2, y - 2); 
    }else if (x <= t - 3 && y >= 2 && tabuleiro[x + 1][y - 1] == 'p' && tabuleiro[x + 2][y - 2] == 'o') { // verifica a diagonal superior direita
        contador++;
        tabuleiro[x + 1][y - 1] = 'o';
        tabuleiro[x][y] = 'o';
        contador += contarCapturas4(tabuleiro, t, x + 2, y - 2);
    }
    return contador;
}


void liberarTabuleiro(char **tabuleiro, int t){
    for (int i = 0; i < t; i++){
        free(tabuleiro[i]);
    }
    free(tabuleiro);
}