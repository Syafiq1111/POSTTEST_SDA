#include <iostream>

using namespace std;

// fungsi balik array
void balikArray(int* arr, int n) {

    int* awal = arr;
    int* akhir = arr + n - 1; 

    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;

        awal++;
        akhir--;
    }
}


int main() {
    
    const int N = 7;
    int data[N];

    for (int i = 0; i < N; i++) {
        data[i] = (i + 1) * 3;
    }

    cout << "sebelum dibalik: ";
    for (int i = 0; i < N; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    balikArray(data, N);

    cout << "habis dibalik: ";
    for (int i = 0; i < N; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
