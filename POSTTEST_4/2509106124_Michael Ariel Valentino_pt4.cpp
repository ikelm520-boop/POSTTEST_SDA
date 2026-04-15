#include <iostream>
using namespace std;

struct Tiket {
    string namaPenumpang;
    string rute;
    Tiket* next;
};

struct Queue {
    Tiket *front = NULL;
    Tiket *rear = NULL;
};

void enqueue(Queue *q, string nama, string rute) {
    Tiket *baru = new Tiket{nama, rute, NULL};

    if (q->rear == NULL) {
        q->front = q->rear = baru;
    } else {
        q->rear->next = baru;
        q->rear = baru;
    }

    cout << "Penumpang masuk antrian!\n";
}

Tiket* dequeue(Queue *q) {
    if (q->front == NULL) {
        cout << "Antrian kosong!\n";
        return NULL;
    }

    Tiket *hapus = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return hapus;
}

void peekQueue(Queue *q) {
    if (q->front == NULL) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "Terdepan: " << q->front->namaPenumpang
         << " | " << q->front->rute << endl;
}

void tampilQueue(Queue *q) {
    if (q->front == NULL) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "\n=== ANTRIAN ===\n";
    Tiket *temp = q->front;

    while (temp != NULL) {
        cout << temp->namaPenumpang << " | "
             << temp->rute << endl;
        temp = temp->next;
    }
}

struct Stack {
    Tiket *top = NULL;
};

void push(Stack *s, string nama, string rute) {
    Tiket *baru = new Tiket{nama, rute, NULL};

    baru->next = s->top;
    s->top = baru;
}

void pop(Stack *s) {
    if (s->top == NULL) {
        cout << "Riwayat kosong!\n";
        return;
    }

    Tiket *hapus = s->top;
    cout << "Hapus transaksi: "
         << hapus->namaPenumpang << endl;

    s->top = s->top->next;
    delete hapus;
}

void peekStack(Stack *s) {
    if (s->top == NULL) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "Transaksi terakhir: "
         << s->top->namaPenumpang
         << " | " << s->top->rute << endl;
}

void tampilStack(Stack *s) {
    if (s->top == NULL) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "\n=== RIWAYAT ===\n";
    Tiket *temp = s->top;

    while (temp != NULL) {
        cout << temp->namaPenumpang << " | "
             << temp->rute << endl;
        temp = temp->next;
    }
}

int main() {
    Queue antrian;
    Stack riwayat;

    int pilihan;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Ambil Tiket (Enqueue)\n";
        cout << "2. Proses Tiket (Dequeue)\n";
        cout << "3. Tampil Antrian\n";
        cout << "4. Tampil Riwayat\n";
        cout << "5. Hapus Riwayat (Pop)\n";
        cout << "6. Peek\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string nama, asal, tujuan;

            cout << "Nama: ";
            cin >> nama;
            cout << "Asal: ";
            cin >> asal;
            cout << "Tujuan: ";
            cin >> tujuan;

            string rute = asal + "->" + tujuan;
            enqueue(&antrian, nama, rute);
        }
        else if (pilihan == 2) {
            Tiket *t = dequeue(&antrian);

            if (t != NULL) {
                cout << "Diproses: "
                     << t->namaPenumpang
                     << " | " << t->rute << endl;

                push(&riwayat, t->namaPenumpang, t->rute);
                delete t;
            }
        }
        else if (pilihan == 3) {
            tampilQueue(&antrian);
        }
        else if (pilihan == 4) {
            tampilStack(&riwayat);
        }
        else if (pilihan == 5) {
            pop(&riwayat);
        }
        else if (pilihan == 6) {
            cout << "\n--- PEEK ---\n";
            peekQueue(&antrian);
            peekStack(&riwayat);
        }

    } while (pilihan != 0);

    return 0;
}