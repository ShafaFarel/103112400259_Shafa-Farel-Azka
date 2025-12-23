#include <iostream>
#include "MultiLinkedList.h"

using namespace std;

NodeChild::NodeChild(string id, string judul, int durasi, int tahun, float rating) {
    IDFilm = id;
    judulFilm = judul;
    durasiFilm = durasi;
    tahunTayang = tahun;
    ratingFilm = rating;
    next = prev = nullptr;
}

NodeParent::NodeParent(string id, string genre) {
    IDGenre = id;
    namaGenre = genre;
    next = prev = nullptr;
    firstChild = lastChild = nullptr;
}

MultiLinkedList::MultiLinkedList() {
    first = last = nullptr;
}

void MultiLinkedList::createListParent() {
    first = last = nullptr;
}

void MultiLinkedList::createListChild() {
    first = last = nullptr;
}

NodeParent* MultiLinkedList::alokasiNodeParent(string id, string genre) {
    return new NodeParent(id, genre);
}

NodeChild* MultiLinkedList::alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    return new NodeChild(id, judul, durasi, tahun, rating);
}

void MultiLinkedList::insertFirstParent(NodeParent*& head, string id, string genre) {
    NodeParent* newNode = alokasiNodeParent(id, genre);
    if (head == nullptr) {
        head = newNode;
        if (this->first == nullptr) this->first = head;
        if (this->last == nullptr) this->last = head;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        this->first = head;
    }
}

void MultiLinkedList::insertFirstChild(NodeParent* parent, string id, string judul, int durasi, int tahun, float rating) {
    if (parent == nullptr) return;
    NodeChild* newNode = alokasiNodeChild(id, judul, durasi, tahun, rating);
    if (parent->firstChild == nullptr) {
        parent->firstChild = parent->lastChild = newNode;
    } else {
        newNode->next = parent->firstChild;
        parent->firstChild->prev = newNode;
        parent->firstChild = newNode;
    }
}

void MultiLinkedList::insertLastChild(NodeParent* parent, string id, string judul, int durasi, int tahun, float rating) {
    if (parent == nullptr) return;
    NodeChild* newNode = alokasiNodeChild(id, judul, durasi, tahun, rating);
    if (parent->firstChild == nullptr) {
        parent->firstChild = parent->lastChild = newNode;
    } else {
        parent->lastChild->next = newNode;
        newNode->prev = parent->lastChild;
        parent->lastChild = newNode;
    }
}

void MultiLinkedList::printStrukturMLL(NodeParent* head) {
    NodeParent* parent = head;
    while (parent != nullptr) {
        cout << "=== Parent ===" << endl;
        cout << "ID Genre: " << parent->IDGenre << endl;
        cout << "Nama Genre: " << parent->namaGenre << endl;

        // Menampilkan film dalam child list
        NodeChild* child = parent->firstChild;
        while (child != nullptr) {
            cout << "- Child: " << endl;
            cout << "  ID Film: " << child->IDFilm << endl;
            cout << "  Judul Film: " << child->judulFilm << endl;
            cout << "  Durasi Film: " << child->durasiFilm << " menit" << endl;
            cout << "  Tahun Tayang: " << child->tahunTayang << endl;
            cout << "  Rating Film: " << child->ratingFilm << endl;
            child = child->next;
        }
        parent = parent->next;
        cout << "-----------------------------" << endl;
    }
}

void MultiLinkedList::searchFilmByRatingRange(NodeParent* head, float minRating, float maxRating) {
    NodeParent* parent = head;
    while (parent != nullptr) {
        cout << "Data Film ditemukan pada list child dari node parent " << parent->namaGenre << endl;
        NodeChild* child = parent->firstChild;
        while (child != nullptr) {
            if (child->ratingFilm >= minRating && child->ratingFilm <= maxRating) {
                cout << "--- Data Film (Child) ---" << endl;
                cout << "ID Film: " << child->IDFilm << endl;
                cout << "Judul Film: " << child->judulFilm << endl;
                cout << "Durasi Film: " << child->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang: " << child->tahunTayang << endl;
                cout << "Rating Film: " << child->ratingFilm << endl;
                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre: " << parent->IDGenre << endl;
                cout << "Nama Genre: " << parent->namaGenre << endl;
                cout << "-------------------------" << endl;
            }
            child = child->next;
        }
        parent = parent->next;
    }
}

void MultiLinkedList::deleteAfterParent(NodeParent*& head, string id) {
    NodeParent* temp = head;
    while (temp != nullptr && temp->IDGenre != id) {
        temp = temp->next;
    }
    if (temp != nullptr && temp->next != nullptr) {
        NodeParent* toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete->next != nullptr) {
            toDelete->next->prev = temp;
        }
        if (toDelete == this->last) this->last = temp;
        delete toDelete;
    }
}

void MultiLinkedList::hapusListChild(NodeParent* head) {
    NodeParent* temp = head;
    while (temp != nullptr) {
        NodeChild* childTemp = temp->firstChild;
        while (childTemp != nullptr) {
            NodeChild* toDelete = childTemp;
            childTemp = childTemp->next;
            delete toDelete;
        }
        temp = temp->next;
    }
}
