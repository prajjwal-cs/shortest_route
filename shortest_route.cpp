#include <iostream>
using namespace std;

void calculateShortestRoute(int n, int m, int arr[], int brr[]) {
    int right[n];
    int left[n];
    int righto = -1;
    int lefto = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1)
            righto = i;
        if (righto != -1)
            right[i] = i - righto;
        else
            right[i] = -1;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 2)
            lefto = i;
        if (lefto != -1)
            left[i] = lefto - i;
        else
            left[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        int res = brr[i] - 1;
        if (arr[res] == 1 || arr[res] == 2 || res == 0) {
            cout << 0 << " ";
        } else {
            if (left[res] > 0 && right[res] > 0) {
                cout << min(left[res], right[res]) << " ";
            } else if (left[res] > 0 && right[res] < 0) {
                cout << left[res] << " ";
            } else if (left[res] < 0 && right[res] > 0) {
                cout << right[res] << " ";
            } else {
                cout << -1 << " ";
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[n];
        for (size_t i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int brr[m];
        for (size_t i = 0; i < m; i++) {
            cin >> brr[i];
        }
        calculateShortestRoute(n, m, arr, brr);
        cout << endl;
    }
    return 0;
}