#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    long long int codigo, quantidade;
    float preco;
    char estado[3], nome[200];
}produtos_t;


void armazenarNaStruct(int n, FILE *arquivo, produtos_t* produtos){
    for (int i = 0; i < n; i++){
        fscanf(arquivo, "%lld\n", &produtos[i].codigo);
        fgets(produtos[i].nome, sizeof(produtos[i].nome), arquivo);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';
        fscanf(arquivo, "%lld\n", &produtos[i].quantidade);
        fscanf(arquivo, "%f\n", &produtos[i].preco);
        fgets(produtos[i].estado, sizeof(produtos[i].estado), arquivo);
        produtos[i].estado[strcspn(produtos[i].estado, "\n")] = '\0';
    }
}



int compararPorNome(const void *produto1, const void *produto2) {
    const produtos_t *p1 = (const produtos_t *)produto1;
    const produtos_t *p2 = (const produtos_t *)produto2;
    return strcmp(p1->nome, p2->nome);
}



void gerarRelatorio(int q, produtos_t* produtos, FILE* arquivo){
    qsort(produtos, q, sizeof(produtos_t), compararPorNome);

    for(int i=0; i<q; i++){
        fprintf(arquivo, "%lld\n", produtos[i].codigo);
        fprintf(arquivo, "%s\n", produtos[i].nome);
        fprintf(arquivo, "%lld\n", produtos[i].quantidade);
        fprintf(arquivo,"%.2f\n", produtos[i].preco);
        fprintf(arquivo, "%s\n", produtos[i].estado);
    }
    fclose(arquivo);
}



void pesquisar(long long int codigo, produtos_t* produtos){
    int i=0;
    while(codigo != produtos[i].codigo){
        i++;
    }
    printf("%lld\n", produtos[i].codigo);
    printf("%s\n", produtos[i].nome);
    printf("%lld\n", produtos[i].quantidade);
    printf("%.2f\n", produtos[i].preco);
    printf("%s\n", produtos[i].estado);
}




void menorQuantidade(int q, produtos_t* produtos){
    int indice=0;
    long long int menorQuantidade;
    menorQuantidade = produtos[0].quantidade;

    for(int i=0; i<q; i++){
        if(menorQuantidade > produtos[i].quantidade){
            menorQuantidade = produtos[i].quantidade;
            indice = i;
        }
    }
    printf("%lld\n", produtos[indice].codigo);
    printf("%s\n", produtos[indice].nome);
    printf("%lld\n", produtos[indice].quantidade);
    printf("%.2f\n", produtos[indice].preco);
    printf("%s\n", produtos[indice].estado);
}




void listarEstado(int q, char estado[], produtos_t* produtos){
    produtos_t produtosEstado[q];
    int j=0;
    // transfere os produtos desse estado para uma struct separada 
    for(int i=0; i<q; i++){
        if(!strcmp(produtos[i].estado, estado)){
            produtosEstado[j].codigo = produtos[i].codigo;
            strcpy(produtosEstado[j].nome, produtos[i].nome);
            produtosEstado[j].quantidade = produtos[i].quantidade;
            produtosEstado[j].preco = produtos[i].preco;
            strcpy(produtosEstado[j].estado, produtos[i].estado);
            j++;
        }
    }
    qsort(produtosEstado, j, sizeof(produtos_t), compararPorNome);
    for(int i=0; i<j; i++){
        printf("%lld\n", produtosEstado[i].codigo);
        printf("%s\n", produtosEstado[i].nome);
        printf("%lld\n", produtosEstado[i].quantidade);
        printf("%.2f\n", produtosEstado[i].preco);
        printf("%s\n", produtosEstado[i].estado);
    }
}




void menorQuantidadeEstado(int q, char estado[], produtos_t* produtos){
    int indice=0;
    long long int menorQuantidade;
    for(int i=0; i<q; i++){
        if(!strcmp(produtos[i].estado, estado)){
            menorQuantidade = produtos[i].quantidade;
            break;
        }
    }
    for(int i=0; i<q; i++){
        if(!strcmp(produtos[i].estado, estado)){
            if(menorQuantidade >= produtos[i].quantidade){
                menorQuantidade = produtos[i].quantidade;
                indice = i;
            }
        }
    }
    printf("%lld\n", produtos[indice].codigo);
    printf("%s\n", produtos[indice].nome);
    printf("%lld\n", produtos[indice].quantidade);
    printf("%.2f\n", produtos[indice].preco);
    printf("%s", produtos[indice].estado);
}




void contagemItens(int q, produtos_t* produtos){
    long long int quantidadeTotal=0;
    for(int i=0; i<q; i++){
        quantidadeTotal += produtos[i].quantidade;
    }
    printf("%lld", quantidadeTotal);
}




int main(int argc, char *argv[]){
    char *input = argv[1];
    FILE *arquivo = fopen(input, "r");

    // obtém o segundo parâmetro como inteiro
    int modo = atoi(argv[2]);
    char param3[200];
    
    int q=0;
    fscanf(arquivo, "%d", &q);
    produtos_t produtos[q];
    armazenarNaStruct(q, arquivo, produtos);
    
    long long int codigoPesquisa;
    switch(modo){
        case 1:
            strcpy(param3, argv[3]);
            param3[strcspn(param3, "\n")] = '\0';
            FILE *output = fopen(param3, "a");
            gerarRelatorio(q, produtos, output);
            break;
        case 2:
            codigoPesquisa = atoll(argv[3]);
            pesquisar(codigoPesquisa, produtos);
            break;
        case 3:
            menorQuantidade(q, produtos);
            break;
        case 4:
            strcpy(param3, argv[3]);
            param3[strcspn(param3, "\n")] = '\0';
            listarEstado(q, param3, produtos);
            break;
        case 5:
            strcpy(param3, argv[3]);
            param3[strcspn(param3, "\n")] = '\0';
            menorQuantidadeEstado(q, param3, produtos);
            break;
        case 6:
            contagemItens(q, produtos);
            break;
    }
    
    fclose(arquivo);
    return EXIT_SUCCESS;

}