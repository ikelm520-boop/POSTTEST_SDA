#include <iostream>
#include <iomanip>
using namespace std;

void balikArray(int* data, int jumlah) {
    int* depan = data;              
    int* belakang = data + jumlah - 1; 

    while (depan < belakang) {
        int sementara = *depan;
        *depan = *belakang;
        *belakang = sementara;

        depan++;     
        belakang--;   
    }
}

int main() {
    int angkaPrima[7] = {2, 3, 5, 7, 11, 13, 17};
    int dataAwal[7];
    int totalElemen = 7;


    for (int k = 0; k < totalElemen; k++) {
        dataAwal[k] = angkaPrima[k];
    }


    balikArray(angkaPrima, totalElemen);

    cout << left << setw(40) << "DATA SEBELUM DIBALIK";
    cout << "DATA SETELAH DIBALIK" << endl;
    cout << string(80, '=') << endl;

    for (int k = 0; k < totalElemen; k++) {
        cout << left << setw(12) << ("Posisi: " + to_string(k));
        cout << setw(12) << ("Isi: " + to_string(dataAwal[k]));
        cout << setw(18) << ("Alamat: " + to_string((long long)&dataAwal[k]));

        cout << setw(12) << ("Posisi: " + to_string(k));
        cout << setw(12) << ("Isi: " + to_string(angkaPrima[k]));
        cout << ("Alamat: " + to_string((long long)&angkaPrima[k])) << endl;
    }

    return 0;
}