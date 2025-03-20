#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int v) : vertices(v) {
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    void shortestPath(int start) {
        vector<int> distance(vertices, -1);
        queue<int> q;
        
        distance[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int neighbor : adjList[current]) {
                if (distance[neighbor] == -1) {
                    distance[neighbor] = distance[current] + 1;
                    q.push(neighbor);
                }
            }
        }

        for (int i = 0; i < vertices; i++) {
            cout << distance[i] << endl;
        }
    }
};

int main() {
    ifstream file("graph.txt");
    if (!file) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    int numVertices, numEdges, startVertex;
    file >> numVertices >> numEdges;

    Graph g(numVertices);

    for (int i = 0; i < numEdges; i++) {
        int u, v;
        file >> u >> v;
        g.addEdge(u, v);
    }

    file >> startVertex;
    file.close();

    g.shortestPath(startVertex);

    return 0;
}
