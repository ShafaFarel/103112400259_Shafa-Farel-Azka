# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Shafa Farel Azka - 103112400259</p>

## Dasar Teori
C++ adalah bahasa pemrograman yang dikembangkan oleh Bjarne Stroustrup pada tahun 1979 sebagai ekstensi dari bahasa C. C++ dirancang untuk mendukung pemrograman berorientasi objek (OOP) yang memungkinkan programmer untuk mendefinisikan kelas dan objek serta mendukung prinsip enkapsulasi, pewarisan, dan polimorfisme. Fitur utama dari C++ adalah kemampuannya untuk memberikan kontrol langsung atas sumber daya sistem melalui pointer, serta mendukung multi-paradigm programming.[1].


### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. Input Output

```C++
#include<iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka 1: ";
    cin >> angka1;
    
    cout << "Masukan angka 2: ";
    cin >> angka2;
    
    cout << "Penjumlahan: " << angka1 + angka2 << endl;
    cout << "Pengurangan: " << angka1 - angka2 << endl;
    cout << "Perkalian: " << angka1 * angka2 << endl;
    cout << "Pembagian: " << angka1 / angka2 << endl;
    cout << "Sisa bagi: " << angka1 % angka2 << endl;

    return 0;   
}
```
Program di atas adalah program kalkulator sederhana yang meminta input dua angka dan kemudian melakukan operasi aritmatika dasar, yaitu penjumlahan, pengurangan, perkalian, pembagian, dan sisa bagi (modulus).

### 2. Percabangan

```C++
#include<iostream>
using namespace std;

int main () {
    int angka1, angka2;
    cout << "Masukkan angka 1: ";
    cin >> angka1;
    
    cout << "Masukan angka 2: ";
    cin >> angka2;

    if (angka1 == angka2) {
        cout << angka1 << " sama dengan " << angka2 << endl; 
    } else if (angka1 < angka2) {
        cout << angka1 << " lebih kecil dari " << angka2 << endl;
    } else if (angka1 > angka2) {
        cout << angka1 << " lebih besar dari " << angka2 << endl;
    }

    int pilihan;
    cout << "\nMenu Artimatika" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Perkalian" << endl;
    cout << "4. Pembagian" << endl;
    cout << "Masukan pilihan (1/2/3):";
    cin >> pilihan;

    switch(pilihan) {
        case 1:
            cout << "Hasil dari penjumlahan: " << angka1 << "+" << angka2 << "=" << angka1 + angka2 << endl;
            break;
        case 2:
            cout << "Hasil dari pengurangan: " << angka1 << "-" << angka2 << "=" << angka1 - angka2 << endl;
            break;
        case 3:
            cout << "Hasil dari perkalian: " << angka1 << "*" << angka2 << "=" << angka1 * angka2 << endl;
            break;
        case 4:
            cout << "Hasil dari pembagian: " << angka1 << "/" << angka2 << "=" << angka1 / angka2 << endl;
            break;
        default:
            cout << "Pilihan tidak ditemukan" << endl;
    }
    
    return 0;
}
```
Program ini sebenernya hampir sama seperti program sebelumnya, yaitu program meminta untuk memasukan dua buah inputan bertipekan integer. Bedanya adalah di dalam pemrosesan nya, program ini menggunakan percabangan dan switch case.

Yang pertama adalah percabangan, percabangan disini akan di eksekusi terlebih dahulu. Angka pertama dan kedua akan dibandingkan, apakah angka satu sama dengan angka dua, angka satu lebih besar dari angka dua atau sebaliknya angka satu lebih kecil dari angka dua. Output yang dihasilkan adalah hasil perbandingan tersebut.

### 3. Perulangan

```C++
#include<iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukan angka : ";
    cin >> angka;

    for (int i = 0; i < angka; i++) {
        cout << i << " - ";
    }

    cout << endl;

    int j = 10;
    while (j > angka) {
        cout << j << " - ";
        j--;
    }

    cout << endl;

    int k = 10;
    do {
        cout << k << " - ";
    } while (k < angka);

    return 0;
}
```
Program ini berisi 3 jenis perulangan yang berbeda, yaitu for, while, dan do-while. Ketika program dijalankan, program meminta untuk memasukkan inputan bertipekan integer. Kemudian angka yang dimasukkan akan diproses, mulai dari for, kemudian while dan terakhir do-while.

For akan melakukan perulangan, yaitu dimulai dari 0 karena i didefinisikan sebagai 0, dan berakhir sebelum angka yang dimasukkan sebelumnya. Jadi untuk angka yang dimasukkan sebagai 5, maka output dari for adalah 0-1-2-3-4-.

While akan melakukan perulangan dimulai dari nilai 10 karena variabel j didefinisikan dengan 10, dan perulangan terus berjalan selama nilai j lebih besar dari angka yang dimasukkan sebelumnya. Pada setiap perulangan, nilai j ditampilkan lalu dikurangi 1. Jadi while akan menampilkan angka menurun yang dipisahkan oleh "-". Semisal inputan angka di awal adalah 5, maka output dari while adalah 10-9-8-7-6-.

