/*
    RESPONSI 2
Nama    : Fitria Rahmadani
NIM     : M0521022
Kelas   : Informatika A
*/

/*
Program music player yang dibuat sendiri.
Program ini memiliki beberapa fitur:
1. Menambahkan lagu
2. Memutar lagu
3. Menampilkan playlist lagu
4. Melewatkan lagu
5. Menyimpan playlist lagu
*/

//Library yang digunakan
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Deklarasi data bertipe struct
struct music {
    char judul[100];
    char artist[100];
    int tahun;
    struct music *next;
    struct music *firstPtr;
    struct music *lastPtr;
};
typedef struct music Music;
typedef Music *MusicPtr;

//Deklarasi fungsi-fungsi dalam program
void enqueueMusic (MusicPtr *firstPtr, MusicPtr *lastPtr);
void dequeueMusic (MusicPtr *firstPtr);
void skipMusic (MusicPtr *firstPtr, int num);
void printList (MusicPtr startPtr);
void fileBin (MusicPtr *firstPtr);
void printBin ();
int isEmpty (MusicPtr startPtr);


//Fungsi utama dalam program yang akan dijalankan terlebih dahulu
int main()
{
    MusicPtr firstPtr = NULL;
    MusicPtr lastPtr = NULL;

    printf("\n\n***********************************************************\n");
    printf("**             SELAMAT DATANG DI JustForMusic            **\n");
    printf("**       Nikmati Mendengarkan Musik di Platform ini      **\n");
    printf("**-------------------------------------------------------**\n");
    printf("**  1. Masuk                                             **\n");
    printf("**  2. Keluar                                            **\n");
    printf("***********************************************************\n");

    int input;
    printf("\nPilihan anda    : ");
    scanf("%d", &input);

    /*
    Pemanggilan fungsi printBin untuk menampilkan playlist dari file music.bin
    Apabila belum terdapat playlist maka screen akan menampilkan "Playlist Tidak Tersedia"
    Playlist yang ada dalam printBin tidak bisa diputar ketika program dijalankan,
    Jadi fungsi ini hanya untuk menampilkan playlist lama dan akan diperbarui ketika menuliskan playlist baru
    */
    printBin();

    switch(input) {
        case 1:
        /*
        Pilihan fitur yang ada pada program.
        User diminta menginputkan pilihan fitur dan akan diproses pada operasi switch.
        Pemilihan fitur akan memanggil fungsi dari masing-masing fitur.
        */

            printf("\n========PLAYLIST LAGU========\n");
            printf("||1. Tambah Lagu           ||\n");
            printf("||2. Putar Lagu            ||\n");
            printf("||3. Skip Lagu             ||\n");
            printf("||4. Print Playlist        ||\n");
            printf("||5. Simpan Playlist       ||\n");
            printf("||6. Selesai               ||\n");
            printf("=============================\n");

            while(1) {
                int choice;
                printf("\nMasukkan pilihan menu : ");
                scanf("%d", &choice);
                switch(choice) {
                    case 1:
                        enqueueMusic(&firstPtr,&lastPtr);
                        break;
                    case 2:
                        dequeueMusic(&firstPtr);
                        break;
                    case 3:
                        skipMusic(&firstPtr,2);
                        break;
                    case 4:
                        printList(firstPtr);
                        break;
                    case 5:
                        fileBin(&firstPtr);
                        printBin();
                        break;
                    case 6:
                        exit(0);
                        break;
                    default:
                        printf("Pilihan anda salah. Masukkan lagi!!\n");
                        break;
                }
            }
        case 2:
            exit(0);
            break;
        default:
            printf("Pilihan anda salah!");
            break;
    }

    return 0;
}

