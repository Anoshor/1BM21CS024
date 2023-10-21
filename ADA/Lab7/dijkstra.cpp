#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

const int MAX_NODES = 100;
using namespace std;


vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
         
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(V, INT_MAX);
        
        dist[S] = 0;
        
        pq.push({0,S});
        
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto it: adj[node]) {
                int edgeWeight = it[1];
                
                int adjNode = it[0];
                
                if(dis+edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }


int main() {

    vector<vector<int>> adj[MAX_NODES];
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    while(true) {
        int u,v,w;
        cout <<endl<< "Enter edge (u v w): ";
        cin >> u >> v >> w;

        if(u==-1) {
            break;
        }
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> res;

    res = dijkstra(V, adj, 0);

    for(auto x: res) {
        cout<<x<<" ";
    }

    return 0;
}
