#include <iostream>

#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {

    const int JUMLAH = 5;
    Mahasiswa mhs[JUMLAH];

    cout << "Input data " << JUMLAH << " mahasiswa:\n";
    for (int i = 0; i < JUMLAH; i++) {
        cout << "\nMahasiswa " << i + 1 << endl;
        cout << "Nama   : ";
        getline(cin, mhs[i].nama);
        cout << "NIM    : ";
        getline(cin, mhs[i].nim);
        cout << "IPK    : ";
        cin >> mhs[i].ipk;
        cin.ignore();
    }

    int indeksTertinggi = 0;
    for (int i = 1; i < JUMLAH; i++) {
        if (mhs[i].ipk > mhs[indeksTertinggi].ipk) {
            indeksTertinggi = i;
        }
    }

    cout << "\nMahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama   : " << mhs[indeksTertinggi].nama << endl;
    cout << "NIM    : " << mhs[indeksTertinggi].nim << endl;
    cout << "IPK    : " << mhs[indeksTertinggi].ipk << endl;

    return 0;
}
