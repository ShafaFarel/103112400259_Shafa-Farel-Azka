#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    // Membuat graph dengan 6 kota
    Graph g(6);

    // Menambahkan kota-kota ke dalam graph
    g.addCity("A");
    g.addCity("B");
    g.addCity("C");
    g.addCity("D");
    g.addCity("E");
    g.addCity("F");

    // Menambahkan edge antar kota
    g.addEdge("A", "B");
    g.addEdge("A", "C");
    g.addEdge("B", "D");
    g.addEdge("B", "E");
    g.addEdge("C", "F");

    // Menampilkan graph
    cout << "Distribusi Jaringan Vaksin:\n";
    g.printGraph();

    // Menemukan dan menampilkan titik kritis
    g.findCriticalPoints();

    // Simulasi event untuk kota tertentu (lockdown)
    g.eventSimulation("B", true);  // Lockdown kota B
    g.eventSimulation("B", false); // Membuka kota B

    return 0;
}
