#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int knapsack(int w, vector<int> p, vector<int> weights) {
    int n = p.size();
    vector<vector<int>> v(n+1,vector<int>(w+1));

    // for(int i=1;i<v.size();i++) {
    //     for(int j=1;j<v[0].size();j++) {
    //         if(weights[i-1]>j) {
    //             v[i][j] = v[i-1][j];
    //         }
    //         else {
    //             v[i][j] = max(v[i-1][j], v[i-1][j-weights[i-1]]+p[i-1]);
    //         }
    //     }
    // }

    for(int i=0;i<v.size();i++) {
        for(int j=0;j<v[0].size();j++) {
            if(i == 0 || j == 0) {
                v[i][j] = 0;
            }
            else if(weights[i-1]>j) {
                v[i][j] = v[i-1][j];
            }
            else {
                v[i][j] = max(v[i-1][j], v[i-1][j-weights[i-1]]+p[i-1]);
            }
        }
    }

    return v[n][w];
}
int main() {
    // vector<int> weights = {2,1,3,2};
    // vector<int> profit = {12,15,25,10};

    vector<int> weights = {2,3,1,2,4};
    vector<int> profit = {10,12,25,13,11};

    cout<<knapsack(5,profit,weights);

    return 0;
}
