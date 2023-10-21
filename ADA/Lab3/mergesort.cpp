#include <iostream>
#include <vector>

using namespace std;

void merge(int low, int mid, int high, vector<int>& arr) {
    int i=low,j=mid+1;
    vector<int> a;
    while(i<=mid && j<=high) {
        if(arr[i]<arr[j]) {
            a.push_back(arr[i]);
            i++;
        }
        else {
            a.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid) {
        a.push_back(arr[i]);
        i++;
    }

    while(j<=high) {
        a.push_back(arr[j]);
        j++;
    }
    int k=0;
    for(int i=0;i<(high-low+1);i++) {
        arr[low+i]=a[i];
    }
}
void mergesort(int low, int high, vector<int>& arr) {
    int n = arr.size();

    // if(n==1) return;

    if(low<high) {
        int mid=low+(high-low)/2;

        mergesort(low,mid,arr);
        mergesort(mid+1,high,arr);
        merge(low, mid, high, arr);
    }
}

int main() {
    vector<int> arr = {2,3,1,5};
    mergesort(0,arr.size()-1,arr);

    for(int i=0;i<arr.size();i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}
