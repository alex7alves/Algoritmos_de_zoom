
/*
    Método do vizinho mais proximo
    para zoom em imagem

    Autor: Alex Alves

*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void AlocarTamanho(int **linha,int **coluna, int **fator,int **linhasZoom,int **colunasZoom);
void LerTamanho(int *linha,int *coluna, int *fator,int *linhasZoom, int *colunasZoom);
void AlocarMatriz(int ***imagem,int *linha,int *coluna,int ***zoom,int *linhasZoom, int *colunasZoom);
void LerMatriz(int **imagem,int**zoom,int *linha,int *coluna);
void VizinhoMaisProximo(int *linha,int *coluna,int *linhasZoom,int *colunasZoom, int *fator,int **imagem, int **zoom);
void MostrarMatriz(int **zoom,int *linhasZoom,int *colunasZoom);


int main()
{
    int *linha,*coluna,*fator,*linhasZoom,*colunasZoom;
    //Criando matriz dinamica
    int **imagem, **zoom;
    AlocarTamanho(&linha,&coluna,&fator,&linhasZoom,&colunasZoom);
    LerTamanho(linha,coluna,fator,linhasZoom,colunasZoom);
    AlocarMatriz(&imagem,linha,coluna,&zoom,linhasZoom,colunasZoom);
    LerMatriz(imagem,zoom,linha,coluna);
    VizinhoMaisProximo(linha,coluna,linhasZoom,colunasZoom,fator,imagem,zoom);
    MostrarMatriz(zoom,linhasZoom,colunasZoom);
    return 0;
}


void AlocarTamanho(int **linha,int **coluna, int **fator,int **linhasZoom,int **colunasZoom)
{
    *linha = (int *)malloc(sizeof(int));
    *coluna = (int *)malloc(sizeof(int));
    *linhasZoom = (int *)malloc(sizeof(int));
    *colunasZoom = (int *)malloc(sizeof(int));
    *fator = (int *)malloc(sizeof(int));
}
void LerTamanho(int *linha,int *coluna, int *fator,int *linhasZoom, int *colunasZoom)
{
    printf("Digite a quantidade de linhas da matriz\n");
    //scanf("%d\n",tamanho);
    cin >> *linha;
    printf("Digite a quantidade de colunas da matriz\n");
    //scanf("%d\n",tamanho);
    cin >> *coluna;
    printf("Digite o fator de zoom\n");
   // scanf("%d\n",fator);
    cin >> *fator;
    *linhasZoom= ((*linha)*(*fator))-1;
    *colunasZoom= ((*coluna)*(*fator))-1;
}

void AlocarMatriz(int ***imagem,int *linha,int *coluna,int ***zoom,int *linhasZoom, int *colunasZoom)
{
    *imagem = (int **)malloc((*linha)*sizeof(int*));
    *zoom = (int **) malloc(*linhasZoom*sizeof(int*));
    for(int i=0;i<*linha;i++){
        (*imagem)[i] = (int *)malloc(*coluna * sizeof(int));
    }
    for(int i=0;i<*linhasZoom;i++){
        (*zoom)[i] = (int *)malloc(*colunasZoom * sizeof(int));
    }
}

void LerMatriz(int **imagem,int**zoom,int *linha,int *coluna)
{
    cout << " Digite a matriz" << endl;
    for (int i =0;i<*linha;i++){
        for(int j=0;j<*coluna;j++){
             cin >>imagem[i][j];
        }
    }
}

void VizinhoMaisProximo(int *linha,int *coluna,int *linhasZoom,int *colunasZoom, int *fator,int **imagem, int **zoom)
{

    for (int i =0;i<*linhasZoom;i++){
        for(int j=0;j<*colunasZoom;j++){
             zoom[i][j]=0;
        }
    }
    int cont=0,linhaImagem=0;
    for (int i =0;i<*linhasZoom;i++){
         if(cont==*fator){
            linhaImagem = linhaImagem+1;
            cont=0;
        }
        for(int j=0,ColunaImagem=0;j<*colunasZoom,ColunaImagem<*coluna;j=j + *fator,ColunaImagem++){

            zoom[i][j]=imagem[linhaImagem][ColunaImagem];
            for(int k=1; k<*fator;k++){
                zoom[i][j+k]=imagem[linhaImagem][ColunaImagem];
            }
        }
        if(linhaImagem>=*linha){
            linhaImagem=0;
        }
        cont++;
    }

}

void MostrarMatriz(int **zoom,int *linhasZoom,int *colunasZoom)
{
    for (int i =0;i<*linhasZoom;i++){
        for(int j=0;j<*colunasZoom;j++){
           cout <<  zoom[i][j]<< " ";
        }
        cout << endl;
    }
}
