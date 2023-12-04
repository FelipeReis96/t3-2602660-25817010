#include <math.h>
#include "trabalho3.h"
#include "imagem.h"
#define LIMITE 127
#define N_TESTES 4

/*void janelaDeslizante (Imagem1C* img){
    Imagem1C* copia = img;
    double mediaLocal=0;
    int i,j, somador=0;


    for(i=0;i<copia->altura;i++){

        for(j = 0; copia -> largura; j++){
            somador=0;
            mediaLocal=0;
            if(i-1 >= 0){
                if(j-1 >= 0){
                    mediaLocal+=copia->dados[i-1][j-1];
                    somador++;
                }
                if(j+1 < copia->largura-1){
                    mediaLocal+=copia->dados[i-1][j+1];
                    somador++;
                }
                mediaLocal+=copia->dados[i-1][j];
                somador++;
            }
            if(i+1 > copia -> altura -1){
                 if(j-1 >= 0){
                    mediaLocal+=copia->dados[i+1][j-1];
                    somador++;
                }
                if(j+1 < copia->largura-1){
                    mediaLocal+=copia->dados[i+1][j+1];
                    somador++;
                }
                mediaLocal+=copia->dados[i+1][j];
                somador++;
            }
            if(j+1 > copia->largura-1){
                mediaLocal+=copia->dados[i][j+1];
                somador++;
            }
            if(j-1 >= 0){
                mediaLocal+=copia->dados[i][j-1];
                somador ++;
            }
            img->dados[i][j]= (double)mediaLocal/somador;
        }
    }
}*/

Imagem1C* mediaLateral(Imagem1C* img){

    int i, j,contaBrancos=0;

    Imagem1C* copia;
    copia = criaImagem1C (img->largura, img->altura);


    for (i = 0; i < img->altura; i++) {
        for(j = 0; j < img->largura; j++) {
            copia->dados[i][j] = img->dados[i][j];
        }
    }

    for(i=0;i<img->altura;i++){
        for(j=0;j<img->largura;j++){
            contaBrancos=0;
            if(i-1 >= 0 && img->dados[i-1][j] >= LIMITE)
                contaBrancos++;
            if(i+1 < img->altura && img->dados[i+1][j] >= LIMITE)
                contaBrancos++;
            if(j-1 >= 0 &&img->dados[i][j-1] >= LIMITE)
                contaBrancos++;
            if(j+1<img->largura && img->dados[i][j+1] >= LIMITE)
                contaBrancos++;
            if(i-1 >= 0 && j-1>=0 && img->dados[i-1][j-1] >= LIMITE)
                contaBrancos++;
            if(i-1 >= 0 && j+1 < img->largura && img->dados[i-1][j+1] >= LIMITE)
                contaBrancos++;
            if(i+1 < img->altura && j+1 < img->largura && img->dados[i+1][j+1] >= LIMITE)
                contaBrancos++;
            if(i+1 < img->altura && j-1>=0 && img->dados[i+1][j-1] >= LIMITE)
                contaBrancos++;
            if(contaBrancos>=4)
                copia->dados[i][j]=255;
            else
                copia->dados[i][j]=0;
        }
    }
    return (copia);
}

double detectaSensorBar (Imagem1C* img, Coordenada* l, Coordenada* r){

    int i,j,contaBrancos=0;

    for(i=0;i<img->altura;i++){
        for(j=0;j<img->largura;j++){
            if(i<5 || i>img->altura-5 || j<5 || j>img->largura-5)
                img->dados[i][j]=0;
            if(img->dados[i][j]<LIMITE)
                img->dados[i][j]=0;
        }
    }
   // janelaDeslizante(img);
   img=mediaLateral(img);
    for(i=0;i<N_TESTES;i++){
        salvaImagem1C (img, "imagem.bmp");
    }

}

