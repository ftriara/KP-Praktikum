#include <stdio.h>

float diskon_barang(int *harga_ptr,int diskon);
int main() {
    unsigned int harga=0,sale=0;
    char produk[50]={0};

    printf("\n=====PROGRAM PENGHITUNG HARGA BARANG=====\n\n");
    printf("Masukkan nama produk         :");
    scanf("%[^\n]s",&produk);
    printf("Harga barang                 :Rp ");
    scanf("%u",&harga);
    printf("Diskon barang (%%)            :");
    scanf("%u",&sale);

    printf("\n\n");
    printf(" ----------Harga Sebelum Diskon---------");
    printf("\n|Nama produk                :%s\t|",produk);
    printf("\n|Harga barang               :Rp %u\t|",harga);
    printf("\n|Diskon barang (%%)          :%u %%\t|",sale);
    printf("\n ---------------------------------------");

    diskon_barang(&harga,sale);

    printf("\n\n");
    printf(" ----------Harga Setelah Diskon---------");
    printf("\n|Nama produk                :%s\t|",produk);
    printf("\n|Harga barang               :Rp %d\t|",harga);
    printf("\n ---------------------------------------");

    return 0;
}

float diskon_barang(int *harga_ptr,int diskon)
{
    *harga_ptr = *harga_ptr - (*harga_ptr * diskon / 100);
}
