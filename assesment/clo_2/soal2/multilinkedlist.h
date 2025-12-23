#ifndef MULTILINKEDLIST_H
#define MULTILINKEDLIST_H

#include <string>
using namespace std;

// Struktur node untuk list anak (film)
struct NodeChild {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    NodeChild* next;
    NodeChild* prev;

    // Konstruktor untuk inisialisasi node anak
    NodeChild(string id, string judul, int durasi, int tahun, float rating);
};

// Struktur node untuk list induk (genre)
struct NodeParent {
    string IDGenre;
    string namaGenre;
    NodeParent* next;
    NodeParent* prev;
    NodeChild* firstChild;
    NodeChild* lastChild;

    // Konstruktor untuk inisialisasi node induk
    NodeParent(string id, string genre);
};

// Kelas Multi Linked List
class MultiLinkedList {
public:
    NodeParent* first;
    NodeParent* last;

    MultiLinkedList();
    void createListParent();
    void createListChild();
    NodeParent* alokasiNodeParent(string id, string genre);
    NodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);

    void insertFirstParent(NodeParent*& head, string id, string genre);
    void insertFirstChild(NodeParent* parent, string id, string judul, int durasi, int tahun, float rating);
    void insertLastChild(NodeParent* parent, string id, string judul, int durasi, int tahun, float rating);

    void printStrukturMLL(NodeParent* head);
    void searchFilmByRatingRange(NodeParent* head, float minRating, float maxRating);
    void deleteAfterParent(NodeParent*& head, string id);
    void hapusListChild(NodeParent* head);
};

#endif
