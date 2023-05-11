#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <limits>

using namespace std;
// Sabitlerin tanımlanması
const int DIZI_BOYUTU = 20;
const int GRAF_BOYUTU = 10;
const int MAX_DEGER = 10;
const int INF = numeric_limits<int>::max();
// Fonksiyonların önceden tanımlanması
void diziyiOlustur(vector<int>& dizi, int boyut);
void diziYazdir(const vector<int>& dizi);
double maksToplamOrtalamasi(const vector<int>& dizi);
void floydWarshall(const vector<vector<int>>& graf, vector<vector<int>>& sonuc);
void matrisYazdir(const vector<vector<int>>& matris);

int main() {
    srand(time(0)); // Rastgelelik için seed ayarı
    
    // Dizi oluşturma
    vector<int> dizi(DIZI_BOYUTU);
    diziyiOlustur(dizi, DIZI_BOYUTU);
    cout << "Dizi:\n";
    diziYazdir(dizi);
    
    // Diziyi sıralama ve süreyi hesaplama
    clock_t baslangic = clock();
    sort(dizi.begin(), dizi.end());
    clock_t bitis = clock();
    double sure = static_cast<double>(bitis - baslangic) / CLOCKS_PER_SEC;
    cout << "\nSıralama Süresi: " << sure << " sn\n";

    cout << "\nSıralanmış Dizi:\n";
    diziYazdir(dizi);

    double ortalama_max_toplam = maksToplamOrtalamasi(dizi);
    // Ortalama maksimum toplamı hesaplama
    cout << "\nOrtalaması: " << ortalama_max_toplam << '\n';

    // Graf oluşturma
    vector<vector<int>> graf = {
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
        
        
    vector<vector<int>> sonuc(GRAF_BOYUTU, vector<int>(GRAF_BOYUTU));

   // Floyd-Warshall algoritmasını uygulama ve süreyi hesaplama
    cout << "\nGraf:\n";
    matrisYazdir(graf);

   
    cout << "\nFloyd Warshall Sonuc:\n";
    matrisYazdir(sonuc);
    
    
     baslangic = clock();
    floydWarshall(graf, sonuc);
    bitis = clock();
    sure = static_cast<double>(bitis - baslangic) / CLOCKS_PER_SEC;
    cout << "\nFloyd Warshall Çalışma Süresi: " << sure << " sn\n";


    return 0;
}

// Rastgele sayılardan oluşan bir dizi oluşturma
void diziyiOlustur(vector<int>& dizi, int boyut) {
    for (int i = 0; i < boyut; i++) {
        dizi[i] = rand() % (2 * MAX_DEGER + 1) - MAX_DEGER;
    }
}

// Diziyi yazdırma
void diziYazdir(const vector<int>& dizi) {
    for (const auto& eleman : dizi) {
        cout << eleman << ' ';
    }
    cout << '\n';
}

// Dizideki maksimum toplamın ortalamasını hesaplama
double maksToplamOrtalamasi(const vector<int>& dizi) {
    int toplam = 0, maks_toplam = 0, eleman_sayisi = 0;
    for (const auto& eleman : dizi) {
        toplam = max(eleman, toplam + eleman);
        maks_toplam = max(toplam, maks_toplam);
        if (toplam == maks_toplam) {
            eleman_sayisi++;
        }
    }
    return static_cast<double>(maks_toplam) / eleman_sayisi;
}

// Floyd-Warshall algoritmasını uygulama
void floydWarshall(const vector<vector<int>>& graf, vector<vector<int>>& sonuc) {
    sonuc = graf;
    int boyut = graf.size();
    for (int i = 0; i < boyut; i++) {
        for (int j = 0; j < boyut; j++) {
            if (sonuc[i][j] == 0 && i != j) {
                sonuc[i][j] = INF;
            }
        }
    }
    for (int k = 0; k < boyut; k++) {
        for (int i = 0; i < boyut; i++) {
            for (int j = 0; j < boyut; j++) {
                if (sonuc[i][k] != INF && sonuc[k][j] != INF &&
                    sonuc[i][k] + sonuc[k][j] < sonuc[i][j]) {
                    sonuc[i][j] = sonuc[i][k] + sonuc[k][j];
                }
            }
        }
    }
}

// Matrisi yazdırma
void matrisYazdir(const vector<vector<int>>& matris) {
    for (const auto& satir : matris) {
        for (const auto& eleman : satir) {
            if (eleman == INF) {
                cout << "INF ";
            }
            else {
                cout << eleman << ' ';
            }
        }
        cout << '\n';
    }
}
