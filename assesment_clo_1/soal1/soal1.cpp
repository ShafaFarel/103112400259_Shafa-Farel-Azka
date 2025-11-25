#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = NULL;

string toLower(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

void insertAkhir(string nama) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node* p = head;
        while (p->next != NULL) p = p->next;
        p->next = baru;
    }
}

void deleteNama(string nama) {
    if (head == NULL) return;

    string target = toLower(nama);
    Node* p = head;
    Node* prev = NULL;

    while (p != NULL) {
        if (toLower(p->nama) == target) {
            if (prev == NULL) {
                head = p->next;
            } else {
                prev->next = p->next;
            }
            delete p;
            return;
        }
        prev = p;
        p = p->next;
    }
}

void viewList() {
    Node* p = head;
    while (p != NULL) {
        cout << p->nama;
        if (p->next != NULL) cout << " ";
        p = p->next;
    }
    cout << "\n";
}

void hitungGenap() {
    int jumlah = 0;
    Node* p = head;
    while (p != NULL) {
        if (p->nama.length() % 2 == 0) jumlah++;
        p = p->next;
    }
    cout << "Jumlah nama dengan huruf genap: " << jumlah << "\n";
}

int main() {
    int menu;
    string nama;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit\n";
        cin >> menu;
        cin.ignore();

        if (menu == 1) {
            cout << "Masukkan nama: ";
            getline(cin, nama);
            insertAkhir(nama);
        }
        else if (menu == 2) {
            cout << "Masukkan nama untuk delete: ";
            getline(cin, nama);
            deleteNama(nama);
        }
        else if (menu == 3) {
            viewList();
        }
        else if (menu == 4) {
            hitungGenap();
        }

    } while (menu != 0);

    return 0;
}
