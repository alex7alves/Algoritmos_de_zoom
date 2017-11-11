
/*
    Autor : Alex Alves

    Programa para pegar os canais do centro da  imagem
    e mostrar eles moificados

*/

#include <iostream>
#include <string.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/videoio.hpp"
#include "opencv2/video/tracking.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
using namespace cv;

// *** endereço da matriz dinamica
void AlocarCanais(int ***r,int ***g,int ***b,Mat img){
    //*x -> Para criar o valor apontado
    *r = (int **)malloc((img.rows)*sizeof(int*));
    *g = (int **)malloc((img.rows)*sizeof(int*));
    *b = (int **)malloc((img.rows)*sizeof(int*));
    for(int i=0;i<img.rows;i++){
        (*r)[i] = (int *)malloc(img.cols*sizeof(int));
        (*g)[i] = (int *)malloc(img.cols*sizeof(int));
        (*b)[i] = (int *)malloc(img.cols*sizeof(int));

    }

}

void SepararCanais(int **r,int **g,int **b,Mat image){

     Vec3i  color;
     for(int i=0; i< image.rows ;i++)
     {
        for(int j=0; j<image.cols ; j++)
        {
          color = image.at<Vec3b>(i,j);
          b[i][j]=  color[0];
          g[i][j]=  color[1];
          r[i][j]=  color[2];
        }
     }
}

void ModificarCanais(int **r,int **g,int **b,Mat image){

     // Fazendo modificações nos canais
    for(int i=0; i< image.rows ;i++)
    {
        for(int j=0; j<image.cols ; j++)
        {
            if (i <50){
                 r[i][j] = 70 ;
                 b[i][j] = 120 ;
                 //g[i][j] = 40;
            }
             if (i >50){
                 r[i][j] = -20 ;
                 b[i][j] = -90 ;
                 //g[i][j]= 60;
            }

        }

    }
}

void MostraImagem(Mat image,int **r,int **g,int **b)
{

// Criando a matriz para poder mostrar
    Mat Mostrar(image.rows,image.cols,image.type());
    Vec3i  color;
    for(int i=0; i< image.rows ;i++)
    {
        for(int j=0; j<image.cols ; j++)
        {
           color[0] = b[i][j];
           color[1] = g[i][j];
           color[2] = r[i][j];
           Mostrar.at<Vec3b>(i,j) = color;
        }

    }

    imshow(" Original ",image);
    imshow("Modificada",Mostrar);
    waitKey();

}
void Centro_Imagem(int fator){
    // Fazendo a janela central
     Mat imagem = imread("C:\\Users\\alve\\Desktop\\Nova pasta\\Testes\\im.png");
    int i = (imagem.rows/fator) -(imagem.rows/(2*fator));
    int j = (imagem.cols/fator) -(imagem.cols/(2*fator));
    int i2 = (imagem.rows/fator) +(imagem.rows/(2*fator));
    int j2 = (imagem.cols/fator) +(imagem.cols/(2*fator));
    Mat Janela(imagem.rows/fator,imagem.cols/fator,imagem.type());
    for(int k=i,linha=0;k<i2,linha<Janela.rows ;k++,linha++){
        for(int w=j,coluna=0;w<j2,coluna<Janela.cols;w++,coluna++){
            Janela.at<Vec3b>(linha,coluna) = imagem.at<Vec3b>(k,w);;
       }

    }
    imshow("Janela",Janela);
    waitKey();
}
// resizeWindow(const string& winname, int width, int height)¶
int main()
{

    Mat image = imread("C:\\Users\\alve\\Desktop\\Nova pasta\\Testes\\im.png");

     // Definindo canais
     int **R,**G,**B;
     // Alocar canais passando o endereço de cada matriz
     AlocarCanais(&R,&G,&B,image);
     // Separando os canais da imagem original
     SepararCanais(R,G,B,image);
     // Modificando canais
     ModificarCanais(R,G,B,image);

     MostraImagem(image,R,G,B);

    //  Centro_Imagem(2);

    return 0;

}


