#include <algorithm>
#include <ctime>
#include <iostream>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

#define A_SIZE 20
#define G_SIZE 10
#define MAX_W 10
#define INF INT_MAX

void generate(vector<int>& a, int size);
void function1(vector<int>& a);
int function2(const vector<int>& a);
void function3(const vector<vector<int>& g, vector<vector<int>>& d);
void print1(const vector<int>& a);
void print2(const vector<vector<int>>& g);
void print3(const vector<vector<int>>& d, int t);

int main() {
    vector<int> a(A_SIZE);
    /*vector<vector<int>> g = {
        {0, 10, 3, 0, 0, 5, 0, 17, 0, 22}, {10, 0, 5, 0, 2, 0, 13, 0, 0, 0},
        {3, 5, 0, 2, 0, 4, 0, 21, 0, 11}, {0, 0, 2, 0, 7, 0, 6, 0, 0, 0},
        {0, 2, 0, 7, 0, 6, 0, 0, 19, 0}, {5, 0, 4, 0, 6, 0, 9, 3, 0, 0},
        {0, 13, 0, 6, 0, 9, 0, 4, 0, 0}, {17, 0, 21, 0, 0, 3, 4, 0, 8, 0},
        {0, 0, 0, 0, 19, 0, 0, 8, 0, 5}, {22, 0, 11, 0, 0, 0, 0, 0, 5, 0}}; */
        
    vector<vector<int>> g = {
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

    vector<vector<int>> d(G_SIZE, vector<int>(G_SIZE));

    int t;

    srand(time(NULL));

    clock_t start, end;
    double time;

    start = clock();

    generate(a, A_SIZE);
    cout << "A:" << endl;
    print1(a);

    function1(a);
    cout << "\nFunction1 Sonuc:" << endl;
    print1(a);

    t = function2(a);
    cout << "\nFunction2 Sonuc: " << t << endl;

    cout << "\nG:" << endl;
    print2(g);

    function3(g, d);
    cout << "\nFunction3 Sonuc:" << endl;
    print2(d);

    cout << "\n" << t << " icin sonuc:" << endl;
    print3(d, t);

    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\nCalisma Suresi: " << time << " sn" << endl;

    return 0;
}


void generate(vector<int>& a, int size) {
	for (int i = 0; i < size; i++) {
	a[i] = rand() % (2 * MAX_W) - MAX_W;
	}
}

void function1(vector<int>& a) {
    sort(a.begin(), a.end());
}

int function2(const vector<int>& a) {
	int t = 0, current_sum = 0, count = 0;
	for (int i = 0; i < a.size(); i++) {
		if (current_sum + a[i] > 0) {
		current_sum = current_sum + a[i];
	}
else {
current_sum = 0;  
}
if (current_sum > t) {
t = current_sum;
count++;
}
}
return t / count;
}

void function3(const vector<vector<int>>& g, vector<vector<int>>& d) {
int size = g.size();
d = g;


for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
        if (i == j) {
            d[i][j] = 0;
        }
        else if (g[i][j] == 0) {
            d[i][j] = INF;
        }
    }
}

for (int k = 0; k < size; k++) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (d[i][k] != INF && d[k][j] != INF &&
                d[i][k] + d[k][j] < d[i][j]) {
                d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}
}

void print1(const vector<int>& a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
		if ((i + 1) % 10 == 0) {
		   cout << endl;
		}
	}
}

void print2(const vector<vector<int>>& g) {
	for (const auto& row : g) {
		for (const auto& elem : row) {
			if (elem == INF) {
			cout << "INF ";
}
else {
    cout << setw(3) << elem << " ";
}
}
cout << endl;
}
}

void print3(const vector<vector<int>>& d, int t) {
	int size = d.size();
	for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
			if (i != j && d[i][j] < t) {
				cout << static_cast<char>('A' + i) << " -> "
				<< static_cast<char>('A' + j) << ": " << d[i][j] << endl;
			}
		}
	}
}





