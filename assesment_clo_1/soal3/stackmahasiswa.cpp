#include "StackMahasiswa.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Implementasi fungsi-fungsi dasar (isEmpty, isFull, createStack, Push, Pop, dll)

bool isEmpty(const StackMahasiswa& S) {
    return S.Top == -1;
}

bool isFull(const StackMahasiswa& S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa& S) {
    S.Top = -1;
}

void Push(StackMahasiswa& S, const Mahasiswa& newData) {
    if (isFull(S)) {
        cout << "Error: Stack penuh, tidak dapat menambah data." << endl;
        return;
    }
    S.Top++;
    S.dataMahasiswa[S.Top] = newData;
    cout << "Push berhasil: " << newData.Nama << " pada posisi " << S.Top + 1 << endl;
}

void Pop(StackMahasiswa& S) {
    if (isEmpty(S)) {
        cout << "Error: Stack kosong, tidak ada yang bisa di-pop." << endl;
        return;
    }
    Mahasiswa popped = S.dataMahasiswa[S.Top];
    cout << "Pop berhasil: " << popped.Nama << " (posisi " << S.Top + 1 << ")" << endl;
    S.Top--;
}

float hitungNilaiAkhir(const Mahasiswa& mhs) {
    return 0.20 * mhs.NilaiTugas + 0.40 * mhs.NilaiUTS + 0.40 * mhs.NilaiUAS;
}

// Implementasi Update dengan 3 argumen
void Update(StackMahasiswa& S, int posisi, const Mahasiswa& newData) {
    if (isEmpty(S)) {
        cout << "Error: Stack kosong, tidak ada yang bisa di-update." << endl;
        return;
    }

    int index = posisi - 1; 

    if (index < 0 || index > S.Top) {
        cout << "Error: Posisi " << posisi << " tidak valid atau di luar batas stack saat ini." << endl;
        return;
    }

    S.dataMahasiswa[index] = newData;
    cout << "\nUpdate berhasil pada posisi " << posisi << " dengan data " << newData.Nama << "." << endl;
}

// Implementasi View dan SearchNilaiAkhir

void View(const StackMahasiswa& S) {
    if (isEmpty(S)) {
        cout << "\nStack kosong." << endl;
        return;
    }
    cout << "\n===== ISI STACK (ATAS -> BAWAH) =====" << endl;
    for (int i = S.Top; i >= 0; --i) {
        const Mahasiswa& m = S.dataMahasiswa[i];
        cout << "Posisi " << i + 1 << ": " << m.Nama << " | NIM: " << m.NIM
             << " | Nilai Akhir: " << fixed << setprecision(2) << hitungNilaiAkhir(m) << endl;
    }
}

void SearchNilaiAkhir(const StackMahasiswa& S, float NilaiAkhirMin, float NilaiAkhirMax) {
    if (isEmpty(S)) {
        cout << "\nStack kosong. Tidak ada data untuk dicari." << endl;
        return;
    }
    cout << "\nHasil pencarian nilai akhir antara " << NilaiAkhirMin << " - " << NilaiAkhirMax << ":" << endl;
    bool found = false;
    for (int i = S.Top; i >= 0; --i) {
        float nilai = hitungNilaiAkhir(S.dataMahasiswa[i]);
        if (nilai >= NilaiAkhirMin && nilai <= NilaiAkhirMax) {
            const Mahasiswa& m = S.dataMahasiswa[i];
            cout << "Posisi " << i + 1 << ": " << m.Nama << " | NIM: " << m.NIM
                 << " | Nilai Akhir: " << fixed << setprecision(2) << nilai << endl;
            found = true;
        }
    }
    if (!found) cout << "Tidak ada mahasiswa dengan rentang nilai tersebut." << endl;
}

// Implementasi MaxNilaiAkhir (Bagian B)
void MaxNilaiAkhir(const StackMahasiswa& S) {
    if (isEmpty(S)) {
        cout << "\nStack kosong. Tidak dapat menentukan nilai akhir terbesar." << endl;
        return;
    }

    float maxNilai = -1.0;
    int maxPosisi = -1; 
    Mahasiswa maxMHS;

    for (int i = S.Top; i >= 0; --i) {
        float nilaiAkhir = hitungNilaiAkhir(S.dataMahasiswa[i]);
        
        if (nilaiAkhir > maxNilai) {
            maxNilai = nilaiAkhir;
            maxPosisi = i + 1;
            maxMHS = S.dataMahasiswa[i];
        }
    }

    cout << "\n=====================================" << endl;
    cout << "  MAHASISWA DENGAN NILAI AKHIR TERBESAR" << endl;
    cout << "=====================================" << endl;
    cout << "Nama           : " << maxMHS.Nama << endl;
    cout << "NIM            : " << maxMHS.NIM << endl;
    cout << "Nilai Akhir    : " << fixed << setprecision(2) << maxNilai << endl;
    cout << "Posisi Stack   : " << maxPosisi << endl;
    cout << "=====================================" << endl;
}