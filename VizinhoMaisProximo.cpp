// M�todo do vizinho mais proximo
// Autor: Alex Alves

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void VizinhoMaisProximo(int tamanho, int fator,int **imagem, int **zoom);

int main()
{

    int tamanho =3,fator =4;
   // int imagem[tamanho][tamanho], zoom[fator*tamanho][fator*tamanho];
    //Criando matriz dinamica
    int **imagem, **zoom;
    imagem = (int **) malloc(tamanho*sizeof(int*));
    zoom = (int **) malloc((fator*tamanho)*sizeof(int*));
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            imagem[i] = (int *)malloc(tamanho * sizeof(int));
           // zoom[i] = (int *)malloc((fator*tamanho) * sizeof(int));
        }
    }
    for(int i=0;i<(fator*tamanho);i++){
        for(int j=0;j<(fator*tamanho);j++){
            zoom[i] = (int *)malloc((fator*tamanho) * sizeof(int));
        }
    }

    VizinhoMaisProximo(tamanho,fator,imagem,zoom);

   // Liberando memoria alocada
 /*  for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
           free(imagem[i]);

        }
    }
     for(int i=0;i<(fator*tamanho);i++){
        for(int j=0;j<(fator*tamanho);j++){
           free(zoom[i]);

        }
    }
     free(imagem);
     free(zoom);*/
    return 0;
}

/*void VizinhoMaisProximo(int tamanho, int fator,int **imagem, int **zoom){
    for (int i =0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            cin >> imagem[i][j];
        }
    }
    for (int i =0;i<(fator*tamanho);i++){
        for(int j=0;j<(fator*tamanho);j++){
             zoom[i][j]=0;
        }
    }
    for (int i =0,linhaImagem=0;i<(fator*tamanho),linhaImagem<tamanho;i=i+fator,linhaImagem++){
        for(int j=0,ColunaImagem=0;j<(fator*tamanho),ColunaImagem<tamanho;j=j+fator,ColunaImagem++){
             zoom[i][j]=imagem[linhaImagem][ColunaImagem];
             for(int k=1; k<fator;k++){
                zoom[i+k][j]=imagem[linhaImagem][ColunaImagem];
                zoom[i][j+k]=imagem[linhaImagem][ColunaImagem];
                zoom[i+k][j+k]=imagem[linhaImagem][ColunaImagem];
             }

        }
    }
    for (int i =0;i<(fator*tamanho);i++){
        for(int j=0;j<(fator*tamanho);j++){
           cout <<  zoom[i][j]<< " ";
        }
        cout << endl;
    }
}*/

void VizinhoMaisProximo(int tamanho, int fator,int **imagem, int **zoom){
    for (int i =0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            cin >> imagem[i][j];
        }
    }
    for (int i =0;i<(fator*tamanho);i++){
        for(int j=0;j<(fator*tamanho);j++){
             zoom[i][j]=0;
        }
    }
    int cont=0,linhaImagem=0;
    for (int i =0;i<(fator*tamanho);i++){
         if(cont==fator){
            linhaImagem = linhaImagem+1;
            cont=0;
        }
        for(int j=0,ColunaImagem=0;j<(fator*tamanho),ColunaImagem<tamanho;j=j+fator,ColunaImagem++){

            zoom[i][j]=imagem[linhaImagem][ColunaImagem];
            for(int k=1; k<fator;k++){
                zoom[i][j+k]=imagem[linhaImagem][ColunaImagem];
            }
        }
        if(linhaImagem>=tamanho){
            linhaImagem=0;
        }
        cont++;
    }
    for (int i =0;i<(fator*tamanho);i++){
        for(int j=0;j<(fator*tamanho);j++){
           cout <<  zoom[i][j]<< " ";
        }
        cout << endl;
    }
}
