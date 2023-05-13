#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define DIZI_BOYUTU 20
#define GRAF_BOYUTU 10
#define MAX_SAYI 10

// Maksimum değer için sonsuz sayı
#define SONSUZ INT_MAX

void dizi_uret(int dizi[], int boyut);
void sirala(int dizi[], int boyut);
int ortalama_bul(int dizi[], int boyut);
void en_kisa_yollari_bul(int g[][GRAF_BOYUTU], int d[][GRAF_BOYUTU], int boyut);
void dizi_yazdir(int dizi[], int boyut);
void graf_yazdir(int g[][GRAF_BOYUTU], int boyut);
void esik_alti_yollari_yazdir(int d[][GRAF_BOYUTU], int boyut, int esik);

int main() {
    int dizi[DIZI_BOYUTU];
    int graf[GRAF_BOYUTU][GRAF_BOYUTU] = {
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
    int esik;

    // Rastgele sayı üretici için seed
    srand(time(NULL));

    // Çalışma süresinin hesaplanması
    clock_t baslangic, bitis;
    double sure;

    baslangic = clock();

    // Dizi oluşturma ve yazdırma
    dizi_uret(dizi, DIZI_BOYUTU);
    printf("Dizi:\n");
    dizi_yazdir(dizi, DIZI_BOYUTU);

    // Diziyi sıralama ve yazdırma
    sirala(dizi, DIZI_BOYUTU);
    printf("\nSirali Dizi:\n");
    dizi_yazdir(dizi, DIZI_BOYUTU);

    // Ortalamayı hesaplama ve yazdırma
    esik = ortalama_bul(dizi, DIZI_BOYUTU);
    printf("\nOrtalama: %d\n", esik);

    // Grafiği yazdırma
    printf("\nGraf:\n");
    graf_yazdir(graf, GRAF_BOYUTU);

    // En kısa yolları bulma ve yazdırma
    en_kisa_yollari_bul(graf, d, GRAF_BOYUTU);
    printf("\nEn Kisa Yollar:\n");
    graf_yazdir(d, GRAF_BOYUTU);

    // Belirlenen eşiğin altındaki yolları yazdırma
    printf("\nEşik (%d) altındaki yollar:\n", esik);
    esik_alti_yollari_yazdir(d, GRAF_BOYUTU, esik);

    bitis = clock();
    sure = ((double)(bitis - baslangic)) / CLOCKS_PER_SEC;
    printf("\nCalisma Suresi: %f sn\n", sure);

    return 0;
}

// Diziye rastgele sayılar atayan fonksiyon
void dizi_uret(int dizi[], int boyut) {
    for (int i = 0; i < boyut; i++) {
        dizi[i] = rand() % (2 * MAX_SAYI) - MAX_SAYI;
    }
}

// Diziyi sıralayan fonksiyon
void sirala(int dizi[], int boyut) {
    for (int i = 0; i < boyut - 1; i++) {
        for (int j = 0; j < boyut - 1 - i; j++) {
            if (dizi[j] > dizi[j + 1]) {
                int gecici = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = gecici;
            }
        }
    }
}

// Dizinin ortalama değerini bulan fonksiyon
int ortalama_bul(int dizi[], int boyut) {
    int toplam = 0, gecici_toplam = 0, sayac=0;
    for (int i = 0; i < boyut; i++) {
        if (gecici_toplam + dizi[i] > 0) {
            gecici_toplam = gecici_toplam + dizi[i];
        }
        else {
            gecici_toplam = 0;
        }
        if (gecici_toplam > toplam) {
            toplam = gecici_toplam;
            sayac++;
        }
    }
    return toplam/sayac;
}


// Grafın en kısa yollarını bulan fonksiyon
void en_kisa_yollari_bul(int g[][GRAF_BOYUTU], int d[][GRAF_BOYUTU], int boyut) {
    for (int i = 0; i < boyut; i++) {
        for (int j = 0; j < boyut; j++) {
            if (g[i][j] != 0) {
                d[i][j] = g[i][j];
            } else {
                d[i][j] = SONSUZ;
            }
        }
    }

    for (int k = 0; k < boyut; k++) {
        for (int i = 0; i < boyut; i++) {
            for (int j = 0; j < boyut; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

// Diziyi yazdıran fonksiyon
void dizi_yazdir(int dizi[], int boyut) {
    for (int i = 0; i < boyut; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

// Grafiği yazdıran fonksiyon
void graf_yazdir(int g[][GRAF_BOYUTU], int boyut) {
    for (int i = 0; i < boyut; i++) {
        for (int j = 0; j < boyut; j++) {
            if (g[i][j] == SONSUZ) {
                printf("inf ");
            } else {
                printf("%d ", g[i][j]);
            }
        }
        printf("\n");
    }
}

// Belirlenen eşiğin altındaki yolları yazdıran fonksiyon
void esik_alti_yollari_yazdir(int d[][GRAF_BOYUTU], int boyut, int esik) {
    for (int i = 0; i < boyut; i++) {
        for (int j = 0; j < boyut; j++) {
            if (i != j && d[i][j] <= esik) {
                printf("(%d, %d): %d\n", i, j, d[i][j]);
            }
        }
    }
}


