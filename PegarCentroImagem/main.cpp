
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

void MostraImagem()
{

   Mat image = imread("C:\\Users\\alve\\Desktop\\Nova pasta\\Testes\\im.png");
   //   Mat image = imread("C:\\Users\\alve\\Desktop\\Nova pasta\\Testes\\homerfeliz.png");
   int r[image.rows][image.cols],g[image.rows][image.cols],b[image.rows][image.cols];
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

// Criando a matriz para poder mostrar
    Mat Mostrar(image.rows,image.cols,image.type());

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
    MostraImagem();
    Mat image = imread("C:\\Users\\alve\\Desktop\\Nova pasta\\Testes\\im.png");
    //  Centro_Imagem(2);

    return 0;

}


