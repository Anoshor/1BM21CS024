#include <iostream>
#include <vector>

using namespace std;

void johnsonTrotter(int n) {
    
    vector<int> permutation(n);
    //initialize the array with the first permutation
    for(int i=0;i<n;i++) {
        permutation[i]=i+1;
    }
    vector<int> direction(n, -1);

    
    int mobile;

    while (1) {
        // current permutation
        for (int i = 0; i < n; i++) {
            cout << permutation[i];
        }
        cout << endl;

        // set the mobileIndex to -1 so that we can end the while loop
        int mobileIndex = -1;
        mobile = 0;
        // mobile = permutation[permutation.size()-1];
        for (int i = 0; i < n; i++) {
            if (direction[i] == -1 && i != 0) {
                //if the element points to left and the value is greater than its left adjacent and also its greater than the current mobile
                if (permutation[i] > permutation[i - 1] && permutation[i] > mobile) {
                    mobile = permutation[i];
                    mobileIndex = i;
                }
            }

            if (direction[i] == 1 && i != n - 1) {
                //if the element points to right and the value is greater than its right adjacent and also its greater than the current mobile
                if (permutation[i] > permutation[i + 1] && permutation[i] > mobile) {
                    mobile = permutation[i];
                    mobileIndex = i;
                }
            }
        }

        // end if no mobile element
        if (mobileIndex == -1) {
            break;
        }

        // Swap adjacent elements (ONLY ONCE)
        if (direction[mobileIndex] == -1) { //if mobile element pointing to left
            swap(permutation[mobileIndex], permutation[mobileIndex - 1]);
            swap(direction[mobileIndex], direction[mobileIndex - 1]);
        } else if (direction[mobileIndex] == 1) { //if mobile element pointing to right
            swap(permutation[mobileIndex], permutation[mobileIndex + 1]);
            swap(direction[mobileIndex], direction[mobileIndex + 1]);
        }

        // Reverse the direction of the elements which are greater than mobile
        for (int i = 0; i < n; i++) {
            if (permutation[i] > mobile) {
                direction[i] = -direction[i];
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Permutations using Johnson Trotter Algorithm:" << endl;
    johnsonTrotter(n);

    return 0;
}
