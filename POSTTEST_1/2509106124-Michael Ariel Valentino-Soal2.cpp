#include <iostream>
using namespace std;


struct Mahasiswa {
    string namaLengkap;
    string nomorInduk;
    double nilaiIPK;
};

int main() {
    const int totalData = 5;   
    Mahasiswa daftarMhs[totalData];

    
    for (int index = 0; index < totalData; index++) {
        cout << "Input Data Mahasiswa Ke-" << index + 1 << endl;
        
        cout << "Nama Lengkap : ";
        getline(cin, daftarMhs[index].namaLengkap);

        cout << "NIM          : ";
        getline(cin, daftarMhs[index].nomorInduk);

        cout << "IPK          : ";
        cin >> daftarMhs[index].nilaiIPK;
        cin.ignore(); 
        
        cout << endl;
    }


    int indeksTerbaik = 0; 

    for (int i = 1; i < totalData; i++) {
        if (daftarMhs[i].nilaiIPK > daftarMhs[indeksTerbaik].nilaiIPK) {
            indeksTerbaik = i;
        }
    }

    
    cout << "\n=== DAFTAR DATA MAHASISWA ===" << endl;
    cout << string(45, '=') << endl;

    for (int i = 0; i < totalData; i++) {
        cout << "Nama : " << daftarMhs[i].namaLengkap << endl;
        cout << "NIM  : " << daftarMhs[i].nomorInduk << endl;
        cout << "IPK  : " << daftarMhs[i].nilaiIPK << endl;
        cout << string(45, '-') << endl;
    }

    
    cout << "\nMahasiswa Dengan IPK Paling Tinggi" << endl;
    cout << string(45, '=') << endl;

    cout << "Nama : " << daftarMhs[indeksTerbaik].namaLengkap << endl;
    cout << "NIM  : " << daftarMhs[indeksTerbaik].nomorInduk << endl;
    cout << "IPK  : " << daftarMhs[indeksTerbaik].nilaiIPK << endl;

    return 0;
}