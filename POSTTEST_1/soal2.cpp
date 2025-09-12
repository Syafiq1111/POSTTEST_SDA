#include <iostream>

using namespace std;

int main() {

    const int N = 3;
    int matriks[N][N];

    int counter = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriks[i][j] = counter * 2;
            counter++;
        }
    }

    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }

    int totaldiagonalutama = 0;
    for (int i = 0; i < N; i++) {
        totaldiagonalutama += matriks[i][i];
    }

    int totaldiagonalsekunder = 0;
    for (int i = 0; i < N; i++) {
        totaldiagonalsekunder += matriks[i][N - 1 - i];
    }

    cout << "total dari diagonal utama = " << totaldiagonalutama << endl;
    cout << "total dari diagonal sekunder = " << totaldiagonalsekunder << endl;
    cout << "Total (utama + sekunder) = " << (totaldiagonalutama + totaldiagonalsekunder) << endl;

    return 0;
}
