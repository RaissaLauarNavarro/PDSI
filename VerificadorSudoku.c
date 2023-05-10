#include <stdio.h>

int main(){
    int numTabuleiros=0, linhas=0, correto=1, quadrante=0;
    scanf("%d", &numTabuleiros);
    linhas = numTabuleiros * 9;
    int matriz[linhas][9];
    
    // zerar a matriz de tabela(s)
    for(int i=0; i<linhas; i++){
        for(int j=0; j<9; j++){
            matriz[i][j] = 0;
        }
    }

    // scan da matriz de tabela(s)
    for(int i=0; i<linhas; i++){
        for(int j=0; j<9; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    //transita entre os tabuleros, executando a quantidade de vezes necessárias
    for(int t=0; t<=(numTabuleiros-1); t++){
        correto = 1;
        
        // verificador de linhas
        for(int i=(t*9); i<(9*t+9); i++){                       
            for(int j=0; j<(9); j++){                        
                //transita entre os valores de cada linha anteriores à posição analizada
                for(int k=0; k<j; k++){                           
                    //verifica se existem numeros repetidos ou fora do intervalo permitido
                    if(matriz[i][j] == matriz[i][k] || matriz[i][j]<1 || matriz[i][j]>9){ 
                        puts("INCORRETO\n");
                        correto=0;
                        break;
                    }
                    if(!correto)
                        break;
                }
                if(!correto)
                    break;
            }
            if(!correto)
                break;
        }
        
        
        //verificador de colunas
        if(correto){
            for(int i=(t*9); i<(9*t+9); i++){                         
                for(int j=(0); j<(9); j++){
                    //transita entre os valores de cada coluna anteriores à posição analizada
                    for(int k=(t*9); k<i; k++){                     
                        //verifica se existem numeros repetidos ou fora do intervalo permitido
                        if(matriz[i][j] == matriz[k][j] || matriz[i][j]<1 || matriz[i][j]>9){
                            puts("INCORRETO\n");
                            correto=0;
                            break;
                        }
                    }
                    if(!correto)
                        break;
                }
                if(!correto)
                    break;
            }
        }
        
        //verificador de quadrantes
        if(correto){
            // transita entre os primeiros elementos de cada quadrante de cada matriz
            for(int linha=(9*t); linha<(9*t+9); linha+=3){
                for(int coluna=0; coluna<9; coluna+=3){
                    
                    // vetor para armazenar a quantidade de um mesmo número que aparece no quadrante
                    int valoresPossiveis[9]={0,0,0,0,0,0,0,0,0};
                    // adiciona 1 à matriz na respectiva posição do número no jogo
                    for(int i=linha; i<(linha+3); i++){
                        for(int j=coluna; j<(coluna+3); j++){
                            int numero = matriz[i][j];
                            valoresPossiveis[numero-1]+=1;
                        }
                    }
                    // verifica no vetor se algum número apareceu mais de uma vez no quadrante
                    for(int k=0; k<9; k++){
                        if(valoresPossiveis[k] >=2){
                            puts("INCORRETO\n");
                            correto=0;
                            break;
                        }
                    }
                    if(!correto)
                        break;
                }
                if(!correto)
                    break;
            }
        }
    if(correto)
        puts("CORRETO");
    }
    
    return 0;
}