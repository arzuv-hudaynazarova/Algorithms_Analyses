#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonksiyon prototipleri
void diziYazdir(int dizi[], int boyut);
void matrisYazdir(int matris[10][10]);
void quickSort(int dizi[], int ilk, int son);
int partition(int dizi[], int ilk, int son);
double ortalamaBul(int dizi[], int boyut);
void matrisOlustur(int G[10][10]);
void floydWarshall(int G[10][10], int D[10][10]);
void yoluYazdir(int D[10][10], int i, int j);

int main() {
    clock_t baslangic, bitis;
    double calismaSuresi;
    baslangic = clock();

    srand(time(NULL));
    int diziA[10], diziB[10], i;
    for (i = 0; i < 10; i++) {
        diziA[i] = rand() % 11 - 5;
        diziB[i] = rand() % 11 - 5;
    }

    printf("Dizi :\n");
    diziYazdir(diziA, 10);
    printf("\n");
    diziYazdir(diziB, 10);

    printf("\nQuicksortun Sonucu:\n");
    quickSort(diziA, 0, 9);
    quickSort(diziB, 0, 9);
    diziYazdir(diziA, 10);
    printf("\n");
    diziYazdir(diziB, 10);

   
    printf("\nOrtalama Sonuc: %f\n", ortalamaBul(diziA, 10));


    int G[10][10], D[10][10];
    matrisOlustur(G);
    printf("\nGraf Matrisi:\n");
    matrisYazdir(G);

    printf("\nFloyd-Warshall Sonucu:\n");
    floydWarshall(G, D);
    matrisYazdir(D);

    printf("\n4. index icin sonuc:\n");
    for (i = 0; i < 10; i++) {
        yoluYazdir(D, 4, i);
    }

    bitis = clock();
    calismaSuresi = ((double)(bitis - baslangic)) / CLOCKS_PER_SEC;
    printf("\nCalisma Suresi: %f sn\n", calismaSuresi);

    return 0;
}

void diziYazdir(int dizi[], int boyut) {
    for (int i = 0; i < boyut; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

void matrisYazdir(int matris[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%3d ", matris[i][j]);
        }
        printf("\n");
    }
}

void quickSort(int dizi[], int ilk, int son) {
    int pivot;
    if (ilk < son) {
        pivot = partition(dizi, ilk, son);
        quickSort(dizi, ilk, pivot - 1);
        quickSort(dizi, pivot + 1, son);
    }
}

int partition(int dizi[], int ilk, int son) {
    int pivot = dizi[son];
    int i = (ilk - 1);

    for (int j = ilk; j <= son - 1; j++) {
        if (dizi[j] < pivot) {
            i++;
            int temp = dizi[i];
            dizi[i] = dizi[j];
            dizi[j] = temp;
        }
    }
    int temp = dizi[i+1];
    dizi[i+1] = dizi[son];
    dizi[son] = temp;
    return (i + 1);
}

double ortalamaBul(int dizi[], int boyut) {
    int toplam = 0;
    for (int i = 0; i < boyut; i++) {
        toplam += dizi[i];
    }
    return (double)toplam / boyut;
}

void matrisOlustur(int G[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            G[i][j] = rand() % 23; // 0 ile 22 arasında rastgele sayılar
        }
    }
}

void floydWarshall(int G[10][10], int D[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            D[i][j] = G[i][j];
        }
    }

    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

void yoluYazdir(int D[10][10], int i, int j) {
    printf("D[%d][%d] = %d\n", i, j, D[i][j]);
}

