#include <stdio.h>
#include <math.h>


float luasSegitiga()
{
    float alas,tinggi;
    float Lsegitiga;
    printf("\nProgram Penghitung Luas Segitiga\n\n");
    printf("Masukkan alas segitiga   : ");
    scanf("%f",&alas);
    printf("Masukkan tinggi segitiga : ");
    scanf("%f",&tinggi);
      if (alas<=0||tinggi<=0){
        printf("Maaf, luas tidak bisa negatif  maupun 0\n");
      }
    Lsegitiga=alas*tinggi/2;
    printf("Luas segitiga adalah %.2f\n",Lsegitiga);
    return Lsegitiga;
}

float luasPersegi()
{
    float sisi;
    float Lpersegi;
    printf("\nProgram Penghitung Luas Persegi\n\n");
    printf("Masukkan sisi persegi : ");
    scanf("%f",&sisi);
      if(sisi<=0){
        printf("Maaf, luas tidak bisa negatif  maupun 0\n");
      }
    Lpersegi=pow(sisi,2);
    printf("Luas persegi adalah %.2f\n",Lpersegi);
    return Lpersegi;
}

float luasPersegiPanjang();

int main()
{
    int pilihan,YT;
    float output;

     while(1==1){
     printf("\n====Program Penghitung Luas Bangun Datar====\n");
     printf("1. Luas Segitiga\n");
     printf("2. Luas Persegi\n");
     printf("3. Luas Persegi Panjang\n");
     printf("4. Berhenti\n\n");
     printf("Masukkan pilihan: ");
     scanf("%d",&pilihan);
     switch(pilihan){
     case 1:
        output=luasSegitiga();
        break;
     case 2:
        output=luasPersegi();
        break;
     case 3:
        output=luasPersegiPanjang();
        break;
     case 4:
        output=-2;
        break;
     default:
        output=-1;
        printf("\nMaaf, input yang anda masukkan salah\n");
        break;
     }
     if(output==-1) continue;
     if(output==-2) break;
     while(1==1){
        printf("\nApakah ingin melanjutkan perhitungan?\n1.Ya\n2.Tidak\n");
        printf("Masukkan pilihan: ");
        scanf("%d",&YT);
        switch(YT){
        case 1:
            output=-1;
            break;
        case 2:
            output=-2;
            break;
        }break;
     }
     if(output==-1) continue;
     if(output==-2) break;
    }
    printf("\nProgram Selesai\n");
  return 0;
}

float luasPersegiPanjang()
{

    float panjang,lebar;
    float Lpersegipanjang;
    printf("\nProgram Penghitung Luas Persegi Panjang\n\n");
    printf("Masukkan panjang persegi panjang : ");
    scanf("%f",&panjang);
    printf("Masukkan lebar persegi panjang   : ");
    scanf("%f",&lebar);
      if (panjang<=0||lebar<=0){
        printf("Maaf, luas tidak bisa negatif  maupun 0\n");
      }
    Lpersegipanjang=panjang*lebar;
    printf("Luas persegi panjang adalah %.2f\n",Lpersegipanjang);
    return Lpersegipanjang;
}
