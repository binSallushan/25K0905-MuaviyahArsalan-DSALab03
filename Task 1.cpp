#include <iostream>
#include <vector>
using namespace std;

void adjacentSwapper(int arr[], int size) {
    long long swaps = 0, comparisons = 0;
    int passes = 0;
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        passes++;
        for (int j = 0; j < size - 1 - i; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    int worstPasses = size > 0 ? size - 1 : 0;
    int saved = worstPasses - passes;
    if (saved < 0) saved = 0;

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "\nTotal swaps made: " << swaps << endl;
    cout << "Total comparisons made: " << comparisons << endl;
    cout << "Passes used: " << passes << " (worst case " << worstPasses << ")" << endl;
    cout << "Passes saved: " << saved << endl;
    cout << "Theoretical worst-case comparisons N(N-1)/2: "
         << (long long)size * (size - 1) / 2 << " | Actual: " << comparisons << endl;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter tracking IDs: ";
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << "Task 1:" << endl;
    adjacentSwapper(v.data(), n);
    return 0;
}
