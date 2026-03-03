#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;

    cout << "Input bilangan pertama : ";
    cin >> angka1;
    cout << "Input bilangan kedua   : ";
    cin >> angka2;

    cout << "\n========================================\n";
    cout << "Nilai sebelum ditukar\n";
    cout << "========================================\n";
    cout << "angka1 = " << angka1 << endl;
    cout << "angka2 = " << angka2 << endl;

    int &ref1 = angka1;
    int &ref2 = angka2;

    int sementara = ref1;
    ref1 = ref2;
    ref2 = sementara;

    cout << "\n========================================\n";
    cout << "Nilai setelah ditukar\n";
    cout << "========================================\n";
    cout << "angka1 = " << angka1 << endl;
    cout << "angka2 = " << angka2 << endl;

    return 0;
}