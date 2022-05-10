//Fitria Rahmadani (M0521022)

#include <stdio.h>
#include <stdlib.h>
#define matematika 100
#define fisika 100
#define kimia 100
#define biologi 100

float rerata_siswa(int no,float arr[3][4]);
float rerata_mapel(int no,float arr[3][4]);

int main()
{
    int siswa,fisika,biologi,matematika,kimia;
    float hasil=0,nilai[3][4]={0};
    int i,j;

    printf("\n=====PROGRAM PENGHITUNG RERATA NILAI 3 SISWA=====\n\n");

    for(siswa=1;siswa<=3;siswa++){
        printf("\nNomor siswa (1-3) : %d \n",siswa);

        printf("Masukkan nilai mata pelajaran (1-100)\n");
        printf("Matematika : ");
        scanf("%d",&matematika);
        printf("Fisika     : ");
        scanf("%d",&fisika);
        printf("Biologi    : ");
        scanf("%d",&biologi);
        printf("Kimia      : ");
        scanf("%d",&kimia);

        nilai[siswa-1][1]+=matematika;
        nilai[siswa-1][2]+=fisika;
        nilai[siswa-1][3]+=biologi;
        nilai[siswa-1][4]+=kimia;
        printf("\n");
    }

    printf("\n\n\tSiswa\t\tMatematika\tFisika\t\tBiologi\t\tKimia\t\tRerata\n");
    for(i=0;i<3;i++){
        printf("\t%d\t",i+1);
        for(j=0;j<4;j++){
            printf("\t%.2f\t",nilai[i][j+1]);
        }printf("\t%.2f\n", rerata_siswa(i,nilai));
    }
    	printf("\tRerata\t\t");
    	for(int j=1;j<5;j++){
            printf("%.2f\t\t", rerata_mapel(j,nilai));
    	}

    	printf("\n\n=====PROGRAM SELESAI=====\n\n");
    return 0;

}

//fungsi rerata per siswa
float rerata_siswa(int no,float arr[3][4])
{
    float hasil=0;
    for(int i=1;i<=4;i++){
        hasil+=(arr[no][i])/4;
    }
    return hasil;
}

//fungsi rerata per mapel
float rerata_mapel(int no,float arr[3][4])
{
    float hasil=0;
    for(int i=0;i<3;i++){
        hasil+=(arr[i][no])/3;
    }
    return hasil;
}
