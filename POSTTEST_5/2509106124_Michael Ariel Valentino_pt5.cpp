#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Circular Linked List Perpustakaan
struct BukuNode {
    string judulBuku;
    BukuNode* next;

    BukuNode(string judul) {
        judulBuku = judul;
        next = nullptr;
    }
};

BukuNode* tambahBuku(BukuNode* head, string judul) {
    try {
        if (judul.empty()) {
            throw string("Judul buku tidak boleh kosong!");
        }

        BukuNode* newNode = new BukuNode(judul);

        if (head == nullptr) {
            newNode->next = newNode;
            return newNode;
        }

        BukuNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;

        return head;
    } 
    catch (string e) {
        cout << "Error tambah buku: " << e << endl;
        return head;
    }
}

bool cariBuku(BukuNode* head, string judulDicari) {
    try {
        if (head == nullptr) {
            throw string("List kosong, tidak ada buku!");
        }

        if (judulDicari.empty()) {
            throw string("Judul yang dicari tidak boleh kosong!");
        }

        BukuNode* temp = head;

        do {
            if (temp->judulBuku == judulDicari) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);

        return false;
    } 
    catch (string e) {
        cout << "Error cari buku: " << e << endl;
        return false;
    }
}

void tampilkanBuku(BukuNode* head) {
    if (head == nullptr) {
        cout << "Daftar buku kosong.\n";
        return;
    }

    BukuNode* temp = head;
    cout << "Daftar Buku:\n";
    do {
        cout << "- " << temp->judulBuku << endl;
        temp = temp->next;
    } while (temp != head);
}

int main() {
    BukuNode* head = nullptr;

    // Tambah buku
    head = tambahBuku(head, "Struktur Data dengan C++");
    head = tambahBuku(head, "Pengantar Algoritma");
    head = tambahBuku(head, "Pemrograman Berorientasi Objek");
    head = tambahBuku(head, "Sistem Basis Data");

    tampilkanBuku(head);

    cout << endl;

    string buku1 = "Pengantar Algoritma";
    string buku2 = "Kalkulus Lanjut";

    cout << "Mencari buku '" << buku1 << "': "
         << (cariBuku(head, buku1) ? "Ditemukan" : "Tidak Ditemukan") << endl;

    cout << "Mencari buku '" << buku2 << "': "
         << (cariBuku(head, buku2) ? "Ditemukan" : "Tidak Ditemukan") << endl;

    return 0;
}