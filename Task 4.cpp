#include <iostream>
#include <vector>
using namespace std;

void diminishingDistanceScanner(int arr[], int size) {
    for (int gap = size / 2; gap >= 1; gap /= 2) {
        long long comparisons = 0, swaps = 0;
        for (int i = gap; i < size; i++) {
            for (int j = i; j >= gap; j -= gap) {
                comparisons++;
                if (arr[j - gap] > arr[j]) {
                    int t = arr[j]; arr[j] = arr[j - gap]; arr[j - gap] = t;
                    swaps++;
                } else {
                    break;
                }
            }
        }
        cout << "Gap: " << gap << endl;
        cout << "  Gap as % of array size: " << (double)gap / size * 100.0 << "%" << endl;
        cout << "  Comparisons in this phase: " << comparisons << endl;
        cout << "  Swaps in this phase: " << swaps << endl;
    }
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter tracking IDs: ";
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << "Task 4:" << endl;
    if (n < 2) {
        cout << "Nothing to sort (fewer than 2 items)." << endl;
        return 0;
    }
    diminishingDistanceScanner(v.data(), n);
    return 0;
}
