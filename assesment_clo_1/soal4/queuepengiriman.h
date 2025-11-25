#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int MAX = 5;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang;
    string Tujuan;
};

struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
};

bool isEmpty(const QueueEkspedisi& Q);
bool isFull(const QueueEkspedisi& Q);
void createQueue(QueueEkspedisi& Q);
void enQueue(QueueEkspedisi& Q, const Paket& newData);
void deQueue(QueueEkspedisi& Q);
void viewQueue(const QueueEkspedisi& Q);
void TotalBiayaPengiriman(const QueueEkspedisi& Q); 

#endif // QUEUEPENGIRIMAN_H