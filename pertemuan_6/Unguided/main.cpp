#include "DoublyList.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    infotype dataKendaraan;
    address P;

    for (int i = 1; i <= 3; i++) {
        cout << "\nmasukkan nomor polisi: ";
        cin >> dataKendaraan.nopol;

        if (isNopolExist(L, dataKendaraan.nopol)) {
            cout << "nomor polisi sudah terdaftar" << endl;
            i--;
            continue;
        }

        cout << "masukkan warna kendaraan: ";
        cin >> dataKendaraan.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> dataKendaraan.thnBuat;

        P = alokasi(dataKendaraan);
        insertLast(L, P);
    }

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    
    string cari;
    cout << "\nMasukkan Nomor Polisi yang dicari : ";
    cin >> cari;

    address hasil = findElm(L, cari);
    cout << endl;

    if (hasil != Nil) {
        cout << "Nomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna        : " << hasil->info.warna << endl;
        cout << "Tahun Buat   : " << hasil->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }

     string hapusNopol;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol;

    address hapus = L.First;
    address prec = Nil;

    while (hapus != Nil && hapus->info.nopol != hapusNopol) {
        prec = hapus;
        hapus = hapus->next;
    }

    if (hapus == Nil) {
        cout << "Data dengan nomor polisi " << hapusNopol << " tidak ditemukan." << endl;
    } else {
        if (hapus == L.First) {
            deleteFirst(L, hapus);
        } else if (hapus == L.Last) {
            deleteLast(L, hapus);
        } else {
            deleteAfter(prec, hapus);
        }
        dealokasi(hapus);
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus." << endl;
    }

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    return 0;
}
