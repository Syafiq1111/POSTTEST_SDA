#include <iostream>
#include <string>

using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
};

struct Node {
    Item data;
    Node* next;
};

Node* buatNodeBaru(string namaItem, string tipe, int jumlahAwal) {
    Node* newNode = new Node;
    newNode->data.namaItem = namaItem;
    newNode->data.tipe = tipe;
    newNode->data.jumlah = jumlahAwal;
    newNode->next = NULL;
    return newNode;
}

void tambahItem(Node** head, string namaItem, string tipe, int jumlahAwal) {
    Node* newNode = buatNodeBaru(namaItem, tipe, jumlahAwal);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "\n[+] Item '" << namaItem << "' berhasil ditambahkan." << endl;
}

void sisipkanItem(Node** head, string namaItem, string tipe, int jumlahAwal, int posisi) {
    if (posisi < 1) {
        cout << "\n[!] Posisi tidak valid." << endl;
        return;
    }
    if (posisi == 1) {
        Node* newNode = buatNodeBaru(namaItem, tipe, jumlahAwal);
        newNode->next = *head;
        *head = newNode;
        cout << "\n[+] Item '" << namaItem << "' berhasil disisipkan di posisi " << posisi << "." << endl;
        return;
    }

    Node* temp = *head;
    int hitung = 1;
    while (temp != NULL && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }

    if (temp == NULL) {
        cout << "\n[!] Posisi sisip melebihi ukuran inventory. Item ditambahkan di akhir." << endl;
        tambahItem(head, namaItem, tipe, jumlahAwal);
    } else {
        Node* newNode = buatNodeBaru(namaItem, tipe, jumlahAwal);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "\n[+] Item '" << namaItem << "' berhasil disisipkan di posisi " << posisi << "." << endl;
    }
}

void hapusItemTerakhir(Node** head) {
    if (*head == NULL) {
        cout << "\n[!] Inventory kosong, tidak ada item untuk dihapus." << endl;
        return;
    }
    if ((*head)->next == NULL) {
        cout << "\n[-] Item '" << (*head)->data.namaItem << "' berhasil dihapus." << endl;
        delete *head;
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    cout << "\n[-] Item '" << temp->next->data.namaItem << "' berhasil dihapus." << endl;
    delete temp->next;
    temp->next = NULL;
}

void hapusSemuaItem(Node** head) {
    if (*head == NULL) {
        cout << "\n[!] Inventory kosong, tidak ada item untuk dihapus." << endl;
        return;
    }
    int jumlahNode = 0;
    while (*head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
        jumlahNode++;
    }
    cout << "\n[-] Semua item berhasil dihapus (" << jumlahNode << " item)." << endl;
}

void gunakanItem(Node** head, string namaItem) {
    if (*head == NULL) {
        cout << "\n[!] Inventory kosong." << endl;
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;
    bool ditemukan = false;

    while (temp != NULL) {
        if (temp->data.namaItem == namaItem) {
            ditemukan = true;
            temp->data.jumlah--;
            cout << "\n[*] Anda menggunakan 1 '" << namaItem << "'. Sisa: " << temp->data.jumlah << endl;
            if (temp->data.jumlah <= 0) {
                cout << "[!] Item '" << namaItem << "' telah habis dan dihapus dari inventory." << endl;
                if (prev == NULL) {
                    *head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
            }
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!ditemukan) {
        cout << "\n[!] Item '" << namaItem << "' tidak ditemukan di inventory." << endl;
    }
}

void tampilkanInventory(Node* head) {
    if (head == NULL) {
        cout << "\n[!] Inventory Anda kosong." << endl;
        return;
    }
    cout << "\n==========================================" << endl;
    cout << "           Isi Inventory Anda" << endl;
    cout << "==========================================" << endl;
    Node* temp = head;
    int index = 1;
    while (temp != NULL) {
        cout << index << ". Nama   : " << temp->data.namaItem << endl;
        cout << "   Tipe   : " << temp->data.tipe << endl;
        cout << "   Jumlah : " << temp->data.jumlah << endl;
        cout << "------------------------------------------" << endl;
        temp = temp->next;
        index++;
    }
}

int main() {
    Node* head = NULL;
    string nama;
    string nim3digit;
    int pilihan;

    cout << "==========================================" << endl;
    cout << "    PROGRAM MANAJEMEN INVENTORY GAME" << endl;
    cout << "==========================================" << endl;
    cout << "Masukkan Nama Anda: ";
    getline(cin, nama);
    cout << "Masukkan 3 digit terakhir NIM Anda: ";
    getline(cin, nim3digit);

    int tigaDigitTerakhir = (nim3digit[0] - '0') * 100 + (nim3digit[1] - '0') * 10 + (nim3digit[2] - '0');
    int duaDigitTerakhir = tigaDigitTerakhir % 100;
    int digitTerakhir = tigaDigitTerakhir % 10;

    int jumlahItemAwal = duaDigitTerakhir;
    if (jumlahItemAwal == 0) jumlahItemAwal = 1;

    int posisiSisip = digitTerakhir + 1;

    do {
        cout << "\n==================[ GAME INVENTORY MANAGEMENT ]==================" << endl;
        cout << "== Player: " << nama << " || NIM: " << nim3digit << " ==" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "[1] === Tambah Item Baru --- (Jumlah Awal: " << jumlahItemAwal << ")" << endl;
        cout << "[2] === Sisipkan Item  ---  (Posisi: " << posisiSisip << ")" << endl;
        cout << "[3] === Hapus Item Terakhir" << endl;
        cout << "[4] === Gunakan Item" << endl;
        cout << "[5] === Tampilkan Inventory" << endl;
        cout << "[6] === Hapus Semua Item" << endl;
        cout << "[0] === Keluar" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << ">> Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        string namaItemBaru, tipeItemBaru;

        switch (pilihan) {
            case 1:
                cout << "\n--- Tambah Item Baru ---" << endl;
                cout << "Masukkan Nama Item: ";
                getline(cin, namaItemBaru);
                cout << "Masukkan Tipe Item: ";
                getline(cin, tipeItemBaru);
                tambahItem(&head, namaItemBaru, tipeItemBaru, jumlahItemAwal);
                break;
            case 2:
                cout << "\n--- Sisipkan Item ---" << endl;
                cout << "Masukkan Nama Item: ";
                getline(cin, namaItemBaru);
                cout << "Masukkan Tipe Item: ";
                getline(cin, tipeItemBaru);
                sisipkanItem(&head, namaItemBaru, tipeItemBaru, jumlahItemAwal, posisiSisip);
                break;
            case 3:
                hapusItemTerakhir(&head);
                break;
            case 4:
                cout << "\n--- Gunakan Item ---" << endl;
                cout << "Masukkan Nama Item yang akan digunakan: ";
                getline(cin, namaItemBaru);
                gunakanItem(&head, namaItemBaru);
                break;
            case 5:
                tampilkanInventory(head);
                break;
            case 6:
                hapusSemuaItem(&head);
                break;
            case 0:
                cout << "\nTerima kasih telah bermain! Program selesai." << endl;
                break;
            default:
                cout << "\n[!] Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }

    } while (pilihan != 0);

    hapusSemuaItem(&head);
    return 0;
}
