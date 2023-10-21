#include <iostream>
#include <cmath>

using namespace std;

bool canPlace(int x[], int k, int i) {
    for (int j = 1; j <= k - 1; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

void nQueens(int n) {
    int x[n + 1];
    int k = 1;
    x[k] = 0;

    while (k > 0) {
        x[k]++;

        while (x[k] <= n && !canPlace(x, k, x[k])) {
            x[k]++;
        }

        if (x[k] <= n) {
            if (k == n) {
                cout << "Solution: ";
                for (int i = 1; i <= n; i++) {
                    cout << "(" << i << ", " << x[i] << ") ";
                }
                cout << endl;
            } else {
                k++;
                x[k] = 0;
            }
        } else {
            k--;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    nQueens(n);

    return 0;
}
