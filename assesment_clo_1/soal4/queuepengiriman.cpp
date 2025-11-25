#include "QueuePengiriman.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int BIAYA_PER_KG = 8250;

bool isEmpty(const QueueEkspedisi& Q) {
    return Q.Head == -1 && Q.Tail == -1;
}

bool isFull(const QueueEkspedisi& Q) {
    return Q.Tail == MAX - 1;
}

void createQueue(QueueEkspedisi& Q) {
    Q.Head = -1;
    Q.Tail = -1;
    cout << "Queue berhasil dibuat." << endl;
}

void enQueue(QueueEkspedisi& Q, const Paket& newData) {
    if (isFull(Q)) {
        cout << "Error: Queue penuh! Tidak dapat melakukan enQueue." << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.Head = 0;
        Q.Tail = 0;
    } else {
        Q.Tail++;
    }

    Q.dataPaket[Q.Tail] = newData;
    cout << "Paket " << newData.KodeResi << " berhasil di-enQueue." << endl;
}

void deQueue(QueueEkspedisi& Q) {
    if (isEmpty(Q)) {
        cout << "Error: Queue kosong! Tidak dapat melakukan deQueue." << endl;
        return;
    }

    Paket deQueuedData = Q.dataPaket[Q.Head];

    if (Q.Head == Q.Tail) {
        createQueue(Q); 
    } else {
        for (int i = Q.Head; i < Q.Tail; i++) {
            Q.dataPaket[i] = Q.dataPaket[i + 1];
        }
        Q.Tail--;
    }
    cout << "DeQueue berhasil. Paket terdepan (" << deQueuedData.KodeResi << ") dihapus." << endl;
}

void viewQueue(const QueueEkspedisi& Q) {
    if (isEmpty(Q)) {
        cout << "\nQueue kosong. Tidak ada data yang ditampilkan." << endl;
        return;
    }

    cout << "\n--- ISI QUEUE PAKET (HEAD -> TAIL) ---" << endl;
    cout << setiosflags(ios::left) << setw(5) << "No."
         << setw(15) << "Kode Resi"
         << setw(20) << "Nama Pengirim"
         << setw(10) << "Berat (kg)"
         << setw(20) << "Tujuan" << endl;
    cout << string(70, '-') << endl;

    for (int i = Q.Head; i <= Q.Tail; ++i) {
        cout << setw(5) << i + 1
             << setw(15) << Q.dataPaket[i].KodeResi
             << setw(20) << Q.dataPaket[i].NamaPengirim
             << setw(10) << Q.dataPaket[i].BeratBarang
             << setw(20) << Q.dataPaket[i].Tujuan << endl;
    }
    cout << string(70, '-') << endl;
}

void TotalBiayaPengiriman(const QueueEkspedisi& Q) {
    if (isEmpty(Q)) {
        cout << "\nQueue kosong. Total biaya Rp 0." << endl;
        return;
    }

    long long totalBiaya = 0;

    for (int i = Q.Head; i <= Q.Tail; ++i) {
        totalBiaya += (long long)Q.dataPaket[i].BeratBarang * BIAYA_PER_KG;
    }

    cout << "\n--- TOTAL BIAYA PENGIRIMAN ---" << endl;
    cout << "Biaya per 1 kg: Rp " << BIAYA_PER_KG << endl;
    cout << "Total Biaya Semua Paket: Rp " << totalBiaya << endl;
    cout << "---------------------------------" << endl;
}