Pada do-while, terdapat variabel k yang menampung nilai 10. Do-while akan selalu menampilkan output 10. Kemudian akan di cek, apakah angka yang dimasukkan lebih dari 10 atau kurang dari 10. Jika angka yang dimasukkan kurang dari 10, do-while ini hanya akan menampilkan output 10. Kalau angka yang dimasukkan lebih dari 10, maka perulangan akan terus berjalan menampilkan angka 10 secara terus menerus. Hal ini terjadi karena while (k < angka) bernilai true terus.

### 4. Struck

```C++
#include<iostream>
using namespace std;

int main() {
    const int MAX = 3;
    struct rapot{
        string nama;
        float nilai;
    };
    
    rapot siswa[MAX];

    for(int i = 0 ; i < MAX; i++){
        cout << "Masukan nama siswa: ";
        cin >> siswa[i].nama;
        cout << "Masukan nilai siswa: ";
        cin >> siswa[i].nilai;
        cout << endl;
    }

    int j = 0;
    while (j < MAX) {
        cout << "Nama siswa: " << siswa[j].nama << ", Nilai: " << siswa[j].nilai << endl;
        j++;
    }
    return 0;
}
```
Program ini menggunakan struktur (struct) untuk menyimpan data siswa, yang terdiri dari nama dan nilai. Struktur rapot digunakan untuk mendeklarasikan dua elemen data, yaitu nama bertipe string dan nilai bertipe float.

Struct rapot: Struktur ini menyimpan data nama siswa dan nilai siswa. Variabel siswa adalah array yang menyimpan data dari 3 siswa.

Array siswa[MAX]: Sebuah array siswa dengan ukuran MAX = 3 digunakan untuk menyimpan data tiga siswa. Data siswa ini dimasukkan oleh pengguna menggunakan perulangan for.

Input dengan for: Pada perulangan for, program meminta pengguna untuk memasukkan nama dan nilai siswa satu per satu. Inputan disimpan di elemen array siswa[i]. Proses ini dilakukan sebanyak tiga kali sesuai dengan ukuran MAX.

Output dengan while: Setelah data siswa dimasukkan, program kemudian menggunakan while untuk menampilkan data yang sudah dimasukkan.

## Unguided 

### 1. soal unguided 1
Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include<iostream>
using namespace std;

int main() {
    float angka1, angka2;
    cout << "Masukkan angka 1: ";
    cin >> angka1;
    
    cout << "Masukan angka 2: ";
    cin >> angka2;
    
    cout << "Penjumlahan: " << angka1 + angka2 << endl;
    cout << "Pengurangan: " << angka1 - angka2 << endl;
    cout << "Perkalian: " << angka1 * angka2 << endl;
    cout << "Pembagian: " << angka1 / angka2 << endl;

    return 0;   
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ShafaFarel/103112400259_Shafa-FarelAzka/blob/main/Pertemuan_Modul1/Unguided/soal1.png)



Program ini meminta dua angka floating point (desimal) dari pengguna dan melakukan empat operasi matematika dasar, yaitu penjumlahan, pengurangan, perkalian, dan pembagian, kemudian menampilkan hasilnya.

### 2. soal unguided 2
Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100
```C++
#include <iostream>
#include <string>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string puluhan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhanKata[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if (angka >= 0 && angka <= 9) {
        cout << satuan[angka] << endl;
    }
    else if (angka >= 10 && angka <= 19) {
        cout << puluhan[angka - 10] << endl;
    }
    else if (angka >= 20 && angka <= 99) {
        int puluh = angka / 10;
        int satu = angka % 10;
        if (satu == 0) cout << puluhanKata[puluh] << endl;
        else cout << puluhanKata[puluh] << " " << satuan[satu] << endl;
    }
    else if (angka == 100) {
        cout << angka << " seratus" << endl;
    }
    else {
        cout << "Invalid, inputan harus di antara 0-100" << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/ShafaFarel/103112400259_Shafa-FarelAzka/blob/main/Pertemuan_Modul1/Unguided/soal2.png)



Program ini bertujuan untuk mengubah angka yang dimasukkan oleh pengguna (antara 0 hingga 100) menjadi kata-kata dalam bahasa Indonesia.

### 3. soal unguided 3
![Screenshot Output Unguided 1_1](https://github.com/ShafaFarel/103112400259_Shafa-FarelAzka/blob/main/Pertemuan_Modul1/Unguided/soal3-unguided.png)
```C++
#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;

    
    for (int i = angka; i >= 1; i--) {
        
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        
        cout << " * ";
       
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/ShafaFarel/103112400259_Shafa-FarelAzka/blob/main/Pertemuan_Modul1/Unguided/soal3.png)


Program ini akan menghasilkan pola angka yang terurut, diikuti dengan bintang, kemudian diikuti dengan angka yang terurut lagi, sesuai dengan input yang diberikan.

## Kesimpulan
Pada modul ini mengajarkan pengenalan dasar dari Bahasa Pemrograman C++. Mulai dari input, output, percabangan, perulangan, struct dan operasi dasar lainnya. Pastinya operasi dasar ini akan sangat berguna untuk kedepannya.

## Referensi
[1] Dewi, Luh Joni Erawati. (2010). "MEDIA PEMBELAJARAN BAHASA PEMROGRAMAN C++". Jurusan Manajemen Informatika, FTK, Undiksha. Diakses pada 27 September 2025 melalui https://ejournal.undiksha.ac.id/index.php/JPTK/article/download/31/25.
<br>[] 
<br>...
