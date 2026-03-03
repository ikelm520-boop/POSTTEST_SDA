#include <iostream>
using namespace std;

/*
Analisis Singkat Kompleksitas Waktu

Program ini bertujuan mencari angka paling kecil
di dalam sebuah array sekaligus mengetahui posisinya.

Alur kerja:
- Ambil elemen pertama sebagai nilai awal terkecil.
- Lakukan perulangan dari indeks ke-1 sampai akhir.
- Bandingkan setiap elemen dengan nilai terkecil saat ini.
- Jika ditemukan yang lebih kecil, maka update nilainya.

Karena perulangan selalu berjalan sebanyak (n-1),
baik data sudah terurut maupun tidak,
maka kompleksitas waktunya adalah O(n).

Kesimpulan:
Semakin besar jumlah data (n),
maka waktu eksekusi bertambah secara linear.
*/

int cariMinimum(int arr[], int size, int &posisiMin){
    int nilaiMin = arr[0];   // anggap elemen pertama paling kecil
    posisiMin = 0;

    for(int i = 1; i < size; i++){
        if(arr[i] < nilaiMin){
            nilaiMin = arr[i];
            posisiMin = i;
        }
    }

    return nilaiMin;
}

int main(){
    int dataAngka[] = {1, 1, 2, 3, 5, 8, 13, 21};
    int panjangData = sizeof(dataAngka) / sizeof(dataAngka[0]);
    int letakMin;

    int hasil = cariMinimum(dataAngka, panjangData, letakMin);

    cout << "Hasil Pencarian Nilai Minimum" << endl;
    cout << "-------------------------------" << endl;
    cout << "Nilai terkecil : " << hasil << endl;
    cout << "Index ke       : " << letakMin << endl;

    return 0;
}