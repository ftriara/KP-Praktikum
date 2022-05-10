#include <stdio.h>

//array list menu makanan
char makan[4][20]={"Bakso","Rendang","Soto","Sate"};
//array list menu minuman
char minum[4][20]={"Sirup","Coklat","Susu","Kopi"};
//array list harga makanan
int harga_mkn[]={15000,25000,10000,12000};
//array list harga minuman
int harga_min[]={4000,5000,7000,5000};

//pendeklarasian fungsi
int menu(void);
int total(int a,int b);
int kembalian(int a,int b);

int main()
{
    menu();

    int pilih;
    int n,harga,bayar;
    int total_mkn=0,total_min=0,tot_mkn=0,tot_min=0;
    int jml_mkn;
    int jml_min;

    //input dari user
    while(1){
        printf("\n\nIngin pesan berapa jenis makanan? ");
        scanf("%d",&n);
        //pemilihan dengan if else
        if(n<1 || n>4){
            printf("Maaf, input yang anda masukkan tidak tersedia.");
            continue;
        }else
            break;
    }
    for(int i=0;i<n;i++){//loop for{
        printf("\nMasukkan pilihan makanan anda         : ");
        scanf("%i",&pilih);
            if(pilih==1 || pilih==2 || pilih==3 || pilih==4){
                printf("Masukkan jumlah makanan yang dipesan  : ");
                scanf("%u",&jml_mkn);
                //pemilihan dengan switch case
                switch(pilih){
                    case 1:
                        total_mkn=harga_mkn[0]*jml_mkn;
                        printf("Pesanan anda %s [%d] porsi \t      :Rp %d\n",makan[0],jml_mkn,total_mkn);
                        printf("-------------------------------------------------\n");
                        break;
                    case 2:
                        total_mkn=harga_mkn[1]*jml_mkn;
                        printf("Pesanan anda %s [%d] porsi \t      :Rp %d\n",makan[1],jml_mkn,total_mkn);
                        printf("-------------------------------------------------\n");
                        break;
                    case 3:
                        total_mkn=harga_mkn[2]*jml_mkn;
                        printf("Pesanan anda %s [%d] porsi \t      :Rp %d\n",makan[2],jml_mkn,total_mkn);
                        printf("-------------------------------------------------\n");
                        break;
                    case 4:
                        total_mkn=harga_mkn[3]*jml_mkn;
                        printf("Pesanan anda %s [%d] porsi \t      :Rp %d\n",makan[3],jml_mkn,total_mkn);
                        printf("-------------------------------------------------\n");
                        break;
                }tot_mkn+=total_mkn;
            }else
            printf("Maaf, pesanan anda tidak tersedia.\n");
            continue;
    }

    while(1){
        printf("\n\nIngin pesan berapa jenis minuman? ");
        scanf("%d",&n);
        //pemilihan dengan if else
        if(n<1 || n>4){
            printf("Maaf, input yang anda masukkan tidak tersedia.");
            continue;
        }else
            break;
    }
    for(int i=0;i<n;i++){//loop for{
        printf("\nMasukkan pilihan minuman anda         : ");
        scanf("%i",&pilih);
            if(pilih==1 || pilih==2 || pilih==3 || pilih==4){
                printf("Masukkan jumlah minuman yang dipesan  : ");
                scanf("%u",&jml_min);
                //pemilihan dengan switch case
                switch(pilih){
                    case 1:
                        total_min=harga_min[0]*jml_min;
                        printf("Pesanan anda %s [%d] porsi \t      :Rp %d\n",minum[0],jml_min,total_min);
                        printf("-------------------------------------------------\n");
                        break;
                    case 2:
                        total_min=harga_min[1]*jml_min;
                        printf("Pesanan anda %s [%d] porsi \t      :Rp %d\n",minum[1],jml_min,total_min);
                        printf("-------------------------------------------------\n");
                        break;
                    case 3:
                        total_min=harga_min[2]*jml_min;
                        printf("Pesanan anda %s [%d] porsi \t      :Rp %d\n",minum[2],jml_min,total_min);
                        printf("-------------------------------------------------\n");
                        break;
                    case 4:
                        total_min=harga_min[3]*jml_min;
                        printf("Pesanan anda %s [%d] porsi \t      :Rp %d\n",minum[3],jml_min,total_min);
                        printf("-------------------------------------------------\n");
                        break;
                }tot_min+=total_min;
            }else
            printf("Maaf, pesanan anda tidak tersedia.\n");
            continue;
    }

    harga=total(tot_mkn,tot_min);
    printf("\n\nTotal harga                 :Rp %d",harga);
    printf("\nMasukkan jumlah pembayaran  :Rp ");
    scanf("%d",&bayar);
    if(bayar>=harga){
        printf("\n\n==========================================\n");
        printf("||Total Harga\t\t:Rp %d\t||\n",harga);
        printf("||Pembayaran\t\t:Rp %d\t||\n",bayar);
        printf("||Kembalian\t\t:Rp %d\t||\n",kembalian(bayar,harga));
        printf("==========================================\n");
    }else if(bayar<harga){
        printf("\n\n==========================================\n");
        printf("||Total Harga\t\t:Rp %d\t||\n",harga);
        printf("||Pembayaran\t\t:Rp %d\t||\n",bayar);
        printf("||Kekurangan\t\t:Rp %d\t||\n",kembalian(bayar,harga));
        printf("||Mohon maaf, uang anda tidak cukup.\t||\n");
        printf("==========================================\n");
    }else
        printf("Maaf,input yang anda masukkan salah.\n");

    printf("\n\t\t\t===Terima kasih atas kehadirannya===");
    printf("\n\t\t\t=======Silakan Datang Kembali=======\n");

    return 0;
}


int menu(void) //fungsi buatan sendiri
{
   printf("\n\t\t=====SELAMAT DATANG DI ENAK RASA=====\t\t");
   printf("\n\n\t\t\t-----PILIHAN MENU-----\t\t\n");
   printf("\n\t\t***MAKANAN***\n");
   printf(" _______________________________________\n\n");
   for(int i=0;i<4;i++){
        printf("|%d. %s \t\t\tRp %u|\n",i+1,makan[i],harga_mkn[i]);
   }
   printf(" _______________________________________\n");

   printf("\n\t\t***MINUMAN***\n");
   printf(" ______________________________________\n\n");
   for(int i=0;i<4;i++){
        printf("|%d. %s \t\t\tRp %u|\n",i+1,minum[i],harga_min[i]);
   }
   printf(" ______________________________________\n");
}

int total(int a,int b) //fungsi buatan sendiri
{
    int harga;
    harga=a+b;

    return harga;
}

int kembalian(int a,int b) //fungsi buatan sendiri
{
    int kembali;
    kembali=a-b;

    return kembali;
}

