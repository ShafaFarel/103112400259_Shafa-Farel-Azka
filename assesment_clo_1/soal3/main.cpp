#include "StackMahasiswa.h"
#include <iostream>

using namespace std;

Mahasiswa createMahasiswa(string nama, string nim, float tugas, float uts, float uas) {
    Mahasiswa mhs;
    mhs.Nama = nama;
    mhs.NIM = nim;
    mhs.NilaiTugas = tugas;
    mhs.NilaiUTS = uts;
    mhs.NilaiUAS = uas;
    return mhs;
}

int main() {
    StackMahasiswa S;

    cout << "--- LANGKAH 1: CREATE STACK ---" << endl;
    createStack(S);

    cout << "\n--- LANGKAH 2: INPUT 6 DATA MAHASISWA (PUSH) ---" << endl;
    
    Push(S, createMahasiswa("Venti", "11111", 75.7, 82.1, 65.5)); 
    Push(S, createMahasiswa("Xiao", "22222", 87.4, 88.9, 81.9)); 
    Push(S, createMahasiswa("Kazuha", "33333", 92.3, 88.8, 82.4)); 
    Push(S, createMahasiswa("Wanderer", "44444", 95.5, 85.5, 90.5)); 
    Push(S, createMahasiswa("Lynette", "55555", 77.7, 99.6, 99.6)); 
    Push(S, createMahasiswa("Chasca", "66666", 99.9, 93.6, 87.3)); 

    cout << "\n--- LANGKAH 3: TAMPILKAN STACK AWAL ---" << endl;
    View(S);

    cout << "\n--- LANGKAH 4: LAKUKAN POP 1X (Chasca) ---" << endl;
    Pop(S);

    cout << "\n--- LANGKAH 5: TAMPILKAN STACK SETELAH POP ---" << endl;
    View(S);

    cout << "\n--- LANGKAH 6: UPDATE DATA PADA POSISI KE-3 ---" << endl;
    Mahasiswa newHeizou = createMahasiswa("Heizou", "77777", 99.9, 88.8, 77.7);
    Update(S, 3, newHeizou);

    cout << "\n--- LANGKAH 7: TAMPILKAN STACK SETELAH UPDATE ---" << endl;
    View(S);

    cout << "\n--- LANGKAH 8: SEARCHING NILAI AKHIR (85.5 - 95.5) ---" << endl;
    SearchNilaiAkhir(S, 85.5, 95.5);

    cout << "\n--- BAGIAN B: MAX NILAI AKHIR ---" << endl;
    MaxNilaiAkhir(S);

    return 0;
}