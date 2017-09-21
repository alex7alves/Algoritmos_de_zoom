#include <iostream>
#include <string>
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
    // Fazendo modifica��es nos canais
    for(int i=0; i< image.rows ;i++)
    {
        for(int j=0; j<image.cols ; j++)
        {
            if (i <30){
                 r[i][j] = 20 ;
                 b[i][j] = 200 ;
            }
             if (i >30){
                 r[i][j] = 100 ;
                 b[i][j] = 120 ;
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

// resizeWindow(const string& winname, int width, int height)�
int main()
{
    MostraImagem();


    return 0;

}


