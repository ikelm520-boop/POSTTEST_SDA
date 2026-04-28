#include <iostream>
#include <string>
using namespace std;

// ============================================================
// STRUKTUR NODE
// Setiap node menyimpan satu judul buku dan pointer ke node
// berikutnya. Karena circular, node terakhir akan menunjuk
// kembali ke node pertama (head).
// ============================================================
struct BukuNode {
    string judulBuku;   // Menyimpan judul buku
    BukuNode* next;     // Pointer ke node berikutnya

    // Constructor: inisialisasi node dengan judul yang diberikan
    // dan set next ke nullptr (belum terhubung ke node manapun)
    BukuNode(string judul) {
        judulBuku = judul;
        next = nullptr;
    }
};

// ============================================================
// FUNGSI: tambahBuku
// Menambahkan buku baru di AKHIR circular linked list.
// Mengembalikan pointer head (bisa berubah jika list awalnya
// kosong).
// ============================================================
BukuNode* tambahBuku(BukuNode* head, string judul) {
    try {
        // Validasi: judul tidak boleh string kosong
        if (judul.empty()) {
            throw string("Judul buku tidak boleh kosong!");
        }

        // Buat node baru dengan judul yang diberikan
        BukuNode* newNode = new BukuNode(judul);

        // Kasus 1: List masih kosong
        // Node baru menjadi satu-satunya elemen, dan next-nya
        // menunjuk ke dirinya sendiri membentuk lingkaran
        if (head == nullptr) {
            newNode->next = newNode; // Circular: tunjuk diri sendiri
            return newNode;          // Node baru menjadi head
        }

        // Kasus 2: List sudah ada isinya
        // Traversal dari head sampai menemukan node terakhir
        // (node terakhir ditandai dengan next-nya == head)
        BukuNode* temp = head;
        while (temp->next != head) {
            temp = temp->next; // Maju ke node berikutnya
        }

        // Sambungkan node terakhir ke node baru
        temp->next = newNode;

        // Tutup lingkaran: node baru menunjuk kembali ke head
        newNode->next = head;

        // Head tidak berubah, kembalikan head yang lama
        return head;
    } 
    catch (const string& e) {
        // Tangkap error validasi dan tampilkan pesannya
        cout << "Error tambah buku: " << e << endl;
        return head; // Kembalikan head tanpa perubahan
    }
}

// ============================================================
// FUNGSI: cariBuku
// Mencari buku berdasarkan judul dalam circular linked list.
// Mengembalikan true jika ditemukan, false jika tidak.
// ============================================================
bool cariBuku(BukuNode* head, const string& judulDicari) {
    try {
        // Validasi: tidak bisa mencari di list yang kosong
        if (head == nullptr) {
            throw string("List kosong, tidak ada buku!");
        }

        // Validasi: judul yang dicari tidak boleh kosong
        if (judulDicari.empty()) {
            throw string("Judul yang dicari tidak boleh kosong!");
        }

        BukuNode* temp = head; // Mulai dari node pertama (head)

        // Gunakan do-while agar head ikut dicek di iterasi pertama
        // (jika pakai while biasa, head akan terlewat)
        do {
            // Cek apakah judul node saat ini cocok dengan yang dicari
            if (temp->judulBuku == judulDicari) {
                return true; // Buku ditemukan, hentikan pencarian
            }
            temp = temp->next; // Pindah ke node berikutnya
        } while (temp != head); // Berhenti saat sudah kembali ke head

        // Semua node sudah dicek, buku tidak ada di list
        return false;
    } 
    catch (const string& e) {
        // Tangkap error validasi dan tampilkan pesannya
        cout << "Error cari buku: " << e << endl;
        return false;
    }
}

// ============================================================
// FUNGSI: tampilkanBuku
// Mencetak semua judul buku dalam circular linked list
// secara berurutan dari head hingga kembali ke head.
// ============================================================
void tampilkanBuku(BukuNode* head) {
    // Jika list kosong, tampilkan pesan dan langsung keluar
    if (head == nullptr) {
        cout << "Daftar buku kosong.\n";
        return;
    }

    BukuNode* temp = head; // Mulai traversal dari head
    cout << "Daftar Buku:\n";

    // do-while agar node pertama (head) ikut ditampilkan
    do {
        cout << "- " << temp->judulBuku << endl;
        temp = temp->next; // Maju ke node berikutnya
    } while (temp != head); // Berhenti saat sudah kembali ke head
}

// ============================================================
// FUNGSI: hapusSemua
// Membersihkan seluruh memori yang dialokasikan oleh list
// untuk mencegah memory leak saat program selesai.
// ============================================================
void hapusSemua(BukuNode*& head) {
    if (head == nullptr) return; // List sudah kosong, tidak perlu hapus

    BukuNode* curr = head->next; // Mulai dari node setelah head

    // Hapus semua node kecuali head terlebih dahulu
    while (curr != head) {
        BukuNode* temp = curr;   // Simpan node yang akan dihapus
        curr = curr->next;        // Maju dulu sebelum dihapus
        delete temp;              // Bebaskan memori node tersebut
    }

    delete head;    // Hapus node head terakhir
    head = nullptr; // Set head ke nullptr, list kini benar-benar kosong
}

// ============================================================
// FUNGSI MAIN
// Entry point program: mendemonstrasikan operasi tambah,
// tampil, dan cari pada circular linked list buku.
// ============================================================
int main() {
    BukuNode* head = nullptr; // Inisialisasi list kosong

    // Tambahkan 4 buku ke dalam list secara berurutan
    head = tambahBuku(head, "Struktur Data dengan C++");
    head = tambahBuku(head, "Pengantar Algoritma");
    head = tambahBuku(head, "Pemrograman Berorientasi Objek");
    head = tambahBuku(head, "Sistem Basis Data");

    // Tampilkan seluruh isi list setelah penambahan
    tampilkanBuku(head);

    cout << endl;

    // Definisikan judul yang akan dicari
    string buku1 = "Pengantar Algoritma"; // Buku yang ada di list
    string buku2 = "Kalkulus Lanjut";     // Buku yang tidak ada di list

    // Cari buku1 dan tampilkan hasilnya
    cout << "Mencari buku '" << buku1 << "': "
         << (cariBuku(head, buku1) ? "Ditemukan" : "Tidak Ditemukan") << endl;

    // Cari buku2 dan tampilkan hasilnya
    cout << "Mencari buku '" << buku2 << "': "
         << (cariBuku(head, buku2) ? "Ditemukan" : "Tidak Ditemukan") << endl;

    // Bersihkan semua memori sebelum program berakhir
    hapusSemua(head);

    return 0; // Program selesai dengan sukses
}