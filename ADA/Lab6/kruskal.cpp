#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class Graph {
private:
    int V;
    vector<Edge> edges;

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    int findParent(vector<int>& parent, int node) {
        return parent[node] == -1 ? node : findParent(parent, parent[node]);
    }

    void unionNodes(vector<int>& parent, int x, int y) {
        int xset = findParent(parent, x);
        int yset = findParent(parent, y);
        parent[xset] = yset;
    }

    vector<Edge> kruskalMST() {
        vector<Edge> result;
        vector<int> parent(V, -1);

        sort(edges.begin(), edges.end(), compareEdges);

        for (const Edge& edge : edges) {
            int srcParent = findParent(parent, edge.src);
            int destParent = findParent(parent, edge.dest);

            if (srcParent != destParent) {
                result.push_back(edge);
                unionNodes(parent, srcParent, destParent);
            }
        }

        return result;
    }
};

int main() {
    int V = 5; // Number of vertices
    Graph graph(V);

    int inputGraph[5][5] = {
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 }
    };

    // Create the graph from the given input
    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            int weight = inputGraph[i][j];
            if (weight != 0) {
                graph.addEdge(i, j, weight);
            }
        }
    }

    vector<Edge> minimumSpanningTree = graph.kruskalMST();

    cout << "Minimum Spanning Tree edges:\n";
    for (const Edge& edge : minimumSpanningTree) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}
