#include <bits/stdc++.h> 
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void heapify(vector<int>& arr, int N, int i)
{
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int l = 2 * i + 1;
 
    // right = 2*i + 2
    int r = 2 * i + 2;
 
    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
vector<int> heapSort(vector<int>& arr, int N) {
	

    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
 
    for (int i = N - 1; i > 0; i--) {
 
        
        swap(arr[0], arr[i]);
 
        
        heapify(arr, i, 0);
    }

    return arr;

}

int main() {

  vector<int> arr = {3,1,4,2,8};

  heapSort(arr, arr.size());

  for(auto x : arr) { cout<<x<<" "; }
  
  return 0;
}
