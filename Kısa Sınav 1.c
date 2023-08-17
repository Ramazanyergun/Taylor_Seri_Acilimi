#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double x;
double x0;
int terimSayisi;

void terimSayisiAl(){
    printf("F(x) = 0.75x^5 - 2x^3 + 1\n");
    printf("Yukaridaki fonksiyonun Taylor Seri Acilimi icin terim sayisi [3,8] girin : ");
    scanf("%d",&terimSayisi);
}
void x0Al(){
    printf("F(x) = 0.75x^5 - 2x^3 + 1\n");
    printf("Yukaridaki fonksiyonun Taylor Seri Acilimi icin x0 degeri [-2,2] girin : ");
    scanf("%lf",&x0);
}
void xAl(){
    printf("F(x) = 0.75x^5 - 2x^3 + 1\n");
    printf("Yukaridaki fonksiyonun Taylor Seri Acilimi icin x degeri [-4,4] girin : ");
    scanf("%lf",&x);
}

double fonk(double x){
    return 0.75*pow(x,5) - 2*pow(x,3) + 1;
    }

double birinciTurev(double x){
   return 0.75*5*pow(x,4) - 2*3*pow(x,2);               //F(x) = 3.75x4 � 6x2
}

double ikinciTurev(double x){
    return 0.75*5*4*pow(x, 3) - 2*3*2*x;              //F(x) = 15x3 � 12x
}

double ucuncuTurev(double x){
    return 0.75*5*4*3*pow(x, 2) - 12;                //F(x) = 45x2 � 12
}

double dorduncuTurev(double x){
    return 0.75*5*4*3*2*x;                            //F(x) =  90x
}

double besinciTurev(double x){
    return 0.75*5*4*3*2*1;                              //F(x) =  90
}


int main(){
    terimSayisiAl();
    x0Al();
    xAl();
    double ilkUcTurev = fonk(x0) + birinciTurev(x0) * (x-x0) + ikinciTurev(x0) * pow(x-x0,2) / 2;
    if(terimSayisi < 3 || terimSayisi > 8){
        terimSayisiAl();
    }
    if(x0 < -2 || x0 > 2){
        x0Al();
    }
    if(x < -4 || x > 4){
        xAl();
    }

    switch (terimSayisi) {
        case 3:
            printf("Sonuc : %lf\n",ilkUcTurev);
            break;
        case 4:
            printf("Sonuc : %lf\n", ilkUcTurev + ucuncuTurev(x0) * pow(x - x0, 3) / 6);
            break;
        case 5:
            printf("Sonuc : %lf\n", ilkUcTurev + ucuncuTurev(x0) * pow(x - x0, 3) / 6 + dorduncuTurev(x0) * pow(x - x0, 4) / 24);
            break;
        case 6:
            printf("Sonuc : %lf\n", ilkUcTurev + ucuncuTurev(x0) * pow(x - x0, 3) / 6 + dorduncuTurev(x0) * pow(x - x0, 4) / 24 + besinciTurev(x0) * pow(x - x0, 5) / 120);
            break;
        case 7:
            printf("Sonuc Hesaplanamaz !\n");
            break;
        case 8:
           printf("Sonuc Hesaplanamaz ! \n");
            break;
        default:
            printf("Yanlis deger girdiniz. Tekrar Deneyin\n");
            terimSayisiAl();
            x0Al();
            xAl();
            break;
    }
}

