#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define DIZI_BOYUTU 20
#define GRAF_BOYUTU 10
#define MAX_ACIKLAMA 10

// Maksimum değer için sonsuz sayı
#define SONSUZ INT_MAX

void diziOlustur(int dizi[], int boyut);
void hizliSiralama(int dizi[], int baslangic, int bitis);
int bolme(int dizi[], int baslangic, int bitis);
double toplamiBul(int dizi[], int boyut);
void enKisaYoluHesapla(int g[][GRAF_BOYUTU], int d[][GRAF_BOYUTU], int boyut);
void diziYazdir(int dizi[], int boyut);
void matrisYazdir(int g[][GRAF_BOYUTU], int boyut);
void sonucYazdir(int d[][GRAF_BOYUTU], int boyut, int t);

int main() {
    
    int dizi[DIZI_BOYUTU];
    int g[GRAF_BOYUTU][GRAF_BOYUTU] = {
        { 0, 10,  3,  0,  0,  5,  0, 17,  0, 22},
        {10,  0,  5,  0,  2,  0, 13,  0,  0,  0},
        { 3,  5,  0,  2,  0,  4,  0, 21,  0, 11},
        { 0,  0,  2,  0,  7,  0,  6,  0,  0,  0},
        { 0,  2,  0,  7,  0,  6,  0,  0, 19,  0},
        { 5,  0,  4,  0,  6,  0,  9,  3,  0,  0},
        { 0, 13,  0,  6,  0,  9,  0,  4,  0,  0},
        {17,  0, 21,  0,  0,  3,  4,  0,  8,  0},
        { 0,  0,  0,  0, 19,  0,  0,  8,  0,  5},
        {22,  0, 11,  0,  0,  0,  0,  0,  5,  0}
    };
    int d[GRAF_BOYUTU][GRAF_BOYUTU];
    int t;

    // Rastgele sayı üreteci için seed
    srand(time(NULL));

    // Çalışma süresinin hesaplanması
    clock_t baslangic, bitis;
    double zaman;

    baslangic = clock();

    diziOlustur(dizi, DIZI_BOYUTU);
    printf("Dizi:\n");
    diziYazdir(dizi, DIZI_BOYUTU);

    hizliSiralama(dizi, 0, DIZI_BOYUTU - 1);
    printf("\nHizliSiralama Sonuc:\n");
    diziYazdir(dizi, DIZI_BOYUTU);

     t = toplamiBul(dizi, DIZI_BOYUTU);
    printf("\nToplamiBul Sonuc: %d\n", t);

    printf("\nG:\n");
    matrisYazdir(g, GRAF_BOYUTU);

    enKisaYoluHesapla(g, d, GRAF_BOYUTU);
    printf("\nEnKisaYoluHesapla Sonuc:\n");
    matrisYazdir(d, GRAF_BOYUTU);

    printf("\n%d icin sonuc:\n", t);
    sonucYazdir(d, GRAF_BOYUTU, t);

    bitis = clock();
    zaman = ((double)(bitis - baslangic)) / CLOCKS_PER_SEC;
    printf("\nCalisma Suresi: %f sn\n", zaman);

    return 0;
}


void diziOlustur(int dizi[], int boyut) {
    if (boyut < 0) {
        printf("Hata: boyut negatif olamaz.\n");
        return;
    }
    for (int i = 0; i < boyut; i++) {
        dizi[i] = rand() % (2 * MAX_ACIKLAMA) - MAX_ACIKLAMA;
    }
}


void hizliSiralama(int dizi[], int baslangic, int bitis) {
    if (baslangic < bitis) {
        int pi = bolme(dizi, baslangic, bitis);
        hizliSiralama(dizi, baslangic, pi - 1);
        hizliSiralama(dizi, pi + 1, bitis);
    }
}


int bolme(int dizi[], int baslangic, int bitis) {
    int pivot = dizi[bitis];
    int i = (baslangic - 1);

    for (int j = baslangic; j <= bitis - 1; j++) {
        if (dizi[j] < pivot) {
            i++;
            int gecici = dizi[i];
            dizi[i] = dizi[j];
            dizi[j] = gecici;
        }
    }
    int gecici = dizi[i + 1];
    dizi[i + 1] = dizi[bitis];
    dizi[bitis] = gecici;
    return (i + 1);
}


void diziYazdir(int dizi[], int boyut) {
    for (int i = 0; i < boyut; i++) {
        printf("%d ", dizi[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}


void matrisYazdir(int matris[][GRAF_BOYUTU], int boyut) {
    for (int i = 0; i < boyut; i++) {
        for (int j = 0; j < boyut; j++) {
            if (matris[i][j] == SONSUZ) {
                printf("INF ");
            }
            else {
                printf("%3d ", matris[i][j]);
            }
        }
        printf("\n");
    }
}


double toplamiBul(int dizi[], int boyut) {
    int t = 0, toplam = 0, sayi = 0;
    for (int i = 0; i < boyut; i++) {
        if (toplam + dizi[i] > 0) {
            toplam = toplam + dizi[i];
        }
        else {
            toplam = 0;
        }
        if (toplam > t) {
            t = toplam;
            sayi++;
        }
    }
    return (double)t/sayi;
}


void enKisaYoluHesapla(int graf[][GRAF_BOYUTU], int mesafe[][GRAF_BOYUTU], int boyut) {
    for (int i = 0; i < boyut; i++) {
        for (int j = 0; j < boyut; j++) {
            if (i == j) {
                mesafe[i][j] = 0;
            }
            else if (graf[i][j] != 0) {
                mesafe[i][j] = graf[i][j];
            }
            else {
                mesafe[i][j] = SONSUZ;
            }
        }
    }

    for (int k = 0; k < boyut; k++) {
        for (int i = 0; i < boyut; i++) {
            for (int j = 0; j < boyut; j++) {
                if (mesafe[i][k] != SONSUZ && mesafe[k][j] != SONSUZ &&
                    mesafe[i][k] + mesafe[k][j] < mesafe[i][j]) {
                    mesafe[i][j] = mesafe[i][k] + mesafe[k][j];
                }
            }
        }
    }
}


void sonucYazdir(int matris[][GRAF_BOYUTU], int boyut, int t) {
    for (int i = 0; i < boyut; i++) {
        for (int j = 0; j < boyut; j++) {
            if (i != j && matris[i][j] < t) {
                printf("%c -> %c: %d\n", 'A' + i, 'A' + j, matris[i][j]);
            }
        }
    }
}


