#include <iostream>
#include <vector>

using namespace std;

int partition(int low, int high, vector<int>& arr) {
    int i=low,j=high;
    int pivot=arr[low];
    while(i<j) {
        while((arr[i]<=pivot) && (i<=(high+1))) {
            i++;
        }
        while((arr[j]>pivot)  &&  (j>=(low-1))) {
            j--;
        }
        if(i<j) {
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void quicksort(int low, int high, vector<int>& arr) {
    if(low<high) {
        int p = partition(low, high, arr);
        quicksort(low,p-1,arr);
        quicksort(p+1,high,arr);
    }
}


int main() {
    
    vector<int> arr = {2,1,5,3};

    quicksort(0,arr.size()-1,arr);

    for(auto x: arr) {
        cout<<x<<" ";
    }
    // cout<<"e";
    return 0;
}