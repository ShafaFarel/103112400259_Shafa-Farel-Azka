#include "Graph.h"

using namespace std;

Graph::Graph(int V) {
    this->V = 0;
    graph.reserve(V);
}

void Graph::addCity(string name) {
    // add city at the end and update mappings
    cityToIndex[name] = graph.size();
    graph.push_back(Node{ name });
    this->V = (int)graph.size();
}

void Graph::addEdge(string u, string v) {
    int uIndex = cityToIndex[u];
    int vIndex = cityToIndex[v];

    graph[uIndex].adj.push_back(vIndex);
    graph[vIndex].adj.push_back(uIndex);
}

void Graph::dfs(int u, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& ap, vector<bool>& visited) {
    static int time = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;

    int children = 0;

    for (int v : graph[u].adj) {
        if (!visited[v]) {
            children++;
            parent[v] = u;
            dfs(v, disc, low, parent, ap, visited);

            low[u] = min(low[u], low[v]);

            if (parent[u] == -1 && children > 1)
                ap[u] = true;
            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = true;
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void Graph::findCriticalPoints() {
    int sz = (int)graph.size();
    vector<int> disc(sz, -1);
    vector<int> low(sz, -1);
    vector<int> parent(sz, -1);
    vector<bool> ap(sz, false);
    vector<bool> visited(sz, false);

    for (int i = 0; i < sz; i++) {
        if (!visited[i])
            dfs(i, disc, low, parent, ap, visited);
    }

    cout << "\nAnalisis Kota Kritis (Single Point of Failure)\n";
    for (int i = 0; i < sz; i++) {
        if (ap[i]) {
            cout << "[PERINGATAN] Kota " << graph[i].name << " adalah KOTA KRITIS!" << endl;
            cout << "-> Jika " << graph[i].name << " lockdown, distribusi terputus." << endl;
        } else {
            cout << "Kota " << graph[i].name << " aman (redundansi oke)." << endl;
        }
    }
}

void Graph::printGraph() {
    for (int i = 0; i < (int)graph.size(); i++) {
        cout << "Node " << graph[i].name << " terhubung ke: ";
        bool first = true;
        for (int adj : graph[i].adj) {
            if (!first) cout << " ";
            cout << graph[adj].name;
            first = false;
        }
        cout << endl;
    }
}

void Graph::eventSimulation(string city, bool lockdown) {
    int cityIndex = cityToIndex[city];
    if (lockdown) {
        cout << "Kota " << city << " dalam lockdown!" << endl;
        // A simple simulation message — real simulation would ignore node during traversal
        cout << "-> Distribusi ke kota lain akan terpengaruh jika kota ini adalah kritis." << endl;
    } else {
        cout << "Kota " << city << " telah dibuka kembali!" << endl;
        cout << "-> Distribusi vaksin kembali normal." << endl;
    }
}
