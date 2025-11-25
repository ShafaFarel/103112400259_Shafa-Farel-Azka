#include <iostream>
#include <cstdlib>

using namespace std;

// Struktur untuk Node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Pointer Head (awal list) dan Tail (akhir list)
Node* head = NULL;
Node* tail = NULL;

// 1. Insert nilai akhir list (Insert at End)
void insertEnd(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        // List kosong
        newNode->prev = NULL;
        head = newNode;
        tail = newNode;
    } else {
        // List tidak kosong
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    cout << "Nilai " << val << " berhasil di-insert di akhir list." << endl;
}

// 2. Delete nilai terakhir (Delete Last)
void deleteLast() {
    if (head == NULL) {
        cout << "List kosong, tidak ada yang dihapus." << endl;
        return;
    }

    Node* temp = tail;
    int deletedVal = temp->data;

    if (head == tail) {
        // Hanya ada satu node
        head = NULL;
        tail = NULL;
    } else {
        // Lebih dari satu node
        tail = tail->prev;
        tail->next = NULL;
    }

    delete temp;
    cout << "Nilai terakhir (" << deletedVal << ") berhasil di-delete." << endl;
}

// 3. View depan ke belakang (Display Forward)
void viewDepan() {
    if (head == NULL) {
        cout << "List kosong." << endl;
        return;
    }

    Node* current = head;
    cout << "List: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// 4. Reverse list (tanpa node baru) dan View setelah di-reverse
void reverseAndView() {
    if (head == NULL || head == tail) {
        cout << "List: ";
        if (head != NULL) cout << head->data;
        cout << endl;
        return;
    }

    Node* current = head;
    Node* temp = NULL;

    // Menukar pointer prev dan next untuk setiap node
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Melangkah ke node berikutnya (yang sekarang ada di prev lama)
    }

    // Menukar head dan tail
    temp = head;
    head = tail;
    tail = temp;

    cout << "List setelah di-reverse: ";
    // Tampilkan dari head baru (yang merupakan tail lama)
    Node* displayCurrent = head;
    while (displayCurrent != NULL) {
        cout << displayCurrent->data << " ";
        displayCurrent = displayCurrent->next;
    }
    cout << endl;
}

// Fungsi utama untuk menjalankan menu
int main() {
    int choice;
    int val;

    do {
        cout << "\nMenu: 1 insert (end), 2 delete (last), 3 view depan, 4 reverse & view (depan), 0 exit" << endl;
        cout << "Masukkan angka: ";
        if (!(cin >> choice)) {
            // Handle input non-integer
            cout << "Input tidak valid. Harap masukkan angka." << endl;
            cin.clear(); // Hapus status error
            cin.ignore(10000, '\n'); // Buang input yang salah
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Masukkan nilai: ";
                if (!(cin >> val)) {
                    cout << "Input tidak valid. Harap masukkan angka." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }
                insertEnd(val);
                break;
            case 2:
                deleteLast();
                break;
            case 3:
                viewDepan();
                break;
            case 4:
                reverseAndView();
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 0);

    // Pembersihan memori sebelum keluar
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;

    return 0;
}