
/*
    Método do vizinho mais proximo
    para zoom em imagem

    Autor: Alex Alves

*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void AlocarFator(int **tamanho, int **fator);
void LerFator(int *tamanho, int *fator);
void AlocarMatriz(int ***imagem,int ***zoom,int *tamanho, int *fator);
void LerMatriz(int **imagem,int**zoom,int *tamanho, int *fator);
void VizinhoMaisProximo(int *tamanho, int *fator,int **imagem, int **zoom);
void MostrarMatriz(int**zoom,int *tamanho, int *fator);

int main()
{
    int *tamanho,*fator;
    //Criando matriz dinamica
    int **imagem, **zoom;
    AlocarFator(&tamanho,&fator);
    LerFator(tamanho,fator);
    AlocarMatriz(&imagem,&zoom,tamanho,fator);
    LerMatriz(imagem,zoom,tamanho,fator);
    VizinhoMaisProximo(tamanho,fator,imagem,zoom);
    MostrarMatriz(zoom,tamanho,fator);
    return 0;
}

void AlocarFator(int **tamanho, int **fator)
{
    *tamanho = (int *)malloc(sizeof(int));
    *fator = (int *)malloc(sizeof(int));
}
void LerFator(int *tamanho, int *fator)
{
    printf("Digite a ordem da matriz\n");
    //scanf("%d\n",tamanho);
    cin >> *tamanho;
    printf("Digite o fator de zoom\n");
   // scanf("%d\n",fator);
    cin >> *fator;
}

void AlocarMatriz(int ***imagem,int ***zoom,int *tamanho, int *fator)
{

    *imagem = (int **)malloc((*tamanho)*sizeof(int*));
    *zoom = (int **) malloc((*fator)*(*tamanho)*sizeof(int*));
    for(int i=0;i<*tamanho;i++){
        (*imagem)[i] = (int *)malloc(*tamanho * sizeof(int));
    }
    for(int i=0;i<((*fator)*(*tamanho));i++){
        (*zoom)[i] = (int *)malloc((*fator)*(*tamanho) * sizeof(int));
    }
}

void LerMatriz(int **imagem,int**zoom,int *tamanho, int *fator)
{
    cout << " Digite a matriz" << endl;
    for (int i =0;i<*tamanho;i++){
        for(int j=0;j<*tamanho;j++){
             cin >>imagem[i][j];
        }
    }
}

void VizinhoMaisProximo(int *tamanho, int *fator,int **imagem, int **zoom)
{

    for (int i =0;i<(*fator)*(*tamanho);i++){
        for(int j=0;j<(*fator)*(*tamanho);j++){
             zoom[i][j]=0;
        }
    }
    int cont=0,linhaImagem=0;
    for (int i =0;i<(*fator)*(*tamanho);i++){
         if(cont==*fator){
            linhaImagem = linhaImagem+1;
            cont=0;
        }
        for(int j=0,ColunaImagem=0;j<(*fator)*(*tamanho),ColunaImagem<*tamanho;j=j + *fator,ColunaImagem++){

            zoom[i][j]=imagem[linhaImagem][ColunaImagem];
            for(int k=1; k<*fator;k++){
                zoom[i][j+k]=imagem[linhaImagem][ColunaImagem];
            }
        }
        if(linhaImagem>=*tamanho){
            linhaImagem=0;
        }
        cont++;
    }

}

void MostrarMatriz(int**zoom,int *tamanho, int *fator)
{
    for (int i =0;i<(*fator)*(*tamanho);i++){
        for(int j=0;j<(*fator)*(*tamanho);j++){
           cout <<  zoom[i][j]<< " ";
        }
        cout << endl;
    }
}
