#include <iostream>
#include <string>
using namespace std;

// Struktur node BST
struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node* left;
    Node* right;

    // Konstruktor untuk inisialisasi node
    Node(string nama, float berat, string tier) {
        namaMember = nama;
        beratBadan = berat;
        tierMember = tier;
        left = right = nullptr;
    }
};

// Kelas Binary Search Tree (BST)
class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Method untuk memeriksa apakah BST kosong
    bool isEmpty() {
        return root == nullptr;
    }

    // Method untuk membuat BST
    void createTree() {
        root = nullptr;
    }

    // Method untuk membuat node baru
    Node* newNode(string nama, float berat, string tier) {
        return new Node(nama, berat, tier);
    }

    // Insert node ke dalam BST
    void insertNode(Node* &root, string nama, float berat, string tier) {
        if (root == nullptr) {
            root = newNode(nama, berat, tier);
        } else if (berat < root->beratBadan) {
            insertNode(root->left, nama, berat, tier);
        } else {
            insertNode(root->right, nama, berat, tier);
        }
    }

    // Insert node dengan data yang diberikan
    void insertNode(string nama, float berat, string tier) {
        insertNode(root, nama, berat, tier);
    }

    // Traversal BST in-order
    void inOrder(Node* root) {
        if (root != nullptr) {
            inOrder(root->left);
            cout << root->beratBadan << " - " << root->namaMember << " - " << root->tierMember << endl;
            inOrder(root->right);
        }
    }

    // Menampilkan traversal in-order
    void inOrder() {
        cout << "=== Traversal InOrder ===" << endl;
        inOrder(root);
    }

    // Menampilkan node paling kiri (nilai terkecil)
    void mostLeft() {
        Node* current = root;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        cout << "Node MostLeft: " << current->beratBadan << " - " << current->namaMember << endl;
    }

    // Menampilkan node paling kanan (nilai terbesar)
    void mostRight() {
        Node* current = root;
        while (current && current->right != nullptr) {
            current = current->right;
        }
        cout << "Node MostRight: " << current->beratBadan << " - " << current->namaMember << endl;
    }

    // Mencari data berdasarkan berat badan
    void searchByBeratBadan(Node* root, float berat) {
        if (root == nullptr) {
            cout << "Data tidak ditemukan dalam BST!" << endl;
            return;
        }
        if (root->beratBadan == berat) {
            cout << "--- Data Node Yang Dicari ---" << endl;
            cout << "Nama Member: " << root->namaMember << endl;
            cout << "Berat Badan: " << root->beratBadan << endl;
            cout << "Tier Member: " << root->tierMember << endl;
            return;
        }
        else if (berat < root->beratBadan) {
            cout << "--- Data Parent ---" << endl;
            cout << "Nama Member: " << root->namaMember << endl;
            cout << "Berat Badan: " << root->beratBadan << endl;
            cout << "Tier Member: " << root->tierMember << endl;
            cout << "Tidak Memiliki Sibling" << endl;
            searchByBeratBadan(root->left, berat);
        }
        else {
            cout << "--- Data Parent ---" << endl;
            cout << "Nama Member: " << root->namaMember << endl;
            cout << "Berat Badan: " << root->beratBadan << endl;
            cout << "Tier Member: " << root->tierMember << endl;
            cout << "Tidak Memiliki Sibling" << endl;
            searchByBeratBadan(root->right, berat);
        }
    }

    // Mencari data berdasarkan berat badan
    void searchByBeratBadan(float berat) {
        searchByBeratBadan(root, berat);
    }
};

int main() {
    BST bst;

    // Membuat tree dengan data anggota gym
    bst.insertNode("Rizkina Azizah", 60, "Basic");
    bst.insertNode("Hakan Ismail", 50, "Bronze");
    bst.insertNode("Olivia Saevali", 65, "Silver");
    bst.insertNode("Felix Pedrosa", 47, "Gold");
    bst.insertNode("Gamel Al Ghifari", 56, "Platinum");
    bst.insertNode("Hanif Al Faiz", 70, "Basic");
    bst.insertNode("Mutiara Fauziah", 52, "Bronze");
    bst.insertNode("Davi Ilyas", 68, "Silver");
    bst.insertNode("Abdad Mubarak", 81, "Gold");

    // Menampilkan traversal in-order
    bst.inOrder();

    // Menampilkan node paling kiri dan kanan
    bst.mostLeft();
    bst.mostRight();

    // Mencari data berdasarkan berat badan
    bst.searchByBeratBadan(70);

    return 0;
}
