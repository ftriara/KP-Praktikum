//Fitria Rahmadani
//M0521022
//Informatika A
//PRAKTIKUM 4

#include <stdio.h>
#include <string.h>

struct Input{
    char nomor[10];
    char buku[50];
    unsigned int stok;
};
typedef struct Input input;

//Array berisi objek bertipe struct
input item[] =
    {
        {"1001", "Hujan", 20},
        {"1024", "Laut Bercerita", 15},
        {"1030", "Laskar Pelangi", 23},
        {"2031", "Ayah", 27},
        {"2147", "Sang Pemimpi", 21},
        {"2379", "Surat Kecil Untuk Tuhan", 10},
        {"3039", "Rembulan Tenggelam Di Wajahmu", 5},
    };

//Enumeration untuk bagian menu
enum Menu{
    eList=1,
    eWrite,
    eRead,
    eUpdate,
    eExit
};

//Enumeration untuk fungsi update
enum Update{
    eNomor=1,
    eJudul,
    eStok,
    eAll
};

//function prototype
void writedata();
void readdata();
void listdata();
void updatedata();

int main()
{
    int pilih;
    printf("\n=====Menu Program=====\n");
    const char *menuName[] = {
        "",
        "Tampilkan isi array",
        "Tulis data ke binary file",
        "Baca data dari binary file",
        "Update data",
        "Keluar dari program"
    };

    for(enum Menu menu = eList; menu<=eExit; ++menu){
        printf("%d. %s\n", menu, menuName[menu]);
    }

    while(1){
        printf("\nMasukkan pilihan menu : ");
        scanf("%d", &pilih);
        if(pilih == eList){
            listdata();
        }else if(pilih == eWrite){
            writedata();
        }else if(pilih == eRead){
            readdata();
        }else if(pilih == eUpdate){
            updatedata();
        }else if(pilih == eExit){
            printf("\nTerima Kasih dan Sampai Jumpa\n");
            break;
        }else{
            printf("\nPilihan anda tidak tersedia. Masukkan ulang!\n");
            continue;
        }
    }
    return 0;
}

//function listdata() untuk menampilkan array of struct
void listdata()
{
    printf("\n%-20s %-50s %5s\n","Nomor Seri","Judul Buku","Jumlah Stok");
    for(int i = 0 ; i < 7 ; i++){
        printf("%-20s %-50s %5u\n", item[i].nomor, item[i].buku, item[i].stok);
    }
    printf("\n");
}

//function writedata() untuk menyimpan array of struct ke dalam bentuk binary file
void writedata()
{
    FILE *fPtr;
    fPtr = fopen("perpustakaan.bin", "wb");
    if(fPtr != NULL){
            for(int i = 0; i < 7; i++){
                fwrite(item[i].nomor, 10 * sizeof(char), 1, fPtr);
                fwrite(item[i].buku, 50 * sizeof(char), 1, fPtr);
                fwrite(&item[i].stok, sizeof(int), 1, fPtr);
            }
            fclose(fPtr);
            printf("Sukses!\nData telah ditulis ke perpustakaan.bin!\n");
    }
    else{
        printf("File perpustakaan.bin tidak tersedia.\n");
    }
}

//function readdata() untuk membaca array of struct yang ada dalam binary file
void readdata()
{
    FILE *fPtr;
    fPtr = fopen("perpustakaan.bin", "rb");
    if(fPtr != NULL){
        printf("\n%-20s %-50s %5s\n","Nomor Seri","Judul Buku","Jumlah Stok");
        for(int i = 0; i < 7; i++){
            fread(item[i].nomor, 10 * sizeof(char), 1, fPtr);
            fread(item[i].buku, 50 * sizeof(char), 1, fPtr);
            fread(&item[i].stok, sizeof(int), 1, fPtr);
            printf("%-20s %-50s %5u\n", item[i].nomor, item[i].buku, item[i].stok);
        }
        fclose(fPtr);
        printf("\n");
    }
    else{
        printf("File perpustakaan.bin tidak tersedia.\n");
    }
}

//function updatedata() untuk meng-update array of struct
void updatedata()
{
    listdata();

    int ubah,pilih;

    printf("\nMasukkan line yang ingin diubah : ");
    scanf("%d",&ubah);

    input data[] = {0};

    printf("\n###Perubahan Data###\n");
    const char *ubahName[] = {
        "",
        "Nomor seri buku",
        "Judul buku",
        "Stok buku",
        "Semua data buku"
    };

    for(enum Update update = eNomor; update<=eAll; ++update){
        printf("%d. %s\n", update, ubahName[update]);
    }

    while(1){
        printf("\nMasukkan pilihan perubahan data : ");
        scanf("%d", &pilih);
        switch(pilih){
            case eNomor:
                printf("Nomor seri lama               : %s\n",item[ubah-1].nomor);
                printf("Masukkan nomor seri yang baru : ");
                scanf("%s",data[ubah-1].nomor);
                strcpy(item[ubah-1].nomor,data[ubah-1].nomor);
                printf("Nomor seri telah diperbaharui menjadi => %s\n",item[ubah-1].nomor);
                writedata();
                break;
            case eJudul:
                printf("Judul yang lama               : %s\n", item[ubah-1].buku);
                printf("Masukkan judul yang baru      : ");
                scanf("\n%[^\n]",data[ubah-1].buku);
                strcpy(item[ubah-1].buku,data[ubah-1].buku);
                printf("Judul buku telah diperbaharui menjadi => %s\n",item[ubah-1].buku);
                writedata();
                break;
            case eStok:
                printf("Stok yang lama                : %u\n", item[ubah-1].stok);
                printf("Masukkan stok yang baru       : ");
                scanf("%u",&data[ubah-1].stok);
                item[ubah-1].stok = data[ubah-1].stok;
                printf("Stok buku telah diperbaharui menjadi => %u\n",item[ubah-1].stok);
                writedata();
                break;
            case eAll:
                printf("Masukkan nomor seri yang baru : ");
                scanf("%s",data[ubah-1].nomor);
                printf("Masukkan judul yang baru      : ");
                scanf("\n%[^\n]",data[ubah-1].buku);
                printf("Masukkan stok yang baru       : ");
                scanf("%u",&data[ubah-1].stok);
                item[ubah-1] = data[ubah-1];
                printf("Data buku telah diperbaharui menjadi => %s\t%s\t%u\n",item[ubah-1].nomor,item[ubah-1].buku,item[ubah-1].stok);
                writedata();
                break;
            default:
                printf("\nPilihan anda tidak tersedia. Masukkan ulang!\n");
                continue;
        }
        break;
    }
}
