#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int MAX = 6;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top; 
};

// Deklarasi (Prototipe Fungsi)
bool isEmpty(const StackMahasiswa& S);
bool isFull(const StackMahasiswa& S);
void createStack(StackMahasiswa& S);
void Push(StackMahasiswa& S, const Mahasiswa& newData);
void Pop(StackMahasiswa& S);
void View(const StackMahasiswa& S);
float hitungNilaiAkhir(const Mahasiswa& mhs); 

// Perhatikan: Fungsi Update harus menerima 3 parameter
void Update(StackMahasiswa& S, int posisi, const Mahasiswa& newData); 
void SearchNilaiAkhir(const StackMahasiswa& S, float NilaiAkhirMin, float NilaiAkhirMax);
void MaxNilaiAkhir(const StackMahasiswa& S); 

#endif // STACKMAHASISWA_H