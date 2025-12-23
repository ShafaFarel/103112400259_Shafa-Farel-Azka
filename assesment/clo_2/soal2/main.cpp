#include <iostream>
#include "MultiLinkedList.h"

using namespace std;

int main() {
    MultiLinkedList mll;
    NodeParent* head = nullptr;

    // Membuat list parent dan child
    mll.insertFirstParent(head, "G001", "Action");
    mll.insertFirstChild(head, "FA001", "The Raid", 101, 2011, 7.6);

    mll.insertFirstParent(head, "G002", "Comedy");
    mll.insertFirstChild(head, "FC001", "Agak Laen", 119, 2024, 8);
    mll.insertLastChild(head, "FC002", "My Stupid Boss", 108, 2016, 6.8);

    mll.insertFirstParent(head, "G003", "Horror");
    mll.insertFirstChild(head, "FH001", "Pengabdi Setan", 107, 2017, 8.4);

    // Menampilkan struktur MLL
    mll.printStrukturMLL(head);

    // Mencari film dengan rentang rating 8.0 - 8.5
    mll.searchFilmByRatingRange(head, 8.0, 8.5);

    // Menghapus node parent dan child yang terkait
    mll.deleteAfterParent(head, "G002");

    // Menampilkan struktur MLL setelah penghapusan
    mll.printStrukturMLL(head);

    return 0;
}
