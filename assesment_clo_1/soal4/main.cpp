#include "QueuePengiriman.h"
#include <iostream>

using namespace std;

Paket inputPaket() {
    Paket p;
    cout << "Input Kode Resi: "; cin >> p.KodeResi;
    cout << "Input Nama Pengirim: "; cin.ignore(); getline(cin, p.NamaPengirim);
    cout << "Input Berat Barang (kg): "; cin >> p.BeratBarang;
    cout << "Input Tujuan: "; cin.ignore(); getline(cin, p.Tujuan);
    return p;
}

Paket createPaket(string resi, string pengirim, int berat, string tujuan) {
    Paket p;
    p.KodeResi = resi;
    p.NamaPengirim = pengirim;
    p.BeratBarang = berat;
    p.Tujuan = tujuan;
    return p;
}

void runStaticOperations(QueueEkspedisi& Q) {
    cout << "\n--- LANGKAH 1: CREATE QUEUE ---" << endl;
    createQueue(Q);

    cout << "\n--- LANGKAH 2: INPUT 5 DATA PAKET (ENQUEUE) ---" << endl;
    
    enQueue(Q, createPaket("123456", "Hutao", 14, "Sumeru")); 
    enQueue(Q, createPaket("234567", "Ayaka", 7, "Fontaine")); 
    enQueue(Q, createPaket("345678", "Bennet", 7, "Natlan")); 
    enQueue(Q, createPaket("456789", "Furina", 16, "Liyue")); 
    enQueue(Q, createPaket("567890", "Nefer", 8, "Inazuma")); 
    
    cout << "\n--- LANGKAH 3: TAMPILKAN QUEUE AWAL ---" << endl;
    viewQueue(Q);

    cout << "\n--- LANGKAH 4: LAKUKAN DEQUEUE 1X ---" << endl;
    deQueue(Q);

    cout << "\n--- LANGKAH 5: TAMPILKAN QUEUE SETELAH DEQUEUE ---" << endl;
    viewQueue(Q);
}

int main() {
    QueueEkspedisi Q;
    int choice;

    runStaticOperations(Q);

    do {
        cout << "\n=====================================" << endl;
        cout << "           Komanaiya Express           " << endl;
        cout << "=====================================" << endl;
        cout << "1. Input Data Paket (enQueue)" << endl;
        cout << "2. Hapus Data Paket (deQueue)" << endl;
        cout << "3. Tampilkan Queue Paket" << endl;
        cout << "4. Hitung Total Biaya Pengiriman" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan anda: ";

        if (!(cin >> choice)) {
            cout << "Input tidak valid. Harap masukkan angka." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                if (!isFull(Q)) {
                    Paket p = inputPaket();
                    enQueue(Q, p);
                } else {
                    cout << "Queue Penuh! Tidak bisa menambah data." << endl;
                }
                break;
            case 2:
                deQueue(Q);
                break;
            case 3:
                viewQueue(Q);
                break;
            case 4:
                TotalBiayaPengiriman(Q);
                break;
            case 0:
                cout << "Keluar dari program. Terima kasih." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 0);

    return 0;
}