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

struct Tiket {
    string namaPenumpang;
    string rute;
};

struct Queue {
    Tiket data[100];
    int front = 0, rear = -1;
};

void enqueue(Queue *q, Tiket t) {
    if (q->rear == 99) {
        cout << "Antrian penuh!\n";
        return;
    }
    q->data[++q->rear] = t;
    cout << "Penumpang masuk antrian!\n";
}

Tiket dequeue(Queue *q) {
    if (q->front > q->rear) {
        cout << "Antrian kosong!\n";
        return {"", ""};
    }
    return q->data[q->front++];
}

void tampilQueue(Queue *q) {
    if (q->front > q->rear) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "\n=== ANTRIAN TIKET ===\n";
    for (int i = q->front; i <= q->rear; i++) {
        cout << (q->data + i)->namaPenumpang << " | "
             << (q->data + i)->rute << endl;
    }
}

void peekQueue(Queue *q) {
    if (q->front > q->rear) {
        cout << "Antrian kosong!\n";
        return;
    }
    cout << "Terdepan: " << (q->data + q->front)->namaPenumpang
         << " | " << (q->data + q->front)->rute << endl;
}

struct Stack {
    Tiket data[100];
    int top = -1;
};

void push(Stack *s, Tiket t) {
    if (s->top == 99) {
        cout << "Riwayat penuh!\n";
        return;
    }
    s->data[++s->top] = t;
}

void pop(Stack *s) {
    if (s->top == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }
    cout << "Hapus transaksi: "
         << (s->data + s->top)->namaPenumpang << endl;
    s->top--;
}

void tampilStack(Stack *s) {
    if (s->top == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "\n=== RIWAYAT TRANSAKSI ===\n";
    for (int i = s->top; i >= 0; i--) {
        cout << (s->data + i)->namaPenumpang << " | "
             << (s->data + i)->rute << endl;
    }
}

void peekStack(Stack *s) {
    if (s->top == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }
    cout << "Transaksi terakhir: "
         << (s->data + s->top)->namaPenumpang
         << " | " << (s->data + s->top)->rute << endl;
}

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

int main() {
    Kereta data[100] = {
        {201, "Mahakam", "Samarinda", "Balikpapan", 120000},
        {202, "Borneo", "Balikpapan", "Bontang", 100000},
        {203, "KaltimExpress", "Samarinda", "Sangatta", 150000}
    };

    int n = 3;
    Queue antrian;
    Stack riwayat;

    int pilihan;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tampil Kereta\n";
        cout << "2. Ambil Tiket (Enqueue)\n";
        cout << "3. Proses Tiket (Dequeue)\n";
        cout << "4. Tampil Antrian\n";
        cout << "5. Tampil Riwayat\n";
        cout << "6. Hapus Riwayat (Pop)\n";
        cout << "7. Peek (Antrian & Riwayat)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            tampil(data, n);
        }
        else if (pilihan == 2) {
            Tiket t;
            cout << "Nama Penumpang: ";
            cin >> t.namaPenumpang;

            string asal, tujuan;
            cout << "Asal: "; cin >> asal;
            cout << "Tujuan: "; cin >> tujuan;

            t.rute = asal + "->" + tujuan;
            enqueue(&antrian, t);
        }
        else if (pilihan == 3) {
            Tiket t = dequeue(&antrian);
            if (t.namaPenumpang != "") {
                cout << "Diproses: " << t.namaPenumpang
                     << " | " << t.rute << endl;

                push(&riwayat, t);
            }
        }
        else if (pilihan == 4) {
            tampilQueue(&antrian);
        }
        else if (pilihan == 5) {
            tampilStack(&riwayat);
        }
        else if (pilihan == 6) {
            pop(&riwayat);
        }
        else if (pilihan == 7) {
            cout << "\n--- PEEK ---\n";
            peekQueue(&antrian);
            peekStack(&riwayat);
        }

    } while (pilihan != 0);

    return 0;
}