/*
Fungsi untuk menambahkan lagu pada playlist.
User diminta untuk menginputkan judul lagu, penyanyi, dan tahun rilis lagu.
Lagu yang diinputkan pertama kali akan berada di dalam playlist dan menunggu untuk diputar.
*/
void enqueueMusic (MusicPtr *firstPtr, MusicPtr *lastPtr)
{
    MusicPtr newPtr = malloc(sizeof(Music));
    Music data;

    if(newPtr != NULL) {
        printf("Judul Lagu       : ");
        scanf("\n%[^\n]",data.judul);
        printf("Nama Penyanyi    : ");
        scanf("\n%[^\n]",data.artist);
        printf("Tahun Rilis      : ");
        scanf("%d",&data.tahun);

        strcpy(newPtr->judul,data.judul);
        strcpy(newPtr->artist,data.artist);
        newPtr->tahun = data.tahun;
        newPtr->next = NULL;

        if(isEmpty(*firstPtr)) {
            *firstPtr = newPtr;
        }else {
            (*lastPtr)->next = newPtr;
        }

        *lastPtr = newPtr;
        printf("Lagu telah ditambahkan ke Playlist!\n");
    }else {
        printf("Lagu tidak dapat ditambahkan!\n");
    }
}

/*
Fungsi untuk memutar lagu pada playlist.
Lagu yang berada pada playlist pertama kali akan diputar pertama kali juga.
*/
void dequeueMusic (MusicPtr *firstPtr)
{
    if (*firstPtr != NULL) {
        MusicPtr temp = *firstPtr;
        *firstPtr = (*firstPtr)->next;
        printf("Lagu %s telah diputar.\n",temp->judul);
        free(temp);
    }else {
        printf("Playlist Kosong!\n");
    }
}

/*
Fungsi untuk menampilkan lagu pada playlist.
*/
void printList (MusicPtr startPtr)
{
    if (startPtr == NULL) {
        printf("Playlist Baru Kosong!\n");
    }else {
        printf("-----------------------------------------------------------------------------\n");
        printf("%40s","Playlist Anda\n");
        printf("-----------------------------------------------------------------------------\n");
        while (startPtr != NULL) {
            printf("%-30s %-30s %10d\n", startPtr->judul, startPtr->artist, startPtr->tahun);
            startPtr = startPtr->next;
        }
    }
}

/*
Fungsi untuk melewatkan lagu pada playlist.
Fungsi ini merupakan pengembangan dari fungsi dequeueMusic sehingga fungsi ini dapat melewatkan 1 lagu pada playlist.
*/
void skipMusic (MusicPtr *firstPtr, int num)
{
    for(int i = 0; i < num; ++i)
    {
        dequeueMusic (firstPtr);
    }
}

/*
Fungsi ini untuk mengecek apakah terdapat isi pada struct atau kosong
*/
int isEmpty (MusicPtr startPtr)
{
    return startPtr == NULL;
}

/*
Fungsi untuk menyimpan playlist ke dalam file music.bin.
Fungsi ini sekaligus memperbarui playlist yang lama.
*/
void fileBin (MusicPtr *firstPtr)
{
    FILE *fmusic;

    Music temp;
    MusicPtr current = *firstPtr;

    fmusic = fopen("music.bin", "wb");
    while(current != NULL){
        strcpy(temp.judul, current->judul);
        strcpy(temp.artist, current->artist);
        temp.tahun = current->tahun;
        fwrite(&temp, sizeof(Music), 1, fmusic);
        current = current->next;
    }
    fclose(fmusic);
}

/*
Fungsi untuk menampilkan playlist dari file music.bin.
Fungsi ini merupakan fungsi yang menampilkan playlist lama sebelum diperbarui.
*/
void printBin ()
{
    FILE *fmusic;

    Music temp;

    fmusic = fopen("music.bin", "rb");
    if(fmusic != NULL){
        printf("-----------------------------------------------------------------------------\n");
        printf("%40s","Playlist Anda\n");
        printf("-----------------------------------------------------------------------------\n");
        while(!feof(fmusic)){
            fread(&temp, sizeof(Music), 1, fmusic);
            if(!feof(fmusic)){
                printf("%-30s %-30s %10d\n", temp.judul, temp.artist, temp.tahun);
            }
        }
            fclose(fmusic);
            printf("\n");
    }
    else{
        printf("Playlist Tidak Tersedia!\n");
    }
}
