#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void TopoSort(int node, vector<int>& vis, stack<int>& stk, vector<int> adj[]) {
    vis[node] = 1;

    for(auto it: adj[node]) {
        if(!vis[it]) {
            TopoSort(it,vis,stk,adj);
        }
        
    }
    stk.push(node);
}

int main() {

    int n;
    cout<<"Enter no. of Vertices: ";
    cin>>n;


    vector<int>adj[n];
    int i,j;
    while(true) {
        cin>>i>>j;
        if(i==j) break;
        adj[i].push_back(j);
    }
    cout<<"print array"<<endl;
    for(int i=0;i<n;i++) {
        
        for (auto it = adj[i].begin();it != adj[i].end(); it++) {
  
            cout << *it << ' ';
        }
        cout<<endl;
    }
    
    stack<int> stk;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++) {
        if(vis[i]==0) {
            TopoSort(i,vis,stk,adj);
        }
    }

    vector<int> topo;
    while(!stk.empty()) {
        topo.push_back(stk.top());
        stk.pop();
    }


    for(auto it: topo) {
        cout<<it<<" ";
    }
    
    return 0;
}
