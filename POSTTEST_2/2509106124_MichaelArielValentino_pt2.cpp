#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

void swapKereta(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(Kereta *arr, int n) {
    cout << "\n=== DATA KERETA ===\n";
    for (int i = 0; i < n; i++) {
        cout << (arr + i)->nomor << " | "
             << (arr + i)->nama << " | "
             << (arr + i)->asal << " -> "
             << (arr + i)->tujuan << " | Rp"
             << (arr + i)->harga << endl;
    }
}

void tambah(Kereta *arr, int &n) { 
    cout << "\nTambah Data:\n";
    cout << "Nomor: "; cin >> (arr + n)->nomor;
    cout << "Nama: "; cin >> (arr + n)->nama;
    cout << "Asal: "; cin >> (arr + n)->asal;
    cout << "Tujuan: "; cin >> (arr + n)->tujuan;
    cout << "Harga: "; cin >> (arr + n)->harga;
    n++;
}

void linearSearch(Kereta *arr, int n, string asal, string tujuan) {
    bool ketemu = false;
    cout << "\nProses Linear Search:\n";

    for (int i = 0; i < n; i++) {
        cout << "Cek data ke-" << i << ": "
             << (arr + i)->asal << " -> "
             << (arr + i)->tujuan << endl;

        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "Ditemukan!\n";
            cout << (arr + i)->nomor << " | "
                 << (arr + i)->nama << " | Rp"
                 << (arr + i)->harga << endl;
            ketemu = true;
        }
    }

    if (!ketemu)
        cout << "Data tidak ditemukan.\n";
}

int jumpSearch(Kereta *arr, int n, int key) {
    int step = sqrt(n);
    int prev = 0;

    while ((arr + min(step, n) - 1)->nomor < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    for (int i = prev; i < min(step, n); i++) {
        if ((arr + i)->nomor == key)
            return i;
    }

    return -1;
}

void merge(Kereta *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Kereta L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = *(arr + l + i);
    for (int j = 0; j < n2; j++)
        R[j] = *(arr + m + 1 + j);

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].nama <= R[j].nama)
            *(arr + k++) = L[i++];
        else
            *(arr + k++) = R[j++];
    }

    while (i < n1)
        *(arr + k++) = L[i++];

    while (j < n2)
        *(arr + k++) = R[j++];
}

void mergeSort(Kereta *arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void selectionSort(Kereta *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + min)->harga)
                min = j;
        }
        swapKereta(arr + i, arr + min);
    }
}

int main() {
    Kereta data[100] = {
        {201, "Mahakam", "Samarinda", "Balikpapan", 120000},
        {202, "Borneo", "Balikpapan", "Bontang", 100000},
        {203, "Kaltim Express", "Samarinda", "Sangatta", 150000}
    };

    int n = 3;
    int pilihan;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tampil Data\n";
        cout << "2. Tambah Data\n";
        cout << "3. Linear Search (Rute)\n";
        cout << "4. Jump Search (Nomor)\n";
        cout << "5. Merge Sort (Nama)\n";
        cout << "6. Selection Sort (Harga)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            tampil(data, n);
        }
        else if (pilihan == 2) {
            tambah(data, n);
        }
        else if (pilihan == 3) {
            string asal, tujuan;
            cout << "Asal: "; cin >> asal;
            cout << "Tujuan: "; cin >> tujuan;
            linearSearch(data, n, asal, tujuan);
        }
        else if (pilihan == 4) {
            int key;
            cout << "Nomor Kereta: ";
            cin >> key;

            int idx = jumpSearch(data, n, key);
            if (idx != -1)
                cout << "Ditemukan: " << (data + idx)->nama << endl;
            else
                cout << "Tidak ditemukan\n";
        }
        else if (pilihan == 5) {
            mergeSort(data, 0, n - 1);
            cout << "Data berhasil diurutkan (Nama A-Z)\n";
        }
        else if (pilihan == 6) {
            selectionSort(data, n);
            cout << "Data berhasil diurutkan (Harga termurah)\n";
        }

    } while (pilihan != 0);

    return 0;
}