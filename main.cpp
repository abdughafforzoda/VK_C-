#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ifstream fin("graph.txt");
    if (!fin) {
        cerr << "Ошибка открытия файла graph.txt" << endl;
        return 1;
    }
    
    int nVertices, nEdges;
    fin >> nVertices;
    fin >> nEdges;
    
    vector<vector<int>> adj(nVertices);
    
    for (int i = 0; i < nEdges; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int startVertex;
    fin >> startVertex;
    fin.close();
    
    const int INF = 1e9;
    vector<int> dist(nVertices, INF);
    
    queue<int> q;
    dist[startVertex] = 0;
    q.push(startVertex);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    for (int d : dist) {
        cout << d << endl;
    }
    
    return 0;
}
