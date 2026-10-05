#include <iostream>
#include <vector>
using namespace std;

void minimalSwapCrane(int arr[], int size) {
    long long swaps = 0, skipped = 0, comparisons = 0;
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        if (minIdx == i) {
            skipped++;
        } else {
            int t = arr[i]; arr[i] = arr[minIdx]; arr[minIdx] = t;
            swaps++;
        }
    }
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "\nTotal actual swaps: " << swaps << endl;
    cout << "Skipped swaps: " << skipped << endl;
    cout << "Total comparisons: " << comparisons
         << " (N(N-1)/2 = " << (long long)size * (size - 1) / 2 << ")" << endl;
    double ratio = comparisons > 0 ? (double)swaps / comparisons * 100.0 : 0.0;
    cout << "Swap-to-Comparison Ratio: " << ratio << "%" << endl;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter tracking IDs: ";
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << "Task 3:" << endl;
    minimalSwapCrane(v.data(), n);
    return 0;
}
