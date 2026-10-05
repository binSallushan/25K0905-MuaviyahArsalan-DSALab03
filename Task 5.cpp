#include <iostream>
#include <vector>
using namespace std;

int midpointSplitSearch(int arr[], int size, int targetID) {
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] > arr[i]) {
            cout << "Error: Conveyor is unsorted. Search aborted." << endl;
            return -1;
        }
    }
    int maxSteps = 0;
    for (int n = size; n > 0; n /= 2) maxSteps++;   // floor(log2(N)) + 1

    int low = 0, high = size - 1, steps = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        steps++;
        cout << "Step " << steps << ": low = " << low << ", mid = " << mid
             << ", high = " << high << endl;
        cout << "  Remaining search space: "
             << (double)(high - low + 1) / size * 100.0 << "%" << endl;
        cout << "  Steps taken: " << steps << " / theoretical max: " << maxSteps << endl;
        if (arr[mid] == targetID) return mid;
        if (targetID < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main() {
    int n, target;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter tracking IDs: ";
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << "Enter tracking ID to search for: ";
    cin >> target;
    cout << "Task 5:" << endl;
    int idx = midpointSplitSearch(v.data(), n, target);
    if (idx != -1) cout << "Found at index: " << idx << endl;
    else cout << "Result: -1 (not found / search aborted)" << endl;
    return 0;
}
